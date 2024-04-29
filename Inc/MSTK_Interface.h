/********************************************/
/* SWC: STK Driver                          */
/* Author: Mohamed Sobh                     */
/* Version: v0.0                            */
/* Date: 12 AUG 2023                        */
/* Description: This is the implem. of STK  */
/********************************************/
/* File Guard */
#ifndef _MSTK_INTERFACE_H_
#define _MSTK_INTERFACE_H_

void MSTK_voidInit(void);
void MSTK_voidDisable(void);
void MSTK_voidBusyWait(u32 Copy_u32Ticks);
void MSTK_voidSingleInterval(u32 Copy_u32Ticks, void (*LpF)(void));
void MSTK_voidPeriodicInterval(u32 Copy_u32Ticks, void (*LpF)(void));
u32 MSTK_u32GetElapsedTime(void);
u32 MSTK_u32GetRemainingTime(void);

#endif /* _MSTK_INTERFACE_H_ */
