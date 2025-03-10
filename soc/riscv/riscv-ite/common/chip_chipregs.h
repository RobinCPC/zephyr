/*
 * Copyright (c) 2020 ITE Corporation. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef CHIP_CHIPREGS_H
#define CHIP_CHIPREGS_H

#include <sys/util.h>

#define EC_REG_BASE_ADDR 0x00f00000

#ifndef FALSE
#define FALSE   0
#endif

/* TRUE can be defined as !FALSE but defining
 * it as 1 allows it to fit into a bitfield.
 */
#ifndef TRUE
#define TRUE    1
#endif

#ifdef _ASMLANGUAGE
#define ECREG(x)        x
#else

/*
 * Macros for hardware registers access.
 */
#define ECREG(x)		(*((volatile unsigned char *)(x)))
#define ECREG_u16(x)		(*((volatile unsigned short *)(x)))
#define ECREG_u32(x)		(*((volatile unsigned long  *)(x)))

/*
 * MASK operation macros
 */
#define SET_MASK(reg, bit_mask)			((reg) |= (bit_mask))
#define CLEAR_MASK(reg, bit_mask)		((reg) &= (~(bit_mask)))
#define IS_MASK_SET(reg, bit_mask)		(((reg) & (bit_mask)) != 0)
#endif /* _ASMLANGUAGE */

#ifndef REG_BASE_ADDR
#define REG_BASE_ADDR				EC_REG_BASE_ADDR
#endif

/**
 * (10XXh) Shared Memory Flash Interface Bridge (SMFI)
 */

/* FBIU Configuration */
#define FBCFG			ECREG(EC_REG_BASE_ADDR + 0x1000)
#define SSMC			BIT(7)

/* Flash Programming Configuration Register*/
#define FPCFG			ECREG(EC_REG_BASE_ADDR + 0x1001)

/* Memory Zone Configuration */
#define MZCFG			ECREG(EC_REG_BASE_ADDR + 0x1002)

/* State Memory Zone Configuration */
#define SMZCFG			ECREG(EC_REG_BASE_ADDR + 0x1003)

/* Flash EC Code Banking Select Register */
#define FECBSR			ECREG(EC_REG_BASE_ADDR + 0x1005)

/* Flash Memory Size Select Registe */
#define FMSSR			ECREG(EC_REG_BASE_ADDR + 0x1007)

/* Flash Memory Pre-Scale */
#define FMPSR			ECREG(EC_REG_BASE_ADDR + 0x1010)

/* Shared Memory EC Control and Status */
#define SMECCS			ECREG(EC_REG_BASE_ADDR + 0x1020)
#define HOSTWA			BIT(5)
#define LKPRR			BIT(2)

/* Shared Memory Host Semaphore */
#define SMHSR			ECREG(EC_REG_BASE_ADDR + 0x1022)

/* FWH Flash ID Register */
#define FWHFIDR			ECREG(EC_REG_BASE_ADDR + 0x1030)

/* Flash Control Register 1 */
#define FLHCTRL1R		ECREG(EC_REG_BASE_ADDR + 0x1031)

/* SPI Flash Read Mode
 * 11b: Uses “Fast Read Dual Input/Output (DIOFR)” cycle (instruction = BBh)
 * 10b: Uses “Fast Read Dual Output (DOFR)” cycle (instruction = 3Bh)
 * 01b: Uses “Fast Read (FREAD)” cycle (instruction = 0Bh)
 * 00b: Uses “Read” cycle (instruction = 03h)
 */
#define SPIFR1			BIT(5)
#define SPIFR0			BIT(4)
/* Serial Wait 1T */
#define LFSW1T			BIT(3)

/* Flash Control Register 2 */
#define FLHCTRL2R		ECREG(EC_REG_BASE_ADDR + 0x1032)

/* 256 bytes cache */
#define DCACHE			ECREG(EC_REG_BASE_ADDR + 0x1033)

/* uC Control Register */
#define UCCTRLR			ECREG(EC_REG_BASE_ADDR + 0x1034)

/* Host Control 2 Register */
#define HCTRL2R			ECREG(EC_REG_BASE_ADDR + 0x1036)

/* HSPI Control 2 Register */
#define HSPICTRL2R		ECREG(EC_REG_BASE_ADDR + 0x1039)

/* HSPI */
#define HSPICTRL3R		ECREG(EC_REG_BASE_ADDR + 0x103A)

/* EC-Indirect Memory Address Register 0 */
#define ECINDAR0		ECREG(EC_REG_BASE_ADDR + 0x103B)

/* EC-Indirect Memory Address Register 1 */
#define ECINDAR1		ECREG(EC_REG_BASE_ADDR + 0x103C)

/* EC-Indirect Memory Address Register 2 */
#define ECINDAR2		ECREG(EC_REG_BASE_ADDR + 0x103D)

/* EC-Indirect Memory Address Register 3 */
#define ECINDAR3		ECREG(EC_REG_BASE_ADDR + 0x103E)

/* EC-Indirect Memory Data Register */
#define ECINDDR			ECREG(EC_REG_BASE_ADDR + 0x103F)

/* Scratch SRAM 0 Address Low Byte Register */
#define SCRA0L			ECREG(EC_REG_BASE_ADDR + 0x1040)

/* Scratch SRAM 0 Address Middle Byte Register */
#define SCRA0M			ECREG(EC_REG_BASE_ADDR + 0x1041)

/* Scratch SRAM 0 Address High Byte Register */
#define SCRA0H			ECREG(EC_REG_BASE_ADDR + 0x1042)

/* Scratch SRAM 1 Address Low Byte Register */
#define SCRA1L			ECREG(EC_REG_BASE_ADDR + 0x1043)

/* Scratch SRAM 1 Address Middle Byte Register */
#define SCRA1M			ECREG(EC_REG_BASE_ADDR + 0x1044)

/* Scratch SRAM 1 Address High Byte Register */
#define SCRA1H			ECREG(EC_REG_BASE_ADDR + 0x1045)

/* Scratch SRAM 2 Address Low Byte Register */
#define SCRA2L			ECREG(EC_REG_BASE_ADDR + 0x1046)

/* Scratch SRAM 2 Address Middle Byte Register */
#define SCRA2M			ECREG(EC_REG_BASE_ADDR + 0x1047)

/* Scratch SRAM 2 Address High Byte Register */
#define SCRA2H			ECREG(EC_REG_BASE_ADDR + 0x1048)

/* Scratch SRAM 3 Address Low Byte Register */
#define SCRA3L			ECREG(EC_REG_BASE_ADDR + 0x1049)

/* Scratch SRAM 3 Address Middle Byte Register */
#define SCRA3M			ECREG(EC_REG_BASE_ADDR + 0x104A)

/* Scratch SRAM 3 Address High Byte Register */
#define SCRA3H			ECREG(EC_REG_BASE_ADDR + 0x104B)

/* Scratch SRAM 4 Address Low Byte Register */
#define SCRA4L			ECREG(EC_REG_BASE_ADDR + 0x104C)

/* Scratch SRAM 4 Address Middle Byte Register */
#define SCRA4M			ECREG(EC_REG_BASE_ADDR + 0x104D)

/* Scratch SRAM 4 Address High Byte Register */
#define SCRA4H			ECREG(EC_REG_BASE_ADDR + 0x104E)

/* Protect 0 Base Addr Register 0 */
#define P0BA0R			ECREG(EC_REG_BASE_ADDR + 0x104F)

/* Protect 0 Base Addr Register 1 */
#define P0BA1R			ECREG(EC_REG_BASE_ADDR + 0x1050)

/* Protect 0 Size Register */
#define P0ZR			ECREG(EC_REG_BASE_ADDR + 0x1051)

/* Protect 1 Base Addr Register 0 */
#define P1BA0R			ECREG(EC_REG_BASE_ADDR + 0x1052)

/* Protect 1 Base Addr Register 1 */
#define P1BA1R			ECREG(EC_REG_BASE_ADDR + 0x1053)

/* Protect 1 Size Register */
#define P1ZR			ECREG(EC_REG_BASE_ADDR + 0x1054)

/* Deferred SPI Instruction */
#define DSINST			ECREG(EC_REG_BASE_ADDR + 0x1055)

/* Deferred SPI Address */
#define DSADR1			ECREG(EC_REG_BASE_ADDR + 0x1056)

/* Deferred SPI Address */
#define DSADR2			ECREG(EC_REG_BASE_ADDR + 0x1057)

/* Host Instruction Control 1 */
#define HINSTC1			ECREG(EC_REG_BASE_ADDR + 0x1058)
#define DISSV			BIT(3)
#define DISS			BIT(2)
#define ENDPI			BIT(1)
#define ENDEI			BIT(0)

/* Host Instruction Control 2 */
#define HINSTC2			ECREG(EC_REG_BASE_ADDR + 0x1059)
#define DISEID8			BIT(3)
#define DISEID7			BIT(2)
#define DISEI52			BIT(1)
#define DISEI20			BIT(0)

/* Host RAM Window Control */
#define HRAMWC			ECREG(EC_REG_BASE_ADDR + 0x105A)
/* Window 0 enabled */
#define WINDOW0EN		BIT(0)
/* Window 1 enabled */
#define WINDOW1EN		BIT(1)
/* 0 : H2RAM-HLPC selected, 1 : H2RAM-HSPI selected */
#define H2RAMS			BIT(4)

/* Host RAM Winodw 0 Base Address */
#define HRAMW0BA		ECREG(EC_REG_BASE_ADDR + 0x105B)
/* Host RAM Window 1 Base Address */
#define HRAMW1BA		ECREG(EC_REG_BASE_ADDR + 0x105C)
/* Host RAM Window 0 Access Allow Size */
#define HRAMW0AAS		ECREG(EC_REG_BASE_ADDR + 0x105D)
/* Host RAM Window 1 Access Allow Size */
#define HRAMW1AAS		ECREG(EC_REG_BASE_ADDR + 0x105E)
#define HOSTRAMSIZE16BYTE	0x00
#define HOSTRAMSIZE32BYTE	0x01
#define HOSTRAMSIZE64BYTE	0x02
#define HOSTRAMSIZE128BYTE	0x03
#define HOSTRAMSIZE256BYTE	0x04
#define HOSTRAMSIZE512BYTE	0x05
#define HOSTRAMSIZE1024BYTE	0x06
#define HOSTRAMSIZE2048BYTE	0x07

#define CHECK64KSRAM		ECREG(EC_REG_BASE_ADDR + 0x1060)
#define CRC_HBYTE		ECREG(EC_REG_BASE_ADDR + 0x1061)
#define CRC_LBYTE		ECREG(EC_REG_BASE_ADDR + 0x1062)
#define FLHCTRL3R		ECREG(EC_REG_BASE_ADDR + 0x1063)
#define FLHCTRL4R		ECREG(EC_REG_BASE_ADDR + 0x1064)
#define P2BA0R			ECREG(EC_REG_BASE_ADDR + 0x1070)
#define P2BA1R			ECREG(EC_REG_BASE_ADDR + 0x1071)
#define P2ZR			ECREG(EC_REG_BASE_ADDR + 0x1072)
#define P3BA0R			ECREG(EC_REG_BASE_ADDR + 0x1073)
#define P3BA1R			ECREG(EC_REG_BASE_ADDR + 0x1074)
#define P3ZR			ECREG(EC_REG_BASE_ADDR + 0x1075)
#define HRAMW2BA		ECREG(EC_REG_BASE_ADDR + 0x1076)
#define HRAMW3BA		ECREG(EC_REG_BASE_ADDR + 0x1077)
#define HRAMW2AAS		ECREG(EC_REG_BASE_ADDR + 0x1078)
#define HRAMW3AAS		ECREG(EC_REG_BASE_ADDR + 0x1079)
#define H2RAMECSIE		ECREG(EC_REG_BASE_ADDR + 0x107A)
#define H2RAMECSA		ECREG(EC_REG_BASE_ADDR + 0x107B)
#define H2RAMHSS		ECREG(EC_REG_BASE_ADDR + 0x107C)
#define HPADR			ECREG(EC_REG_BASE_ADDR + 0x107E)
#define STCDMACR		ECREG(EC_REG_BASE_ADDR + 0x1080)
#define SCRA5L			ECREG(EC_REG_BASE_ADDR + 0x1081)
#define SCRA5M			ECREG(EC_REG_BASE_ADDR + 0x1082)
#define SCRA5H			ECREG(EC_REG_BASE_ADDR + 0x1083)
#define SCRA6L			ECREG(EC_REG_BASE_ADDR + 0x1084)
#define SCRA6M			ECREG(EC_REG_BASE_ADDR + 0x1085)
#define SCRA6H			ECREG(EC_REG_BASE_ADDR + 0x1086)
#define SCRA7L			ECREG(EC_REG_BASE_ADDR + 0x1087)
#define SCRA7M			ECREG(EC_REG_BASE_ADDR + 0x1088)
#define SCRA7H			ECREG(EC_REG_BASE_ADDR + 0x1089)
#define SCRA8L			ECREG(EC_REG_BASE_ADDR + 0x108A)
#define SCRA8M			ECREG(EC_REG_BASE_ADDR + 0x108B)
#define SCRA8H			ECREG(EC_REG_BASE_ADDR + 0x108C)
#define SCRA9L			ECREG(EC_REG_BASE_ADDR + 0x108D)
#define SCRA9M			ECREG(EC_REG_BASE_ADDR + 0x108E)
#define SCRA9H			ECREG(EC_REG_BASE_ADDR + 0x108F)
#define SCRA10L			ECREG(EC_REG_BASE_ADDR + 0x1090)
#define SCRA10M			ECREG(EC_REG_BASE_ADDR + 0x1091)
#define SCRA10H			ECREG(EC_REG_BASE_ADDR + 0x1092)
#define SCRA11L			ECREG(EC_REG_BASE_ADDR + 0x1093)
#define SCRA11M			ECREG(EC_REG_BASE_ADDR + 0x1094)
#define SCRA11H			ECREG(EC_REG_BASE_ADDR + 0x1095)
#define SCRA12L			ECREG(EC_REG_BASE_ADDR + 0x1096)
#define SCRA12M			ECREG(EC_REG_BASE_ADDR + 0x1097)
#define SCRA12H			ECREG(EC_REG_BASE_ADDR + 0x1098)
#define ROMARL			ECREG(EC_REG_BASE_ADDR + 0x1099)
#define ROMARM			ECREG(EC_REG_BASE_ADDR + 0x109A)
#define ROMARH			ECREG(EC_REG_BASE_ADDR + 0x109B)
#define SEMBARL			ECREG(EC_REG_BASE_ADDR + 0x109C)
#define SEMBARM			ECREG(EC_REG_BASE_ADDR + 0x109D)
#define SEMBARH			ECREG(EC_REG_BASE_ADDR + 0x109E)
#define SCRATH_SRAM		0x08

