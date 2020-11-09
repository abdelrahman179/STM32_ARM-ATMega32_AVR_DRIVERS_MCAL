/**********************************************************************************/
/* Author : AbdElrahman I.Zaki                                                    */
/* Date   : 8 August 2020                                                         */
/* Version: V02                                                                   */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 Reset & Clock Control "RCC" User Manual   */
/**********************************************************************************/

#ifndef _RCC_CONFIG_H_
#define _RCC_CONFIG_H_


/* Options : 
			RCC_HSI 		  
			RCC_HSE_CRYSTAL   
			RCC_HSE_RC       
			RCC_PLL 			 
*/
#define RCC_SYS_CLOCK         RCC_HSE_CRYSTAL

/*
  Options :
			RCC_PLL_HSI_BY2   
			RCC_PLL_HSE       
			RCC_PLL_HSE_BY2
*/ 
#define RCC_PLL_SOURCE    RCC_PLL_HSE_BY2

/*
	Options :	- NO_CLOCK_FACTOR                                           
				- PLL_Clock_MULTIPLE_BY_2                                   
				- PLL_Clock_MULTIPLE_BY_3                                   
				- PLL_Clock_MULTIPLE_BY_4                                   
				- PLL_Clock_MULTIPLE_BY_5                                   
				- PLL_Clock_MULTIPLE_BY_6                                   
				- PLL_Clock_MULTIPLE_BY_7                                   
				- PLL_Clock_MULTIPLE_BY_8                                   
				- PLL_Clock_MULTIPLE_BY_9                                   
				- PLL_Clock_MULTIPLE_BY_10                                  
				- PLL_Clock_MULTIPLE_BY_11                                 
				- PLL_Clock_MULTIPLE_BY_12                                 
				- PLL_Clock_MULTIPLE_BY_13                                 
				- PLL_Clock_MULTIPLE_BY_14                                
				- PLL_Clock_MULTIPLE_BY_15                                
				- PLL_Clock_MULTIPLE_BY_16       
*/
#define CLK_FACTOR		PLL_CLOCK_MULTIPLE_BY_16

/* Clock Security System            
	Options:    > DISABLE_CLOCK_SECURITY_SYSTEM 
				> ENABLE_CLOCK_SECURITY_SYSTEM		
					- Set HSI by H.W. when there are failure in HSI 
                	- Set HSI by H.W. when leaving stop or standby	*/
#define CLK_SECURITY_SYSTEM          DISABLE_CLOCK_SECURITY_SYSTEM


/* Microcontroller output clock, used to measure clock error          
    It's used for: - Diagnostics 
                  - C/K Cascading 
  Options : 
			NO_CLOCK      
			HSI_CLOCK     
			HSE_CLOCK     
			PLL_CLOCK_BY2     
			SYSTEM_CLOCK
*/ 
#define RCC_MCO_PIN       NO_CLOCK


/*
   Options : -16 - 15 
*/ 
#define HSI_STEP_CORRECTION   0 




#endif 
