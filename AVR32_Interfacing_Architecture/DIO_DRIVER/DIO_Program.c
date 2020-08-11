/*************************************************************/
/*  AUTHOR     : AbdElrahman Ibrahim Zaki                    */
/*  DATE       : 10th of June 2020											 */
/*  VERSION	   : V0.1										 */
/*  DESCRIPTION: DIO Program                                  */
/*                                                           */
/*************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"

#include "DIO_Register.h"


// DDR's direction either input or output
void DIO_voidSetPinDirection(u8 PORT ,u8 PIN, u8 Direction)
{
	// Range Check
	if ( PORT < 4 && PIN < 8 )
	{
		if ( Direction == OUTPUT )
		{
			switch(PORT)
			{
			// DDR output is 1 in order to switch on the Output REG
				case PORTA : SET_BIT(DDRA_REG , PIN);  break;
				case PORTB : SET_BIT(DDRB_REG , PIN);  break;
				case PORTC : SET_BIT(DDRC_REG , PIN);  break;
				case PORTD : SET_BIT(DDRD_REG , PIN);  break;
			}
		}
		else if ( Direction == INPUT )
		{
			switch(PORT)
			{
		  // DDR output is 1 in order to switch on the Input REG
				case PORTA : CLR_BIT(DDRA_REG , PIN);  break;
				case PORTB : CLR_BIT(DDRB_REG , PIN);  break;
				case PORTC : CLR_BIT(DDRC_REG , PIN);  break;
				case PORTD : CLR_BIT(DDRD_REG , PIN);  break;
			}
		}
		else 
		{
			// Do nothing 
		}
	}
	else 
	{
		// Do nothing 
	}
	
}

// Set Pin value either low or high
void DIO_voidSetPinValue(u8 PORT ,u8 PIN, u8 Value)
{
	// Range Check
	if ( PORT < 4 && PIN < 8 )
	{
		if ( Value == HIGH )
		{
			switch(PORT)
			{
			// Set the Output Port Register to HIGH to get 1
				case PORTA : SET_BIT(PORTA_REG , PIN);  break;
				case PORTB : SET_BIT(PORTB_REG , PIN);  break;
				case PORTC : SET_BIT(PORTC_REG , PIN);  break;
				case PORTD : SET_BIT(PORTD_REG , PIN);  break;
			}
		}
		else if ( Value == LOW )
		{
			switch(PORT)
			{
			// Clear the Output Port Register to LOW to get 0
				case PORTA : CLR_BIT(PORTA_REG , PIN);  break;
				case PORTB : CLR_BIT(PORTB_REG , PIN);  break;
				case PORTC : CLR_BIT(PORTC_REG , PIN);  break;
				case PORTD : CLR_BIT(PORTD_REG , PIN);  break;
			}
		}
		else 
		{
			// Do nothing 
		}
	}
	else 
	{
		// Do nothing 
	}
}


u8 DIO_u8GetPinValue(u8 PORT ,u8 PIN)
{
	u8 Local_u8PinValue = 0;    // initialize any local variable with 0 
	
	if (PORT < 4 && PIN < 8)
	{	
	    switch(PORT)
			{
				case PORTA : Local_u8PinValue = GET_BIT(PINA_REG , PIN);  break;
				case PORTB : Local_u8PinValue = GET_BIT(PINB_REG , PIN);  break;
				case PORTC : Local_u8PinValue = GET_BIT(PINC_REG , PIN);  break;
				case PORTD : Local_u8PinValue = GET_BIT(PIND_REG , PIN);  break;
			}
    }
	else
	{
		Local_u8PinValue = 0XFF;
	}
	return Local_u8PinValue;
}


// To set all the DDRs REG pins to get output or input M.C.
void DIO_voidSetPortDirection(u8 PORT, u8 Direction)
{
	/* Check on the Required PORT Number */
		switch (PORT)
		{

		case     PORTA: DDRA_REG = Direction; break;
		case     PORTB: DDRB_REG = Direction; break;
		case     PORTC: DDRC_REG = Direction; break;
		case     PORTD: DDRD_REG = Direction; break;

		default: /* Wrong Port ID */        break;
		}
}


// To set all the PORTs REG pins to get HIGH or LOW values
void DIO_voidSetPortValue(u8 PORT, u8 Value)
{
	/* Check on the Required PORT Number */
		switch (PORT)
		{
		case     PORTA: PORTA_REG = Value; break;
		case     PORTB: PORTB_REG = Value; break;
		case     PORTC: PORTC_REG = Value; break;
		case     PORTD: PORTD_REG = Value; break;

		default: /* Wrong Port ID */       break;
		}
}
