/* --- General Control (GCTRL) --- */
#define IT8XXX2_GCTRL_BASE      0x00F02000
#define IT8XXX2_GCTRL_EIDSR     ECREG(IT8XXX2_GCTRL_BASE + 0x31)

/**
 *
 * (11xxh) Interrupt controller (INTC)
 *
 */
#define ISR0			ECREG(EC_REG_BASE_ADDR + 0x3F00)
#define ISR1			ECREG(EC_REG_BASE_ADDR + 0x3F01)
#define ISR2			ECREG(EC_REG_BASE_ADDR + 0x3F02)
#define ISR3			ECREG(EC_REG_BASE_ADDR + 0x3F03)
#define ISR4			ECREG(EC_REG_BASE_ADDR + 0x3F14)
#define ISR5			ECREG(EC_REG_BASE_ADDR + 0x3F18)
#define ISR6			ECREG(EC_REG_BASE_ADDR + 0x3F1C)
#define ISR7			ECREG(EC_REG_BASE_ADDR + 0x3F20)
#define ISR8			ECREG(EC_REG_BASE_ADDR + 0x3F24)
#define ISR9			ECREG(EC_REG_BASE_ADDR + 0x3F28)
#define ISR10			ECREG(EC_REG_BASE_ADDR + 0x3F2C)
#define ISR11			ECREG(EC_REG_BASE_ADDR + 0x3F30)
#define ISR12			ECREG(EC_REG_BASE_ADDR + 0x3F34)
#define ISR13			ECREG(EC_REG_BASE_ADDR + 0x3F38)
#define ISR14			ECREG(EC_REG_BASE_ADDR + 0x3F3C)
#define ISR15			ECREG(EC_REG_BASE_ADDR + 0x3F40)
#define ISR16			ECREG(EC_REG_BASE_ADDR + 0x3F44)
#define ISR17			ECREG(EC_REG_BASE_ADDR + 0x3F48)
#define ISR18			ECREG(EC_REG_BASE_ADDR + 0x3F4C)
#define ISR19			ECREG(EC_REG_BASE_ADDR + 0x3F50)
#define ISR20			ECREG(EC_REG_BASE_ADDR + 0x3F54)
#define ISR21			ECREG(EC_REG_BASE_ADDR + 0x3F58)
#define ISR22			ECREG(EC_REG_BASE_ADDR + 0x3F5C)
#define ISR23			ECREG(EC_REG_BASE_ADDR + 0x3F90)

#define IER0			ECREG(EC_REG_BASE_ADDR + 0x3F04)
#define IER1			ECREG(EC_REG_BASE_ADDR + 0x3F05)
#define IER2			ECREG(EC_REG_BASE_ADDR + 0x3F06)
#define IER3			ECREG(EC_REG_BASE_ADDR + 0x3F07)
#define IER4			ECREG(EC_REG_BASE_ADDR + 0x3F15)
#define IER5			ECREG(EC_REG_BASE_ADDR + 0x3F19)
#define IER6			ECREG(EC_REG_BASE_ADDR + 0x3F1D)
#define IER7			ECREG(EC_REG_BASE_ADDR + 0x3F21)
#define IER8			ECREG(EC_REG_BASE_ADDR + 0x3F25)
#define IER9			ECREG(EC_REG_BASE_ADDR + 0x3F29)
#define IER10			ECREG(EC_REG_BASE_ADDR + 0x3F2D)
#define IER11			ECREG(EC_REG_BASE_ADDR + 0x3F31)
#define IER12			ECREG(EC_REG_BASE_ADDR + 0x3F35)
#define IER13			ECREG(EC_REG_BASE_ADDR + 0x3F39)
#define IER14			ECREG(EC_REG_BASE_ADDR + 0x3F3D)
#define IER15			ECREG(EC_REG_BASE_ADDR + 0x3F41)
#define IER16			ECREG(EC_REG_BASE_ADDR + 0x3F45)
#define IER17			ECREG(EC_REG_BASE_ADDR + 0x3F49)
#define IER18			ECREG(EC_REG_BASE_ADDR + 0x3F4D)
#define IER19			ECREG(EC_REG_BASE_ADDR + 0x3F51)
#define IER20			ECREG(EC_REG_BASE_ADDR + 0x3F55)
#define IER21			ECREG(EC_REG_BASE_ADDR + 0x3F59)
#define IER22			ECREG(EC_REG_BASE_ADDR + 0x3F5D)
#define IER23			ECREG(EC_REG_BASE_ADDR + 0x3F91)

#define IELMR0			ECREG(EC_REG_BASE_ADDR + 0x3F08)
#define IELMR1			ECREG(EC_REG_BASE_ADDR + 0x3F09)
#define IELMR2			ECREG(EC_REG_BASE_ADDR + 0x3F0A)
#define IELMR3			ECREG(EC_REG_BASE_ADDR + 0x3F0B)
#define IELMR4			ECREG(EC_REG_BASE_ADDR + 0x3F16)
#define IELMR5			ECREG(EC_REG_BASE_ADDR + 0x3F1A)
#define IELMR6			ECREG(EC_REG_BASE_ADDR + 0x3F1E)
#define IELMR7			ECREG(EC_REG_BASE_ADDR + 0x3F22)
#define IELMR8			ECREG(EC_REG_BASE_ADDR + 0x3F26)
#define IELMR9			ECREG(EC_REG_BASE_ADDR + 0x3F2A)
#define IELMR10			ECREG(EC_REG_BASE_ADDR + 0x3F2E)
#define IELMR11			ECREG(EC_REG_BASE_ADDR + 0x3F32)
#define IELMR12			ECREG(EC_REG_BASE_ADDR + 0x3F36)
#define IELMR13			ECREG(EC_REG_BASE_ADDR + 0x3F3A)
#define IELMR14			ECREG(EC_REG_BASE_ADDR + 0x3F3E)
#define IELMR15			ECREG(EC_REG_BASE_ADDR + 0x3F42)
#define IELMR16			ECREG(EC_REG_BASE_ADDR + 0x3F46)
#define IELMR17			ECREG(EC_REG_BASE_ADDR + 0x3F4A)
#define IELMR18			ECREG(EC_REG_BASE_ADDR + 0x3F4E)
#define IELMR19			ECREG(EC_REG_BASE_ADDR + 0x3F52)
#define IELMR20			ECREG(EC_REG_BASE_ADDR + 0x3F56)
#define IELMR21			ECREG(EC_REG_BASE_ADDR + 0x3F5A)
#define IELMR22			ECREG(EC_REG_BASE_ADDR + 0x3F5E)
#define IELMR23			ECREG(EC_REG_BASE_ADDR + 0x3F92)

#define IPOLR0			ECREG(EC_REG_BASE_ADDR + 0x3F0C)
#define IPOLR1			ECREG(EC_REG_BASE_ADDR + 0x3F0D)
#define IPOLR2			ECREG(EC_REG_BASE_ADDR + 0x3F0E)
#define IPOLR3			ECREG(EC_REG_BASE_ADDR + 0x3F0F)
#define IPOLR4			ECREG(EC_REG_BASE_ADDR + 0x3F17)
#define IPOLR5			ECREG(EC_REG_BASE_ADDR + 0x3F1B)
#define IPOLR6			ECREG(EC_REG_BASE_ADDR + 0x3F1F)
#define IPOLR7			ECREG(EC_REG_BASE_ADDR + 0x3F23)
#define IPOLR8			ECREG(EC_REG_BASE_ADDR + 0x3F27)
#define IPOLR9			ECREG(EC_REG_BASE_ADDR + 0x3F2B)
#define IPOLR10			ECREG(EC_REG_BASE_ADDR + 0x3F2F)
#define IPOLR11			ECREG(EC_REG_BASE_ADDR + 0x3F33)
#define IPOLR12			ECREG(EC_REG_BASE_ADDR + 0x3F37)
#define IPOLR13			ECREG(EC_REG_BASE_ADDR + 0x3F3B)
#define IPOLR14			ECREG(EC_REG_BASE_ADDR + 0x3F3F)
#define IPOLR15			ECREG(EC_REG_BASE_ADDR + 0x3F43)
#define IPOLR16			ECREG(EC_REG_BASE_ADDR + 0x3F47)
#define IPOLR17			ECREG(EC_REG_BASE_ADDR + 0x3F4B)
#define IPOLR18			ECREG(EC_REG_BASE_ADDR + 0x3F4F)
#define IPOLR19			ECREG(EC_REG_BASE_ADDR + 0x3F53)
#define IPOLR20			ECREG(EC_REG_BASE_ADDR + 0x3F57)
#define IPOLR21			ECREG(EC_REG_BASE_ADDR + 0x3F5B)
#define IPOLR22			ECREG(EC_REG_BASE_ADDR + 0x3F5F)
#define IPOLR23			ECREG(EC_REG_BASE_ADDR + 0x3F93)

#define IVECT			ECREG(EC_REG_BASE_ADDR + 0x3F10)

/**
 *
 * (12xxh) EC Access to ost Controlled Modules (EC2I Bridge)
 *
 */
#define IHIOA			ECREG(EC_REG_BASE_ADDR + 0x1200)
#define IHD			ECREG(EC_REG_BASE_ADDR + 0x1201)
#define LSIOHA			ECREG(EC_REG_BASE_ADDR + 0x1202)
#define SIOLV			ECREG(EC_REG_BASE_ADDR + 0x1203)
#define IBMAE			ECREG(EC_REG_BASE_ADDR + 0x1204)
#define IBCTL			ECREG(EC_REG_BASE_ADDR + 0x1205)

/* Lock Super I/O Host Access Register */
#define LKCFG			BIT(0)

/* Super I/O Access Lock Violation Register */
#define CFGLV			BIT(0)

/* EC to I-Bus Modules Access Enable Register */
#define SWUCAE			BIT(2)
#define CFGAE			BIT(0)

/* I-Bus Control Register */
#define CWIB			BIT(2)
#define CRIB			BIT(1)
#define CSAE			BIT(0)

/**
 *
 * (13xxh) Keyboard Controller (KBC)
 *
 */
#define KBHICR			ECREG(EC_REG_BASE_ADDR + 0x1300)
#define KBIRQR			ECREG(EC_REG_BASE_ADDR + 0x1302)
#define KBHISR			ECREG(EC_REG_BASE_ADDR + 0x1304)
#define KBHIKDOR		ECREG(EC_REG_BASE_ADDR + 0x1306)
#define KBHIMDOR		ECREG(EC_REG_BASE_ADDR + 0x1308)
#define KBHIDIR			ECREG(EC_REG_BASE_ADDR + 0x130A)

/* KBC Host Interface Control Register*/
#define PM1ICIE			BIT(6)
#define PM1OCIE			BIT(5)
#define PM1HIE			BIT(4)
#define IBFCIE			BIT(3)
#define OBECIE			BIT(2)
#define OBFMIE			BIT(1)
#define OBFKIE			BIT(0)

/* KBC Interrupt Control Register */
#define IRQNP			BIT(6)
#define IRQ11B			BIT(2)
#define IRQ12B			BIT(1)
#define IRQ1B			BIT(0)

/* KBC Host Interface Keyboard/Mouse Status Register */
#define PARE			BIT(7)
#define GTIM			BIT(6)
#define AOBF			BIT(5)
#define KEYL			BIT(4)
#define C_D			BIT(3)
#define SYSF			BIT(2)
#define IBF			BIT(1)
#define OBF			BIT(0)

/**
 *
 * (14xxh) System Wake-Up Control (SWUC)
 *
 */
#define SWCTL1			ECREG(EC_REG_BASE_ADDR + 0x1400)
#define SWCTL2			ECREG(EC_REG_BASE_ADDR + 0x1402)
#define SWCTL3			ECREG(EC_REG_BASE_ADDR + 0x1404)
#define SWCBALR			ECREG(EC_REG_BASE_ADDR + 0x1408)
#define SWCBAHR			ECREG(EC_REG_BASE_ADDR + 0x140A)
#define SWCIER			ECREG(EC_REG_BASE_ADDR + 0x140C)
#define SWCHSTR			ECREG(EC_REG_BASE_ADDR + 0x140E)
#define SWCHIER			ECREG(EC_REG_BASE_ADDR + 0x1410)

/**
 *
 * (14XXh) ISO14443 PICC Register
 *
 */
#define PICC_BASE_ADDR		(EC_REG_BASE_ADDR + 0x1400)
#define PATQA0SR		ECREG(EC_REG_BASE_ADDR + 0x1400)
#define PATQA1SR		ECREG(EC_REG_BASE_ADDR + 0x1401)
#define PSAKSR			ECREG(EC_REG_BASE_ADDR + 0x1402)
#define PTRRR			ECREG(EC_REG_BASE_ADDR + 0x1403)
#define PFDTA1R			ECREG(EC_REG_BASE_ADDR + 0x141E)
#define PFDTA2R			ECREG(EC_REG_BASE_ADDR + 0x141F)
#define PACCR			ECREG(EC_REG_BASE_ADDR + 0x1404)
#define PIR			ECREG(EC_REG_BASE_ADDR + 0x1405)
#define PICC_HF_ENABLE		BIT(5)
#define PICC_HF_DISABLE		BIT(4)
#define PICC_DATA_ERROR		BIT(3)
#define PICC_RX_DONE		BIT(2)
#define PICC_TX_DONE		BIT(1)
#define PICC_ANTI_COLL_DONE	BIT(0)
#define PIMR			ECREG(EC_REG_BASE_ADDR + 0x1406)
#define PMCR			ECREG(EC_REG_BASE_ADDR + 0x1407)
#define PTXCR			ECREG(EC_REG_BASE_ADDR + 0x1408)
#define PRAMBA0R		ECREG(EC_REG_BASE_ADDR + 0x140A)
#define PRAMBA1R		ECREG(EC_REG_BASE_ADDR + 0x140B)
#define PTSR			ECREG(EC_REG_BASE_ADDR + 0x140C)
#define PRTC0R			ECREG(EC_REG_BASE_ADDR + 0x140E)
#define PRTC1R			ECREG(EC_REG_BASE_ADDR + 0x140F)
#define PUID0R			ECREG(EC_REG_BASE_ADDR + 0x1410)
#define PUID0R_ADDR		(PICC_BASE_ADDR + 0x10)
#define PUID1R			ECREG(EC_REG_BASE_ADDR + 0x1411)
#define PUID2R			ECREG(EC_REG_BASE_ADDR + 0x1412)
#define PUID3R			ECREG(EC_REG_BASE_ADDR + 0x1413)
#define PUID4R			ECREG(EC_REG_BASE_ADDR + 0x1414)
#define PUID5R			ECREG(EC_REG_BASE_ADDR + 0x1415)
#define PUID6R			ECREG(EC_REG_BASE_ADDR + 0x1416)
#define PUID7R			ECREG(EC_REG_BASE_ADDR + 0x1417)
#define PUID8R			ECREG(EC_REG_BASE_ADDR + 0x1418)
#define PUID9R			ECREG(EC_REG_BASE_ADDR + 0x1419)
#define PDER			ECREG(EC_REG_BASE_ADDR + 0x141A)
#define PRC0R			ECREG(EC_REG_BASE_ADDR + 0x141C)
#define PRC1R			ECREG(EC_REG_BASE_ADDR + 0x141D)

