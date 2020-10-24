/*********************************************************/
/* Author : AbdElrahman I.Zaki                           */
/* Date   : 10 August 2020                               */
/* Version: V01                                          */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 GPIO program     */
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"


            /* ------ Function that sets the pin "mode and configuration" ------- */
void MGPIO_voidSetPinDirection(GPIO_Port_ID Copy_PORT , GPIO_Pin_No Copy_PIN , GPIO_Modes Copy_MODE)
{
    switch (Copy_PORT)
    {                      
        case GPIOA : 
                    /* Check if Pin lies between 0-7 noting that each pin consists of 4 bits "CRL Configuration Register Low"  */
                    if (Copy_PIN <= 7) 
                        {
                            /*  Reset the chosen PIN which consists of 4 bits not all the CRL Register 
                                As long as we will use logical operation we have to reset first "not to over-write"  */
                                // Note : We can use 4 SET-PINss but it consumes more clocks                              
                            GPIOA_CRL &= ~ ((0b1111) << (Copy_PIN * 4));
                            /* Set the chosen MODE on the chosen PIN */
                            GPIOA_CRL |=   ((Copy_MODE) << (Copy_PIN * 4));
                        }
                    /* Check if Pin lies between 8-15 noting that each pin consists of 4 bits "CRH Configuration Register High" */
                    else if (Copy_PIN <= 15)
                        {
                            /* To get the exact chosen Pin when it's multiplied by 4 */
                            Copy_PIN = Copy_PIN - 8;
                            /* Reset the chosen PIN which consists of 4 bits not all the CRH Register */
                            GPIOA_CRH &= ~ ((0b1111) << (Copy_PIN * 4));
                            /* Set the chosen MODE on the chosen PIN */
                            GPIOA_CRH |=   ((Copy_MODE) << (Copy_PIN * 4));
                        }
                    break;

        case GPIOB :
                    /* Check if Pin lies between 0-7 noting that each pin consists of 4 bits "CRL Configuration Register Low"  */
                    if (Copy_PIN <= 7) 
                        {
                            /*  Reset the chosen PIN which consists of 4 bits not all the CRL Register 
                                As long as we will use logical operation we have to reset first "not to over-write"  */
                                // Note : We can use 4 SET-PINss but it consumes more clocks        
                            GPIOB_CRL &= ~ ((0b1111) << (Copy_PIN * 4));
                            /* Set the chosen MODE on the chosen PIN */
                            GPIOB_CRL |=   ((Copy_MODE) << (Copy_PIN * 4));
                        }
                    /* Check if Pin lies between 8-15 noting that each pin consists of 4 bits "CRH Configuration Register High" */
                    else if (Copy_PIN <= 15)
                        {
                            /* To get the exact chosen Pin when it's multiplied by 4 */
                            Copy_PIN = Copy_PIN - 8;
                            /* Reset the chosen PIN which consists of 4 bits not all the CRH Register */
                            GPIOB_CRH &= ~ ((0b1111) << (Copy_PIN * 4));
                            /* Set the chosen MODE on the chosen PIN */
                            GPIOB_CRH |=   ((Copy_MODE) << (Copy_PIN * 4));
                        }
                    break;

                        /* Despite the current MC GPIO Peripheral PORTC has only 3 Pins, the below 
                            code is workable for either the current MC or any other STM32 MC */
        case GPIOC :
                    /* Check if Pin lies between 0-7 "CRL Register" */
                    if (Copy_PIN <= 7) 
                        {
                            /*  Reset the chosen PIN which consists of 4 bits not all the CRL Register 
                                As long as we will use logical operation we have to reset first "not to over-write"  */
                                // Note : We can use 4 SET-PINss but it consumes more clocks        
                            GPIOC_CRL &= ~ ((0b1111) << (Copy_PIN * 4));
                            /* Set the chosen MODE on the chosen PIN */
                            GPIOC_CRL |=   ((Copy_MODE) << (Copy_PIN * 4));
                        }
                    /* Check if Pin lies between 8-15 "CRH Register" */
                    else if (Copy_PIN <= 15)
                        {
                            /* To get the exact chosen Pin when it's multiplied by 4 */
                            Copy_PIN = Copy_PIN - 8;
                            /* Reset the chosen PIN which consists of 4 bits not all the CRH Register */
                            GPIOC_CRH &= ~ ((0b1111) << (Copy_PIN * 4));
                            /* Set the chosen MODE on the chosen PIN */
                            GPIOC_CRH |=   ((Copy_MODE) << (Copy_PIN * 4));
                        }
                    break;

        default : /* just to avoid any compiler errors */ 
                    break;
    }
}

                  /* ----- Function that sets the pin value either "High or Low" ------- */
    /* To speed up the GPIO Set Pin Value Function, I've used BSRR & BRR registers to reduce processing cycles */
