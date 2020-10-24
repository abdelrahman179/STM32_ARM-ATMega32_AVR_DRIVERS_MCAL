/*******************************************************************************/
/* Author : AbdElrahman I.Zaki                                                 */
/* Date   : 21 August 2020                                                     */
/* Version: V01                                                                */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 EXT Int Prototypes of Public Functions */
/*******************************************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/* EXTI0 line 0 equivalent A0 , B0 , C0 
.
.
.
   EXTI15 line 15 equivalent A15 , B15 , C15 
   AFIO_EXTICR1_Register controls which pin enabled */
// line and mode will be checked through the #define 
void MEXTI_voidInit(void);

/* Sense mode : - Rising edge
                - Falling edge   
                - Any logical change  in ARM we have 6 modes 
                  using #define, sense mode cannot be changed during run-time 
                  So, we will use the below function*/
void MEXTI_voidSetSignalLatch(u8 Copy_u8EXTILine , u8 Copy_u8EXTISenseMode);

/* Enable the EXTI */
void MEXTI_voidEnableEXTI(u8 Copy_u8Line);

/* Disable the EXTI */
void MEXTI_voidDisableEXTI(u8 Copy_u8Line);

/* Set a swoftware trigger */
void MEXTI_voidSoftwareTrigger(u8 Copy_u8Line);

/* This function is being called in main.c to hold an address of another function that have the ISR written by user */
void MEXTI_voidSetCallBack(void (*ptr) (void));


#endif
