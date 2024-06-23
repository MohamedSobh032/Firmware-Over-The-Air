#ifndef MAIN_H_
#define MAIN_H_

/************************************** ESP8266 SETTINGS **************************************/
/****************** HW SETTINGS ******************/
/* Used USART in the Bootloader */
#define ESP8266_USART			USART1
/* RESET PIN */
#define ESP8266_RESET_PIN		GPIOA, MGPIO_PIN00
/* USART PERIPHERAL CLOCK */
#define ESP8266_PERI_CLOCK		MRCC_BUS_APB2, MRCC_APB2_USART1EN
/* USART PINS */
#define ESP8266_USART_TX		GPIOA, MGPIO_PIN09
#define ESP8266_USART_RX		GPIOA, MGPIO_PIN10
/* USART PINS ALTERNATE DIRECTION */
#define ESP8266_USART_TX_AF		MGPIO_AF07
#define ESP8266_USART_RX_AF		MGPIO_AF07
/* INITIALIZATION */
#define ESP8266_USART_INIT_STRUCTURE	{115200, MUSART_DATAWIDTH_8BIT, \
										MUSART_STOP_ONE_BIT, MUSART_DISABLE, \
										MUSART_PARITY_EVEN, MUSART_DIRECTION_TX_RX, \
										MUSART_DISABLE, MUSART_OVER_SAMPLING_16}
/*************************************************/
/****************** SW SETTINGS ******************/
/* RESET DELAY */
#define ESP8266_RESET_DELAY		1000
/* THRESHOLD OF READING */
#define BOOT_THRESHOLD_VALUE	0x0F
/*************************************************/
/**********************************************************************************************/

/* Sectors That Will be Taken From the Flash Starting From Sector 1 */
#define _SECTORS_TO_BE_ERASED_		3


#endif /* MAIN_H_ */
