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
void MGPIO_voidSetPinDirection(u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8MODE)
{
    switch (Copy_u8PORT)
    {                      
        case GPIOA : 
                    /* Check if Pin lies between 0-7 noting that each pin consists of 4 bits "CRL Configuration Register Low"  */
                    if (Copy_u8PIN <= 7) 
                        {
                            /*  Reset the chosen PIN which consists of 4 bits not all the CRL Register 
                                As long as we will use logical operation we have to reset first "not to over-write"  */
                                // Note : We can use 4 SET-PINss but it consumes more clocks                              
                            GPIOA_CRL &= ~ ((0b1111) << (Copy_u8PIN * 4));
                            /* Set the chosen MODE on the chosen PIN */
                            GPIOA_CRL |=   ((Copy_u8MODE) << (Copy_u8PIN * 4));
                        }
                    /* Check if Pin lies between 8-15 noting that each pin consists of 4 bits "CRH Configuration Register High" */
                    else if (Copy_u8PIN <= 15)
                        {
                            /* To get the exact chosen Pin when it's multiplied by 4 */
                            Copy_u8PIN = Copy_u8PIN - 8;
                            /* Reset the chosen PIN which consists of 4 bits not all the CRH Register */
                            GPIOA_CRH &= ~ ((0b1111) << (Copy_u8PIN * 4));
                            /* Set the chosen MODE on the chosen PIN */
                            GPIOA_CRH |=   ((Copy_u8MODE) << (Copy_u8PIN * 4));
                        }
                    break;

        case GPIOB :
                    /* Check if Pin lies between 0-7 noting that each pin consists of 4 bits "CRL Configuration Register Low"  */
                    if (Copy_u8PIN <= 7) 
                        {
                            /*  Reset the chosen PIN which consists of 4 bits not all the CRL Register 
                                As long as we will use logical operation we have to reset first "not to over-write"  */
                                // Note : We can use 4 SET-PINss but it consumes more clocks        
                            GPIOB_CRL &= ~ ((0b1111) << (Copy_u8PIN * 4));
                            /* Set the chosen MODE on the chosen PIN */
                            GPIOB_CRL |=   ((Copy_u8MODE) << (Copy_u8PIN * 4));
                        }
                    /* Check if Pin lies between 8-15 noting that each pin consists of 4 bits "CRH Configuration Register High" */
                    else if (Copy_u8PIN <= 15)
                        {
                            /* To get the exact chosen Pin when it's multiplied by 4 */
                            Copy_u8PIN = Copy_u8PIN - 8;
                            /* Reset the chosen PIN which consists of 4 bits not all the CRH Register */
                            GPIOB_CRH &= ~ ((0b1111) << (Copy_u8PIN * 4));
                            /* Set the chosen MODE on the chosen PIN */
                            GPIOB_CRH |=   ((Copy_u8MODE) << (Copy_u8PIN * 4));
                        }
                    break;

                        /* Despite the current MC GPIO Peripheral PORTC has only 3 Pins, the below 
                            code is workable for either the current MC or any other STM32 MC */
        case GPIOC :
                    /* Check if Pin lies between 0-7 "CRL Register" */
                    if (Copy_u8PIN <= 7) 
                        {
                            /*  Reset the chosen PIN which consists of 4 bits not all the CRL Register 
                                As long as we will use logical operation we have to reset first "not to over-write"  */
                                // Note : We can use 4 SET-PINss but it consumes more clocks        
                            GPIOC_CRL &= ~ ((0b1111) << (Copy_u8PIN * 4));
                            /* Set the chosen MODE on the chosen PIN */
                            GPIOC_CRL |=   ((Copy_u8MODE) << (Copy_u8PIN * 4));
                        }
                    /* Check if Pin lies between 8-15 "CRH Register" */
                    else if (Copy_u8PIN <= 15)
                        {
                            /* To get the exact chosen Pin when it's multiplied by 4 */
                            Copy_u8PIN = Copy_u8PIN - 8;
                            /* Reset the chosen PIN which consists of 4 bits not all the CRH Register */
                            GPIOC_CRH &= ~ ((0b1111) << (Copy_u8PIN * 4));
                            /* Set the chosen MODE on the chosen PIN */
                            GPIOC_CRH |=   ((Copy_u8MODE) << (Copy_u8PIN * 4));
                        }
                    break;

        default : /* just to avoid any compiler errors */ 
                    break;
    }
}

                  /* ----- Function that sets the pin value either "High or Low" ------- */
    /* To speed up the GPIO Set Pin Value Function, I've used BSRR & BRR registers to reduce processing cycles */