void MGPIO_voidSetPinValue(GPIO_Port_ID Copy_PORT , GPIO_Pin_No Copy_PIN , u8 Copy_u8VALUE)
{
    switch (Copy_PORT)
    {                
        case GPIOA : 
                    /* If the value entered by the user is high : set the pin */
                    if (Copy_u8VALUE == HIGH) 
                        {
                                 /* Using ODR output data register GPIOA_ODR |=  (1 << (BIT)) 3 cycles */
                            // SET_BIT(GPIOA_ODR , Copy_PIN);
                                 /* Using BSRR Bit Set Reset Register GPIOA_BSR = (1 << (BIT)) 2 cycles */
                            GPIOA_BSR = (1 << Copy_PIN);
                        }
                    /* If the value entered by the user is low : clear the pin */
                    else if (Copy_u8VALUE == LOW)
                        {
                                 /* Using ODR output data Register GPIOA_ODR |=  (1 << (BIT)) 3 cycles */   
                            // CLR_BIT(GPIOA_ODR , Copy_PIN);
                                 /* Using BRR Bit Reset Register GPIOA_BRR = (1 << (BIT)) 2 cycles */
                            GPIOA_BRR = (1 << Copy_PIN);
                        }
                    break;

        case GPIOB : 
                    /* If the value entered by the user is high : set the pin */
                    if (Copy_u8VALUE == HIGH) 
                        {
                                 /* Using ODR output data register GPIOA_ODR |=  (1 << (BIT)) 3 cycles */
                            //SET_BIT(GPIOB_ODR , Copy_PIN);
                                 /* Using BSRR Bit Set Reset Register GPIOA_BSR = (1 << (BIT)) 2 cycles */
                            GPIOB_BSR = (1 << Copy_PIN);
                        }
                    /* If the value entered by the user is low : clear the pin */
                    else if (Copy_u8VALUE == LOW)
                        {   
                                 /* Using ODR output data register GPIOA_ODR |=  (1 << (BIT)) 3 cycles */    
                            // CLR_BIT(GPIOB_ODR , Copy_PIN);
                                 /* Using BRR Bit Reset Register GPIOA_BRR = (1 << (BIT)) 2 cycles */
                            GPIOB_BRR = (1 << Copy_PIN);
                        }
                    break;

        case GPIOC : 
                    /* If the value entered by the user is high : set the pin */
                    if (Copy_u8VALUE == HIGH) 
                        {
                                 /* Using ODR output data register GPIOA_ODR |=  (1 << (BIT)) 3 cycles */
                            // SET_BIT(GPIOC_ODR , Copy_PIN);
                                 /* Using BSRR Bit Set Reset Register GPIOA_BSR = (1 << (BIT)) 2 cycles */
                            GPIOC_BSR = (1 << Copy_PIN);
                        }
                    /* If the value entered by the user is low : clear the pin */
                    else if (Copy_u8VALUE == LOW)
                        {
                                 /* Using ODR output data register GPIOA_ODR |=  (1 << (BIT)) 3 cycles */ 
                            // CLR_BIT(GPIOC_ODR , Copy_PIN);
                                 /* Using BRR Bit Reset Register GPIOA_BRR = (1 << (BIT)) 2 cycles */
                            GPIOC_BRR = (1 << Copy_PIN);
                        }
                    break;

        default : /* just to avoid any compiler errors */ 
                    break;
    }

}

void MGPIO_voidTogglePinValue (GPIO_Port_ID Copy_PORT , GPIO_Pin_No Copy_PIN)
{
	switch (Copy_PORT) 
    {
		case GPIOA:
			        TOG_BIT(GPIOA_ODR , Copy_PIN);     break;		                                    
		case GPIOB:
			        TOG_BIT(GPIOA_ODR , Copy_PIN);     break;		
		case GPIOC: 
			        TOG_BIT(GPIOC_ODR , Copy_PIN);     break;	
		default   :                                    break;
	}
}

            /* ----- Function that get the pin value either "High or Low" ------- */
