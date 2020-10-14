/*******************************************************************************/
/* Author : AbdElrahman I.Zaki                                                 */
/* Date   : 19 August 2020                                                     */
/* Version: V01                                                                */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 NVIC Prototypes of Public Functions    */
/*******************************************************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/* Function that enables external interrupts from 0 to 59  */
void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNum);

/* Function that disables external interrupts from 0 to 59  */
void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNum);

/* Function that enables the pending flag for debugging  */
void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNum); 

/* Function that disables the pending flag for debugging  */
void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNum);

/* Function that reads the interrupt activity status flag  */
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNum)




#endif 
