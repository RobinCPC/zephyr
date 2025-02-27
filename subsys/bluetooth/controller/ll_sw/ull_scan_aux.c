/*
 * Copyright (c) 2020 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <sys/byteorder.h>
#include <sys/util.h>

#include "util/mem.h"
#include "util/memq.h"
#include "util/mayfly.h"
#include "util/util.h"

#include "hal/ticker.h"

#include "ticker/ticker.h"

#include "pdu.h"

#include "lll.h"
#include "lll/lll_vendor.h"
#include "lll_scan.h"
#include "lll_scan_aux.h"
#include "lll/lll_df_types.h"
#include "lll_sync.h"
#include "lll_sync_iso.h"

#include "ull_scan_types.h"
#include "ull_sync_types.h"

#include "ull_internal.h"
#include "ull_scan_internal.h"
#include "ull_sync_internal.h"

#define BT_DBG_ENABLED IS_ENABLED(CONFIG_BT_DEBUG_HCI_DRIVER)
#define LOG_MODULE_NAME bt_ctlr_ull_scan_aux
#include "common/log.h"
#include <soc.h>
#include "hal/debug.h"

static int init_reset(void);
static inline struct ll_scan_aux_set *aux_acquire(void);
static inline void aux_release(struct ll_scan_aux_set *aux);
static inline uint8_t aux_handle_get(struct ll_scan_aux_set *aux);
static inline struct ll_sync_set *sync_create_get(struct ll_scan_set *scan);
static void last_disabled_cb(void *param);
static void done_disabled_cb(void *param);
static void flush(struct ll_scan_aux_set *aux, struct node_rx_hdr *rx);
static void ticker_cb(uint32_t ticks_at_expire, uint32_t remainder,
		      uint16_t lazy, uint8_t force, void *param);
static void ticker_op_cb(uint32_t status, void *param);
static void ticker_op_aux_failure(void *param);

static struct ll_scan_aux_set ll_scan_aux_pool[CONFIG_BT_CTLR_SCAN_AUX_SET];
static void *scan_aux_free;

int ull_scan_aux_init(void)
{
	int err;

	err = init_reset();
	if (err) {
		return err;
	}

	return 0;
}

int ull_scan_aux_reset(void)
{
	int err;

	err = init_reset();
	if (err) {
		return err;
	}

	return 0;
}

void ull_scan_aux_setup(memq_link_t *link, struct node_rx_hdr *rx)
{
	struct pdu_adv_aux_ptr *aux_ptr;
	struct pdu_adv_com_ext_adv *p;
	uint32_t ticks_slot_overhead;
	struct lll_scan_aux *lll_aux;
	struct ll_scan_aux_set *aux;
	uint32_t window_widening_us;
	uint32_t ticks_slot_offset;
	uint32_t ticks_aux_offset;
	struct pdu_adv_ext_hdr *h;
	struct ll_scan_set *scan;
	struct ll_sync_set *sync;
	struct pdu_adv_adi *adi;
	struct node_rx_ftr *ftr;
	uint32_t ready_delay_us;
	uint32_t aux_offset_us;
	uint32_t ticker_status;
	struct lll_scan *lll;
	struct pdu_adv *pdu;
	uint8_t aux_handle;
	bool is_lll_sched;
	bool is_scan_req;
	bool is_lll_aux;
	uint8_t *ptr;
	uint8_t phy;

	is_scan_req = false;
	is_lll_aux = false;
	ftr = &rx->rx_ftr;

	switch (rx->type) {
	case NODE_RX_TYPE_EXT_1M_REPORT:
		lll_aux = NULL;
		aux = NULL;
		lll = ftr->param;
		scan = HDR_LLL2ULL(lll);
		sync = sync_create_get(scan);
		phy = BT_HCI_LE_EXT_SCAN_PHY_1M;
		break;
	case NODE_RX_TYPE_EXT_CODED_REPORT:
		lll_aux = NULL;
		aux = NULL;
		lll = ftr->param;
		scan = HDR_LLL2ULL(lll);
		sync = sync_create_get(scan);
		phy = BT_HCI_LE_EXT_SCAN_PHY_CODED;
		break;
	case NODE_RX_TYPE_EXT_AUX_REPORT:
		if (ull_scan_aux_is_valid_get(HDR_LLL2ULL(ftr->param))) {
			/* Node has valid aux context so its scan was scheduled
			 * from ULL.
			 */
			lll_aux = ftr->param;
			aux = HDR_LLL2ULL(lll_aux);
			/* FIXME: pick the aux somehow */
			lll = aux->rx_head->rx_ftr.param;
			LL_ASSERT(!lll->lll_aux);
		} else {
			/* Node that does not have valid aux context was
			 * scheduled from LLL. We can retrieve aux context
			 * from lll_scan as it was stored there when superior
			 * PDU was handled.
			 */
			lll = ftr->param;

			lll_aux = lll->lll_aux;
			LL_ASSERT(lll_aux);

			aux = HDR_LLL2ULL(lll_aux);
			LL_ASSERT(lll == aux->rx_head->rx_ftr.param);

			/* aux is retrieved from LLL Aux scheduling */
			is_lll_aux = true;
		}

		scan = HDR_LLL2ULL(lll);
		sync = (void *)scan;
		scan = ull_scan_is_valid_get(scan);
		phy = lll_aux->phy;
		if (scan) {
			/* Here we are scanner context */
			sync = sync_create_get(scan);

			/* Generate report based on PHY scanned */
			switch (phy) {
			case PHY_1M:
				rx->type = NODE_RX_TYPE_EXT_1M_REPORT;
				break;
			case PHY_2M:
				rx->type = NODE_RX_TYPE_EXT_2M_REPORT;
				break;
			case PHY_CODED:
				rx->type = NODE_RX_TYPE_EXT_CODED_REPORT;
				break;
			default:
				LL_ASSERT(0);
				return;
			}

			/* Backup scan requested flag as it is in union with
			 * `extra` struct member which will be set to NULL
			 * in subsequent code.
			 */
			is_scan_req = !!ftr->scan_req;

#if defined(CONFIG_BT_CTLR_SYNC_PERIODIC)
		} else {
			/* Here we are periodic sync context */
			rx->type = NODE_RX_TYPE_SYNC_REPORT;
			rx->handle = ull_sync_handle_get(sync);

			/* lll_aux and aux are auxiliary channel context,
			 * reuse the existing aux context to scan the chain.
			 * hence lll_aux and aux are not released or set to NULL.
			 */
			sync = NULL;
		}
		break;

	case NODE_RX_TYPE_SYNC_REPORT:
		{
			struct ll_sync_set *ull_sync;
			struct lll_sync *lll_sync;

			/* set the sync handle corresponding to the LLL context
			 * passed in the node rx footer field.
			 */
			lll_sync = ftr->param;
			ull_sync = HDR_LLL2ULL(lll_sync);
			rx->handle = ull_sync_handle_get(ull_sync);

			/* FIXME: we will need lll_scan if chain was scheduled
			 *        from LLL; should we store lll_scan_set in
			 *        lll_sync instead?
			 */
			lll = NULL;
			lll_aux = NULL;
			aux = NULL;
			scan = NULL;
			sync = NULL;
			phy =  lll_sync->phy;
#endif /* CONFIG_BT_CTLR_SYNC_PERIODIC */

		}
		break;
	default:
		LL_ASSERT(0);
		return;
	}

	/* Copy to local flag since we need to clear 'extra' field */
	is_lll_sched = !!ftr->aux_sched;

	rx->link = link;
	ftr->extra = NULL;

	pdu = (void *)((struct node_rx_pdu *)rx)->pdu;
	p = (void *)&pdu->adv_ext_ind;
	if (!p->ext_hdr_len) {
		goto ull_scan_aux_rx_flush;
	}

	h = (void *)p->ext_hdr_adv_data;
	if (!h->aux_ptr && !sync) {
		if (is_scan_req) {
			LL_ASSERT(aux && aux->rx_last);

			aux->rx_last->rx_ftr.extra = rx;
			aux->rx_last = rx;

			return;
		}

		goto ull_scan_aux_rx_flush;
	}

	ptr = h->data;

	if (h->adv_addr) {
#if defined(CONFIG_BT_CTLR_SYNC_PERIODIC)
		if (sync && (pdu->tx_addr == scan->per_scan.adv_addr_type) &&
		    !memcmp(ptr, scan->per_scan.adv_addr, BDADDR_SIZE)) {
			scan->per_scan.state = LL_SYNC_STATE_ADDR_MATCH;
		}
#endif /* CONFIG_BT_CTLR_SYNC_PERIODIC */

		ptr += BDADDR_SIZE;
	}

	if (h->tgt_addr) {
		ptr += BDADDR_SIZE;
	}

	adi = NULL;
	if (h->adi) {
		adi = (void *)ptr;
		ptr += sizeof(*adi);
	}

	aux_ptr = NULL;
	if (h->aux_ptr) {
		aux_ptr = (void *)ptr;
		ptr += sizeof(*aux_ptr);
	}

	if (h->sync_info) {
		struct pdu_adv_sync_info *si;

		si = (void *)ptr;
		ptr += sizeof(*si);

#if defined(CONFIG_BT_CTLR_SYNC_PERIODIC)
		if (sync && adi && (adi->sid == scan->per_scan.sid) &&
		    (scan->per_scan.state == LL_SYNC_STATE_ADDR_MATCH)) {
			ull_sync_setup(scan, aux, rx, si);
		}
#endif /* CONFIG_BT_CTLR_SYNC_PERIODIC */
	}

	if (!aux_ptr || !aux_ptr->offs) {
		goto ull_scan_aux_rx_flush;
	}

	if (!aux) {
		aux = aux_acquire();
		if (!aux) {
			goto ull_scan_aux_rx_flush;
		}

		aux->rx_last = NULL;
		lll_aux = &aux->lll;

		ull_hdr_init(&aux->ull);
		lll_hdr_init(lll_aux, aux);
	}

	/* Enqueue the rx in aux context */
	if (aux->rx_last) {
		aux->rx_last->rx_ftr.extra = rx;
	} else {
		aux->rx_head = rx;
	}
	aux->rx_last = rx;

	lll_aux->chan = aux_ptr->chan_idx;
	lll_aux->phy = BIT(aux_ptr->phy);

	/* See if this was already scheduled from LLL. If so, store aux context
	 * in global scan struct so we can pick it when scanned node is received
	 * with a valid context.
	 */
	if (is_lll_sched) {
		lll->lll_aux = lll_aux;
		lll_aux->state = 0U;

		return;
	}

	/* Switching to ULL scheduling to receive auxiliary PDUs */
	lll->lll_aux = NULL;

	/* Determine the window size */
	if (aux_ptr->offs_units) {
		lll_aux->window_size_us = OFFS_UNIT_300_US;
	} else {
		lll_aux->window_size_us = OFFS_UNIT_30_US;
	}

	aux_offset_us = (uint32_t)aux_ptr->offs * lll_aux->window_size_us;

	/* CA field contains the clock accuracy of the advertiser;
	 * 0 - 51 ppm to 500 ppm
	 * 1 - 0 ppm to 50 ppm
	 */
	if (aux_ptr->ca) {
		window_widening_us = SCA_DRIFT_50_PPM_US(aux_offset_us);
	} else {
		window_widening_us = SCA_DRIFT_500_PPM_US(aux_offset_us);
	}

	lll_aux->window_size_us += (EVENT_TICKER_RES_MARGIN_US +
				    ((EVENT_JITTER_US + window_widening_us) << 1));

	ready_delay_us = lll_radio_rx_ready_delay_get(lll_aux->phy, 1);

	/* Calculate the aux offset from start of the scan window */
	aux_offset_us += ftr->radio_end_us;
	aux_offset_us -= PKT_AC_US(pdu->len, phy);
	aux_offset_us -= EVENT_JITTER_US;
	aux_offset_us -= ready_delay_us;
	aux_offset_us -= window_widening_us;

	/* TODO: active_to_start feature port */
	aux->ull.ticks_active_to_start = 0;
	aux->ull.ticks_prepare_to_start =
		HAL_TICKER_US_TO_TICKS(EVENT_OVERHEAD_XTAL_US);
	aux->ull.ticks_preempt_to_start =
		HAL_TICKER_US_TO_TICKS(EVENT_OVERHEAD_PREEMPT_MIN_US);
	aux->ull.ticks_slot =
		HAL_TICKER_US_TO_TICKS(EVENT_OVERHEAD_START_US +
				       ready_delay_us +
				       PKT_AC_US(PDU_AC_EXT_PAYLOAD_SIZE_MAX,
						 lll_aux->phy) +
				       EVENT_OVERHEAD_END_US);

	ticks_slot_offset = MAX(aux->ull.ticks_active_to_start,
				aux->ull.ticks_prepare_to_start);
	if (IS_ENABLED(CONFIG_BT_CTLR_LOW_LAT)) {
		ticks_slot_overhead = ticks_slot_offset;
	} else {
		ticks_slot_overhead = 0U;
	}
	ticks_slot_offset += HAL_TICKER_US_TO_TICKS(EVENT_OVERHEAD_START_US);

	ticks_aux_offset = HAL_TICKER_US_TO_TICKS(aux_offset_us);

	/* Yield the primary scan window ticks in ticker */
	if (scan) {
		uint8_t handle;

		handle = ull_scan_handle_get(scan);

		ticker_status = ticker_yield_abs(TICKER_INSTANCE_ID_CTLR,
						 TICKER_USER_ID_ULL_HIGH,
						 (TICKER_ID_SCAN_BASE + handle),
						 (ftr->ticks_anchor +
						  ticks_aux_offset -
						  ticks_slot_offset),
						 NULL, NULL);
		LL_ASSERT((ticker_status == TICKER_STATUS_SUCCESS) ||
			  (ticker_status == TICKER_STATUS_BUSY));
	}

	aux_handle = aux_handle_get(aux);

	ticker_status = ticker_start(TICKER_INSTANCE_ID_CTLR,
				     TICKER_USER_ID_ULL_HIGH,
				     TICKER_ID_SCAN_AUX_BASE + aux_handle,
				     ftr->ticks_anchor - ticks_slot_offset,
				     ticks_aux_offset,
				     TICKER_NULL_PERIOD,
				     TICKER_NULL_REMAINDER,
				     TICKER_NULL_LAZY,
				     (aux->ull.ticks_slot +
				      ticks_slot_overhead),
				     ticker_cb, aux, ticker_op_cb, aux);
	LL_ASSERT((ticker_status == TICKER_STATUS_SUCCESS) ||
		  (ticker_status == TICKER_STATUS_BUSY));

	return;

