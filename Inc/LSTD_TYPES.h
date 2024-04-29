/*******************************************/
/* SWC: STANDARD TYPES                     */
/* Author: Mohamed Sobh                    */
/* Version: v0.0                           */
/* Date: 04 AUG 2023                       */
/* Description: This is the implem. of STD */
/*******************************************/
/* Header Guard File */
#ifndef _LSTD_TYPES_H_
#define _LSTD_TYPES_H_

typedef unsigned char 	    u8;
typedef unsigned short		u16;
typedef unsigned int	    u32;
typedef  double             u64;

typedef signed char 		s8;
typedef signed short		s16;
typedef signed int			s32;

typedef  float 			    f32;

typedef enum {
	false = 0,
	true = 1
} bool;

#define NULL                (void *)0

#endif /* _LSTD_TYPES_H_ */
