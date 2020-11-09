/*******************************************************************************/
/* Author : AbdElrahman I.Zaki                                                 */
/* Date   : 17 August 2020                                                     */
/* Version: V01                                                                */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 AFIO Prototype of public functions     */
/*******************************************************************************/

#ifndef _AFIO_INTERFACE_H
#define _AFIO_INTERFACE_H


#define EXTI0  0
#define EXTI1  1
#define EXTI2  2
#define EXTI3  3

#define EXTI4  4
#define EXTI5  5
#define EXTI6  6
#define EXTI7  7

#define EXTI8  8
#define EXTI9  9
#define EXTI10 10
#define EXTI11 11

#define EXTI12 12
#define EXTI13 13
#define EXTI14 14
#define EXTI15 15

/* 
  * AFIO_voidSelectPortForLine - > Assign the line for specific port 
  * i/p : (u8) line number 0:15  / (u8) Port id 0:6
*/
void AFIO_voidSetEXTIConfiguration(u8 Copy_u8EXTI_Line ,u8 Copy_u8PortMap );


#endif