ull_scan_aux_rx_flush:
#if defined(CONFIG_BT_CTLR_SYNC_PERIODIC)
	if (sync) {
		scan->per_scan.state = LL_SYNC_STATE_IDLE;
	}
#endif /* CONFIG_BT_CTLR_SYNC_PERIODIC */

	if (aux) {
		if (is_lll_aux) {
			flush(aux, rx);
		} else {
			struct ull_hdr *hdr;

			/* Setup the disabled callback to flush the
			 * auxiliary PDUs
			 */
			hdr = &aux->ull;
			LL_ASSERT(!hdr->disabled_cb);

			hdr->disabled_param = rx;
			hdr->disabled_cb = last_disabled_cb;
		}

		return;
	}

	ll_rx_put(link, rx);
	ll_rx_sched();
}

void ull_scan_aux_done(struct node_rx_event_done *done)
{
	struct ll_scan_aux_set *aux;
	struct ull_hdr *hdr;

	/* Get reference to ULL context */
	aux = CONTAINER_OF(done->param, struct ll_scan_aux_set, ull);

	/* Setup the disabled callback to flush the auxiliary PDUs */
	hdr = &aux->ull;
	LL_ASSERT(!hdr->disabled_cb);

	hdr->disabled_param = aux;
	hdr->disabled_cb = done_disabled_cb;
}

