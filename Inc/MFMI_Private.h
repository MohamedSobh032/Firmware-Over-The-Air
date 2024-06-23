/******************************************************/
/* SWC: FMI Driver                                    */
/* Author: Mohamed Sobh                               */
/* Version: v2.0                                      */
/* Date: 02 APR 2024                                  */
/* Description: This is the implem. of FMI            */
/******************************************************/
/* Header File Guard */
#ifndef _MFMI_PRIVATE_H_
#define _MFMI_PRIVATE_H_

typedef struct {
	volatile u32 ACR;
	volatile u32 KEYR;
	volatile u32 OPTKEYR;
	volatile u32 SR;
	volatile u32 CR;
	volatile u32 OPTCR;
}FMI_t;

#define FMI		((FMI_t*) 0x40023C00)

/**********************************************/
/*          Enumerator for Addresses          */
/**********************************************/
typedef enum {
	MFMI_SECTOR_ZERO_ADDRESS  = 0x08000000,
	MFMI_SECTOR_ONE_ADDRESS   = 0x08004000,
	MFMI_SECTOR_TWO_ADDRESS   = 0x08008000,
	MFMI_SECTOR_THREE_ADDRESS = 0x0800C000,
	MFMI_SECTOR_FOUR_ADDRESS  = 0x08010000,
	MFMI_SECTOR_FIVE_ADDRESS  = 0x08020000,
	MFMI_SECTOR_SIX_ADDRESS   = 0x08040000,
	MFMI_SECTOR_SEVEN_ADDRESS = 0x08060000
} MFMI_SECTOR_ADDRESS;

/**********************************************/
/*     Private Functions for Flash Driver     */
/**********************************************/
static void Private_vFlashLock(void);
static void Private_vFlashUnlock(void);

/**********************************************/
/* 				KEYR KEY Values 			  */
/**********************************************/
/* KEY1 Value */
#define MFMI_KEYR_KEY1		0x45670123
/* KEY2 Value */
#define MFMI_KEYR_KEY2		0xCDEF89AB

/**********************************************/
/*                PSIZE Values                */
/**********************************************/
/* PROGRAM x08 */
#define MFMI_PROGRAM_SIZE_08		0b00
/* PROGRAM x16 */
#define MFMI_PROGRAM_SIZE_16		0b01
/* PROGRAM x32 */
#define MFMI_PROGRAM_SIZE_32		0b10
/* PROGRAM x64 */
#define MFMI_PROGRAM_SIZE_64		0b11

/**********************************************/
/* 				SR BITS Mapping 			  */
/**********************************************/
/* End Of Operation Flag */
#define MFMI_SR_EOP_BIT		0
/* Busy Flag */
#define MFMI_SR_BSY_BIT		16

/**********************************************/
/* 				CR BITS Mapping 			  */
/**********************************************/
/* Programming Flag */
#define MFMI_CR_PG_BIT		0
/* Sector Erase Flag */
#define MFMI_CR_SER_BIT		1
/* Sector Number Bit */
#define MFMI_CR_SNB_BIT		3
/* Program Size Bit */
#define MFMI_CR_PSIZE_BIT	8
/* Start Flag */
#define MFMI_CR_STRT_BIT	16
/* LOCK Flag */
#define MFMI_CR_LOCK_BIT	31

#endif /* _MFMI_PRIVATE_H_ */
