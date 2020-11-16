/*********************************************************/
/* Author : AbdElrahman I.Zaki                           */
/* Date   : 10 August 2020                               */
/* Version: V03                                          */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 GPIO program     */
/*********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"


            /* ------ Function that sets the pin "mode and configuration" ------- */
void MGPIO_voidSetPinDirection(GPIO_Port_ID Copy_PORT , GPIO_Pin_No Copy_PIN , u8 Copy_u8MODE)
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
                            MGPIOA -> CRL &= ~ ((0b1111) << (Copy_PIN * 4));
                            /* Set the chosen MODE on the chosen PIN */
                            MGPIOA -> CRL |=   ((Copy_u8MODE) << (Copy_PIN * 4));
                        }
                    /* Check if Pin lies between 8-15 noting that each pin consists of 4 bits "CRH Configuration Register High" */
                    else if (Copy_PIN <= 15)
                        {
                            /* To get the exact chosen Pin when it's multiplied by 4 */
                            Copy_PIN = Copy_PIN - 8;
                            /* Reset the chosen PIN which consists of 4 bits not all the CRH Register */
                            MGPIOA -> CRH &= ~ ((0b1111) << (Copy_PIN * 4));
                            /* Set the chosen MODE on the chosen PIN */
                            MGPIOA -> CRH |=   ((Copy_u8MODE) << (Copy_PIN * 4));
                        }
                    break;

        case GPIOB :
                    /* Check if Pin lies between 0-7 noting that each pin consists of 4 bits "CRL Configuration Register Low"  */
                    if (Copy_PIN <= 7) 
                        {
                            /*  Reset the chosen PIN which consists of 4 bits not all the CRL Register 
                                As long as we will use logical operation we have to reset first "not to over-write"  */
                                // Note : We can use 4 SET-PINss but it consumes more clocks        
                            MGPIOB -> CRL &= ~ ((0b1111) << (Copy_PIN * 4));
                            /* Set the chosen MODE on the chosen PIN */
                            MGPIOB -> CRL |=   ((Copy_u8MODE) << (Copy_PIN * 4));
                        }
                    /* Check if Pin lies between 8-15 noting that each pin consists of 4 bits "CRH Configuration Register High" */
                    else if (Copy_PIN <= 15)
                        {
                            /* To get the exact chosen Pin when it's multiplied by 4 */
                            Copy_PIN = Copy_PIN - 8;
                            /* Reset the chosen PIN which consists of 4 bits not all the CRH Register */
                            MGPIOB -> CRH &= ~ ((0b1111) << (Copy_PIN * 4));
                            /* Set the chosen MODE on the chosen PIN */
                            MGPIOB -> CRH |=   ((Copy_u8MODE) << (Copy_PIN * 4));
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
                            MGPIOC -> CRL &= ~ ((0b1111) << (Copy_PIN * 4));
                            /* Set the chosen MODE on the chosen PIN */
                            MGPIOC -> CRL |=   ((Copy_u8MODE) << (Copy_PIN * 4));
                        }
                    /* Check if Pin lies between 8-15 "CRH Register" */
                    else if (Copy_PIN <= 15)
                        {
                            /* To get the exact chosen Pin when it's multiplied by 4 */
                            Copy_PIN = Copy_PIN - 8;
                            /* Reset the chosen PIN which consists of 4 bits not all the CRH Register */
                            MGPIOC -> CRH &= ~ ((0b1111) << (Copy_PIN * 4));
                            /* Set the chosen MODE on the chosen PIN */
                            MGPIOC -> CRH |=   ((Copy_u8MODE) << (Copy_PIN * 4));
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
                            // SET_BIT(MGPIOA -> ODR , Copy_PIN);
                                 /* Using BSRR Bit Set Reset Register GPIOA_BSR = (1 << (BIT)) 2 cycles */
                            MGPIOA -> BSR = (1 << Copy_PIN);
                        }
                    /* If the value entered by the user is low : clear the pin */
                    else if (Copy_u8VALUE == LOW)
                        {
                                 /* Using ODR output data Register GPIOA_ODR |=  (1 << (BIT)) 3 cycles */   
                            // CLR_BIT(MGPIOA -> ODR , Copy_PIN);
                                 /* Using BRR Bit Reset Register GPIOA_BRR = (1 << (BIT)) 2 cycles */
                            MGPIOA -> BRR = (1 << Copy_PIN);
                        }
                    break;

        case GPIOB : 
                    /* If the value entered by the user is high : set the pin */
                    if (Copy_u8VALUE == HIGH) 
                        {
                                 /* Using ODR output data register GPIOA_ODR |=  (1 << (BIT)) 3 cycles */
                            //SET_BIT(MGPIOB -> ODR , Copy_PIN);
                                 /* Using BSRR Bit Set Reset Register GPIOA_BSR = (1 << (BIT)) 2 cycles */
                            MGPIOB -> BSR = (1 << Copy_PIN);
                        }
                    /* If the value entered by the user is low : clear the pin */
                    else if (Copy_u8VALUE == LOW)
                        {   
                                 /* Using ODR output data register GPIOA_ODR |=  (1 << (BIT)) 3 cycles */    
                            // CLR_BIT(MGPIOB -> ODR , Copy_PIN);
                                 /* Using BRR Bit Reset Register GPIOA_BRR = (1 << (BIT)) 2 cycles */
                            MGPIOB -> BRR = (1 << Copy_PIN);
                        }
                    break;

        case GPIOC : 
                    /* If the value entered by the user is high : set the pin */
                    if (Copy_u8VALUE == HIGH) 
                        {
                                 /* Using ODR output data register GPIOA_ODR |=  (1 << (BIT)) 3 cycles */
                            // SET_BIT(MGPIOC -> ODR , Copy_PIN);
                                 /* Using BSRR Bit Set Reset Register GPIOA_BSR = (1 << (BIT)) 2 cycles */
                            MGPIOC -> BSR = (1 << Copy_PIN);
                        }
                    /* If the value entered by the user is low : clear the pin */
                    else if (Copy_u8VALUE == LOW)
                        {
                                 /* Using ODR output data register GPIOA_ODR |=  (1 << (BIT)) 3 cycles */ 
                            // CLR_BIT(MGPIOC -> ODR , Copy_PIN);
                                 /* Using BRR Bit Reset Register GPIOA_BRR = (1 << (BIT)) 2 cycles */
                            MGPIOC -> BRR = (1 << Copy_PIN);
                        }
                    break;

        default : /* just to avoid any compiler errors */ 
                    break;
    }

}

            /* ----- Function that get the pin value either "High or Low" ------- */