uint8_t ull_scan_aux_lll_handle_get(struct lll_scan_aux *lll)
{
	return aux_handle_get((void *)lll->hdr.parent);
}

struct ll_scan_aux_set *ull_scan_aux_is_valid_get(struct ll_scan_aux_set *aux)
{
	if (((uint8_t *)aux < (uint8_t *)ll_scan_aux_pool) ||
	    ((uint8_t *)aux > ((uint8_t *)ll_scan_aux_pool +
			       (sizeof(struct ll_scan_aux_set) *
				(CONFIG_BT_CTLR_SCAN_AUX_SET - 1))))) {
		return NULL;
	}

	return aux;
}

void ull_scan_aux_release(memq_link_t *link, struct node_rx_hdr *rx)
{
	struct lll_scan_aux *lll_aux;
	struct ll_scan_aux_set *aux;
	struct lll_scan *lll;

	lll = rx->rx_ftr.param;
	lll_aux = lll->lll_aux;
	if (lll_aux) {
		aux = HDR_LLL2ULL(lll_aux);
		flush(aux, NULL);
	}

	/* Mark for buffer for release */
	rx->type = NODE_RX_TYPE_RELEASE;

	ll_rx_put(link, rx);
	ll_rx_sched();
}

static int init_reset(void)
{
	/* Initialize adv aux pool. */
	mem_init(ll_scan_aux_pool, sizeof(struct ll_scan_aux_set),
		 sizeof(ll_scan_aux_pool) / sizeof(struct ll_scan_aux_set),
		 &scan_aux_free);

	return 0;
}

