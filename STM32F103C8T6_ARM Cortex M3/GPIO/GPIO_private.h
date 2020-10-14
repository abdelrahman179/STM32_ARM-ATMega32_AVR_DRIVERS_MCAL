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
#define GPIOA_CRL       *((u32 *)(GPIOA_BASE_ADDRESS + 0x00))
#define GPIOA_CRH       *((u32 *)(GPIOA_BASE_ADDRESS + 0x04))
#define GPIOA_IDR       *((u32 *)(GPIOA_BASE_ADDRESS + 0x08))
#define GPIOA_ODR       *((u32 *)(GPIOA_BASE_ADDRESS + 0x0C))
#define GPIOA_BSR       *((u32 *)(GPIOA_BASE_ADDRESS + 0x10))
#define GPIOA_BRR       *((u32 *)(GPIOA_BASE_ADDRESS + 0x14))
#define GPIOA_LCK       *((u32 *)(GPIOA_BASE_ADDRESS + 0x18))

/* GPIO PORTB Registers Addresses "Base-address + Offset" */
#define GPIOB_CRL       *((u32 *)(GPIOB_BASE_ADDRESS + 0x00))
#define GPIOB_CRH       *((u32 *)(GPIOB_BASE_ADDRESS + 0x04))
#define GPIOB_IDR       *((u32 *)(GPIOB_BASE_ADDRESS + 0x08))
#define GPIOB_ODR       *((u32 *)(GPIOB_BASE_ADDRESS + 0x0C))
#define GPIOB_BSR       *((u32 *)(GPIOB_BASE_ADDRESS + 0x10))
#define GPIOB_BRR       *((u32 *)(GPIOB_BASE_ADDRESS + 0x14))
#define GPIOB_LCK       *((u32 *)(GPIOB_BASE_ADDRESS + 0x18))

/* GPIO PORTC Registers Addresses "Base-address + Offset" */
#define GPIOC_CRL       *((u32 *)(GPIOC_BASE_ADDRESS + 0x00))
#define GPIOC_CRH       *((u32 *)(GPIOC_BASE_ADDRESS + 0x04))
#define GPIOC_IDR       *((u32 *)(GPIOC_BASE_ADDRESS + 0x08))
#define GPIOC_ODR       *((u32 *)(GPIOC_BASE_ADDRESS + 0x0C))
#define GPIOC_BSR       *((u32 *)(GPIOC_BASE_ADDRESS + 0x10))
#define GPIOC_BRR       *((u32 *)(GPIOC_BASE_ADDRESS + 0x14))
#define GPIOC_LCK       *((u32 *)(GPIOC_BASE_ADDRESS + 0x18))


/* ------------- Pins Output Mode/Configuration ---------------- */

#define OUTPUT_SPEED_10MHZ_PP        0b0001  /* Output Mode, 10MHz Config, Push-Pull                        */
#define OUTPUT_SPEED_10MHZ_OD        0b0101  /* Output Mode, 10MHz Config, Open Drain                       */
#define OUTPUT_SPEED_10MHZ_AFPP      0b1001  /* Output Mode, 10MHz Config, Alternative Function Push Pull   */
#define OUTPUT_SPEED_10MHZ_AFOD      0b1101  /* Output Mode, 10MHz Config, Alternative Function Open Drain  */

#define OUTPUT_SPEED_2MHZ_PP         0b0010  /* Output Mode, 2MHz Config, Push-Pull                         */
#define OUTPUT_SPEED_2MHZ_OD         0b0110  /* Output Mode, 2MHz Config, Open Drain                        */
#define OUTPUT_SPEED_2MHZ_AFPP       0b1010  /* Output Mode, 2MHz Config, Alternative Function Push Pull    */
#define OUTPUT_SPEED_2MHZ_AFOD       0b1110  /* Output Mode, 2MHz Config, Alternative Function Open Drain   */

#define OUTPUT_SPEED_50MHZ_PP        0b0011  /* Output Mode, 50MHz Config, Push-Pull                        */
#define OUTPUT_SPEED_50MHZ_OD        0b0111  /* Output Mode, 50MHz Config, Open Drain                       */
#define OUTPUT_SPEED_50MHZ_AFPP      0b1011  /* Output Mode, 50MHz Config, Alternative Function Push Pull   */
#define OUTPUT_SPEED_50MHZ_AFOD      0b1111  /* Output Mode, 50MHz Config, Alternative Function Open Drain  */

/* ------------- Pins Input Mode/Configuration ---------------- */

#define INPUT_ANALOG                 0b0000  /* Input Mode Config: Analog                                   */
#define INPUT_FLOATING               0b0100  /* Input Mode Config: Floating "Sensors"                       */
#define INPUT_PULL_UP_OR_DOWN        0b1000  /* Input Mode Config: Pull Up/Down                             */



#endif
