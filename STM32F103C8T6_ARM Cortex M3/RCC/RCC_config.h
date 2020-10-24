/**********************************************************************************/
/* Author : AbdElrahman I.Zaki                                                    */
/* Date   : 8 August 2020                                                         */
/* Version: V02                                                                   */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 Reset & Clock Control "RCC" User Manual   */
/**********************************************************************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H


/* Options : 
			RCC_HSI 		  
			RCC_HSE_CRYSTAL   
			RCC_HSE_RC       
			RCC_PLL 			 
*/
#define SYS_CLOCK         RCC_HSE_CRYSTAL

/* 
    Clock Security System : (ENABLE - DISABLE)
    Security Sys that indicates HSE errors, fire interrupt and switch to HSI CLK 
*/
#define CSS_ON            DISABLE

/*
   Options : -16 - 15 
*/ 
#define HSI_STEP_CORRECTION   0 

/*
  Options :
			RCC_PLL_HSI_BY2   
			RCC_PLL_HSE       
			RCC_PLL_HSE_BY2
*/ 
#define RCC_PLL_SOURCE    HSI_CLOCK

/*
  Options : 2 - 16 
*/ 
#define RCC_PLL_MUL       2 

/* Microcontroller output clock, used to measure clock error          
    It's used for: - Diagnostics 
                  - C/K Cascading 
  Options : 
			NO_CLOCK      
			HSI_CLOCK     
			HSE_CLOCK     
			PLL_CLOCK     
			SYSTEM_CLOCK
*/ 
#define RCC_MCO_PIN       NO_CLOCK

/*
  Options :  		  
			RCC_PRESCALER_2   
			RCC_PRESCALER_4 
			RCC_PRESCALER_6
			RCC_PRESCALER_8
*/ 
#define RCC_ADC_PRESCALER    RCC_PRESCALER_2

/*
  Options : 
			RCC_PRESCALER_0 		  
			RCC_PRESCALER_2   
			RCC_PRESCALER_4 
			RCC_PRESCALER_8 
			RCC_PRESCALER_16
*/ 
#define RCC_APB2_PRESCALER   RCC_PRESCALER_0

/*
  Options : 
			RCC_PRESCALER_0 		  
			RCC_PRESCALER_2   
			RCC_PRESCALER_4 
			RCC_PRESCALER_8 
			RCC_PRESCALER_16
*/
/* Note : this bus clock must not exceed 36 MHZ*/
#define RCC_APB1_PRESCALER   RCC_PRESCALER_0

/*
  Options : 
			RCC_PRESCALER_0 		  
			RCC_PRESCALER_2
			RCC_PRESCALER_4			
			RCC_PRESCALER_8 
			RCC_PRESCALER_16
			RCC_PRESCALER_64
			RCC_PRESCALER_128
			RCC_PRESCALER_256
			RCC_PRESCALER_512			
*/
#define RCC_AHB_PRESCALER    RCC_PRESCALER_0





#endif 