static inline struct ll_scan_aux_set *aux_acquire(void)
{
	return mem_acquire(&scan_aux_free);
}

static inline void aux_release(struct ll_scan_aux_set *aux)
{
	mem_release(aux, &scan_aux_free);
}

static inline uint8_t aux_handle_get(struct ll_scan_aux_set *aux)
{
	return mem_index_get(aux, ll_scan_aux_pool,
			     sizeof(struct ll_scan_aux_set));
}

static inline struct ll_sync_set *sync_create_get(struct ll_scan_set *scan)
{
#if defined(CONFIG_BT_CTLR_SYNC_PERIODIC)
	return scan->per_scan.sync;
#else /* !CONFIG_BT_CTLR_SYNC_PERIODIC */
	return NULL;
#endif /* !CONFIG_BT_CTLR_SYNC_PERIODIC */
}

static void last_disabled_cb(void *param)
{
	struct ll_scan_aux_set *aux;
	struct node_rx_hdr *rx;

	rx = param;
	aux = HDR_LLL2ULL(rx->rx_ftr.param);

	flush(aux, rx);
}

static void done_disabled_cb(void *param)
{
	flush(param, NULL);
}

static void flush(struct ll_scan_aux_set *aux, struct node_rx_hdr *rx)
{
	if (aux->rx_last) {
		struct lll_scan *lll;

		if (rx) {
			aux->rx_last->rx_ftr.extra = rx;
		}

		rx = aux->rx_head;
		lll = rx->rx_ftr.param;
		lll->lll_aux = NULL;

		ll_rx_put(rx->link, rx);
		ll_rx_sched();
	} else if (rx) {
		ll_rx_put(rx->link, rx);
		ll_rx_sched();
	}

	aux_release(aux);
}