u8 MGPIO_u8GetPinValue(GPIO_Port_ID Copy_PORT , GPIO_Pin_No Copy_PIN)
{
    u8 LOC_u8Value = 0;
    switch (Copy_PORT)
    {
                    /* Get the pin value from the Input Data Register */
        case GPIOA : LOC_u8Value = GET_BIT(MGPIOA -> IDR , Copy_PIN); break;
        case GPIOB : LOC_u8Value = GET_BIT(MGPIOB -> IDR , Copy_PIN); break;
        case GPIOC : LOC_u8Value = GET_BIT(MGPIOC -> IDR , Copy_PIN); break;
        default    :                                                  break;
    }
    return LOC_u8Value;
}

                        /* ----- Function that toggle Pin ----- */
void MGPIO_voidTogglePinValue (GPIO_Port_ID Copy_PORT , GPIO_Pin_No Copy_PIN)
{
	switch (Copy_PORT) 
    {
		case GPIOA:
			        TOG_BIT(MGPIOA -> ODR , Copy_PIN);     break;		                                    
		case GPIOB:
			        TOG_BIT(MGPIOB -> ODR , Copy_PIN);     break;		
		case GPIOC: 
			        TOG_BIT(MGPIOC -> ODR , Copy_PIN);     break;	
		default   :                                        break;
	}
}



        /* ----- Function that Set mode of all port pins ----- */
void MGPIO_voidSetPortMode(GPIO_Port_ID Copy_PORT , u8 Copy_u8MODE)
{
	for (GPIO_Pin_No PIIN_S = PIN0 ; PIIN_S <= PIN15 ; PIIN_S ++)
    {
		MGPIO_voidSetPinDirection(Copy_PORT , PIIN_S , Copy_u8MODE);
	}
}

        /* ----- Function that Set direction of all port pins ----- */
void MGPIO_VoidSetPortDirection(GPIO_Port_ID Copy_PORT , u8 Copy_u8Position , u8 Copy_u8MODE)
{

	switch(Copy_PORT)
    {
        case GPIOA:
            if      (Copy_u8Position == LOW ) 
                        { MGPIOA -> CRL = (0x11111111 * Copy_u8MODE) ; }
            else if (Copy_u8Position == HIGH) 
                        { MGPIOA -> CRH = (0x11111111 * Copy_u8MODE) ; }
            break;

        case GPIOB:
            if      (Copy_u8Position == LOW ) 
                        { MGPIOB -> CRL = (0x11111111 * Copy_u8MODE) ; }
            else if (Copy_u8Position == HIGH) 
                        { MGPIOB -> CRH = (0x11111111 * Copy_u8MODE) ; }
            break;

        case GPIOC:
            if      ( Copy_u8Position == LOW  ) 
                        { MGPIOC -> CRL = (0x11111111 * Copy_u8MODE) ; }
            else if ( Copy_u8Position == HIGH ) 
                        { MGPIOC -> CRH = (0x11111111 * Copy_u8MODE) ; }
            break;
	}
}

    /* ----- Function that Set value of all port pins ----- */