/**
 *
 * (15xxh) Power Management Channel (PMC)
 *
 */
/* PM1 */
#define PM1STS			ECREG(EC_REG_BASE_ADDR + 0x1500)
#define PM1DO			ECREG(EC_REG_BASE_ADDR + 0x1501)
#define PM1DOSCI		ECREG(EC_REG_BASE_ADDR + 0x1502)
#define PM1DOSMI		ECREG(EC_REG_BASE_ADDR + 0x1503)
#define PM1DI			ECREG(EC_REG_BASE_ADDR + 0x1504)
#define PM1DISCI		ECREG(EC_REG_BASE_ADDR + 0x1505)
#define PM1CTL			ECREG(EC_REG_BASE_ADDR + 0x1506)
#define PM1IC			ECREG(EC_REG_BASE_ADDR + 0x1507)
#define PM1IE			ECREG(EC_REG_BASE_ADDR + 0x1508)
/* PM2 */
#define PM2STS			ECREG(EC_REG_BASE_ADDR + 0x1510)
#define PM2DO			ECREG(EC_REG_BASE_ADDR + 0x1511)
#define PM2DOSCI		ECREG(EC_REG_BASE_ADDR + 0x1512)
#define PM2DOSMI		ECREG(EC_REG_BASE_ADDR + 0x1513)
#define PM2DI			ECREG(EC_REG_BASE_ADDR + 0x1514)
#define PM2DISCI		ECREG(EC_REG_BASE_ADDR + 0x1515)
#define PM2CTL			ECREG(EC_REG_BASE_ADDR + 0x1516)
#define PM2IC			ECREG(EC_REG_BASE_ADDR + 0x1517)
#define PM2IE			ECREG(EC_REG_BASE_ADDR + 0x1518)
/* Mailbox */
#define MBXCTRL			ECREG(EC_REG_BASE_ADDR + 0x1519)
/* 16-byte PMC2EX Mailbox 0 ~ Mailbox 15 */
#define MBXEC_00		ECREG(EC_REG_BASE_ADDR + 0x15F0)
#define MBXEC_01		ECREG(EC_REG_BASE_ADDR + 0x15F1)
#define MBXEC_02		ECREG(EC_REG_BASE_ADDR + 0x15F2)
#define MBXEC_03		ECREG(EC_REG_BASE_ADDR + 0x15F3)
#define MBXEC_04		ECREG(EC_REG_BASE_ADDR + 0x15F4)
#define MBXEC_05		ECREG(EC_REG_BASE_ADDR + 0x15F5)
#define MBXEC_06		ECREG(EC_REG_BASE_ADDR + 0x15F6)
#define MBXEC_07		ECREG(EC_REG_BASE_ADDR + 0x15F7)
#define MBXEC_08		ECREG(EC_REG_BASE_ADDR + 0x15F8)
#define MBXEC_09		ECREG(EC_REG_BASE_ADDR + 0x15F9)
#define MBXEC_10		ECREG(EC_REG_BASE_ADDR + 0x15FA)
#define MBXEC_11		ECREG(EC_REG_BASE_ADDR + 0x15FB)
#define MBXEC_12		ECREG(EC_REG_BASE_ADDR + 0x15FC)
#define MBXEC_13		ECREG(EC_REG_BASE_ADDR + 0x15FD)
#define MBXEC_14		ECREG(EC_REG_BASE_ADDR + 0x15FE)
#define MBXEC_15		ECREG(EC_REG_BASE_ADDR + 0x15FF)
#define PM3STS			ECREG(EC_REG_BASE_ADDR + 0x1520)
#define PM3DO			ECREG(EC_REG_BASE_ADDR + 0x1521)
#define PM3DI			ECREG(EC_REG_BASE_ADDR + 0x1522)
#define PM3CTL			ECREG(EC_REG_BASE_ADDR + 0x1523)
#define PM3IC			ECREG(EC_REG_BASE_ADDR + 0x1524)
#define PM3IE			ECREG(EC_REG_BASE_ADDR + 0x1525)
#define PM4STS			ECREG(EC_REG_BASE_ADDR + 0x1530)
#define PM4DO			ECREG(EC_REG_BASE_ADDR + 0x1531)
#define PM4DI			ECREG(EC_REG_BASE_ADDR + 0x1532)
#define PM4CTL			ECREG(EC_REG_BASE_ADDR + 0x1533)
#define PM4IC			ECREG(EC_REG_BASE_ADDR + 0x1534)
#define PM4IE			ECREG(EC_REG_BASE_ADDR + 0x1535)
#define PM5STS			ECREG(EC_REG_BASE_ADDR + 0x1540)
#define PM5DO			ECREG(EC_REG_BASE_ADDR + 0x1541)
#define PM5DI			ECREG(EC_REG_BASE_ADDR + 0x1542)
#define PM5CTL			ECREG(EC_REG_BASE_ADDR + 0x1543)
#define PM5IC			ECREG(EC_REG_BASE_ADDR + 0x1544)
#define PM5IE			ECREG(EC_REG_BASE_ADDR + 0x1545)

/* PM Status Register */
#define SMIEVT			BIT(6)
#define SCIEVT			BIT(5)
#define BURST			BIT(4)
#define P_C_D			BIT(3)
#define P_IBF			BIT(1)
#define P_OBF			BIT(0)

/* PM Control */
#define APM			BIT(7)
#define SCINP			BIT(6)
#define OBEIE			BIT(1)
#define IBFIE			BIT(0)

/* PM Interrupt Control */
#define SMINP			BIT(6)
#define SCIB			BIT(2)
#define SMIB			BIT(1)
#define IRQB			BIT(0)

/* PM Interrupt Enable */
#define HWSMIEN			BIT(5)
#define HWSCIEN			BIT(4)
#define HWIRQEN			BIT(3)
#define SMIEN			BIT(2)
#define SCIEN			BIT(1)
#define IRQEN			BIT(0)

/* PM Interrupt Enable */
#define MBXEN			BIT(7)

/**
 *
 * (16XXh) General Purpose I/O Control Register
 *
 */
/* GPIO data register */
#define GCR			ECREG(EC_REG_BASE_ADDR + 0x1600)
#define GFLE			BIT(7)
#define WUI7EN			BIT(6)
#define WUI6EN			BIT(5)
#define LPCRSTEN_GPB7		BIT(2)
#define LPCRSTEN_GPD2		BIT(1)

#define GCR1			ECREG(EC_REG_BASE_ADDR + 0x16F0)
#define SPICTRL_0		BIT(4)
#define SPICTRL_1		BIT(5)
#define SSSPIBP			BIT(6)
#define SPICTRL_2		BIT(7)

#define GCR2			ECREG(EC_REG_BASE_ADDR + 0x16F1)
#define CK32OE			BIT(6)
#define SMB3E			BIT(5)
#define PECIE			BIT(4)

#define GCR3			ECREG(EC_REG_BASE_ADDR + 0x16F2)
#define GCR4			ECREG(EC_REG_BASE_ADDR + 0x16F3)
#define GCR5			ECREG(EC_REG_BASE_ADDR + 0x16F4)
#define GCR6			ECREG(EC_REG_BASE_ADDR + 0x16F5)
#define GCR7			ECREG(EC_REG_BASE_ADDR + 0x16F6)
#define GCR8			ECREG(EC_REG_BASE_ADDR + 0x16F7)
#define GCR9			ECREG(EC_REG_BASE_ADDR + 0x16F8)
#define GCR10			ECREG(EC_REG_BASE_ADDR + 0x16F9)
#define GCR11			ECREG(EC_REG_BASE_ADDR + 0x16FA)
#define GCR12			ECREG(EC_REG_BASE_ADDR + 0x16FB)
#define GCR13			ECREG(EC_REG_BASE_ADDR + 0x16FC)
#define GCR14			ECREG(EC_REG_BASE_ADDR + 0x16FD)
#define GCR15			ECREG(EC_REG_BASE_ADDR + 0x16FE)
#define GCR16			ECREG(EC_REG_BASE_ADDR + 0x16E0)
#define GCR17			ECREG(EC_REG_BASE_ADDR + 0x16E1)
#define GCR18			ECREG(EC_REG_BASE_ADDR + 0x16E2)
#define GCR19			ECREG(EC_REG_BASE_ADDR + 0x16E4)
#define GCR20			ECREG(EC_REG_BASE_ADDR + 0x16E5)
#define GCR21			ECREG(EC_REG_BASE_ADDR + 0x16E6)

/*
 * TODO: use pinmux driver to enable uart function so we can remove these
 * registers' declaration.
 */
/* GPIO control register */
#define GPCRB0			ECREG(EC_REG_BASE_ADDR + 0x1618)
#define GPCRB1			ECREG(EC_REG_BASE_ADDR + 0x1619)
#define GPCRD5			ECREG(EC_REG_BASE_ADDR + 0x162D)
#define GPCRE5			ECREG(EC_REG_BASE_ADDR + 0x1635)
#define GPCRF3			ECREG(EC_REG_BASE_ADDR + 0x163B)
#define GPCRF4			ECREG(EC_REG_BASE_ADDR + 0x163C)
#define GPCRF5			ECREG(EC_REG_BASE_ADDR + 0x163D)
#define GPCRH1			ECREG(EC_REG_BASE_ADDR + 0x1649)
#define GPCRH2			ECREG(EC_REG_BASE_ADDR + 0x164A)
#define GPCRI7			ECREG(EC_REG_BASE_ADDR + 0x1657)

/* Port Data Mirror Register */
#define GPDMRA			ECREG(EC_REG_BASE_ADDR + 0x1661)
#define GPDMRB			ECREG(EC_REG_BASE_ADDR + 0x1662)
#define GPDMRC			ECREG(EC_REG_BASE_ADDR + 0x1663)
#define GPDMRD			ECREG(EC_REG_BASE_ADDR + 0x1664)
#define GPDMRE			ECREG(EC_REG_BASE_ADDR + 0x1665)
#define GPDMRF			ECREG(EC_REG_BASE_ADDR + 0x1666)
#define GPDMRG			ECREG(EC_REG_BASE_ADDR + 0x1667)
#define GPDMRH			ECREG(EC_REG_BASE_ADDR + 0x1668)
#define GPDMRI			ECREG(EC_REG_BASE_ADDR + 0x1669)
#define GPDMRJ			ECREG(EC_REG_BASE_ADDR + 0x166A)
#define GPDMRM			ECREG(EC_REG_BASE_ADDR + 0x166D)

#define GPCR_PORT_PIN_MODE_INPUT    BIT(7)
#define GPCR_PORT_PIN_MODE_OUTPUT   BIT(6)
#define GPCR_PORT_PIN_MODE_PULLUP   BIT(2)
#define GPCR_PORT_PIN_MODE_PULLDOWN BIT(1)

/**
 *
 * (17XXh) PS/2 Interface Register
 *
 */
#define PSCTL1			ECREG(EC_REG_BASE_ADDR + 0x1700)
#define PSCTL2			ECREG(EC_REG_BASE_ADDR + 0x1701)
#define PSCTL3			ECREG(EC_REG_BASE_ADDR + 0x1702)
#define PSINT1			ECREG(EC_REG_BASE_ADDR + 0x1704)
#define PSINT2			ECREG(EC_REG_BASE_ADDR + 0x1705)
#define PSINT3			ECREG(EC_REG_BASE_ADDR + 0x1706)
#define PSSTS1			ECREG(EC_REG_BASE_ADDR + 0x1708)
#define PSSTS2			ECREG(EC_REG_BASE_ADDR + 0x1709)
#define PSSTS3			ECREG(EC_REG_BASE_ADDR + 0x170A)
#define PSDAT1			ECREG(EC_REG_BASE_ADDR + 0x170C)
#define PSDAT2			ECREG(EC_REG_BASE_ADDR + 0x170D)
#define PSDAT3			ECREG(EC_REG_BASE_ADDR + 0x170E)

/* PS/2 Control Register */
#define DCEN			BIT(4)
#define TRMS			BIT(3)
#define PSHE			BIT(2)
#define CCLK			BIT(1)
#define CDAT			BIT(0)

/* PS/2 Interrupt Control Register */
#define TDIE			BIT(2)
#define SIE			BIT(1)
#define SMIE			BIT(0)

/* PS/2 Status Register */
#define FER			BIT(5)
#define PER			BIT(4)
#define TDS			BIT(3)
#define SS			BIT(2)
#define CLS			BIT(1)
#define DLS			BIT(0)

/**
 *
 * (18xxh) PWM & SmartAuto Fan Control (PWM)
 *
 */
#ifndef __ASSEMBLER__
struct pwm_it8xxx2_regs {
	/* 0x000: Channel0 Clock Prescaler */
	volatile uint8_t C0CPRS;
	/* 0x001: Cycle Time0 */
	volatile uint8_t CTR;
	/* 0x002~0x00A: Reserved1 */
	volatile uint8_t Reserved1[9];
	/* 0x00B: Prescaler Clock Frequency Select */
	volatile uint8_t PCFSR;
	/* 0x00C~0x00F: Reserved2 */
	volatile uint8_t Reserved2[4];
	/* 0x010: Cycle Time1 MSB */
	volatile uint8_t CTR1M;
	/* 0x011~0x022: Reserved3 */
	volatile uint8_t Reserved3[18];
	/* 0x023: PWM Clock Control */
	volatile uint8_t ZTIER;
	/* 0x024~0x026: Reserved4 */
	volatile uint8_t Reserved4[3];
	/* 0x027: Channel4 Clock Prescaler */
	volatile uint8_t C4CPRS;
	/* 0x028: Channel4 Clock Prescaler MSB */
	volatile uint8_t C4MCPRS;
	/* 0x029~0x02A: Reserved5 */
	volatile uint8_t Reserved5[2];
	/* 0x02B: Channel6 Clock Prescaler */
	volatile uint8_t C6CPRS;
	/* 0x02C: Channel6 Clock Prescaler MSB */
	volatile uint8_t C6MCPRS;
	/* 0x02D: Channel7 Clock Prescaler */
	volatile uint8_t C7CPRS;
	/* 0x02E: Channel7 Clock Prescaler MSB */
	volatile uint8_t C7MCPRS;
	/* 0x02F~0x040: Reserved6 */
	volatile uint8_t reserved6[18];
	/* 0x041: Cycle Time1 */
	volatile uint8_t CTR1;
	/* 0x042: Cycle Time2 */
	volatile uint8_t CTR2;
	/* 0x043: Cycle Time3 */
	volatile uint8_t CTR3;
};
#endif /* !__ASSEMBLER__ */

