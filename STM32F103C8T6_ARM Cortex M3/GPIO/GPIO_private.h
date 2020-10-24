/****************************************************************************************/
/* Author : AbdElrahman I.Zaki                                                          */
/* Date   : 10 August 2020                                                              */
/* Version: V01                                                                         */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 GPIO Register addresses and private functions   */
/****************************************************************************************/

#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

/* GPIO Ports Base Addresses */
#define GPIOA_BASE_ADDRESS      0x40010800
#define GPIOB_BASE_ADDRESS      0x40010C00
#define GPIOC_BASE_ADDRESS      0x40011000

/* GPIO PORTA Registers Addresses "Base-address + Offset" */
#define GPIOA_CRL       *((volatile u32 *)(GPIOA_BASE_ADDRESS + 0x00))
#define GPIOA_CRH       *((volatile u32 *)(GPIOA_BASE_ADDRESS + 0x04))
#define GPIOA_IDR       *((volatile u32 *)(GPIOA_BASE_ADDRESS + 0x08))
#define GPIOA_ODR       *((volatile u32 *)(GPIOA_BASE_ADDRESS + 0x0C))
#define GPIOA_BSR       *((volatile u32 *)(GPIOA_BASE_ADDRESS + 0x10))
#define GPIOA_BRR       *((volatile u32 *)(GPIOA_BASE_ADDRESS + 0x14))
#define GPIOA_LCK       *((volatile u32 *)(GPIOA_BASE_ADDRESS + 0x18))

/* GPIO PORTB Registers Addresses "Base-address + Offset" */
#define GPIOB_CRL       *((volatile u32 *)(GPIOB_BASE_ADDRESS + 0x00))
#define GPIOB_CRH       *((volatile u32 *)(GPIOB_BASE_ADDRESS + 0x04))
#define GPIOB_IDR       *((volatile u32 *)(GPIOB_BASE_ADDRESS + 0x08))
#define GPIOB_ODR       *((volatile u32 *)(GPIOB_BASE_ADDRESS + 0x0C))
#define GPIOB_BSR       *((volatile u32 *)(GPIOB_BASE_ADDRESS + 0x10))
#define GPIOB_BRR       *((volatile u32 *)(GPIOB_BASE_ADDRESS + 0x14))
#define GPIOB_LCK       *((volatile u32 *)(GPIOB_BASE_ADDRESS + 0x18))

/* GPIO PORTC Registers Addresses "Base-address + Offset" */
#define GPIOC_CRL       *((volatile u32 *)(GPIOC_BASE_ADDRESS + 0x00))
#define GPIOC_CRH       *((volatile u32 *)(GPIOC_BASE_ADDRESS + 0x04))
#define GPIOC_IDR       *((volatile u32 *)(GPIOC_BASE_ADDRESS + 0x08))
#define GPIOC_ODR       *((volatile u32 *)(GPIOC_BASE_ADDRESS + 0x0C))
#define GPIOC_BSR       *((volatile u32 *)(GPIOC_BASE_ADDRESS + 0x10))
#define GPIOC_BRR       *((volatile u32 *)(GPIOC_BASE_ADDRESS + 0x14))
#define GPIOC_LCK       *((volatile u32 *)(GPIOC_BASE_ADDRESS + 0x18))





#endif
