/*****************************************************************************/
/* Author : AbdElrahman I.Zaki                                               */
/* Date   : 29 July 2020                                                     */
/* Version: V02                                                              */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 Reset & Clock Control "RCC" Program  */
/*****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

/* Initialize clock depending on paramters chosen by the user */
void RCC_voidInitSysClock (void)
{
	/* Choose CLK System from (HSI - HSE Crystal - HSE RC - PLL) */
	#if SYS_CLOCK == RCC_HSI 
		SET_BIT(RCC_CR   , RCC_HSI_ON);         // HSI On @ CR 
		while( !(RCC_CR & (1<<RCC_HSI_RDY) ) ); // Wait Till HSI RDY
		CLR_BIT(RCC_CFGR , RCC_SW0);            // Choosing HSI from System Clock Switch @ CFGR
		CLR_BIT(RCC_CFGR , RCC_SW1);
		
	#elif SYS_CLOCK == RCC_HSE_CRYSTAL
		SET_BIT(RCC_CR   , RCC_HSE_ON);         // HSE On @ CR 
		while( !(RCC_CR & (1<<RCC_HSE_RDY) ) ); // Wait Till HSE RDY
		CLR_BIT(RCC_CR   , RCC_HSE_BYP);	    // Disable bypass
		CLR_BIT(RCC_CFGR , RCC_SW1 );           // Choosing HSE from System Clock Switch @ CFGR
		SET_BIT(RCC_CFGR , RCC_SW0 );
	
	#elif SYS_CLOCK == RCC_HSE_RC
		SET_BIT(RCC_CR   , RCC_HSE_ON);          // HSE On @ CR 
		while( !(RCC_CR & (1<<RCC_HSE_RDY) ) );  // Wait Till HSE RDY
		SET_BIT(RCC_CR   , RCC_HSE_BYP);	     // Enable bypass
		CLR_BIT(RCC_CFGR , RCC_SW1);             // Choosing HSE from System Clock Switch @ CFGR
		SET_BIT(RCC_CFGR , RCC_SW0);
		
    #elif SYS_CLOCK == PLL_CLOCK
		
		RCC_CFGR &= ~(15 << RCC_PLL_MUL0);                 // Clear the four bits 18-21 @ CFGR
		RCC_CFGR |= ((RCC_PLL_MUL - 2) << RCC_PLL_MUL0);   // Load the new multiplication value chosen by user
		
		    #if   RCC_PLL_SOURCE == RCC_PLL_HSI_BY2
			    SET_BIT(RCC_CR   , RCC_HSI_ON );      // HSI on
			    CLR_BIT(RCC_CFGR , RCC_PLL_SRC);      // CLR PLL SRC Bit to Select HSI/2
			
		    #elif RCC_PLL_SOURCE == RCC_PLL_HSE
			    SET_BIT(RCC_CR   , RCC_HSE_ON );      // HSE on
			    SET_BIT(RCC_CFGR , RCC_PLL_SRC);      // SET PLL SRC Bit HSE to Select HSE
			
		    #elif RCC_PLL_SOURCE == RCC_PLL_HSE_BY2 
			    SET_BIT(RCC_CR   , RCC_HSE_ON   );    // HSE on
			    SET_BIT(RCC_CFGR , RCC_PLL_XTPRE);    // Enable prescaller by 2
			    SET_BIT(RCC_CFGR , RCC_PLL_SRC  );    // SET PLL SRC Bit HSE to Select HSE
			
		    #else
			    #error "PLL Configuration error"
		    #endif
	
		while( !(RCC_CR & (1<<RCC_PLL_RDY) ) );  // Wait till PLL RDY
		SET_BIT(RCC_CR   , RCC_PLL_ON);          // PLL On
		CLR_BIT(RCC_CFGR , RCC_SW0   );          // Choosing PLL from System Clock Switch @ CFGR
		SET_BIT(RCC_CFGR , RCC_SW1   );           

	#else
		#error "CLK System Configuration error"
	#endif
	

	
	/* Set the correction factor */ 
	#if HSI_STEP_CORRECTION != 0 
		RCC_CR &= ~(31 << RCC_HSI_TRIM0);      // Clear the five bits
		RCC_CR |= ((HSI_STEP_CORRECTION + 16 ) << RCC_HSI_TRIM0);
	#endif



	
	/* Choosing output on MCO  Control Register Bits: 26-24*/
	#if   RCC_MCO_PIN == NO_CLOCK 
		CLR_BIT(RCC_CFGR , RCC_MCO_2);  
		
	#elif RCC_MCO_PIN == HSI_CLOCK
		SET_BIT(RCC_CR   , RCC_HSI_ON);  // HSI on
		SET_BIT(RCC_CFGR , RCC_MCO_0 );
		CLR_BIT(RCC_CFGR , RCC_MCO_1 );
		SET_BIT(RCC_CFGR , RCC_MCO_2 );
		
    #elif RCC_MCO_PIN == HSE_CLOCK
		SET_BIT(RCC_CR   , RCC_HSE_ON);  // HSE on
		CLR_BIT(RCC_CFGR , RCC_MCO_0 );
		SET_BIT(RCC_CFGR , RCC_MCO_1 );
		SET_BIT(RCC_CFGR , RCC_MCO_2 );
		
	#elif RCC_MCO_PIN == PLL_CLOCK
        SET_BIT(RCC_CR   , RCC_PLL_ON);  // PLL on
		SET_BIT(RCC_CFGR , RCC_MCO_0 );
		SET_BIT(RCC_CFGR , RCC_MCO_1 );
		SET_BIT(RCC_CFGR , RCC_MCO_2 );
		
	#elif RCC_MCO_PIN == SYSTEM_CLOCK
		CLR_BIT(RCC_CFGR , RCC_MCO_0);
		CLR_BIT(RCC_CFGR , RCC_MCO_1);
		SET_BIT(RCC_CFGR , RCC_MCO_2);
	#else
		#error "MCO Configuration error"
	#endif
	
	
	
	/* To enable or disable Clock security system */
	#if CSS_ON == ENABLE 
		SET_BIT(RCC_CR , RCC_CSS_ON);
	#elif CSS_ON == DISABLE
		CLR_BIT(RCC_CR , RCC_CSS_ON);
    #else
		#error "CSS Configuration error"
	#endif
	

	/* Choosing a prescaler for the ADC */
	#if   RCC_ADC_PRESCALER == RCC_PRESCALER_2 
		CLR_BIT(RCC_CFGR , RCC_ADCPRE0);
		CLR_BIT(RCC_CFGR , RCC_ADCPRE2);
	#elif RCC_ADC_PRESCALER == RCC_PRESCALER_4
		SET_BIT(RCC_CFGR , RCC_ADCPRE0);
		CLR_BIT(RCC_CFGR , RCC_ADCPRE2);
	#elif RCC_ADC_PRESCALER == RCC_PRESCALER_6
		CLR_BIT(RCC_CFGR , RCC_ADCPRE0);
		SET_BIT(RCC_CFGR , RCC_ADCPRE2);
	#elif RCC_ADC_PRESCALER == RCC_PRESCALER_8
		SET_BIT(RCC_CFGR , RCC_ADCPRE0);
		SET_BIT(RCC_CFGR , RCC_ADCPRE2);
	#else
		#error "ADC Prescaler Configuration error")
	#endif
	

	/* Choosing a prescaler for the APB2 */
	#if   RCC_APB2_PRESCALER == RCC_PRESCALER_0 
		CLR_BIT(RCC_CFGR , RCC_PPRE2_2);
	#elif RCC_APB2_PRESCALER == RCC_PRESCALER_2
		CLR_BIT(RCC_CFGR , RCC_PPRE2_0);
		CLR_BIT(RCC_CFGR , RCC_PPRE2_1);
		SET_BIT(RCC_CFGR , RCC_PPRE2_2);
	#elif RCC_APB2_PRESCALER == RCC_PRESCALER_4
		SET_BIT(RCC_CFGR , RCC_PPRE2_0);
		CLR_BIT(RCC_CFGR , RCC_PPRE2_1);
		SET_BIT(RCC_CFGR , RCC_PPRE2_2);
	#elif RCC_APB2_PRESCALER == RCC_PRESCALER_8
		CLR_BIT(RCC_CFGR , RCC_PPRE2_0);
		SET_BIT(RCC_CFGR , RCC_PPRE2_1);
		SET_BIT(RCC_CFGR , RCC_PPRE2_2);
	#elif RCC_APB2_PRESCALER == RCC_PRESCALER_16
		SET_BIT(RCC_CFGR , RCC_PPRE2_0);
		SET_BIT(RCC_CFGR , RCC_PPRE2_1);
		SET_BIT(RCC_CFGR , RCC_PPRE2_2);
	#else
		#error "APB2 Prescaler Configuration error"
	#endif
	
	/* Choosing a prescaler for the APB1 */
	#if   RCC_APB1_PRESCALER == RCC_PRESCALER_0 
		CLR_BIT(RCC_CFGR , RCC_PPRE1_2);
	#elif RCC_APB1_PRESCALER == RCC_PRESCALER_2
		CLR_BIT(RCC_CFGR , RCC_PPRE1_0);
		CLR_BIT(RCC_CFGR , RCC_PPRE1_1);
		SET_BIT(RCC_CFGR , RCC_PPRE1_2);
	#elif RCC_APB1_PRESCALER == RCC_PRESCALER_4
		SET_BIT(RCC_CFGR , RCC_PPRE1_0);
		CLR_BIT(RCC_CFGR , RCC_PPRE1_1);
		SET_BIT(RCC_CFGR , RCC_PPRE1_2);
	#elif RCC_APB1_PRESCALER == RCC_PRESCALER_8
		CLR_BIT(RCC_CFGR , RCC_PPRE1_0);
		SET_BIT(RCC_CFGR , RCC_PPRE1_1);
		SET_BIT(RCC_CFGR , RCC_PPRE1_2);
	#elif RCC_APB1_PRESCALER == RCC_PRESCALER_16
		SET_BIT(RCC_CFGR , RCC_PPRE1_0);
		SET_BIT(RCC_CFGR , RCC_PPRE1_1);
		SET_BIT(RCC_CFGR , RCC_PPRE1_2);
	#else
		#error "APB1 Configuration error"
	#endif
	
	/* Choosing a prescaller for the AHB */
	#if   RCC_AHB_PRESCALER == RCC_PRESCALER_0 
		CLR_BIT(RCC_CFGR , RCC_HPRE3);
	#elif RCC_AHB_PRESCALER == RCC_PRESCALER_2
		CLR_BIT(RCC_CFGR , RCC_HPRE0);
		CLR_BIT(RCC_CFGR , RCC_HPRE1);
		CLR_BIT(RCC_CFGR , RCC_HPRE2);
		SET_BIT(RCC_CFGR , RCC_HPRE3);
	#elif RCC_AHB_PRESCALER == RCC_PRESCALER_4
		SET_BIT(RCC_CFGR , RCC_HPRE0);
		CLR_BIT(RCC_CFGR , RCC_HPRE1);
		CLR_BIT(RCC_CFGR , RCC_HPRE2);
		SET_BIT(RCC_CFGR , RCC_HPRE3);
	#elif RCC_AHB_PRESCALER == RCC_PRESCALER_8
		CLR_BIT(RCC_CFGR , RCC_HPRE0);
		SET_BIT(RCC_CFGR , RCC_HPRE15);
		CLR_BIT(RCC_CFGR , RCC_HPRE2);
		SET_BIT(RCC_CFGR , RCC_HPRE3);
	#elif RCC_AHB_PRESCALER == RCC_PRESCALER_16
		SET_BIT(RCC_CFGR , RCC_HPRE0);
		SET_BIT(RCC_CFGR , RCC_HPRE1);
		CLR_BIT(RCC_CFGR , RCC_HPRE2);
		SET_BIT(RCC_CFGR , RCC_HPRE3);
	#elif RCC_AHB_PRESCALER == RCC_PRESCALER_64
		CLR_BIT(RCC_CFGR , RCC_HPRE0);
		CLR_BIT(RCC_CFGR , RCC_HPRE1);
		SET_BIT(RCC_CFGR , RCC_HPRE2);
		SET_BIT(RCC_CFGR , RCC_HPRE3);
	#elif RCC_AHB_PRESCALER == RCC_PRESCALER_128
		SET_BIT(RCC_CFGR , RCC_HPRE0);
		CLR_BIT(RCC_CFGR , RCC_HPRE1);
		SET_BIT(RCC_CFGR , RCC_HPRE2);
		SET_BIT(RCC_CFGR , RCC_HPRE3);
	#elif RCC_AHB_PRESCALER == RCC_PRESCALER_256
		CLR_BIT(RCC_CFGR , RCC_HPRE0);
		SET_BIT(RCC_CFGR , RCC_HPRE1);
		SET_BIT(RCC_CFGR , RCC_HPRE2);
		SET_BIT(RCC_CFGR , RCC_HPRE3);
	#elif RCC_AHB_PRESCALER == RCC_PRESCALER_512
		SET_BIT(RCC_CFGR , RCC_HPRE0);
		SET_BIT(RCC_CFGR , RCC_HPRE1);
		SET_BIT(RCC_CFGR , RCC_HPRE2);
		SET_BIT(RCC_CFGR , RCC_HPRE3);
	#else
		#error "AHB Prescaler Configuration error"
	#endif
	
}


void RCC_voidEnableClock (u8 Copy_u8BusId , u8 Copy_u8PerId)
{
    if (Copy_u8PerId <= 31)
    {
      switch (Copy_u8BusId) 
      {
        case RCC_AHP  : SET_BIT (RCC_AHBENR  , Copy_u8PerId ); break;
        case RCC_APB1 : SET_BIT (RCC_APB1ENR , Copy_u8PerId ); break;
        case RCC_APB2 : SET_BIT (RCC_APB2ENR , Copy_u8PerId ); break;
        default       :                                        break;
      }
    }
    else 
    {
        /* ERROR*/
    }
}

void RCC_voidDisableClock(u8 Copy_u8BusId , u8 Copy_u8PerId)
{
    if (Copy_u8PerId <= 31)
    {
      switch (Copy_u8BusId) 
      {
        case RCC_AHP  : CLEAR_BIT (RCC_AHBENR  , Copy_u8PerId ); break;
        case RCC_APB1 : CLEAR_BIT (RCC_APB1ENR , Copy_u8PerId ); break;
        case RCC_APB2 : CLEAR_BIT (RCC_APB2ENR , Copy_u8PerId ); break;
        default       :                                          break;
      }
    }
    else 
    {
        /* ERROR*/
    }
}

