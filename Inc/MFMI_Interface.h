/********************************************/
/* SWC: FMI Driver                          */
/* Author: Mohamed Sobh                     */
/* Version: v0.0                            */
/* Date: 18 JAN 2024                        */
/* Description: This is the implem. of FMI  */
/********************************************/
/* File Guard */
#ifndef _MFMI_INTERFACE_H_
#define _MFMI_INTERFACE_H_

void MFMI_voidInit(void);
void MFMI_voidSectorErase(u8 Copy_u8SectorNumber);
void MFMI_voidProgram(u32 Copy_u32Address, u16* Copy_u16DataToBeWritten, u16 Copy_u16Length);

typedef enum {
	MFMI_SECTOR_ZERO  = 0,
	MFMI_SECTOR_ONE   = 1,
	MFMI_SECTOR_TWO   = 2,
	MFMI_SECTOR_THREE = 3,
	MFMI_SECTOR_FOUR  = 4,
	MFMI_SECTOR_FIVE  = 5,
	MFMI_SECTOR_SIX   = 6,
	MFMI_SECTOR_SEVEN = 7
} MFMI_SectorNumbers;

#endif /* _MFMI_INTERFACE_H_ */
