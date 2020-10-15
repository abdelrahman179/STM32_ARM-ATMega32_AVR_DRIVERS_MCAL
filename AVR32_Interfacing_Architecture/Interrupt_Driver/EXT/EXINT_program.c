/****************************************************************/
/*   Author          :    AbdElrahman Ibrahim Zaki		    */
/*	 Date 				:    25th of June 2020 				          	*/
/*	 Version 			:    1.0V 							                	*/
/*	 Description 		:  External Interrupt Program file   */
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXINT_interface.h"
#include "EXINT_private.h"
#include "EXINT_config.h"



#define NULL (void *)0
void (*x)(void) = NULL;
void (*y)(void) = NULL;
void (*z)(void) = NULL;

void EXT_INT_voidInit(void)
{
	/* Repeat the Interrupt as long as the signal is at low level */
	#if  SENSE_MODE == LOW_LEVEL
	     CLR_BIT(MCUCR , 0);
		 CLR_BIT(MCUCR , 1);
    /* Interrupt will occur at any signal stage */
	#elif  SENSE_MODE == IOC
	     SET_BIT(MCUCR , 0);
		 CLR_BIT(MCUCR , 1);
    /* Interrupt will occur at any falling edge of the signal */
    #elif  SENSE_MODE == FALLING_EDGE
	     CLR_BIT(MCUCR , 0);
		 SET_BIT(MCUCR , 1);
    /* Interrupt will occur at any falling edge of the signal */
    #elif  SENSE_MODE == RISING_EDGE
	     SET_BIT(MCUCR , 0);
		 SET_BIT(MCUCR , 1);
	#else  
        #error  "Wrong Sense Mode Selection"	
	
	#endif	 
	
	CLR_BIT(GICR , 6);
}

void EXT_INT_voidEnable(void)
{
    #if   INTERRUPT_CH == EXT0
	// Peripheral Interrupt Enable = INT0
	SET_BIT(GICR , 6);
	CLR_BIT(GICR , 5);
	CLR_BIT(GICR , 5);

    #elif   INTERRUPT_CH == EXT1
	// Peripheral Interrupt Enable = INT1
	SET_BIT(GICR , 7);
	CLR_BIT(GICR , 6);
	CLR_BIT(GICR , 5);

    #elif   INTERRUPT_CH == EXT2
	// Peripheral Interrupt Enable = INT2
	SET_BIT(GICR , 5);
	CLR_BIT(GICR , 7);
	CLR_BIT(GICR , 5);

    #elif   INTERRUPT_CH == EXT0_EXT1
	// Peripheral Interrupt Enable = INT0 and INT2
	SET_BIT(GICR , 6);
	SET_BIT(GICR , 7);
	CLR_BIT(GICR , 5);

    #elif   INTERRUPT_CH == EXT0_EXT2
	// Peripheral Interrupt Enable = INT0 and INT2
	SET_BIT(GICR , 6);
	SET_BIT(GICR , 5);
	CLR_BIT(GICR , 7);

    #elif   INTERRUPT_CH == EXT1_EXT2
	// Peripheral Interrupt Enable = INT1 and INT2
	SET_BIT(GICR , 5);
	SET_BIT(GICR , 7);
	CLR_BIT(GICR , 6);

    #elif   INTERRUPT_CH == EXT0_EXT1_EXT2
	// Peripheral Interrupt Enable = INT1 , INT2 and INT 3
	SET_BIT(GICR , 7);
	SET_BIT(GICR , 6);
	SET_BIT(GICR , 5);

    #else

       #error       "Wrong Interrupt Channel Selection"

    #endif
}

void EXT_INT_voidDisable(void)
{
	CLR_BIT(GICR , 7);
	CLR_BIT(GICR , 6);
	CLR_BIT(GICR , 5);
}

// pointer to function that allow MCAL to call a function from the Application layer
void EXT0_INT_voidSetCallBack(void (*pf)(void))
{
	x = pf;
}

void EXT1_INT_voidSetCallBack(void (*pf)(void))
{
	y = pf;
}

void EXT2_INT_voidSetCallBack(void (*pf)(void))
{
	z = pf;
}

// To notify the Linker that it's a used function not to optimize it
// External Interrupt 0
void __vector_1 ()  __attribute__((signal , used));
void __vector_1 () 
{
	x();
}

// External Interrupt 1
void __vector_2 ()  __attribute__((signal , used));
void __vector_2 ()
{
	y();
}

// External Interrupt 2
void __vector_3 ()  __attribute__((signal , used));
void __vector_3 ()
{
	z();
}
