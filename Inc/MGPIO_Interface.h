/**********************************************/
/* SWC: GPIO Driver                           */
/* Author: Mohamed Sobh                       */
/* Version: v0.0                              */
/* Date: 11 AUG 2023                          */
/* Description: This is the implem. of GPIO   */
/**********************************************/
/* File Guard */
#ifndef _MGPIO_INTERFACE_H_
#define _MGPIO_INTERFACE_H_

typedef struct {
    volatile u32 MODER;
    volatile u32 OTYPER;
    volatile u32 OSPEEDR;
    volatile u32 PUPDR;
    volatile u32 IDR;
    volatile u32 ODR;
    volatile u32 BSRR;
    volatile u32 LCKR;
    volatile u32 AFRL;
    volatile u32 AFRH;
} GPIO_t;


/* GPIOA Base Address is 0x40020000 */
#define GPIOA       ((GPIO_t*)0x40020000)
/* GPIOB Base Address is 0x40020400 */
#define GPIOB       ((GPIO_t*)0x40020400)
/* GPIOC Base Address is 0x40020800 */
#define GPIOC       ((GPIO_t*)0x40020800)


/**********************************************/
/*                  GPIO Pins                 */
/**********************************************/
typedef enum {
	MGPIO_PIN00 = 0,
	MGPIO_PIN01 = 1,
	MGPIO_PIN02 = 2,
	MGPIO_PIN03 = 3,
	MGPIO_PIN04 = 4,
	MGPIO_PIN05 = 5,
	MGPIO_PIN06 = 6,
	MGPIO_PIN07 = 7,
	MGPIO_PIN08 = 8,
	MGPIO_PIN09 = 9,
	MGPIO_PIN10 = 10,
	MGPIO_PIN11 = 11,
	MGPIO_PIN12 = 12,
	MGPIO_PIN13 = 13,
	MGPIO_PIN14 = 14,
	MGPIO_PIN15 = 15
} MGPIO_PIN;

/**********************************************/
/*        GPIO Pins Alternate Direction       */
/**********************************************/
typedef enum {
	MGPIO_AF00 = 0,
	MGPIO_AF01 = 1,
	MGPIO_AF02 = 2,
	MGPIO_AF03 = 3,
	MGPIO_AF04 = 4,
	MGPIO_AF05 = 5,
	MGPIO_AF06 = 6,
	MGPIO_AF07 = 7,
	MGPIO_AF08 = 8,
	MGPIO_AF09 = 9,
	MGPIO_AF10 = 10,
	MGPIO_AF11 = 11,
	MGPIO_AF12 = 12,
	MGPIO_AF13 = 13,
	MGPIO_AF14 = 14,
	MGPIO_AF15 = 15,
} MGPIO_AF;

void MGPIO_voidSetPinMode        (GPIO_t* GPIOx, MGPIO_PIN Copy_GPIOPin, u8 Copy_u8Mode);
void MGPIO_voidSetPinOutputType  (GPIO_t* GPIOx, MGPIO_PIN Copy_GPIOPin, u8 Copy_u8OType);
void MGPIO_voidSetPinOutputSpeed (GPIO_t* GPIOx, MGPIO_PIN Copy_GPIOPin, u8 Copy_u8Speed);
void MGPIO_voidSetPinInputType   (GPIO_t* GPIOx, MGPIO_PIN Copy_GPIOPin, u8 Copy_u8IType);
void MGPIO_voidSetPinAFDirection (GPIO_t* GPIOx, MGPIO_PIN Copy_GPIOPin, MGPIO_AF Copy_GPIOAFDir);
void MGPIO_voidSetPinValue       (GPIO_t* GPIOx, MGPIO_PIN Copy_GPIOPin, u8 Copy_u8Value);
void MGPIO_voidSetPartValue      (GPIO_t* GPIOx, u16 Copy_u16Data, BIT_SIZE Copy_BITSize, MGPIO_PIN Copy_GPIOPinStart);
void MGPIO_voidSetPinDirectAccess(GPIO_t* GPIOx, MGPIO_PIN Copy_GPIOPin, u8 Copy_u8Value);
void MGPIO_voidTogglePinValue    (GPIO_t* GPIOx, MGPIO_PIN Copy_GPIOPin);
u8 MGPIO_u8GetPinValue           (GPIO_t* GPIOx, MGPIO_PIN Copy_GPIOPin);

/**********************************************/
/*               GPIO Pin Modes               */
/**********************************************/
#define MGPIO_MODE_INPUT			0b00
#define MGPIO_MODE_OUTPUT			0b01
#define MGPIO_MODE_ALTERNATE		0b10
#define MGPIO_MODE_ANALOG			0b11

/**********************************************/
/*              GPIO Output Types             */
/**********************************************/
#define MGPIO_OUTPUT_TYPE_PP		0b0
#define MGPIO_OUTPUT_TYPE_OD		0b1

/**********************************************/
/*               GPIO Pin Speed               */
/**********************************************/
#define MGPIO_LOW_SPEED				0b00
#define MGPIO_MEDIUM_SPEED			0b01
#define MGPIO_HIGH_SPEED			0b10
#define MGPIO_VHIGH_SPEED			0b11

/**********************************************/
/*              GPIO Input Types              */
/**********************************************/
#define MGPIO_INPUT_TYPE_FLOATING	0b00
#define MGPIO_INPUT_TYPE_PULLUP		0b01
#define MGPIO_INPUT_TYPE_PULLDOWN	0b10

/**********************************************/
/*               GPIO Pin Value               */
/**********************************************/
#define MGPIO_OUTPUT_LOW			0b0
#define MGPIO_OUTPUT_HIGH			0b1

/**********************************************/
/*        GPIO Pin Value Direct Access        */
/**********************************************/
#define MGPIO_OUTPUT_DIRECT_SET		0
#define MGPIO_OUTPUT_DIRECT_RST		16

#endif /* _MGPIO_INTERFACE_H_ */
