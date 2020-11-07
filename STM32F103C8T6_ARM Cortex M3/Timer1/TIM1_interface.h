/*******************************************************************************/
/* Author : AbdElrahman I.Zaki                                                 */
/* Date   : 03 September 2020                                                  */
/* Version: V01                                                                */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 Timer1 Prototypes of Public Functions  */
/*******************************************************************************/


#ifndef _TIM1_INTERFACE_H_
#define _TIM1_INTERFACE_H_

/* Timer1 Initialization Function */
void MTIM1_voidInit(void);

/* Enable Timer1 */
void MTIM1_voidEnableTimer1(void);

/* Disable Timer1 */
void MTIM1_voidDisableTimer1(void);


void MTIM1_voidLoadOPCCR(u16 Copy_u16Value);

#endif 
