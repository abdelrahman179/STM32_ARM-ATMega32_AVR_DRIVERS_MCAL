/**************************************************************************************/
/* Author : AbdElrahman I.Zaki                                                        */
/* Date   : 8 August 2020                                                             */
/* Version: V01                                                                       */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 RCC Registers Definitions/Private Functions   */
/**************************************************************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

                    /* Register Definitions */

// 0x40021000  RCC base address > AHB Bus

/* ------- Clock System/Processor Selection "HSI/HSE/PLL" ------- */
#define RCC_CR           *((u32*)0x40021000)
#define RCC_CFGR         *((u32*)0x40021004)

/* -------------------------------------------------------------- */

// Reset 
#define RCC_CIR          *((u32*)0x40021008)
#define RCC_APB2RSTR     *((u32*)0x4002100C)
#define RCC_APB1RSTR     *((u32*)0x40021010)

/* ----------- Enable/Disable Clock on Peripherals -------------- */
// Enable/Disable C/K on Peripherals lies on AHB  Bus
#define RCC_AHBENR       *((u32*)0x40021014)
// Enable/Disable C/K on Peripherals lies on APB2 Bus 
#define RCC_APB2ENR      *((u32*)0x40021018)
// Enable/Disable C/K on Peripherals lies on APB1 Bus 
#define RCC_APB1ENR      *((u32*)0x4002101C)
/* --------------------------------------------------------------- */

// Reset
#define RCC_BDCR         *((u32*)0x40021020)
#define RCC_CSR          *((u32*)0x40021024)


/* Clock Types */
#define  RCC_HSE_CRYSTAL   0
#define  RCC_HSE_RC        1
#define  RCC_HSI           2
#define  RCC_PLL           3

/* PLL Options */
#define RCC_PLL_IN_HSI_DIV_2  0
#define RCC_PLL_IN_HSE_DIV_2  1
#define RCC_PLL_IN_HSE        2

/* Microcontroller Clock Output MCO */
#define NO_CLK              0
#define SYS_CLK             1
#define HSI_CLK             2
#define HSE_CLK             3
#define PLL_CLK_DIV_2       4


/* PLL Multiplication Factor */
#define PLL_INPUT_CK_x2   0
#define PLL_INPUT_CK_x3   1
#define PLL_INPUT_CK_x4   2
#define PLL_INPUT_CK_x5   3
#define PLL_INPUT_CK_x6   4
#define PLL_INPUT_CK_x7   5
#define PLL_INPUT_CK_x8   6
#define PLL_INPUT_CK_x9   7
#define PLL_INPUT_CK_x10  8
#define PLL_INPUT_CK_x11  9
#define PLL_INPUT_CK_x12  10
#define PLL_INPUT_CK_x13  11
#define PLL_INPUT_CK_x14  12
#define PLL_INPUT_CK_x15  13
#define PLL_INPUT_CK_x16  14


#endif
