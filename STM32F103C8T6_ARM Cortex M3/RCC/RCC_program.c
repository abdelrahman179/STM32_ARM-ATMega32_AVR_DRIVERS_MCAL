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


/* ----- Initialize clock depending on paramters chosen by the user ----- */
void MRCC_voidInitSysClock (void)
{
	u32 LOC_u32TimeOut = 0;

	/* Choose CLK System from (HSI - HSE Crystal - HSE RC - PLL) */
	#if RCC_SYS_CLOCK == RCC_HSI 	
		/* BIT 1:0 -> Choose Between HSI OR HSE OR PLL */
		/* HSI Selected As A System Clock */
		CLR_BIT(MRCC_Ptr -> CFGR, 0);
		CLR_BIT(MRCC_Ptr -> CFGR, 1);
		/* Bit 0 -> Enable The HSI Clock */
		SET_BIT(MRCC_Ptr -> CR, 0);
		/* Bit 1 -> Checking While The HSI Clock Is Stable */
		while( ( ( GET_BIT( MRCC_Ptr->CR , 1 ) ) == 0 ) && ( LOC_u32TimeOut < 100000 ) ){ LOC_u32TimeOut++; }
		if(LOC_u32TimeOut >= 100000){ /*TimeOut*/ }	

	#elif RCC_SYS_CLOCK == RCC_HSE_CRYSTAL /* HSE not bypassed */
		/* BIT 1:0 -> Choose Between HSI OR HSE OR PLL */
		/* HSE Selected As A System Clock */
		SET_BIT(MRCC_Ptr -> CFGR, 0);
		CLR_BIT(MRCC_Ptr-> CFGR, 1);
		/* Bit 16 -> Enable The HSE Clock */
		SET_BIT(MRCC_Ptr -> CR, 16);
		/* Bit 17 -> Checking While The HSE Clock Is Stable */
		while( ( ( GET_BIT(MRCC_Ptr -> CR , 17) ) == 0 ) && ( LOC_u32TimeOut < 100000 ) ){ LOC_u32TimeOut++; }
		if(LOC_u32TimeOut >= 100000){ /*TimeOut*/ }
	
	#elif RCC_SYS_CLOCK == RCC_HSE_RC /* HSE bypassed */
		/* The HSEBYP Can Be Written Only When HSE Oscilator Is Disabled */
		/* HSE Clock Disabled */
		CLR_BIT(MRCC_Ptr -> CR, 16);
		/* BIT 18 -> To Select HSE BYPASS */
		/* HSEBYPASS Clock Enable */
		SET_BIT(MRCC_Ptr -> CR, 18);
		/* BIT 1:0 -> Choose Between HSI OR HSE OR PLL */
		/* HSE Selected As A System Clock */
		SET_BIT(MRCC_Ptr -> CFGR, 0);
		CLR_BIT(MRCC_Ptr -> CFGR, 1);
		/* Bit 16 -> Enable The HSE Clock */
		SET_BIT(MRCC_Ptr -> CR, 16);
		/* Bit 17 -> Checking While The HSE Clock Is Stable */
		while( ( ( GET_BIT( MRCC_Ptr -> CR , 17) ) == 0 ) && ( LOC_u32TimeOut < 100000 ) ){ LOC_u32TimeOut++; }
		if(LOC_u32TimeOut >= 100000){ /*TimeOut*/ }

    #elif RCC_SYS_CLOCK == RCC_PLL
		
		/* BIT 1:0 -> Choose Between HSI OR HSE OR PLL */
		/* PLL Selected As A System Clock */
		CLR_BIT(MRCC_Ptr -> CFGR, 0);
		SET_BIT(MRCC_Ptr -> CFGR, 1);
		/*The Start Of Nested #IF*/
		/* Choosing The Multiplication Factor For PLL */
		#if (CLK_FACTOR >= NO_CLOCK_FACTOR) && (CLK_FACTOR <= PLL_CLOCK_MULTIPLE_BY_16) 
			MRCC_Ptr -> CFGR &= ~( ( 0b1111 )     << 18 ) ;
			MRCC_Ptr -> CFGR |=  (CLK_FACTOR) << 18   ;
		#elif (CLK_FACTOR > PLL_CLOCK_MULTIPLE_BY_16) || (CLK_FACTOR < NO_CLOCK_FACTOR)
			#warning "Wrong Multiplication Factor"
		/*The End OF Nested #IF */
		#endif

		/*The Start Of Nested #IF*/
		#if RCC_PLL_SOURCE == PLL_HSI_DIVIDED_BY_2

			/* BIT 16 -> Choose PLL Source -> If HSI/2 OR HSE */
			/* PLL Entery Clock Source Is HSI Divided By 2 */
			CLR_BIT(MRCC_Ptr -> CFGR, 16);

		#elif RCC_PLL_SOURCE == PLL_HSE
			/* Bit 16 -> Enable The HSE Clock */
			SET_BIT(MRCC_Ptr -> CR, 16);
			/* BIT 16 -> Choose PLL Source -> If HSI/2 OR HSE */
			/* PLL Entery Clock Source Is HSE */
			SET_BIT(MRCC_Ptr -> CFGR, 16);
			/* BIT 17 -> IF PLL Source IS HSE Then Choose Between Divide HSE/2 Or Not  */
			/* HSE Is Not Divided */
			CLR_BIT(MRCC_Ptr -> CFGR, 17);

		#elif RCC_PLL_SOURCE == PLL_HSE_DIVIDED_BY_2
			/* Bit 16 -> Enable The HSE Clock */
			SET_BIT(MRCC_Ptr -> CR, 16);
			/* BIT 16 -> Choose PLL Source -> If HSI/2 OR HSE */
			/* PLL Entery Clock Source Is HSE */
			SET_BIT(MRCC_Ptr -> FGR, 16);
			/* BIT 17 -> IF PLL Source IS HSE Then Choose Between Divide HSE/2 Or Not  */
			/* HSE Is Divided By Two */
			SET_BIT(MRCC_Ptr -> CFGR, 17);

			/*The End Of Nested IF*/
		#endif

		/* PLL Clock Enable */
		SET_BIT(MRCC_Ptr -> CR, 24);

		/* Wait Until PLL Ready Flag Set */
		while( ( (GET_BIT(MRCC_Ptr -> CR, 25) ) == 0 ) && (LOC_u32TimeOut < 100000) ){ LOC_u32TimeOut++; }
		if(LOC_u32TimeOut >= 100000){ /*TimeOut*/ }  

	#else
		#error "Invalid CLK System Configuration"
	#endif


	/* ----- To enable or disable Clock security system ----- */
	#if CLK_SECURITY_SYSTEM == ENABLE_CLOCK_SECURITY_SYSTEM 
		SET_BIT(MRCC_Ptr -> CR, 19);
	#elif CLK_SECURITY_SYSTEM == DISABLE_CLOCK_SECURITY_SYSTEM
		CLR_BIT(MRCC_Ptr -> CR, 19);
    #else
		#error "CSS Configuration error"
	#endif


	/* ----- Choosing output on MCO  Control Register Bits: 26-24 ----- */
	#if   RCC_MCO_PIN == NO_CLOCK 
		CLR_BIT(MRCC_Ptr -> CFGR , 26);
		CLR_BIT(MRCC_Ptr -> CFGR , 27);  
		
	#elif RCC_MCO_PIN == HSI_CLOCK
		SET_BIT(MRCC_Ptr -> CR   , 0);  // HSI on
		SET_BIT(MRCC_Ptr -> CFGR , 24);
		CLR_BIT(MRCC_Ptr -> CFGR , 25);
		SET_BIT(MRCC_Ptr -> CFGR , 26);
		CLR_BIT(MRCC_Ptr -> CFGR , 27);
		
    #elif RCC_MCO_PIN == HSE_CLOCK
		SET_BIT(MRCC_Ptr -> CR   , 16);  // HSE on
		CLR_BIT(MRCC_Ptr -> CFGR , 24);
		SET_BIT(MRCC_Ptr -> CFGR , 25);
		SET_BIT(MRCC_Ptr -> CFGR , 26);
		CLR_BIT(MRCC_Ptr -> CFGR , 27);
		
	#elif RCC_MCO_PIN == PLL_CLOCK_BY2
        SET_BIT(MRCC_Ptr -> CR   , 24);  // PLL on
		SET_BIT(MRCC_Ptr -> CFGR , 24);
		SET_BIT(MRCC_Ptr -> CFGR , 25);
		SET_BIT(MRCC_Ptr -> CFGR , 26);
		CLR_BIT(MRCC_Ptr -> CFGR , 27);
		
	#elif RCC_MCO_PIN == SYSTEM_CLOCK
		CLR_BIT(MRCC_Ptr -> CFGR , 24);
		CLR_BIT(MRCC_Ptr -> CFGR , 25);
		SET_BIT(MRCC_Ptr -> CFGR , 26);
	#else
		#error "Invalid MCO Configuration"
	#endif	
}


