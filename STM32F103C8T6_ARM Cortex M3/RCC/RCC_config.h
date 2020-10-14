/**********************************************************************************/
/* Author : AbdElrahman I.Zaki                                                    */
/* Date   : 8 August 2020                                                         */
/* Version: V01                                                                   */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 Reset & Clock Control "RCC" User Manual   */
/**********************************************************************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/* Options: RCC_HSE_CRYSTAL
            RCC_HSE_RC
            RCC_HSI
            RCC_PLL      */
#define RCC_CLOCK_TYPE   RCC_HSE_CRYSTAL

/* Note: Select a value only if you have PLL as an input clock source */
/* Options: RCC_PLL_IN_HSI_DIV_2
            RCC_PLL_IN_HSE_DIV_2
            RCC_PLL_IN_HSE       */
#if (RCC_CLOCK_TYPE == RCC_PLL)
    #define RCC_PLL_INPUT   RCC_PLL_IN_HSE_DIV_2
#endif

/* Note: Select a value only if you have PLL as an input clock source */
/* Caution: The PLL output frequency must not exceed 72 MHz           */
/* These bits has to be set only when PLL is disabled                 */
/* Options: 2 -> 16 */ 
#if (RCC_CLOCK_TYPE == RCC_PLL)
    #define RCC_PLL_MUL_VAL    4    
#endif

/* Microcontroller output clock, used to measure clock error          */
/* It's used for: - Diagnostics 
                  - C/K Cascading 
   Range : - No Clock
           - System Clock
           - HSI
           - HSE
           - PLL divided by 2        */
#define RCC_MCO_SELECTION   NO_CLOCK



#endif 