u8 MGPIO_u8GetPinValue(GPIO_Port_ID Copy_PORT , GPIO_Pin_No Copy_PIN)
{
    u8 LOC_u8Value = 0;
    switch (Copy_PORT)
    {
                    /* Get the pin value from the Input Data Register */
        case GPIOA : LOC_u8Value = GET_BIT(GPIOA_IDR , Copy_PIN); break;
        case GPIOB : LOC_u8Value = GET_BIT(GPIOB_IDR , Copy_PIN); break;
        case GPIOC : LOC_u8Value = GET_BIT(GPIOC_IDR , Copy_PIN); break;
        default    :                                              break;
    }
    return LOC_u8Value;
}

void GPIO_voidSetPortMode(GPIO_Port_ID Copy_PORT , GPIO_Modes Copy_MODE)
{
	for (GPIO_Pin_No PIIN_S = PIN0 ; PIIN_S <= PIN15 ; PIIN_S ++)
    {
		MGPIO_voidSetPinDirection(Copy_PORT , PIIN_S , Copy_MODE);
	}
}

void MGPIO_voidSetPortValue(GPIO_Port_ID Copy_PORT , u16 Copy_u16Value)
{
	switch (Copy_PORT) 
    {
		case GPIOA :
			GPIOA_ODR = Copy_u16Value;     break;
		case GPIOB :
			GPIOB_ODR = Copy_u16Value;     break;
		case GPIOC : 
			GPIOC_ODR = Copy_u16Value;     break;
		default    :                       break;
	}
}

void GPIO_voidWritePins(GPIO_Port_ID Copy_PORT , GPIO_Pin_No CopyStartPinNumber , GPIO_No_Of_Pins CopyNumOfPins , u8 Copy_u8Value)
{
	switch (Copy_PORT) 
    {
		case GPIOA :
			GPIOA_ODR &= ~ (CopyNumOfPins << CopyStartPinNumber );
			GPIOA_ODR |=   (Copy_u8Value  << CopyStartPinNumber );          break;
		case GPIOB :
			GPIOB_ODR &= ~ (CopyNumOfPins << CopyStartPinNumber );
			GPIOB_ODR |=   (Copy_u8Value  << CopyStartPinNumber );          break;
		case GPIOC : 
			GPIOC_ODR &= ~ (CopyNumOfPins << CopyStartPinNumber );
			GPIOC_ODR |=   (Copy_u8Value  << CopyStartPinNumber );          break;
		default    :                                                        break;
	}
}

            /* -----  Function that locks pin mode till the next reset  ------- */
void MGPIO_u8LockPin(GPIO_Port_ID Copy_PORT , GPIO_Pin_No Copy_PIN)
{
    u32 Temp = 0x00010000;
	switch (Copy_PORT) 
    {
		case GPIOA :
			Temp |=  (1 << Copy_PIN);
			/* Set LCKK bit */
			GPIOA_LCK = Temp;
			/* Reset LCKK bit */
			GPIOA_LCK =  (1 << Copy_PIN);
			/* Set LCKK bit */
			GPIOA_LCK = Temp;
			/* Read LCKK bit*/
			Temp = GPIOA_LCK;
			/* Read LCKK bit*/
			Temp = GPIOA_LCK;
			break;

		case GPIOB :
			Temp |=  (1 << Copy_PIN) ;
			/* Set LCKK bit */
			GPIOB_LCK = Temp;
			/* Reset LCKK bit */
			GPIOB_LCK =  (1 << Copy_PIN);
			/* Set LCKK bit */
			GPIOB_LCK = Temp;
			/* Read LCKK bit*/
			Temp = GPIOB_LCK;
			/* Read LCKK bit*/
			Temp = GPIOB_LCK;
			break;

		case GPIOC : 
			Temp |= (1 << Copy_PIN);
			/* Set LCKK bit */
			GPIOC_LCK = Temp;
			/* Reset LCKK bit */
			GPIOC_LCK = (1 << Copy_PIN);
			/* Set LCKK bit */
			GPIOC_LCK = Temp;
			/* Read LCKK bit*/
			Temp = GPIOC_LCK;
			/* Read LCKK bit*/
			Temp = GPIOC_LCK;
			break;

		default    : 
            break;
	}
}
