/****************************************************************************/
/* Author : AbdElrahman I.Zaki                                              */
/* Date   : 8 August 2020                                                   */
/* Version: V01                                                             */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 RCC Prototypes of Public Functions  */
/****************************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB  0
#define RCC_APB1 1
#define RCC_APB2 2

/* A function that intitialize the system clock */ 
void RCC_voidInitSysClock(void);

/* A function that enables the system clock */ 
void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);

/* A function that disables the system clock */ 
void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);


#endif
