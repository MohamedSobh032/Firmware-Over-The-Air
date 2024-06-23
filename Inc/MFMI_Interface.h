/******************************************************/
/* SWC: FMI Driver                                    */
/* Author: Mohamed Sobh                               */
/* Version: v2.0                                      */
/* Date: 02 APR 2024                                  */
/* Description: This is the implem. of FMI            */
/******************************************************/
/* Header File Guard */
#ifndef _MFMI_INTERFACE_H_
#define _MFMI_INTERFACE_H_

typedef enum {
	MFMI_SECTOR_ZERO  = 0,
	MFMI_SECTOR_ONE   = 1,
	MFMI_SECTOR_TWO   = 2,
	MFMI_SECTOR_THREE = 3,
	MFMI_SECTOR_FOUR  = 4,
	MFMI_SECTOR_FIVE  = 5,
	MFMI_SECTOR_SIX   = 6,
	MFMI_SECTOR_SEVEN = 7,
	MFMI_FALSE_SECTOR = 10
} MFMI_SectorNumber;

void MFMI_vInit(void);
MFMI_SectorNumber MFMI_getSectorNumber(u32 Copy_u32Address);
void MFMI_vSectorErase(u8 Copy_u8SectorNumber);
void MFMI_vProgram(u32 Copy_u32Address, u16* Copy_u16DataToBeWritten, u16 Copy_u16Length);

#endif /* _MFMI_INTERFACE_H_ */