void MRCC_voidEnableClock (u8 Copy_u8BusId , u8 Copy_u8PerId)
{
    if (Copy_u8PerId <= 31)
    {
      switch (Copy_u8BusId) 
      {
        case AHB_BUS  : SET_BIT(MRCC_Ptr -> AHBENR  , Copy_u8PerId ); break;
        case APB1_BUS : SET_BIT(MRCC_Ptr -> APB1ENR , Copy_u8PerId ); break;
        case APB2_BUS : SET_BIT(MRCC_Ptr -> APB2ENR , Copy_u8PerId ); break;
        default       :                                      	      break;
      }
    }
    else 
    {
        /* ERROR*/
    }
}

void MRCC_voidDisableClock(u8 Copy_u8BusId , u8 Copy_u8PerId)
{
    if (Copy_u8PerId <= 31)
    {
      switch (Copy_u8BusId) 
      {
        case AHB_BUS  : CLR_BIT(MRCC_Ptr -> AHBENR  , Copy_u8PerId ); break;
        case APB1_BUS : CLR_BIT(MRCC_Ptr -> APB1ENR , Copy_u8PerId ); break;
        case APB2_BUS : CLR_BIT(MRCC_Ptr -> APB2ENR , Copy_u8PerId ); break;
        default       :                                  		      break;
      }
    }
    else 
    {
        /* ERROR*/
    }
}

