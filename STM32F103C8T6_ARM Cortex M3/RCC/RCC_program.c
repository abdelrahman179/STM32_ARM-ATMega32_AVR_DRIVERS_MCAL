/*****************************************************************************/
/* Author : AbdElrahman I.Zaki                                               */
/* Date   : 29 July 2020                                                     */
/* Version: V01                                                              */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 Reset & Clock Control "RCC" Program  */
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

/* Initialize clock depending on paramters chosen by the user */
void RCC_voidInitSysClock(void)
{
    /* Note: Bit Math not used not to consume more cycles/execution time */ 
    #if   (RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL)
        /* Oscillator not bypassed HSE-ON = 1 & HSE-BYP = 0 */
        RCC_CR   = 0x00010000;
        // System Clock Switch > HSE 
        RCC_CFGR = 0x00000001;


    #elif (RCC_CLOCK_TYPE == RCC_HSE_RC)
        /* Oscillator bypassed HSE-ON = 1 & HSE-BYP = 1  "Xtal cancelled Vcc is the i/p" */
        RCC_CR   = 0x00050000;
        /* System Clock Switch > HSE */
        RCC_CFGR = 0x00000001;


    #elif (RCC_CLOCK_TYPE == RCC_HSI)
        /* Enable HSI + Default Trimming = 16 */
        RCC_CR   = 0x00000081;
        /* System Clock Switch > HSI */
        RCC_CFGR = 0x00000000;


    #elif (RCC_CLOCK_TYPE == RCC_PLL)
        #if   (RCC_PLL_INPUT == RCC_PLL_IN_HSI_DIV_2)
            /* SW > PLL - SWS > PLL - HPRE > SYSCLK not divided - 
               PPRE1 > HCLK divided by 2 - PPRE2 > HCLK not divided -
               PLLSRC > HSI/2 - PLLXTPRE > HSE CLK not divided - PLLMUL > x2 - 
               USBPRE > 0 - MCO > No CLK */ 
            RCC_CFGR = 0x0000040A;  
            /* Enable HSI & PLL */
            RCC_CR   = 0x01000081;  

        #elif (RCC_PLL_INPUT == RCC_PLL_IN_HSE_DIV_2)
            /* SW > PLL - SWS > PLL - HPRE > SYSCLK not divided - 
               PPRE1 > HCLK divided by 2 - PPRE2 > HCLK not divided -
               PLLSRC > HSI/2 - PLLXTPRE > HSE CLK divided by 2 - PLLMUL > x2 - 
               USBPRE > 0 - MCO > No CLK */ 
            RCC_CFGR = 0x0002040A;  
            /* Enable HSE & PLL */
            RCC_CR   = 0x01000081;  

        #elif (RCC_PLL_INPUT == RCC_PLL_IN_HSE)

		#endif
    #else
        #error ("Wrong System Clock Selection")
    #endif


}


/* ----- RCC Clock Enable on peripherals lies on AHB/APB1/APB2 ----- */
void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
    // Input Validation > Peripherals Range 0 - 31
    if (Copy_u8PerId <= 31)
    {
        switch (Copy_u8BusId)
        {
            case RCC_AHB  : SET_BIT(RCC_AHBENR  , Copy_u8PerId);  break;
            case RCC_APB1 : SET_BIT(RCC_APB1ENR , Copy_u8PerId);  break;
            case RCC_APB2 : SET_BIT(RCC_APB2ENR , Copy_u8PerId);  break;
            //default     : /* Return Error */                    break;
        }
    }

    else
    {
        /* Return Error */ 
    }
}


/* ----- RCC Clock Disable on peripherals lies on AHB/APB1/APB2 ----- */
void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
{
    // Input Validation > Peripherals Range 0 - 31
    if (Copy_u8PerId <= 31)
    {
        switch (Copy_u8BusId)
        {
            case RCC_AHB  : CLR_BIT(RCC_AHBENR  , Copy_u8PerId);  break;
            case RCC_APB1 : CLR_BIT(RCC_APB1ENR , Copy_u8PerId);  break;
            case RCC_APB2 : CLR_BIT(RCC_APB2ENR , Copy_u8PerId);  break;
            //default     : /* Return Error */                    break;
        }
    }

    else
    {
        /* Return Error */ 
    }
}