/* PWM register fields */
/* 0x023: PWM Clock Control */
#define IT8XXX2_PWM_PCCE		BIT(1)

/**
 *
 * (19xxh) Analog to Digital converter (ADC)
 *
 */
#define ADCECR			ECREG(EC_REG_BASE_ADDR + 0x1901)
#define ADCCSR			ECREG(EC_REG_BASE_ADDR + 0x1902)
#define ADCGC0R			ECREG(EC_REG_BASE_ADDR + 0x1903)
#define ADCGC1R			ECREG(EC_REG_BASE_ADDR + 0x1904)
#define ADCCXC_BASE		(EC_REG_BASE_ADDR + 0x1905)
#define ADCCXC0R(ch)		ECREG(ADCCxC_BASE + ((ch) * 2))
#define ADCCXC1R(ch)		ECREG(ADCCxC_BASE + 1 + ((ch) * 2))
#define ADCDMALBAR		ECREG(EC_REG_BASE_ADDR + 0x190D)
#define ADCDMAHBAR		ECREG(EC_REG_BASE_ADDR + 0x190E)
#define ADCDMABLR		ECREG(EC_REG_BASE_ADDR + 0x190F)
#define ADCDLR			ECREG(EC_REG_BASE_ADDR + 0x1910)
#define ADCIMR			ECREG(EC_REG_BASE_ADDR + 0x1911)
#define ADCISR			ECREG(EC_REG_BASE_ADDR + 0x1912)
#define ADCCxS_BASE		(EC_REG_BASE_ADDR + 0x1950)
#define ADCCXD0R(ch)		ECREG(ADCCxS_BASE0 + ((ch) * 2))
#define ADCCXD1R(ch)		ECREG(ADCCxS_BASE + 1 + ((ch) * 2))

/* ADC Status Register */
#define FIRHIACC		BIT(7)
#define AINITB			BIT(3)
#define ADCPS			BIT(2)
#define DOVE			BIT(1)
#define EOCE			BIT(0)

/* ADC Configuration Register */
#define DFILEN			BIT(5)
#define INTECEN			BIT(2)
#define ADCEN			BIT(0)

/* Voltage Channel Control Register */
#define DATVAL			BIT(7)
#define INTDVEN			BIT(5)

/* Calibration Data Control Register */
#define AHCE			BIT(7)
#define HCDATVAL		BIT(5)
#define GCDATVAL		BIT(4)
#define VHSCKE			BIT(1)
#define GECKE			BIT(0)

/**
 *
 * (1Axxh) Real Time Clock (RTC)
 *
 */
#define SECREG			ECREG(EC_REG_BASE_ADDR + 0x1A00)
#define SECA1REG		ECREG(EC_REG_BASE_ADDR + 0x1A01)
#define MINREG			ECREG(EC_REG_BASE_ADDR + 0x1A02)
#define MINA1REG		ECREG(EC_REG_BASE_ADDR + 0x1A03)
#define HRREG			ECREG(EC_REG_BASE_ADDR + 0x1A04)
#define HRA1REG			ECREG(EC_REG_BASE_ADDR + 0x1A05)
#define DOWREG			ECREG(EC_REG_BASE_ADDR + 0x1A06)
#define DOMREG			ECREG(EC_REG_BASE_ADDR + 0x1A07)
#define MONREG			ECREG(EC_REG_BASE_ADDR + 0x1A08)
#define YRREG			ECREG(EC_REG_BASE_ADDR + 0x1A09)
#define CTLREGA			ECREG(EC_REG_BASE_ADDR + 0x1A0A)
#define CTLREGB			ECREG(EC_REG_BASE_ADDR + 0x1A0B)
#define CTLREGC			ECREG(EC_REG_BASE_ADDR + 0x1A0C)
#define DOMA1REG		ECREG(EC_REG_BASE_ADDR + 0x1A0D)
#define MONA1REG		ECREG(EC_REG_BASE_ADDR + 0x1A0E)
#define SECA2REG		ECREG(EC_REG_BASE_ADDR + 0x1A0F)
#define MINA2REG		ECREG(EC_REG_BASE_ADDR + 0x1A10)
#define HRA2REG			ECREG(EC_REG_BASE_ADDR + 0x1A11)
#define DOMA2REG		ECREG(EC_REG_BASE_ADDR + 0x1A12)
#define MONA2REG		ECREG(EC_REG_BASE_ADDR + 0x1A13)
#define PORSREGA		ECREG(EC_REG_BASE_ADDR + 0x1A14)
#define PORSREGB		ECREG(EC_REG_BASE_ADDR + 0x1A15)

/* --- Wake-Up Control (WUC) --- */
#define IT8XXX2_WUC_BASE   0x00F01B00

/* TODO: should a defined interface for configuring wake-up interrupts */
#define IT8XXX2_WUC_WUEMR1 (IT8XXX2_WUC_BASE + 0x00)
#define IT8XXX2_WUC_WUEMR3 (IT8XXX2_WUC_BASE + 0x02)
#define IT8XXX2_WUC_WUEMR5 (IT8XXX2_WUC_BASE + 0x0c)
#define IT8XXX2_WUC_WUESR1 (IT8XXX2_WUC_BASE + 0x04)
#define IT8XXX2_WUC_WUESR3 (IT8XXX2_WUC_BASE + 0x06)
#define IT8XXX2_WUC_WUESR5 (IT8XXX2_WUC_BASE + 0x0d)
#define IT8XXX2_WUC_WUENR3 (IT8XXX2_WUC_BASE + 0x0a)
#define IT8XXX2_WUC_WUBEMR1 (IT8XXX2_WUC_BASE + 0x3c)
#define IT8XXX2_WUC_WUBEMR5 (IT8XXX2_WUC_BASE + 0x0f)

/**
 *
 * (1Cxxh) SMBus Interface (SMB)
 *
 */
#define HOSTA_A			ECREG(EC_REG_BASE_ADDR + 0x1C40)
#define HOSTA_B			ECREG(EC_REG_BASE_ADDR + 0x1C80)
#define HOSTA_C			ECREG(EC_REG_BASE_ADDR + 0x1CC0)
#define HOSTA_BDS		BIT(7)
#define HOSTA_TMOE		BIT(6)
#define HOSTA_NACK		BIT(5)
#define HOSTA_FAIL		BIT(4)
#define HOSTA_BSER		BIT(3)
#define HOSTA_DVER		BIT(2)
#define HOSTA_FINTR		BIT(1)
#define HOSTA_HOBY		BIT(0)
#define HOSTA_ANY_ERROR		(HOSTA_DVER | HOSTA_BSER | \
				HOSTA_FAIL | HOSTA_NACK | HOSTA_TMOE)
#define HOSTA_NEXT_BYTE		HOSTA_BDS
#define HOSTA_ALL_WC_BIT		(HOSTA_FINTR | \
				HOSTA_ANY_ERROR | HOSTA_BDS)

#define HOCTL_A			ECREG(EC_REG_BASE_ADDR + 0x1C41)
#define HOCTL_B			ECREG(EC_REG_BASE_ADDR + 0x1C81)
#define HOCTL_C			ECREG(EC_REG_BASE_ADDR + 0x1CC1)
#define HOCTL_PEC_EN		BIT(7)
#define HOCTL_SRT		BIT(6)
#define HOCTL_LABY		BIT(5)
#define HOCTL_SMCD2		BIT(4)
#define HOCTL_SMCD1		BIT(3)
#define HOCTL_SMCD0		BIT(2)
#define HOCTL_KILL		BIT(1)
#define HOCTL_INTREN		BIT(0)

#define HOCMD_A			ECREG(EC_REG_BASE_ADDR + 0x1C42)
#define HOCMD_B			ECREG(EC_REG_BASE_ADDR + 0x1C82)
#define HOCMD_C			ECREG(EC_REG_BASE_ADDR + 0x1CC2)
#define TRASLA_A		ECREG(EC_REG_BASE_ADDR + 0x1C43)
#define TRASLA_B		ECREG(EC_REG_BASE_ADDR + 0x1C83)
#define TRASLA_C		ECREG(EC_REG_BASE_ADDR + 0x1CC3)
#define D0REG_A			ECREG(EC_REG_BASE_ADDR + 0x1C44)
#define D0REG_B			ECREG(EC_REG_BASE_ADDR + 0x1C84)
#define D0REG_C			ECREG(EC_REG_BASE_ADDR + 0x1CC4)
#define D1REG_A			ECREG(EC_REG_BASE_ADDR + 0x1C45)
#define D1REG_B			ECREG(EC_REG_BASE_ADDR + 0x1C85)
#define D1REG_C			ECREG(EC_REG_BASE_ADDR + 0x1CC5)
#define HOBDB_A			ECREG(EC_REG_BASE_ADDR + 0x1C46)
#define HOBDB_B			ECREG(EC_REG_BASE_ADDR + 0x1C86)
#define HOBDB_C			ECREG(EC_REG_BASE_ADDR + 0x1CC6)
#define PECERC_A		ECREG(EC_REG_BASE_ADDR + 0x1C47)
#define PECERC_B		ECREG(EC_REG_BASE_ADDR + 0x1C87)
#define PECERC_C		ECREG(EC_REG_BASE_ADDR + 0x1CC7)
#define RESLADR_A		ECREG(EC_REG_BASE_ADDR + 0x1C48)
#define RESLADR_B		ECREG(EC_REG_BASE_ADDR + 0x1C88)
#define RESLADR_2_A		ECREG(EC_REG_BASE_ADDR + 0x1C51)
#define RESLADR_2_B		ECREG(EC_REG_BASE_ADDR + 0x1C91)
#define SLDA_A			ECREG(EC_REG_BASE_ADDR + 0x1C49)
#define SLDA_B			ECREG(EC_REG_BASE_ADDR + 0x1C89)
#define SMBPCTL_A		ECREG(EC_REG_BASE_ADDR + 0x1C4A)
#define SMBPCTL_B		ECREG(EC_REG_BASE_ADDR + 0x1C8A)
#define SMBPCTL_C		ECREG(EC_REG_BASE_ADDR + 0x1CCA)
#define SLSTA_A			ECREG(EC_REG_BASE_ADDR + 0x1C4B)
#define SLSTA_B			ECREG(EC_REG_BASE_ADDR + 0x1C8B)
#define INT81			BIT(7)
#define BIS			BIT(6)
#define SPDS			BIT(5)
#define MSLA2			BIT(4)
#define RCS			BIT(3)
#define STS			BIT(2)
#define SDS			BIT(1)
#define HONOST			BIT(0)

#define SICR_A			ECREG(EC_REG_BASE_ADDR + 0x1C4C)
#define SICR_B			ECREG(EC_REG_BASE_ADDR + 0x1C8C)
#define NDADR_A			ECREG(EC_REG_BASE_ADDR + 0x1C4D)
#define NDADR_B			ECREG(EC_REG_BASE_ADDR + 0x1C8D)
#define NDLB_A			ECREG(EC_REG_BASE_ADDR + 0x1C4E)
#define NDLB_B			ECREG(EC_REG_BASE_ADDR + 0x1C8E)
#define NDHB_A			ECREG(EC_REG_BASE_ADDR + 0x1C4F)
#define NDHB_B			ECREG(EC_REG_BASE_ADDR + 0x1C8F)
#define HOCTL2_A		ECREG(EC_REG_BASE_ADDR + 0x1C50)
#define HOCTL2_B		ECREG(EC_REG_BASE_ADDR + 0x1C90)
#define HOCTL2_C		ECREG(EC_REG_BASE_ADDR + 0x1CD0)
#define SMB4P7USL		ECREG(EC_REG_BASE_ADDR + 0x1C00)
#define SMB4P0USH		ECREG(EC_REG_BASE_ADDR + 0x1C01)
#define SMB300NS		ECREG(EC_REG_BASE_ADDR + 0x1C02)
#define SMB250NS		ECREG(EC_REG_BASE_ADDR + 0x1C03)
#define SMB25MS			ECREG(EC_REG_BASE_ADDR + 0x1C04)
#define SMB45P3USL		ECREG(EC_REG_BASE_ADDR + 0x1C05)
#define SMB45P3USH		ECREG(EC_REG_BASE_ADDR + 0x1C06)
#define SMB4P7A4P0H		ECREG(EC_REG_BASE_ADDR + 0x1C07)
#define SLVISEL			ECREG(EC_REG_BASE_ADDR + 0x1C08)
#define SCLKTS_A		ECREG(EC_REG_BASE_ADDR + 0x1C09)
#define SCLKTS_B		ECREG(EC_REG_BASE_ADDR + 0x1C0A)
#define SCLKTS_C		ECREG(EC_REG_BASE_ADDR + 0x1C0B)
#define SMBFFCTRL1		ECREG(EC_REG_BASE_ADDR + 0x1C0D)
#define SMBFFSTS1		ECREG(EC_REG_BASE_ADDR + 0x1C0E)
#define SMBFFCTRL2		ECREG(EC_REG_BASE_ADDR + 0x1C0F)
#define SMBFFSTS2		ECREG(EC_REG_BASE_ADDR + 0x1C10)
#define CHSEF			ECREG(EC_REG_BASE_ADDR + 0x1C11)
#define HOCTL3_A		ECREG(EC_REG_BASE_ADDR + 0x1C52)
#define HOCTL3_B		ECREG(EC_REG_BASE_ADDR + 0x1C92)
#define HOCTL3_C		ECREG(EC_REG_BASE_ADDR + 0x1CD2)
#define MCODE_A			ECREG(EC_REG_BASE_ADDR + 0x1C53)
#define MCODE_B			ECREG(EC_REG_BASE_ADDR + 0x1C93)
#define MCODE_C			ECREG(EC_REG_BASE_ADDR + 0x1CD3)

/**
 *
 * (1Dxxh) Keyboard Matrix Scan control (KBS)
 *
 */
