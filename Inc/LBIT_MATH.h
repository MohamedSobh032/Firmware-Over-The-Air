/************************************************/
/* SWC: BIT MATH                                */
/* Author: Mohamed Sobh                         */
/* Version: v0.0                                */
/* Date: 04 AUG 2023                            */
/* Description: This is the implem. of BIT MATH */
/************************************************/
/* Header Guard File */
#ifndef _LBIT_MATH_H_
#define _LBIT_MATH_H_


#define SET_BIT(REG_NAME, BIT_NUM)				      			REG_NAME = REG_NAME | (1 << BIT_NUM)
#define CLR_BIT(REG_NAME, BIT_NUM)      			  			REG_NAME = REG_NAME & (~(1 << BIT_NUM))
#define TOG_BIT(REG_NAME, BIT_NUM)      			  			REG_NAME = REG_NAME ^ (1 << BIT_NUM)
#define GET_BIT(REG_NAME, BIT_NUM)      			  			((REG_NAME >> BIT_NUM) & 1)
#define WRT_BIT(REG_NAME, BIT_NUM, BIT_VALUE)					(BIT_VALUE == 1) ? SET_BIT(REG_NAME, BIT_NUM) : CLR_BIT(REG_NAME, BIT_NUM)
#define WRITE_BITS(REG_NAME, VALUE, NUM_OF_BITS, START_BIT) 	REG_NAME = ((u32)(VALUE << START_BIT)) | (REG_NAME & (~((u32)(NUM_OF_BITS << START_BIT))))

typedef enum {
	ONE_BIT    = 0x0001,
	TWO_BITS   = 0x0003,
	THREE_BITS = 0x0007,
	FOUR_BITS  = 0x000F,
	FIVE_BITS  = 0x001F,
	SIX_BITS   = 0x003F,
	SEVEN_BTIS = 0x007F,
	EIGHT_BITS = 0x00FF,
	NINE_BITS  = 0x01FF
} BIT_SIZE;

#endif /* _LBIT_MATH_H_ */
