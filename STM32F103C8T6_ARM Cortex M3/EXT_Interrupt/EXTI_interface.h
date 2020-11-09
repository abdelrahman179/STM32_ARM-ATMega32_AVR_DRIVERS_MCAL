/*******************************************************************************/
/* Author : AbdElrahman I.Zaki                                                 */
/* Date   : 21 August 2020                                                     */
/* Version: V01                                                                */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 EXT Int Prototypes of Public Functions */
/*******************************************************************************/

#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_

/* EXTI16 -> PVD , EXTI17 -> RTC , EXTI18 -> USB , EXTI19 -> Ethernet wakeup */
/* Line0 = GPIOA0 GPIOB0 GPIOC0 and so on */
#define LINE0       0
#define LINE1       1
#define LINE2       2
#define LINE3       3
#define LINE4       4
#define LINE5       5
#define LINE6       6
#define LINE7       7
#define LINE8       8
#define LINE9       9
#define LINE10      10
#define LINE11      11
#define LINE12      12
#define LINE13      13
#define LINE14      14
#define LINE15      15


#define RISING_EDGE         0
#define FALLING_EDGE        1
#define ON_CHANGE           2

/* EXTI0 line 0 equivalent A0 , B0 , C0 
.
.
.
   EXTI15 line 15 equivalent A15 , B15 , C15 
   AFIO_EXTICR1_Register controls which pin enabled */ 

/* Sense mode : - Rising edge
                - Falling edge   
                - Any logical change  in ARM we have 6 modes 
                  using #define, sense mode cannot be changed during run-time 
                  So, we will use the below function*/
void MEXTI_voidInit(u8 Copy_u8EXILine, u8 Copy_u8EXIMode);


/* Enable the EXTI */
void MEXTI_voidEnableEXTI(u8 Copy_u8EXTILine);

/* Disable the EXTI */
void MEXTI_voidDisableEXTI(u8 Copy_u8EXTILine);

/* Set a swoftware trigger */
void MEXTI_voidSoftwareTrigger(u8 Copy_u8EXTILine);

/* This function is being called in main.c to hold an address of another function that have the ISR written by user */
void MEXTI_voidSetCallBack(void (*ptr) (void), u8 Copy_u8EXTILine);


#endif