#define KSOL			ECREG(EC_REG_BASE_ADDR + 0x1D00)
#define KSOH1			ECREG(EC_REG_BASE_ADDR + 0x1D01)
#define KSOCTRL			ECREG(EC_REG_BASE_ADDR + 0x1D02)
#define KSOH2			ECREG(EC_REG_BASE_ADDR + 0x1D03)
#define KSI			ECREG(EC_REG_BASE_ADDR + 0x1D04)
#define KSICTRL			ECREG(EC_REG_BASE_ADDR + 0x1D05)
#define KSIGCTRL		ECREG(EC_REG_BASE_ADDR + 0x1D06)
#define KSIGOEN			ECREG(EC_REG_BASE_ADDR + 0x1D07)
#define KSIGDAT			ECREG(EC_REG_BASE_ADDR + 0x1D08)
#define KSIGDMRR		ECREG(EC_REG_BASE_ADDR + 0x1D09)
#define KSOHGCTRL		ECREG(EC_REG_BASE_ADDR + 0x1D0A)
#define KSOHGOEN		ECREG(EC_REG_BASE_ADDR + 0x1D0B)
#define KSOHGDMRR		ECREG(EC_REG_BASE_ADDR + 0x1D0C)
#define KSOLGCTRL		ECREG(EC_REG_BASE_ADDR + 0x1D0D)
#define KSOLGOEN		ECREG(EC_REG_BASE_ADDR + 0x1D0E)
#define KSOLGDMRR		ECREG(EC_REG_BASE_ADDR + 0x1D0F)
#define KSO0LSDR		ECREG(EC_REG_BASE_ADDR + 0x1D10)
#define KSO1LSDR		ECREG(EC_REG_BASE_ADDR + 0x1D11)
#define KSO2LSDR		ECREG(EC_REG_BASE_ADDR + 0x1D12)
#define KSO3LSDR		ECREG(EC_REG_BASE_ADDR + 0x1D13)
#define KSO4LSDR		ECREG(EC_REG_BASE_ADDR + 0x1D14)
#define KSO5LSDR		ECREG(EC_REG_BASE_ADDR + 0x1D15)
#define KSO6LSDR		ECREG(EC_REG_BASE_ADDR + 0x1D16)
#define KSO7LSDR		ECREG(EC_REG_BASE_ADDR + 0x1D17)
#define KSO8LSDR		ECREG(EC_REG_BASE_ADDR + 0x1D18)
#define KSO9LSDR		ECREG(EC_REG_BASE_ADDR + 0x1D19)
#define KSO10LSDR		ECREG(EC_REG_BASE_ADDR + 0x1D1A)
#define KSO11LSDR		ECREG(EC_REG_BASE_ADDR + 0x1D1B)
#define KSO12LSDR		ECREG(EC_REG_BASE_ADDR + 0x1D1C)
#define KSO13LSDR		ECREG(EC_REG_BASE_ADDR + 0x1D1D)
#define KSO14LSDR		ECREG(EC_REG_BASE_ADDR + 0x1D1E)
#define KSO15LSDR		ECREG(EC_REG_BASE_ADDR + 0x1D1F)
#define KSO16LSDR		ECREG(EC_REG_BASE_ADDR + 0x1D20)
#define KSO17LSDR		ECREG(EC_REG_BASE_ADDR + 0x1D21)
#define SDC1R			ECREG(EC_REG_BASE_ADDR + 0x1D22)
#define SDEN			BIT(7)
#define INTSDVEN		BIT(5)

/* BIT2 ~ BIT0  Scan loop select */
#define SLS_00_ROUND		0x00
#define SLS_02_ROUND		0x01
#define SLS_03_ROUND		0x02
#define SLS_04_ROUND		0x03
#define SLS_05_ROUND		0x04
#define SLS_06_ROUND		0x05
#define SLS_07_ROUND		0x06
#define SLS_08_ROUND		0x07

#define SDC2R			ECREG(EC_REG_BASE_ADDR + 0x1D23)
#define KSOPCS1			BIT(7)
#define KSOPCS0			BIT(6)

/* BIT3 ~ BIT0  Wait KSO high delay */
#define WKSOHDLY_23US		0x00
#define WKSOHDLY_31US		0x01
#define WKSOHDLY_39US		0x02
#define WKSOHDLY_47US		0x03
#define WKSOHDLY_55US		0x04
#define WKSOHDLY_63US		0x05
#define WKSOHDLY_71US		0x06
#define WKSOHDLY_79US		0x07
#define WKSOHDLY_87US		0x08
#define WKSOHDLY_95US		0x09

#define SDC3R			ECREG(EC_REG_BASE_ADDR + 0x1D24)

/* BIT7 ~ BIT4  Wait KSO low delay */
#define WKSOLDLY_11US		(0x00 << 4)
#define WKSOLDLY_13US		(0x01 << 4)
#define WKSOLDLY_15US		(0x02 << 4)
#define WKSOLDLY_17US		(0x03 << 4)
#define WKSOLDLY_19US		(0x04 << 4)
#define WKSOLDLY_21US		(0x05 << 4)
#define WKSOLDLY_23US		(0x06 << 4)
#define WKSOLDLY_25US		(0x07 << 4)
#define WKSOLDLY_27US		(0x08 << 4)
#define WKSOLDLY_29US		(0x09 << 4)

/* BIT3 ~ BIT0  Spacing delay between rounds */
#define SDLYBR_00MS		0x00
#define SDLYBR_01MS		0x01
#define SDLYBR_02MS		0x02
#define SDLYBR_03MS		0x03
#define SDLYBR_04MS		0x04
#define SDLYBR_05MS		0x05
#define SDLYBR_06MS		0x06
#define SDLYBR_07MS		0x07
#define SDLYBR_08MS		0x08
#define SDLYBR_09MS		0x09
#define SDLYBR_10MS		0x0A
#define SDLYBR_11MS		0x0B
#define SDLYBR_12MS		0x0C
#define SDLYBR_13MS		0x0D
#define SDLYBR_14MS		0x0E
#define SDLYBR_15MS		0x0F

#define SDSR			ECREG(EC_REG_BASE_ADDR + 0x1D25)
#define SDV			BIT(0)

/* Keyboard Scan Out Control Register */
#define KSOPU			BIT(2)
#define KSOOD			BIT(0)

/* Keyboard Scan In Control Register */
#define KSIPU			BIT(2)

/**
 *
 * (1Exxh) EC Clock and Power Management controller (ECPM)
 *
 */
#define CGCTRL1R		ECREG(EC_REG_BASE_ADDR + 0x1E01)
#define CGCTRL2R		ECREG(EC_REG_BASE_ADDR + 0x1E02)
#define CGCTRL3R		ECREG(EC_REG_BASE_ADDR + 0x1E05)
#define PLLCTRL			ECREG(EC_REG_BASE_ADDR + 0x1E03)
#define AUTOCG			ECREG(EC_REG_BASE_ADDR + 0x1E04)
#define PLLFREQR		ECREG(EC_REG_BASE_ADDR + 0x1E06)
#define PLLSSCR			ECREG(EC_REG_BASE_ADDR + 0x1E07)
#define PLLCSS			ECREG(EC_REG_BASE_ADDR + 0x1E08)
#define CGCTRL4R		ECREG(EC_REG_BASE_ADDR + 0x1E09)
#define EC_1E00			ECREG(EC_REG_BASE_ADDR + 0x1E00)
#define ECPM_PDCTRL1R		ECREG(EC_REG_BASE_ADDR + 0x1E01)
#define EC_1E03			ECREG(EC_REG_BASE_ADDR + 0x1E03)
#define EC_1E06			ECREG(EC_REG_BASE_ADDR + 0x1E06)
#define LDOCTR			ECREG(EC_REG_BASE_ADDR + 0x1E0A)
#define PLLSTCR			ECREG(EC_REG_BASE_ADDR + 0x1E0B)
#define SCDCR0			ECREG(EC_REG_BASE_ADDR + 0x1E0C)
#define SCDCR1			ECREG(EC_REG_BASE_ADDR + 0x1E0D)
#define SCDCR2			ECREG(EC_REG_BASE_ADDR + 0x1E0E)
#define SCDCR3			ECREG(EC_REG_BASE_ADDR + 0x1E0F)
#define CGCTRL5R		ECREG(EC_REG_BASE_ADDR + 0x1E13)
#define LOWFREQ			ECREG(EC_REG_BASE_ADDR + 0x1E19)

/**
 *
 * (1Fxxh) External Timer & External Watchdog (ETWD)
 *
 */
#ifndef __ASSEMBLER__
struct wdt_it8xxx2_regs {
	/* 0x000: Reserved1 */
	volatile uint8_t reserved1;
	/* 0x001: External Timer1/WDT Configuration */
	volatile uint8_t ETWCFG;
	/* 0x002: External Timer1 Prescaler */
	volatile uint8_t ET1PSR;
	/* 0x003: External Timer1 Counter High Byte */
	volatile uint8_t ET1CNTLHR;
	/* 0x004: External Timer1 Counter Low Byte */
	volatile uint8_t ET1CNTLLR;
	/* 0x005: External Timer1/WDT Control */
	volatile uint8_t ETWCTRL;
	/* 0x006: External WDT Counter Low Byte */
	volatile uint8_t EWDCNTLR;
	/* 0x007: External WDT Key */
	volatile uint8_t EWDKEYR;
	/* 0x008: Reserved2 */
	volatile uint8_t reserved2;
	/* 0x009: External WDT Counter High Byte */
	volatile uint8_t EWDCNTHR;
	/* 0x00A: External Timer2 Prescaler */
	volatile uint8_t ET2PSR;
	/* 0x00B: External Timer2 Counter High Byte */
	volatile uint8_t ET2CNTLHR;
	/* 0x00C: External Timer2 Counter Low Byte */
	volatile uint8_t ET2CNTLLR;
	/* 0x00D: Reserved3 */
	volatile uint8_t reserved3;
	/* 0x00E: External Timer2 Counter High Byte2 */
	volatile uint8_t ET2CNTLH2R;
	/* 0x00F~0x03F: Reserved4 */
	volatile uint8_t reserved4[49];
	/* 0x040: External Timer1 Counter Observation Low Byte */
	volatile uint8_t ET1CNTOLR;
	/* 0x041: External Timer1 Counter Observation High Byte */
	volatile uint8_t ET1CNTOHR;
	/* 0x042~0x043: Reserved5 */
	volatile uint8_t reserved5[2];
	/* 0x044: External Timer1 Counter Observation Low Byte */
	volatile uint8_t ET2CNTOLR;
	/* 0x045: External Timer1 Counter Observation High Byte */
	volatile uint8_t ET2CNTOHR;
	/* 0x046: External Timer1 Counter Observation High Byte2 */
	volatile uint8_t ET2CNTOH2R;
	/* 0x047~0x05F: Reserved6 */
	volatile uint8_t reserved6[25];
	/* 0x060: External WDT Counter Observation Low Byte */
	volatile uint8_t EWDCNTOLR;
	/* 0x061: External WDT Counter Observation High Byte */
	volatile uint8_t EWDCNTOHR;
};
#endif /* !__ASSEMBLER__ */

/* WDT register fields */
/* 0x001: External Timer1/WDT Configuration */
#define IT8XXX2_WDT_EWDKEYEN		BIT(5)
#define IT8XXX2_WDT_EWDSRC		BIT(4)
#define IT8XXX2_WDT_LEWDCNTL		BIT(3)
#define IT8XXX2_WDT_LET1CNTL		BIT(2)
#define IT8XXX2_WDT_LET1PS		BIT(1)
#define IT8XXX2_WDT_LETWCFG		BIT(0)
/* 0x002: External Timer1 Prescaler */
#define IT8XXX2_WDT_ETPS_32P768_KHZ	0x00
#define IT8XXX2_WDT_ETPS_1P024_KHZ	0x01
#define IT8XXX2_WDT_ETPS_32_HZ		0x02
/* 0x005: External Timer1/WDT Control */
#define IT8XXX2_WDT_EWDSCEN		BIT(5)
#define IT8XXX2_WDT_EWDSCMS		BIT(4)
#define IT8XXX2_WDT_ET2TC		BIT(3)
#define IT8XXX2_WDT_ET2RST		BIT(2)
#define IT8XXX2_WDT_ET1TC		BIT(1)
#define IT8XXX2_WDT_ET1RST		BIT(0)

/* External Timer register fields */
/* External Timer 3~8 control */
#define IT8XXX2_EXT_ETXRST		BIT(1)
#define IT8XXX2_EXT_ETXEN		BIT(0)

/**
 *
 * Observation external timer
 *
 */
#define ET3CNTOLR		ECREG(EC_REG_BASE_ADDR + 0x1F48)
#define ET3CNTOHR		ECREG(EC_REG_BASE_ADDR + 0x1F49)
#define ET3CNTOH2R		ECREG(EC_REG_BASE_ADDR + 0x1F4A)
#define ET4CNTOLR		ECREG(EC_REG_BASE_ADDR + 0x1F4C)
#define ET4CNTOHR		ECREG(EC_REG_BASE_ADDR + 0x1F4D)
#define ET4CNTOH2R		ECREG(EC_REG_BASE_ADDR + 0x1F4E)
#define ET4CNTOH3R		ECREG(EC_REG_BASE_ADDR + 0x1F4F)
#define ET5CNTOLR		ECREG(EC_REG_BASE_ADDR + 0x1F50)
#define ET5CNTOHR		ECREG(EC_REG_BASE_ADDR + 0x1F51)
#define ET5CNTOH2R		ECREG(EC_REG_BASE_ADDR + 0x1F52)
#define ET6CNTOLR		ECREG(EC_REG_BASE_ADDR + 0x1F54)
#define ET6CNTOHR		ECREG(EC_REG_BASE_ADDR + 0x1F55)
#define ET6CNTOH2R		ECREG(EC_REG_BASE_ADDR + 0x1F56)
#define ET6CNTOH3R		ECREG(EC_REG_BASE_ADDR + 0x1F57)
#define ET7CNTOLR		ECREG(EC_REG_BASE_ADDR + 0x1F58)
#define ET7CNTOHR		ECREG(EC_REG_BASE_ADDR + 0x1F59)
#define ET7CNTOH2R		ECREG(EC_REG_BASE_ADDR + 0x1F5A)
#define ET8CNTOLR		ECREG(EC_REG_BASE_ADDR + 0x1F5C)
#define ET8CNTOHR		ECREG(EC_REG_BASE_ADDR + 0x1F5D)
#define ET8CNTOH2R		ECREG(EC_REG_BASE_ADDR + 0x1F5E)
#define ET8CNTOH3R		ECREG(EC_REG_BASE_ADDR + 0x1F5F)

#define ETXCNTOR(x)		(ECREG_u32(EC_REG_BASE_ADDR\
					+ 0x1F40 + (x - 1) * 4))

#define ETPS_32_768_KHZ		0x00
#define ETPS_1_024_KHZ		0x01
#define ETPS_32_HZ		0x02
#define ETPS_8_MHZ		0x03
#define ET_3_8_TC		BIT(2)
#define ET_3_8_RST		BIT(1)
#define ET_3_8_EN		BIT(0)

/**
 *
 * (20xxh) General Control (GCTRL)
 *
 */