static void ticker_cb(uint32_t ticks_at_expire, uint32_t remainder,
		      uint16_t lazy, uint8_t force, void *param)
{
	static memq_link_t link;
	static struct mayfly mfy = {0, 0, &link, NULL, lll_scan_aux_prepare};
	struct ll_scan_aux_set *aux = param;
	static struct lll_prepare_param p;
	uint32_t ret;
	uint8_t ref;

	DEBUG_RADIO_PREPARE_O(1);

	/* Increment prepare reference count */
	ref = ull_ref_inc(&aux->ull);
	LL_ASSERT(ref);

	/* Append timing parameters */
	p.ticks_at_expire = ticks_at_expire;
	p.remainder = 0; /* FIXME: remainder; */
	p.lazy = lazy;
	p.force = force;
	p.param = &aux->lll;
	mfy.param = &p;

	/* Kick LLL prepare */
	ret = mayfly_enqueue(TICKER_USER_ID_ULL_HIGH, TICKER_USER_ID_LLL,
			     0, &mfy);
	LL_ASSERT(!ret);

	DEBUG_RADIO_PREPARE_O(1);
}

static void ticker_op_cb(uint32_t status, void *param)
{
	static memq_link_t link;
	static struct mayfly mfy = {0, 0, &link, NULL, ticker_op_aux_failure};
	uint32_t ret;

	if (status == TICKER_STATUS_SUCCESS) {
		return;
	}

	mfy.param = param;

	ret = mayfly_enqueue(TICKER_USER_ID_ULL_LOW, TICKER_USER_ID_ULL_HIGH,
			     0, &mfy);
	LL_ASSERT(!ret);
}

static void ticker_op_aux_failure(void *param)
{
	flush(param, NULL);
}
