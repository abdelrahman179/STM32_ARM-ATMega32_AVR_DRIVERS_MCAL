/**************************************************************************************/
/* Author : AbdElrahman I.Zaki                                                        */
/* Date   : 8 August 2020                                                             */
/* Version: V02                                                                       */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 RCC Registers Definitions/Private Functions   */
/**************************************************************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

// Base Address : 0x4002 1000
            /* ---------------------- Register Definitions ---------------------- */
#define RCC_CR        *((volatile u32 *) 0x40021000) /* Clock Control Register                   */
#define RCC_CFGR      *((volatile u32 *) 0x40021004) /* Clock Configuration Register             */
#define RCC_CIR       *((volatile u32 *) 0x40021008) /* Clock Interrupt Register                 */
#define RCC_APB2RSTR  *((volatile u32 *) 0x4002100C) /* APB2 Peripheral Reset Register           */
#define RCC_APB1RSTR  *((volatile u32 *) 0x40021010) /* APB1 Peripheral Reset Register           */
/* ----------- Enable/Disable Clock on Peripherals -------------- */
#define RCC_AHBENR    *((volatile u32 *) 0x40021014) /* AHB Perihperal Clock Enable Register     */
#define RCC_APB2ENR   *((volatile u32 *) 0x40021018) /* APB2 Perihperal Clock Enable Register    */
#define RCC_APB1ENR   *((volatile u32 *) 0x4002101C) /* APB1 Perihperal Clock Enable Register    */

#define RCC_BDCR      *((volatile u32 *) 0x40021020) /* Backup Domain Control Register           */
#define RCC_CSR       *((volatile u32 *) 0x40021024) /* Control/Status Register                  */

            /* ---------------------- Configuratuin Parameters ---------------------- */

#define ENABLE   1
#define DISABLE  0

/* ------ Clock system options ------ */
#define RCC_HSI 		  0         /* Internal RC 8MHz */
#define RCC_HSE_CRYSTAL   1         /* CLK  4 -> 16 MHz */
#define RCC_HSE_RC        2         /* CLK up to 25 MHz */
#define RCC_PLL           3         /* CLK up to 72 MHz */

/* ------ PLL options ------ */
/* Division option exist just in case we couldn't reach 72 MHz.
    ex: Cry 16MHz, req PLL at 72MHz, prescaler ?? 
        We shall try HSE/2 = 16/2 = 8, multiply by 9 = 72MHz */
#define RCC_PLL_HSI_BY2   0         /**/
#define RCC_PLL_HSE       1
#define RCC_PLL_HSE_BY2   2

/* ------ MCO PIN Options ------ */
/* Is used to generate an output CLK on it for error measurement 
    - For Diagnostics   - For CLK Cascading */
#define NO_CLOCK      0     
#define HSI_CLOCK     1
#define HSE_CLOCK     2
#define PLL_CLOCK     3
#define SYSTEM_CLOCK  4

/* ------ Prescaler Options for Buses ------ */
#define RCC_PRESCALER_0 	 0	  
#define RCC_PRESCALER_2     2
#define RCC_PRESCALER_4     3
#define RCC_PRESCALER_6     4   
#define RCC_PRESCALER_16    5
#define RCC_PRESCALER_64    6
#define RCC_PRESCALER_128   7
#define RCC_PRESCALER_256   8
#define RCC_PRESCALER_512   9   


/* ------ RCC_CR BITS ------ */
#define RCC_HSI_ON       0      /* 1 : 8MHz RC Osc ON --- 0 : 8MHz RC Osc OFF */
#define RCC_HSI_RDY      1      /* Fired when HSI CLK become stable "Settling time" */
#define RCC_HSI_TRIM0    3      /* bits from 3-7 by default 1 0 0 0 0 = 16, +Step -> 40KHz, -Step -> 40KHz */      
#define RCC_HSE_ON       16     /* HSE On */
#define RCC_HSE_RDY      17     /* Fired when HSE CLK become stable "Settling time" */
#define RCC_HSE_BYP      18     /* 0 : Crystal Oscillator , 1 : RC o/p xtal1 cancelled and i/p is Vcc */
#define RCC_CSS_ON       19     /* Security Sys that indicates HSE errors, fire interrupt and switch to HSI CLK */
#define RCC_PLL_ON       24     /* PLL Enable Bit  */
#define RCC_PLL_RDY      25     /* PLL CLK RDY Flag as PLL takes time to finish CLK muliplexing */

/* ------ RCC_CFGR BITS ------ */
#define RCC_SW0          0      /* System Clock Switch BIT 0 */
#define RCC_SW1          1      /* System Clock Switch BIT 1 */

#define RCC_HPRE0        4      /*  AHB Prescaler -> 0000 : SYSCLK not divided "Processor CLK = AHB CLK" */
#define RCC_HPRE1        5      /*  1000: SYSCLK/2, 1001: SYSCLK/4, 1010: SYSCLK/8,     */
#define RCC_HPRE2        6      /*  1011: SYSCLK/16, 1100: SYSCLK/64, 1101: SYSCLK/128, */
#define RCC_HPRE3        7      /*  1110: SYSCLK/256, 1111: SYSCLK/512                  */

#define RCC_PPRE1_0      8      /* APB1 Low Speed Prescaler "WARNING: Donnot exceed 36MHz" */
#define RCC_PPRE1_1      9      /* 000 : HCLK not divided "APB2 CLK = AHB CLK"  So, AHB must not exceed 36MHz */
#define RCC_PPRE1_2      10     /* 100 : HCLK/2, 101 : HCLK/4, 110 : HCLK/8, 111 : HCLK/16 */

#define RCC_PPRE2_0      11     /* APB2 High Speed Prescaler -> 000 : HCLK not divided "APB2 CLK = AHB CLK" */
#define RCC_PPRE2_1      12     /* 100 : HCLK/2, 101 : HCLK/4,  */
#define RCC_PPRE2_2      13     /* 110 : HCLK/8, 111 : HCLK/16  */

#define RCC_ADCPRE0      14     /* ADC Prescaler freq on CLK to the ADCs -> 00 : PCLK/2, 01 : PCLK/4, 10 : PCLK/6, */
#define RCC_ADCPRE2      15     /* 11 : PCLK/8 */

#define RCC_PLL_SRC      16     /* PLL Entry CLK SRC, 0 : HSI/2,  1 : HSE "HSI cannot be the PLL without dividing" */
#define RCC_PLL_XTPRE    17     /* HSE Divider for PLL Entry, 0 : HSE not divided, 1 : HSE/2 */

#define RCC_PLL_MUL0     18     /* PLL Mulitiplication factor "WARNING: PLL O/P freq must not exceed 72 MHz" */

/* WARNING: when system CLK selected to o/p MCO, CLK mustnot exceed 50MHz max IO speed */
#define RCC_MCO_0        24     /* Microcontroller CLK O/P -> 000 : No CLK, */
#define RCC_MCO_1        25     /* 100 : SYS CLK Selected, 101 : HSI CLK Selected, */
#define RCC_MCO_2        26     /* 110 : HSE CLK Selected, 111 : PLL CLK/2 Selected */     
         
         
#endif