#define ECHIPID1		ECREG(EC_REG_BASE_ADDR + 0x2000)
#define ECHIPID2		ECREG(EC_REG_BASE_ADDR + 0x2001)
#define ECHIPVER		ECREG(EC_REG_BASE_ADDR + 0x2002)
#define IDR			ECREG(EC_REG_BASE_ADDR + 0x2004)
#define RSTS			ECREG(EC_REG_BASE_ADDR + 0x2006)
#define RSTC1			ECREG(EC_REG_BASE_ADDR + 0x2007)
#define RSMFI			BIT(7)
#define RINTC			BIT(6)
#define REC2I			BIT(5)
#define RKBC			BIT(4)
#define RSWUC			BIT(3)
#define RPMC			BIT(2)
#define RGPIO			BIT(1)
#define RPWM			BIT(0)
#define RSTC2			ECREG(EC_REG_BASE_ADDR + 0x2008)
#define RADC			BIT(7)
#define RDAC			BIT(6)
#define RWUC			BIT(5)
#define RKBS			BIT(4)
#define REGPC			BIT(2)
#define RCIR			BIT(1)
#define RSTC3			ECREG(EC_REG_BASE_ADDR + 0x2009)
#define RPS23			BIT(6)
#define RPS22			BIT(5)
#define RPS21			BIT(4)
#define RSMBD			BIT(3)
#define RSMBC			BIT(2)
#define RSMBB			BIT(1)
#define RSMBA			BIT(0)
/*the same time and writing 0111b is reserved.*/
#define RSTC4			ECREG(EC_REG_BASE_ADDR + 0x2011)
#define RPECI			BIT(4)
#define RTMR			BIT(3)
#define RUART2			BIT(2)
#define RUART1			BIT(1)
#define RSPI			BIT(0)

#define BADRSEL			ECREG(EC_REG_BASE_ADDR + 0x200A)
#define WNCKR			ECREG(EC_REG_BASE_ADDR + 0x200B)
#define OSCTRL			ECREG(EC_REG_BASE_ADDR + 0x200C)
#define SPCTRL1			ECREG(EC_REG_BASE_ADDR + 0x200D)
#define RSTCH			ECREG(EC_REG_BASE_ADDR + 0x200E)
#define GENIRQ			ECREG(EC_REG_BASE_ADDR + 0x200F)
#define RSTDMMC			ECREG(EC_REG_BASE_ADDR + 0x2010)
#define SPECTRL2		ECREG(EC_REG_BASE_ADDR + 0x2012)
#define SPECTRL3		ECREG(EC_REG_BASE_ADDR + 0x2016)
#define PI2ECH			ECREG(EC_REG_BASE_ADDR + 0x2014)
#define PI2ECL			ECREG(EC_REG_BASE_ADDR + 0x2015)
#define BINTADDR0R		ECREG(EC_REG_BASE_ADDR + 0x2019)
#define BINTADDR1R		ECREG(EC_REG_BASE_ADDR + 0x201A)
#define BINTCTRLR		ECREG(EC_REG_BASE_ADDR + 0x201B)
#define SPCTRL4			ECREG(EC_REG_BASE_ADDR + 0x201C)
#define SHA1HASHCTRLR		ECREG(EC_REG_BASE_ADDR + 0x202D)
#define SHA1HBADDR		ECREG(EC_REG_BASE_ADDR + 0x202E)
#define MCCR			ECREG(EC_REG_BASE_ADDR + 0x2030)
#define EIDSR			ECREG(EC_REG_BASE_ADDR + 0x2031)
#define PMER1			ECREG(EC_REG_BASE_ADDR + 0x2032)
#define PMER2			ECREG(EC_REG_BASE_ADDR + 0x2033)
#define FRR0			ECREG(EC_REG_BASE_ADDR + 0x2034)
#define FRR1			ECREG(EC_REG_BASE_ADDR + 0x2035)
#define FRR2			ECREG(EC_REG_BASE_ADDR + 0x2036)
#define MCCR1			ECREG(EC_REG_BASE_ADDR + 0x203E)
#define IVTBAR			ECREG(EC_REG_BASE_ADDR + 0x2041)
#define DMMYR			ECREG(EC_REG_BASE_ADDR + 0x2045)
#define PWMENR			ECREG(EC_REG_BASE_ADDR + 0x204A)
#define PDSCR1			ECREG(EC_REG_BASE_ADDR + 0x204C)
#define PDSCR2			ECREG(EC_REG_BASE_ADDR + 0x204D)
#define PDSCR3			ECREG(EC_REG_BASE_ADDR + 0x204E)
#define PDSCR4			ECREG(EC_REG_BASE_ADDR + 0x204F)
#define PDSCR5			ECREG(EC_REG_BASE_ADDR + 0x2050)
#define PDSCR6			ECREG(EC_REG_BASE_ADDR + 0x2051)
#define PDSCR7			ECREG(EC_REG_BASE_ADDR + 0x2052)
#define DRI_6_25		(0x00)
#define DRI_7_50		(0x01)
#define DRI_8_75		(0x02)
#define DRI_10_00		(0x03)
#define DRI_GPIOB0(x)		((x) << 6)
#define DRI_GPIOA6(x)		((x) << 4)
#define DRI_GPIOA5(x)		((x) << 2)
#define DRI_GPIOA4(x)		((x) << 0)
#define DRI_GPIOB4(x)		((x) << 6)
#define DRI_GPIOB3(x)		((x) << 4)
#define DRI_GPIOB2(x)		((x) << 2)
#define DRI_GPIOB1(x)		((x) << 0)
#define DRI_GPIOB5(x)		((x) << 0)
#define DRI_GPIOC3(x)		((x) << 4)
#define DRI_GPIOC2(x)		((x) << 2)
#define DRI_GPIOC1(x)		((x) << 0)
#define DRI_GPIOC7(x)		((x) << 4)
#define DRI_GPIOC6(x)		((x) << 2)
#define DRI_GPIOC5(x)		((x) << 0)
#define DRI_GPIOD5(x)		((x) << 6)
#define DRI_GPIOD4(x)		((x) << 4)
#define DRI_GPIOD3(x)		((x) << 2)
#define DRI_GPIOD2(x)		((x) << 0)
#define DRI_GPIOD7(x)		((x) << 2)
#define PMER5			ECREG(EC_REG_BASE_ADDR + 0x2057)
#define PIECR0			ECREG(EC_REG_BASE_ADDR + 0x205A)
#define PIECR1			ECREG(EC_REG_BASE_ADDR + 0x205B)
#define PIECR2			ECREG(EC_REG_BASE_ADDR + 0x205C)
#define PIECR3			ECREG(EC_REG_BASE_ADDR + 0x205D)
#define INTOSC			ECREG(EC_REG_BASE_ADDR + 0x205E)

/**
 *
 * (21xxh) External GPIO Controller (EGPC)
 *
 */
#define EADDR			ECREG(EC_REG_BASE_ADDR + 0x2100)
#define EDAT			ECREG(EC_REG_BASE_ADDR + 0x2101)
#define ECNT			ECREG(EC_REG_BASE_ADDR + 0x2102)
#define ESTS			ECREG(EC_REG_BASE_ADDR + 0x2103)

/**
 *
 * (23xxh) Consumer IR (CIR)
 *
 */
#define C0DR			ECREG(EC_REG_BASE_ADDR + 0x2300)
#define C0MSTCR			ECREG(EC_REG_BASE_ADDR + 0x2301)
#define CIR_CTXSEL		BIT(7)
#define CIR_CRXSEL		BIT(6)
#define CIR_ILSEL		BIT(5)
#define CIR_ILE			BIT(4)
#define CIR_FIFOTL1		BIT(3)
#define CIR_FIFOTL0		BIT(2)
#define CIR_FIFOCLR		BIT(1)
#define CIR_RESET		BIT(0)
#define C0IER			ECREG(EC_REG_BASE_ADDR + 0x2302)
#define C0IIR			ECREG(EC_REG_BASE_ADDR + 0x2303)
#define C0CFR			ECREG(EC_REG_BASE_ADDR + 0x2304)
#define C0RCR			ECREG(EC_REG_BASE_ADDR + 0x2305)
#define CIR_RXEN		BIT(7)
#define CIR_RDWOS		BIT(5)
#define CIR_RXEND		BIT(4)
#define CIR_RXACT		BIT(3)
#define CIR_RXDCR2		BIT(2)
#define CIR_RXDCR1		BIT(1)
#define CIR_RXDCR0		BIT(0)
#define C0TCR			ECREG(EC_REG_BASE_ADDR + 0x2306)
#define C0SCK			ECREG(EC_REG_BASE_ADDR + 0x2307)
#define DLLOCK			BIT(7)
#define BRCM2			BIT(6)
#define BRCM1			BIT(5)
#define BRCM0			BIT(4)
#define DLLTE			BIT(3)
#define DLL1P8E			BIT(2)
#define TXDCKG			BIT(1)
#define SCKS			BIT(0)
#define C0BDLR			ECREG(EC_REG_BASE_ADDR + 0x2308)
#define C0BDHR			ECREG(EC_REG_BASE_ADDR + 0x2309)
#define C0TFSR			ECREG(EC_REG_BASE_ADDR + 0x230A)
#define C0RFSR			ECREG(EC_REG_BASE_ADDR + 0x230B)
#define C0WCSSR			ECREG(EC_REG_BASE_ADDR + 0x230C)
#define C0WCL			ECREG(EC_REG_BASE_ADDR + 0x230D)
#define C0WCR			ECREG(EC_REG_BASE_ADDR + 0x230E)
#define C0WPS			ECREG(EC_REG_BASE_ADDR + 0x230F)
#define CSCRR			ECREG(EC_REG_BASE_ADDR + 0x2310)

/**
 *
 * (25xxh) Debugger (DBGR)
 *
 */
#define BKA1L			ECREG(EC_REG_BASE_ADDR + 0x2510)
#define BKA1M			ECREG(EC_REG_BASE_ADDR + 0x2511)
#define BKA1H			ECREG(EC_REG_BASE_ADDR + 0x2512)
#define BKA2L			ECREG(EC_REG_BASE_ADDR + 0x2513)
#define BKA2M			ECREG(EC_REG_BASE_ADDR + 0x2514)
#define BKA2H			ECREG(EC_REG_BASE_ADDR + 0x2515)
#define BKA3L			ECREG(EC_REG_BASE_ADDR + 0x2516)
#define BKA3M			ECREG(EC_REG_BASE_ADDR + 0x2517)
#define BKA3H			ECREG(EC_REG_BASE_ADDR + 0x2518)

/**
 *
 * (26xxh) Serial Peripheral Interface (SSPI)
 *
 */
#define SPI_BASE_ADDR		(EC_REG_BASE_ADDR + 0x2600)
#define SPIDATA			ECREG(EC_REG_BASE_ADDR + 0x2600)
#define SPICTRL1		ECREG(EC_REG_BASE_ADDR + 0x2601)
#define CHPOL			BIT(7)
#define CLPOL			BIT(6)
#define CLPHS			BIT(5)
#define SCKFREQ2		BIT(4)
#define SCKFREQ1		BIT(3)
#define SCKFREQ0		BIT(2)
#define NTREN			BIT(1)
#define WIRECH0			BIT(0)
#define SPICTRL2		ECREG(EC_REG_BASE_ADDR + 0x2602)
#define HBANK			BIT(7)
#define DEVBUSYPOL		BIT(6)
#define BYTEWIDTH2		BIT(5)
#define BYTEWIDTH1		BIT(4)
#define BYTEWIDTH0		BIT(3)
#define CHRW			BIT(2)
#define BLKSEL			BIT(1)
#define WIRECH1			BIT(0)
#define SPISTS			ECREG(EC_REG_BASE_ADDR + 0x2603)
#define WAITBUSYSTART		BIT(7)
#define DEVBUSY			BIT(6)
#define TRANEND			BIT(5)
#define CH0START		BIT(4)
#define CH1START		BIT(3)
#define TRANIP			BIT(2)
#define TRANENDIF		BIT(1)
#define SPIBUSY			BIT(0)
#define SPICTRL3		ECREG(EC_REG_BASE_ADDR + 0x2604)
#define CMDQAUTOMODE		BIT(5)
#define DEVBUSYMODE		BIT(3)
#define CSPOLSEL		BIT(2)
#define CHPOL1			BIT(1)
#define BUSYNOCLK		BIT(0)
#define CH0CMDADDRLB		ECREG(EC_REG_BASE_ADDR + 0x2605)
#define CH0CMDADDRHB		ECREG(EC_REG_BASE_ADDR + 0x2606)
#define CH0CMDADDRHB2		ECREG(EC_REG_BASE_ADDR + 0x2621)
#define DMATCNTLB		ECREG(EC_REG_BASE_ADDR + 0x2607)
#define DMATCNTHB		ECREG(EC_REG_BASE_ADDR + 0x2608)
#define SPIWRCMDL		ECREG(EC_REG_BASE_ADDR + 0x2609)
#define CH0DMARDLB		ECREG(EC_REG_BASE_ADDR + 0x260A)
#define CH0DMARDHB		ECREG(EC_REG_BASE_ADDR + 0x260B)
#define INTSTS			ECREG(EC_REG_BASE_ADDR + 0x260C)
#define CH2CMDQEND		(BIT(5) | BIT(6))
#define CH1CMDQEND		BIT(6)
#define CH0CMDQEND		BIT(5)
#define SPICMDQENDMASK		BIT(4)
#define SPIRING1FI		BIT(2)
#define SPIRING0FI		BIT(1)
#define SPICMDQEND		BIT(0)
#define SPICTRL5		ECREG(EC_REG_BASE_ADDR + 0x260D)
#define CH2SELCMDQ		BIT(6)
#define CH1SELCMDQ		BIT(5)
#define CH0SELCMDQ		BIT(4)
#define CMDQMODE		BIT(0)
#define CH0WRMEMADDRLB		ECREG(EC_REG_BASE_ADDR + 0x260E)
#define CH0WRMEMADDRHB		ECREG(EC_REG_BASE_ADDR + 0x260F)
#define CH0WRMEMADDRHB2		ECREG(EC_REG_BASE_ADDR + 0x2623)
#define CMDQINVPR		ECREG(EC_REG_BASE_ADDR + 0x2610)
#define CH0WTSR			ECREG(EC_REG_BASE_ADDR + 0x2611)
#define CH1CMDADDRLB		ECREG(EC_REG_BASE_ADDR + 0x2612)
#define CH1CMDADDRHB		ECREG(EC_REG_BASE_ADDR + 0x2613)
#define CH1WRMEMADDRLB		ECREG(EC_REG_BASE_ADDR + 0x2614)
#define CH1WRMEMADDRHB		ECREG(EC_REG_BASE_ADDR + 0x2615)
#define CH1WTSR			ECREG(EC_REG_BASE_ADDR + 0x2616)
#define CH1DMARDLB		ECREG(EC_REG_BASE_ADDR + 0x2617)
#define CH1DMARDHB		ECREG(EC_REG_BASE_ADDR + 0x2618)
#define CH2CMDADDRLB		ECREG(EC_REG_BASE_ADDR + 0x2619)
#define CH2CMDADDRHB		ECREG(EC_REG_BASE_ADDR + 0x261A)
#define CH2WRMEMADDRLB		ECREG(EC_REG_BASE_ADDR + 0x261B)
#define CH2WRMEMADDRHB		ECREG(EC_REG_BASE_ADDR + 0x261C)
#define CH2WTSR			ECREG(EC_REG_BASE_ADDR + 0x261D)
#define CH2DMARDLB		ECREG(EC_REG_BASE_ADDR + 0x261E)
#define CH2DMARDHB		ECREG(EC_REG_BASE_ADDR + 0x261F)
#define SPICTRL6		ECREG(EC_REG_BASE_ADDR + 0x2620)
#define CH2START		BIT(3)
#define WIRECH2			BIT(0)