void MGPIO_voidSetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8VALUE)
{
    switch (Copy_u8PORT)
    {                
        case GPIOA : 
                    /* If the value entered by the user is high : set the pin */
                    if (Copy_u8VALUE == GPIO_HIGH) 
                        {
                                 /* Using ODR output data register GPIOA_ODR |=  (1 << (BIT)) 3 cycles */
                            // SET_BIT(GPIOA_ODR , Copy_u8PIN);
                                 /* Using BSRR Bit Set Reset Regiset GPIOA_BSR = (1 << (BIT)) 2 cycles */
                            GPIOA_BSR = (1 << Copy_u8PIN);
                        }
                    /* If the value entered by the user is low : clear the pin */
                    else if (Copy_u8VALUE == GPIO_LOW)
                        {
                                 /* Using ODR output data register GPIOA_ODR |=  (1 << (BIT)) 3 cycles */   
                            // CLR_BIT(GPIOA_ODR , Copy_u8PIN);
                                 /* Using BRR Bit Reset Regiset GPIOA_BRR = (1 << (BIT)) 2 cycles */
                            GPIOA_BRR = (1 << Copy_u8PIN);
                        }
                    break;

        case GPIOB : 
                    /* If the value entered by the user is high : set the pin */
                    if (Copy_u8VALUE == GPIO_HIGH) 
                        {
                                 /* Using ODR output data register GPIOA_ODR |=  (1 << (BIT)) 3 cycles */
                            //SET_BIT(GPIOB_ODR , Copy_u8PIN);
                                 /* Using BSRR Bit Set Reset Regiset GPIOA_BSR = (1 << (BIT)) 2 cycles */
                            GPIOB_BSR = (1 << Copy_u8PIN);
                        }
                    /* If the value entered by the user is low : clear the pin */
                    else if (Copy_u8VALUE == GPIO_LOW)
                        {   
                                 /* Using ODR output data register GPIOA_ODR |=  (1 << (BIT)) 3 cycles */    
                            // CLR_BIT(GPIOB_ODR , Copy_u8PIN);
                                 /* Using BRR Bit Reset Regiset GPIOA_BRR = (1 << (BIT)) 2 cycles */
                            GPIOB_BRR = (1 << Copy_u8PIN);
                        }
                    break;

        case GPIOC : 
                    /* If the value entered by the user is high : set the pin */
                    if (Copy_u8VALUE == GPIO_HIGH) 
                        {
                                 /* Using ODR output data register GPIOA_ODR |=  (1 << (BIT)) 3 cycles */
                            // SET_BIT(GPIOC_ODR , Copy_u8PIN);
                                 /* Using BSRR Bit Set Reset Regiset GPIOA_BSR = (1 << (BIT)) 2 cycles */
                            GPIOC_BSR = (1 << Copy_u8PIN);
                        }
                    /* If the value entered by the user is low : clear the pin */
                    else if (Copy_u8VALUE == GPIO_LOW)
                        {
                                 /* Using ODR output data register GPIOA_ODR |=  (1 << (BIT)) 3 cycles */ 
                            // CLR_BIT(GPIOC_ODR , Copy_u8PIN);
                                 /* Using BRR Bit Reset Regiset GPIOA_BRR = (1 << (BIT)) 2 cycles */
                            GPIOC_BRR = (1 << Copy_u8PIN);
                        }
                    break;

        default : /* just to avoid any compiler errors */ 
                    break;
    }

}

            /* ----- Function that get the pin value either "High or Low" ------- */
u8 MGPIO_u8GetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN)
{
    u8 LOC_u8Value = 0;
    switch (Copy_u8PORT)
    {
                    /* Get the pin value from the Input Data Register */
        case GPIOA : LOC_u8Value = GET_BIT(GPIOA_IDR , Copy_u8PIN); break;
        case GPIOB : LOC_u8Value = GET_BIT(GPIOB_IDR , Copy_u8PIN); break;
        case GPIOC : LOC_u8Value = GET_BIT(GPIOC_IDR , Copy_u8PIN); break;
    }
    return LOC_u8Value;
}

            /* -----  Function that locks pin mode untill the next reset  ------- */
void MGPIO_u8LockPin(u8 Copy_u8PORT , u8 Copy_u8PIN)
{
    
}
