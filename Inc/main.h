/*
 * main.h
 *
 *  Created on: Jun 22, 2024
 *      Author: Mohamed
 */

#ifndef MAIN_H_
#define MAIN_H_

/* Reset Pin */
#define ESP8266_RESET_PIN			GPIOA, MGPIO_PIN00
/* THRESHOLD OF THE READING */
#define BOOT_THRESHOLD_VALUE		0x0F
/* Sectors That Will be Taken From the Flash Starting From Sector 1 */
#define _SECTORS_TO_BE_ERASED_		3
/* Used USART in the Bootloader */
#define BOOT_USART					USART1

#endif /* MAIN_H_ */