/**
 *
 * (27xxh) Extern Serial Port (UART1)
 *
 */
#define REG_UART1_BASE		(EC_REG_BASE_ADDR + 0x2700)
#define UART1_RBR		ECREG(REG_UART1_BASE + 0x00)
#define UART1_IER		ECREG(REG_UART1_BASE + 0x01)
#define UART1_IIR		ECREG(REG_UART1_BASE + 0x02)
#define UART1_LCR		ECREG(REG_UART1_BASE + 0x03)
#define UART1_MCR		ECREG(REG_UART1_BASE + 0x04)
#define UART1_LSR		ECREG(REG_UART1_BASE + 0x05)
#define UART1_MSR		ECREG(REG_UART1_BASE + 0x06)
#define UART1_SCR		ECREG(REG_UART1_BASE + 0x07)
#define UART1_ECSPMR		ECREG(REG_UART1_BASE + 0x08)
#define UART1_SPPR		ECREG(REG_UART1_BASE + 0x09)
#define UART1_UTBR		ECREG(REG_UART1_BASE + 0x00)
#define UART1_UFCR		ECREG(REG_UART1_BASE + 0x02)
#define UART1_UMSR		ECREG(REG_UART1_BASE + 0x06)
#define UART1_USCR		ECREG(REG_UART1_BASE + 0x07)

/**
 *
 * (28xxh) Extern Serial Port (UART2)
 *
 */
#define REG_UART2_BASE		(EC_REG_BASE_ADDR + 0x2800)
#define UART2_RBR		ECREG(REG_UART2_BASE + 0x00)
#define UART2_IER		ECREG(REG_UART2_BASE + 0x01)
#define UART2_IIR		ECREG(REG_UART2_BASE + 0x02)
#define UART2_LCR		ECREG(REG_UART2_BASE + 0x03)
#define UART2_MCR		ECREG(REG_UART2_BASE + 0x04)
#define UART2_LSR		ECREG(REG_UART2_BASE + 0x05)
#define UART2_MSR		ECREG(REG_UART2_BASE + 0x06)
#define UART2_SCR		ECREG(REG_UART2_BASE + 0x07)
#define UART2_ECSPMR		ECREG(REG_UART2_BASE + 0x08)
#define UART2_UTBR		ECREG(REG_UART2_BASE + 0x00)
#define UART2_UFCR		ECREG(REG_UART2_BASE + 0x02)
#define UART2_UMSR		ECREG(REG_UART2_BASE + 0x06)
#define UART2_USCR		ECREG(REG_UART2_BASE + 0x07)

/**
 *
 * (29xxh) 8 Bit Timer (TMR)
 *
 */
#define PRSC			ECREG(EC_REG_BASE_ADDR + 0x2900)
#define GCSMS			ECREG(EC_REG_BASE_ADDR + 0x2901)
#define CTR_A0			ECREG(EC_REG_BASE_ADDR + 0x2902)
#define CTR_A1			ECREG(EC_REG_BASE_ADDR + 0x2903)
#define CTR_B0			ECREG(EC_REG_BASE_ADDR + 0x2904)
#define CTR_B1			ECREG(EC_REG_BASE_ADDR + 0x2905)
#define DCR_A0			ECREG(EC_REG_BASE_ADDR + 0x2906)
#define DCR_A1			ECREG(EC_REG_BASE_ADDR + 0x2907)
#define DCR_B0			ECREG(EC_REG_BASE_ADDR + 0x2908)
#define DCR_B1			ECREG(EC_REG_BASE_ADDR + 0x2909)
#define CCGSR			ECREG(EC_REG_BASE_ADDR + 0x290A)
#define TMRCE			ECREG(EC_REG_BASE_ADDR + 0x290B)
#define TMEIE			ECREG(EC_REG_BASE_ADDR + 0x290C)

/**
 *
 * (2Cxxh) Platform Environment Control Interface (PECI)
 *
 */
#define HOSTAR			ECREG(EC_REG_BASE_ADDR + 0x2C00)
#define TEMPERR			BIT(7)
#define BUSERR			BIT(6)
#define EXTERR			BIT(5)
#define WR_FCS_ERR		BIT(3)
#define RD_FCS_ERR		BIT(2)
#define FINISH			BIT(1)
#define HOBY			BIT(0)
#define HOCTLR			ECREG(EC_REG_BASE_ADDR + 0x2C01)
#define FIFOCLR			BIT(5)
#define FCSERR_ABT		BIT(4)
#define PECIHEN			BIT(3)
#define CONCTRL			BIT(2)
#define AWFCS_EN		BIT(1)
#define PECISTART		BIT(0)
#define HOCMDR			ECREG(EC_REG_BASE_ADDR + 0x2C02)
#define HOTRADDR		ECREG(EC_REG_BASE_ADDR + 0x2C03)
#define HOWRLR			ECREG(EC_REG_BASE_ADDR + 0x2C04)
#define HORDLR			ECREG(EC_REG_BASE_ADDR + 0x2C05)
#define HOWRDR			ECREG(EC_REG_BASE_ADDR + 0x2C06)
#define HORDDR			ECREG(EC_REG_BASE_ADDR + 0x2C07)
#define HOCTL2R			ECREG(EC_REG_BASE_ADDR + 0x2C08)
#define RWFCSV			ECREG(EC_REG_BASE_ADDR + 0x2C09)
#define RRFCSV			ECREG(EC_REG_BASE_ADDR + 0x2C0A)
#define WFCSV			ECREG(EC_REG_BASE_ADDR + 0x2C0B)
#define RFCSV			ECREG(EC_REG_BASE_ADDR + 0x2C0C)
#define AWFCSV			ECREG(EC_REG_BASE_ADDR + 0x2C0D)
#define PADCTLR			ECREG(EC_REG_BASE_ADDR + 0x2C0E)

/**
 *
 * (2Dxxh) I2C/JTAG
 *
 */
#define CLOCK_CGCTRL5R		(REG_BASE_ADDR + 0x1E13)
#define CLK_C_MEMS_MIC		0x40
#define CLK_C_ADC		0x20
#define CLK_C_SPI_SLAVE		0x10
#define CLK_C_HF		0x08
#define CLK_C_USB		0x04
#define CLK_C_UART		0x02
#define CLK_C_SSPI		0x01
#define CLK_C_ALL		0x7F
#define GCTRL_BASE_ADDR		(REG_BASE_ADDR + 0x2000)
#define GCTRL_PMER1		(GCTRL_BASE_ADDR + 0x32)
#define GCTRL_PMER2		(GCTRL_BASE_ADDR + 0x33)
#define PADIE0			(GCTRL_BASE_ADDR + 0x5A)
#define PADIE1			(GCTRL_BASE_ADDR + 0x5B)
#define PADIE2			(GCTRL_BASE_ADDR + 0x5C)
#define PADIE3			(GCTRL_BASE_ADDR + 0x5D)

/**
 *
 * (2Exxh) Consumer Electronics Control (CEC)
 *
 */
#define CECDR			ECREG(EC_REG_BASE_ADDR + 0x2E00)
#define CECFSTS			ECREG(EC_REG_BASE_ADDR + 0x2E01)
#define CECDLA			ECREG(EC_REG_BASE_ADDR + 0x2E02)
#define CECCTRL			ECREG(EC_REG_BASE_ADDR + 0x2E03)
#define CECSTS			ECREG(EC_REG_BASE_ADDR + 0x2E04)
#define CECIE			ECREG(EC_REG_BASE_ADDR + 0x2E05)
#define CECOPSTS		ECREG(EC_REG_BASE_ADDR + 0x2E06)
#define CECCRH			ECREG(EC_REG_BASE_ADDR + 0x2E07)

/**
 *
 * (3Cxxh) Crypto Engine
 *
 */

#define CE_CTRL_1ST		ECREG(EC_REG_BASE_ADDR + 0x3C00)
#define CE_RNG			ECREG(EC_REG_BASE_ADDR + 0x3C20)


/* Shared Memory Flash Interface Bridge (SMFI) registers */

#ifndef __ASSEMBLER__
struct flash_it8xxx2_regs {
	volatile uint8_t reserved1[59];
	/* 0x3B: EC-Indirect memory address 0 */
	volatile uint8_t SMFI_ECINDAR0;
	/* 0x3C: EC-Indirect memory address 1 */
	volatile uint8_t SMFI_ECINDAR1;
	/* 0x3D: EC-Indirect memory address 2 */
	volatile uint8_t SMFI_ECINDAR2;
	/* 0x3E: EC-Indirect memory address 3 */
	volatile uint8_t SMFI_ECINDAR3;
	/* 0x3F: EC-Indirect memory data */
	volatile uint8_t SMFI_ECINDDR;
	/* 0x40: Scratch SRAM 0 address low byte */
	volatile uint8_t SMFI_SCAR0L;
	/* 0x41: Scratch SRAM 0 address middle byte */
	volatile uint8_t SMFI_SCAR0M;
	/* 0x42: Scratch SRAM 0 address high byte */
	volatile uint8_t SMFI_SCAR0H;
	volatile uint8_t reserved2[95];
	/* 0xA2: Flash control 6 */
	volatile uint8_t SMFI_FLHCTRL6R;
};
#endif /* !__ASSEMBLER__ */

/* SMFI register fields */

/* EC-Indirect read internal flash */
#define EC_INDIRECT_READ_INTERNAL_FLASH BIT(6)
/* Enable EC-indirect page program command */
#define IT8XXX2_SMFI_MASK_ECINDPP BIT(3)
/* Scratch SRAM 0 address(BIT(19)) */
#define IT8XXX2_SMFI_SC0A19 BIT(7)
/* Scratch SRAM enable */
#define IT8XXX2_SMFI_SCAR0H_ENABLE BIT(3)

/* --- GPIO --- */
#define IT8XXX2_GPIO_BASE  0x00F01600
#define IT8XXX2_GPIO2_BASE 0x00F03E00

#define IT8XXX2_GPIO_GCR        ECREG(IT8XXX2_GPIO_BASE + 0x00)

#define IT8XXX2_GPIO_GCRX(offset) ECREG(IT8XXX2_GPIO_BASE + (offset))
#define IT8XXX2_GPIO_GCR25_OFFSET 0xd1
#define IT8XXX2_GPIO_GCR26_OFFSET 0xd2
#define IT8XXX2_GPIO_GCR27_OFFSET 0xd3
#define IT8XXX2_GPIO_GCR28_OFFSET 0xd4
#define IT8XXX2_GPIO_GCR31_OFFSET 0xd5
#define IT8XXX2_GPIO_GCR32_OFFSET 0xd6
#define IT8XXX2_GPIO_GCR33_OFFSET 0xd7
#define IT8XXX2_GPIO_GCR19_OFFSET 0xe4
#define IT8XXX2_GPIO_GCR20_OFFSET 0xe5
#define IT8XXX2_GPIO_GCR21_OFFSET 0xe6
#define IT8XXX2_GPIO_GCR22_OFFSET 0xe7
#define IT8XXX2_GPIO_GCR23_OFFSET 0xe8
#define IT8XXX2_GPIO_GCR24_OFFSET 0xe9
#define IT8XXX2_GPIO_GCR30_OFFSET 0xed
#define IT8XXX2_GPIO_GCR29_OFFSET 0xee
/* TODO: correct GRCx to GCRx */
#define IT8XXX2_GPIO_GRC1       ECREG(IT8XXX2_GPIO_BASE + 0xF0)
#define IT8XXX2_GPIO_GRC21      ECREG(IT8XXX2_GPIO_BASE + 0xE6)

#define IT8XXX2_GPIO_GPCRP0     ECREG(IT8XXX2_GPIO2_BASE + 0x18)
#define IT8XXX2_GPIO_GPCRP1     ECREG(IT8XXX2_GPIO2_BASE + 0x19)

/* Analog to Digital Converter (ADC) */

#ifndef __ASSEMBLER__
struct adc_it8xxx2_regs {
	volatile uint8_t ADCSTS;
	volatile uint8_t ADCCFG;
	volatile uint8_t ADCCTL;
	volatile uint8_t ADCGCR;
	volatile uint8_t VCH0CTL;
	volatile uint8_t KDCTL;
	volatile uint8_t reserved1[18];
	volatile uint8_t VCH0DATL;
	volatile uint8_t VCH0DATM;
	volatile uint8_t reserved2[42];
	volatile uint8_t ADCDVSTS;
};
#endif /* !__ASSEMBLER__ */

/* ADC conversion time select 1 */
#define IT8XXX2_ADC_ADCCTS1			BIT(7)
/* Analog accuracy initialization */
#define IT8XXX2_ADC_AINITB			BIT(3)
/* ADC conversion time select 0 */
#define IT8XXX2_ADC_ADCCTS0			BIT(5)
/* ADC module enable */
#define IT8XXX2_ADC_ADCEN			BIT(0)
/* ADC data buffer keep enable */
#define IT8XXX2_ADC_DBKEN			BIT(7)
/* W/C data valid flag */
#define IT8XXX2_ADC_DATVAL			BIT(7)
/* Data valid interrupt of adc */
#define IT8XXX2_ADC_INTDVEN			BIT(5)
/* Automatic hardware calibration enable */
#define IT8XXX2_ADC_AHCE			BIT(7)

/*
 * Clock and Power Management (ECPM)
 */
#define IT83XX_ECPM_BASE  0x00F01E00

#define IT83XX_ECPM_CGCTRL4R_OFF 0x09

#define CGC_OFFSET_SMBF		((IT83XX_ECPM_CGCTRL4R_OFF << 8) | 0x80)
#define CGC_OFFSET_SMBE		((IT83XX_ECPM_CGCTRL4R_OFF << 8) | 0x40)
#define CGC_OFFSET_SMBD		((IT83XX_ECPM_CGCTRL4R_OFF << 8) | 0x20)
#define CGC_OFFSET_SMBC		((IT83XX_ECPM_CGCTRL4R_OFF << 8) | 0x10)
#define CGC_OFFSET_SMBB		((IT83XX_ECPM_CGCTRL4R_OFF << 8) | 0x08)
#define CGC_OFFSET_SMBA		((IT83XX_ECPM_CGCTRL4R_OFF << 8) | 0x04)

