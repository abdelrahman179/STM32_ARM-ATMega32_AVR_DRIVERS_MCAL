/****************************************************************************************/
/* Author : AbdElrahman I.Zaki                                                          */
/* Date   : 19 September 2020                                                           */
/* Version: V02                                                                         */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 USART Communication Protocol private            */
/*              functions prototype and registers definition                            */
/****************************************************************************************/


#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H



typedef struct 
{
    volatile u32 USART_SR;      /* Status Register */
    volatile u32 USART_DR;      /* Data Register */
    volatile u32 USART_BRR;     /* Baud Rate Register */
    volatile u32 USART_CR1;     /* Control Register 1 */
    volatile u32 USART_CR2;     /* Control Register 2 */
    volatile u32 USART_CR3;     /* Control Register 3 */
    volatile u32 USART_GRPR;    /* Guard Time and Prescaler Register */
}USART_Type;


#define USART1_Ptr  ((volatile USART_Type*) 0x40013800)






#endif