void MGPIO_voidSetPortValue(GPIO_Port_ID Copy_PORT , u8 Copy_u8Value)
{
	for (GPIO_Pin_No PIIN_S = PIN0 ; PIIN_S <= PIN15 ; PIIN_S ++)
	    {
			MGPIO_voidSetPinValue(Copy_PORT , PIIN_S , Copy_u8Value);
		}

}


/* ----- Function that get value of all port pins ----- */
u16 MGPIO_u16GetPortValue(GPIO_Port_ID Copy_PORT , u8 Copy_u8Position )
{
	u16 LOC_u16Result = 0;

	switch(Copy_PORT)
    {
        case GPIOA:
            LOC_u16Result = MGPIOA -> IDR;
            if      (Copy_u8Position == LOW )
                        { LOC_u16Result &= 0x00FF ; }
            else if (Copy_u8Position == HIGH)
                        { LOC_u16Result &= 0xFF00 ; }
            break;

        case GPIOB:
            LOC_u16Result = MGPIOB -> IDR;
            if      ( Copy_u8Position == LOW  )
                        { LOC_u16Result &= 0x00FF ; }
            else if ( Copy_u8Position == HIGH )
                        { LOC_u16Result &= 0xFF00 ; }
            break;

        case GPIOC:
            LOC_u16Result = MGPIOC -> IDR;
            if      ( Copy_u8Position == LOW  )
                        { LOC_u16Result &= 0x00FF ; }
            else if ( Copy_u8Position == HIGH )
                        { LOC_u16Result &= 0xFF00 ; }
            break;
    }
	return LOC_u16Result ;
}

void MGPIO_voidWritePins(GPIO_Port_ID Copy_PORT , GPIO_Pin_No CopyStartPinNumber , GPIO_No_Of_Pins CopyNumOfPins , u8 Copy_u8Value)
{
	switch (Copy_PORT) 
    {
		case GPIOA :
			MGPIOA -> ODR &= ~ (CopyNumOfPins << CopyStartPinNumber );
			MGPIOA -> ODR |=   (Copy_u8Value  << CopyStartPinNumber );          break;
		case GPIOB :
			MGPIOB -> ODR &= ~ (CopyNumOfPins << CopyStartPinNumber );
			MGPIOB -> ODR |=   (Copy_u8Value  << CopyStartPinNumber );          break;
		case GPIOC : 
			MGPIOC -> ODR &= ~ (CopyNumOfPins << CopyStartPinNumber );
			MGPIOC -> ODR |=   (Copy_u8Value  << CopyStartPinNumber );          break;
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
			MGPIOA -> LCK = Temp;
			/* Reset LCKK bit */
			MGPIOA -> LCK =  (1 << Copy_PIN);
			/* Set LCKK bit */
			MGPIOA -> LCK = Temp;
			/* Read LCKK bit*/
			Temp = MGPIOA -> LCK;
			/* Read LCKK bit*/
			Temp = MGPIOA -> LCK;
			break;

		case GPIOB :
			Temp |=  (1 << Copy_PIN) ;
			/* Set LCKK bit */
			MGPIOB -> LCK = Temp;
			/* Reset LCKK bit */
			MGPIOB -> LCK =  (1 << Copy_PIN);
			/* Set LCKK bit */
			MGPIOB -> LCK = Temp;
			/* Read LCKK bit*/
			Temp = MGPIOB -> LCK;
			/* Read LCKK bit*/
			Temp = MGPIOB -> LCK;
			break;

		case GPIOC : 
			Temp |= (1 << Copy_PIN);
			/* Set LCKK bit */
			MGPIOC -> LCK = Temp;
			/* Reset LCKK bit */
			MGPIOC -> LCK = (1 << Copy_PIN);
			/* Set LCKK bit */
			MGPIOC -> LCK = Temp;
			/* Read LCKK bit*/
			Temp = MGPIOC -> LCK;
			/* Read LCKK bit*/
			Temp = MGPIOC -> LCK;
			break;

		default:                    break;
	}
}
