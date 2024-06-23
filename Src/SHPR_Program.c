/******************************************************/
/* SWC: HPR Driver                                    */
/* Author: Mohamed Sobh                               */
/* Version: v1.0                                      */
/* Date: 02 APR 2024                                  */
/* Description: This is the implem. of HPR            */
/******************************************************/
#include "stdlib.h"
#include "LBIT_MATH.h"
#include "LSTD_TYPES.h"
#include "MFMI_Interface.h"

u32 Global_u32BaseAddress = 0;

static u8 Private_u8ASCII2Hex(u8 Copy_u8ASCII)
{
	if (Copy_u8ASCII >= '0' && Copy_u8ASCII <= '9') { return Copy_u8ASCII - '0'; }
	else if (Copy_u8ASCII >= 'A' && Copy_u8ASCII <= 'F') { return Copy_u8ASCII - 55; }
	return 0;
}

u32 SHPR_u32ParseAddress(u8* Copy_u8Address) {
	return ((u32)(Private_u8ASCII2Hex(Copy_u8Address[0]) << 28)
		  | (u32)(Private_u8ASCII2Hex(Copy_u8Address[1]) << 24)
		  | (u32)(Private_u8ASCII2Hex(Copy_u8Address[2]) << 20)
		  | (u32)(Private_u8ASCII2Hex(Copy_u8Address[3]) << 16)
		  | (u32)(Private_u8ASCII2Hex(Copy_u8Address[4]) << 12)
		  | (u32)(Private_u8ASCII2Hex(Copy_u8Address[5]) << 8)
		  | (u32)(Private_u8ASCII2Hex(Copy_u8Address[6]) << 4)
		  | (u32)(Private_u8ASCII2Hex(Copy_u8Address[7]) << 0));
}

u8 SHPR_u8GetRecordLength(u8* Copy_u8DataRecord) {
	/* Get the Length of the Record [1][2] */
	return (Private_u8ASCII2Hex(Copy_u8DataRecord[1]) << 4) + Private_u8ASCII2Hex(Copy_u8DataRecord[2]);
}

void SHPR_vParseHexRecord(u8* Copy_u8DataRecord) {
	/* If Start Record, Set the Base Address */
	if (Copy_u8DataRecord[8] == '4') {
		Global_u32BaseAddress = (u32)( ((u32)(Private_u8ASCII2Hex(Copy_u8DataRecord[9])  << 28))
									 | ((u32)(Private_u8ASCII2Hex(Copy_u8DataRecord[10]) << 24))
									 | ((u32)(Private_u8ASCII2Hex(Copy_u8DataRecord[11]) << 20))
									 | ((u32)(Private_u8ASCII2Hex(Copy_u8DataRecord[12]) << 16)) );
	}
	else if (Copy_u8DataRecord[8] == '0') {
		/* Get the Length of the Record [1][2] */
		u8 Local_u8Length = (Private_u8ASCII2Hex(Copy_u8DataRecord[1]) << 4) + Private_u8ASCII2Hex(Copy_u8DataRecord[2]);
		/* Get the Offset Address [3][4][5][6] */
		u16 Local_u16OffsetAddress = (u16)( ((u16)(Private_u8ASCII2Hex(Copy_u8DataRecord[3])<<12))
				 	 	 	 	 	 	  | ((u16)(Private_u8ASCII2Hex(Copy_u8DataRecord[4])<< 8))
										  | ((u16)(Private_u8ASCII2Hex(Copy_u8DataRecord[5])<< 4))
										  | ((u16)(Private_u8ASCII2Hex(Copy_u8DataRecord[6])<< 0)) );
		/* Get The Address Location */
		u32 Local_u32Addresss = Global_u32BaseAddress + (u32)(Local_u16OffsetAddress);
		u8 Local_u8Counter = 0;
		u16* Local_u16Data = (u16*)malloc(sizeof(u16) * (Local_u8Length / 2));
		//u16 Local_u16Data[Local_u8Length/2];
		for (; Local_u8Counter < Local_u8Length / 2; Local_u8Counter++)
		{
			Local_u16Data[Local_u8Counter] = (u16)(((u16)(Private_u8ASCII2Hex(Copy_u8DataRecord[(4*Local_u8Counter)+9])<<4))
					 	 	 	 	 	 	     | ((u16)(Private_u8ASCII2Hex(Copy_u8DataRecord[(4*Local_u8Counter)+10])<<0))
												 | ((u16)(Private_u8ASCII2Hex(Copy_u8DataRecord[(4*Local_u8Counter)+11])<<12))
												 | ((u16)(Private_u8ASCII2Hex(Copy_u8DataRecord[(4*Local_u8Counter)+12])<<8)));
		}
		MFMI_vProgram(Local_u32Addresss, (u16*)Local_u16Data, Local_u8Length/2);
	}
}