/* TODO: rename IT83XX_ECPM_BASE to IT8XXX2_ECPM_BASE */
#define IT8XXX2_ECPM_PLLCTRL    ECREG(IT83XX_ECPM_BASE + 0x03)
#ifndef __ASSEMBLER__
enum chip_pll_mode {
	CHIP_PLL_DOZE = 0,
	CHIP_PLL_SLEEP = 1,
	CHIP_PLL_DEEP_DOZE = 3,
};
#endif
#define IT8XXX2_ECPM_AUTOCG     ECREG(IT83XX_ECPM_BASE + 0x04)
#define IT8XXX2_ECPM_CGCTRL3R   ECREG(IT83XX_ECPM_BASE + 0x05)
#define IT8XXX2_ECPM_PLLFREQR   ECREG(IT83XX_ECPM_BASE + 0x06)
#define IT8XXX2_ECPM_PLLCSS     ECREG(IT83XX_ECPM_BASE + 0x08)
#define IT8XXX2_ECPM_SCDCR0     ECREG(IT83XX_ECPM_BASE + 0x0c)
#define IT8XXX2_ECPM_SCDCR1     ECREG(IT83XX_ECPM_BASE + 0x0d)
#define IT8XXX2_ECPM_SCDCR2     ECREG(IT83XX_ECPM_BASE + 0x0e)
#define IT8XXX2_ECPM_SCDCR3     ECREG(IT83XX_ECPM_BASE + 0x0f)
#define IT8XXX2_ECPM_SCDCR4     ECREG(IT83XX_ECPM_BASE + 0x10)

/*
 * The count number of the counter for 25 ms register.
 * The 25 ms register is calculated by (count number *1.024 kHz).
 */

#define I2C_CLK_LOW_TIMEOUT		255 /* ~=249 ms */

/* SMBus/I2C Interface (SMB/I2C) */
#define IT83XX_SMB_BASE		0x00F01C00
#define IT83XX_SMB_4P7USL		ECREG(IT83XX_SMB_BASE+0x00)
#define IT83XX_SMB_4P0USL		ECREG(IT83XX_SMB_BASE+0x01)
#define IT83XX_SMB_300NS		ECREG(IT83XX_SMB_BASE+0x02)
#define IT83XX_SMB_250NS		ECREG(IT83XX_SMB_BASE+0x03)
#define IT83XX_SMB_25MS			ECREG(IT83XX_SMB_BASE+0x04)
#define IT83XX_SMB_45P3USL		ECREG(IT83XX_SMB_BASE+0x05)
#define IT83XX_SMB_45P3USH		ECREG(IT83XX_SMB_BASE+0x06)
#define IT83XX_SMB_4P7A4P0H		ECREG(IT83XX_SMB_BASE+0x07)
#define IT83XX_SMB_SLVISELR		ECREG(IT83XX_SMB_BASE+0x08)
#define IT83XX_SMB_SCLKTS(ch)	ECREG(IT83XX_SMB_BASE+0x09+ch)
#define IT83XX_SMB_CHSEF		ECREG(IT83XX_SMB_BASE+0x11)
#define IT83XX_SMB_CHSAB		ECREG(IT83XX_SMB_BASE+0x20)
#define IT83XX_SMB_CHSCD		ECREG(IT83XX_SMB_BASE+0x21)
#define IT83XX_SMB_HOSTA(base)	ECREG(base+0x00)
#define IT83XX_SMB_HOCTL(base)	ECREG(base+0x01)
#define IT83XX_SMB_HOCMD(base)	ECREG(base+0x02)
#define IT83XX_SMB_TRASLA(base)	ECREG(base+0x03)
#define IT83XX_SMB_D0REG(base)	ECREG(base+0x04)
#define IT83XX_SMB_D1REG(base)	ECREG(base+0x05)
#define IT83XX_SMB_HOBDB(base)	ECREG(base+0x06)
#define IT83XX_SMB_PECERC(base)	ECREG(base+0x07)
#define IT83XX_SMB_SMBPCTL(base)	ECREG(base+0x0A)
#define IT83XX_SMB_HOCTL2(base)	ECREG(base+0x10)

/**
 * Enhanced SMBus/I2C Interface
 * Ch_D: 0x00F03680, Ch_E: 0x00F03500, Ch_F: 0x00F03580
 * Ch_D: ch = 0x03, Ch_E: ch = 0x00, Ch_F: ch = 0x01
 */
#define IT83XX_I2C_DRR(base)		ECREG(base+0x00)
#define IT83XX_I2C_PSR(base)		ECREG(base+0x01)
#define IT83XX_I2C_HSPR(base)		ECREG(base+0x02)
#define IT83XX_I2C_STR(base)		ECREG(base+0x03)
#define IT83XX_I2C_DHTR(base)		ECREG(base+0x04)
#define IT83XX_I2C_TOR(base)		ECREG(base+0x05)
#define IT83XX_I2C_DTR(base)		ECREG(base+0x08)
#define IT83XX_I2C_CTR(base)		ECREG(base+0x09)
#define IT83XX_I2C_CTR1(base)		ECREG(base+0x0A)
#define IT83XX_I2C_BYTE_CNT_L(base)	ECREG(base+0x0C)
#define IT83XX_I2C_IRQ_ST(base)		ECREG(base+0x0D)
#define IT83XX_I2C_IDR(base)		ECREG(base+0x06)
#define IT83XX_I2C_TOS(base)		ECREG(base+0x07)
#define IT83XX_I2C_IDR2(base)		ECREG(base+0x1F)
#define IT83XX_I2C_RAMHA(base)		ECREG(base+0x23)
#define IT83XX_I2C_RAMLA(base)		ECREG(base+0x24)
#define IT83XX_I2C_RAMHA2(base)		ECREG(base+0x2B)
#define IT83XX_I2C_RAMLA2(base)		ECREG(base+0x2C)
#define IT83XX_I2C_CMD_ADDH(base)	ECREG(base+0x25)
#define IT83XX_I2C_CMD_ADDL(base)	ECREG(base+0x26)
#define IT83XX_I2C_RAMH2A(base)		ECREG(base+0x50)
#define IT83XX_I2C_CMD_ADDH2(base)	ECREG(base+0x52)

/* --- General Control (GCTRL) --- */
#define IT83XX_GCTRL_BASE 0x00F02000

#ifdef IT83XX_CHIP_ID_3BYTES
#define IT83XX_GCTRL_CHIPID1         ECREG(IT83XX_GCTRL_BASE + 0x85)
#define IT83XX_GCTRL_CHIPID2         ECREG(IT83XX_GCTRL_BASE + 0x86)
#define IT83XX_GCTRL_CHIPID3         ECREG(IT83XX_GCTRL_BASE + 0x87)
#else
#define IT83XX_GCTRL_CHIPID1         ECREG(IT83XX_GCTRL_BASE + 0x00)
#define IT83XX_GCTRL_CHIPID2         ECREG(IT83XX_GCTRL_BASE + 0x01)
#endif
#define IT83XX_GCTRL_CHIPVER         ECREG(IT83XX_GCTRL_BASE + 0x02)
#define IT83XX_GCTRL_DBGROS          ECREG(IT83XX_GCTRL_BASE + 0x03)
#define IT83XX_SMB_DBGR                    BIT(0)

/*
 * Writing 00h to this register and the CPU program counter will be paused
 * until the next low to high transition of the 65.536 clock.
 */
#define IT83XX_GCTRL_WNCKR           ECREG(IT83XX_GCTRL_BASE + 0x0B)
#define IT83XX_GCTRL_RSTS            ECREG(IT83XX_GCTRL_BASE + 0x06)
#define IT83XX_GCTRL_BADRSEL         ECREG(IT83XX_GCTRL_BASE + 0x0A)
#define IT83XX_GCTRL_SPCTRL1         ECREG(IT83XX_GCTRL_BASE + 0x0D)
#define IT83XX_GCTRL_RSTDMMC         ECREG(IT83XX_GCTRL_BASE + 0x10)
#define IT83XX_GCTRL_RSTC4           ECREG(IT83XX_GCTRL_BASE + 0x11)
#define IT83XX_GCTRL_SPCTRL4         ECREG(IT83XX_GCTRL_BASE + 0x1C)
#define IT83XX_GCTRL_MCCR3           ECREG(IT83XX_GCTRL_BASE + 0x20)
#define IT83XX_GCTRL_SPISLVPFE             BIT(6)
#define IT83XX_GCTRL_RSTC5           ECREG(IT83XX_GCTRL_BASE + 0x21)
#define IT83XX_GCTRL_MCCR            ECREG(IT83XX_GCTRL_BASE + 0x30)
#define IT83XX_GCTRL_ICACHE_RESET          BIT(4)
#define IT83XX_GCTRL_PMER1           ECREG(IT83XX_GCTRL_BASE + 0x32)
#define IT83XX_GCTRL_PMER2           ECREG(IT83XX_GCTRL_BASE + 0x33)
#define IT83XX_GCTRL_EPLR            ECREG(IT83XX_GCTRL_BASE + 0x37)
#define IT83XX_GCTRL_EPLR_ENABLE           BIT(0)
#define IT83XX_GCTRL_IVTBAR          ECREG(IT83XX_GCTRL_BASE + 0x41)
#define IT83XX_GCTRL_MCCR2           ECREG(IT83XX_GCTRL_BASE + 0x44)
#define IT83XX_GCTRL_PIN_MUX0        ECREG(IT83XX_GCTRL_BASE + 0x46)
#define IT83XX_DLM14_ENABLE                BIT(5)
#define IT83XX_GCTRL_SSCR            ECREG(IT83XX_GCTRL_BASE + 0x4A)
#define IT83XX_GCTRL_ETWDUARTCR      ECREG(IT83XX_GCTRL_BASE + 0x4B)
#define IT83XX_GCTRL_WMCR            ECREG(IT83XX_GCTRL_BASE + 0x4C)
#define IT83XX_GCTRL_H2ROFSR         ECREG(IT83XX_GCTRL_BASE + 0x53)
/* bit[0] = 0 or 1 : disable or enable ETWD hardware reset */
#define ETWD_HW_RST_EN                     BIT(0)
#define IT83XX_GCTRL_RVILMCR0        ECREG(IT83XX_GCTRL_BASE + 0x5D)
#define ILMCR_ILM0_ENABLE                  BIT(0)
#define ILMCR_ILM2_ENABLE                  BIT(2)
#define IT83XX_GCTRL_EWPR0PFH(i)     ECREG(IT83XX_GCTRL_BASE + 0x60 + i)
#define IT83XX_GCTRL_EWPR0PFD(i)     ECREG(IT83XX_GCTRL_BASE + 0xA0 + i)
#define IT83XX_GCTRL_EWPR0PFEC(i)    ECREG(IT83XX_GCTRL_BASE + 0xC0 + i)

/* Serial Peripheral Interface (SPI) */
#define IT83XX_SPI_BASE  0x00F03A00

#define IT83XX_SPI_SPISGCR           ECREG(IT83XX_SPI_BASE + 0x00)
#define IT83XX_SPI_SPISCEN                 BIT(0)
#define IT83XX_SPI_TXRXFAR           ECREG(IT83XX_SPI_BASE + 0x01)
#define IT83XX_SPI_CPURXF2A                BIT(4)
#define IT83XX_SPI_CPURXF1A                BIT(3)
#define IT83XX_SPI_CPUTFA                  BIT(1)
#define IT83XX_SPI_TXFCR             ECREG(IT83XX_SPI_BASE + 0x02)
#define IT83XX_SPI_TXFCMR                  BIT(2)
#define IT83XX_SPI_TXFR                    BIT(1)
#define IT83XX_SPI_TXFS                    BIT(0)
#define IT83XX_SPI_GCR2              ECREG(IT83XX_SPI_BASE + 0x03)
#define IT83XX_SPI_RXF2OC                  BIT(4)
#define IT83XX_SPI_RXF1OC                  BIT(3)
#define IT83XX_SPI_RXFAR                   BIT(0)
#define IT83XX_SPI_IMR               ECREG(IT83XX_SPI_BASE + 0x04)
#define IT83XX_SPI_RX_FIFO_FULL            BIT(7)
#define IT83XX_SPI_RX_REACH                BIT(5)
#define IT83XX_SPI_EDIM                    BIT(2)
#define IT83XX_SPI_ISR               ECREG(IT83XX_SPI_BASE + 0x05)
#define IT83XX_SPI_TXFSR             ECREG(IT83XX_SPI_BASE + 0x06)
#define IT83XX_SPI_ENDDETECTINT            BIT(2)
#define IT83XX_SPI_RXFSR             ECREG(IT83XX_SPI_BASE + 0x07)
#define IT83XX_SPI_RXFFSM                  (BIT(4) | BIT(3))
#define IT83XX_SPI_RXF2FS                  BIT(2)
#define IT83XX_SPI_RXF1FS                  BIT(1)
#ifdef CHIP_VARIANT_IT83202BX
#define IT83XX_SPI_SPISRDR           ECREG(IT83XX_SPI_BASE + 0x08)
#else
#define IT83XX_SPI_SPISRDR           ECREG(IT83XX_SPI_BASE + 0x0b)
#endif
#define IT83XX_SPI_CPUWTFDB0         ECREG_u32(IT83XX_SPI_BASE + 0x08)
#define IT83XX_SPI_FCR               ECREG(IT83XX_SPI_BASE + 0x09)
#define IT83XX_SPI_SPISRTXF                BIT(2)
#define IT83XX_SPI_RXFR                    BIT(1)
#define IT83XX_SPI_RXFCMR                  BIT(0)
#define IT83XX_SPI_RXFRDRB0          ECREG_u32(IT83XX_SPI_BASE + 0x0C)
#define IT83XX_SPI_FTCB0R            ECREG(IT83XX_SPI_BASE + 0x18)
#define IT83XX_SPI_FTCB1R            ECREG(IT83XX_SPI_BASE + 0x19)
#define IT83XX_SPI_TCCB0             ECREG(IT83XX_SPI_BASE + 0x1A)
#define IT83XX_SPI_TCCB1             ECREG(IT83XX_SPI_BASE + 0x1B)
#define IT83XX_SPI_HPR2              ECREG(IT83XX_SPI_BASE + 0x1E)
#define IT83XX_SPI_EMMCBMR           ECREG(IT83XX_SPI_BASE + 0x21)
#define IT83XX_SPI_EMMCABM                 BIT(1) /* eMMC Alternative Boot Mode */
#define IT83XX_SPI_RX_VLISMR         ECREG(IT83XX_SPI_BASE + 0x26)
#define IT83XX_SPI_RVLIM                   BIT(0)
#define IT83XX_SPI_RX_VLISR          ECREG(IT83XX_SPI_BASE + 0x27)
#define IT83XX_SPI_RVLI                    BIT(0)

#endif /* CHIP_CHIPREGS_H */
