/****************************************************************************************/
/* Author : AbdElrahman I.Zaki                                                          */
/* Date   : 19 September 2020                                                           */
/* Version: V02                                                                         */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 USART Communication Protocol                    */
/*              program file                                                            */
/****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

#define THRESHOLD_VALUE  9000000UL

void (*MUSART1_CallBack)(void);

void MUSART_voidInit(void)
{
    /* Set the Mantissa value of the Baud Rate */
	u32 Local_u32Mantissa = (F_CPU) / (16 * USART1_BAUD_RATE);

	u32 Local_u32Fraction = (((F_CPU * 100) / (16 * USART1_BAUD_RATE)) % 100) * 16;

    /* If the value of fraction is > 1500, add one to Mantissa */
	if(Local_u32Fraction > 1500)
    { 
        Local_u32Mantissa += 1; 
        Local_u32Fraction = 0; 
    }

	#if USART1_STATUS == USART1_ENABLE

		USART1_Ptr -> USART_SR = 0; /* Reset the Status Register */

                /* Set the word size */
		#if   USART1_WORD_LENGTH == _8BIT_WORD_LENGTH       
					CLR_BIT(USART1_Ptr -> USART_CR1, 12);   

		#elif USART1_WORD_LENGTH == _9BIT_WORD_LENGTH
					SET_BIT(USART1_Ptr -> USART_CR1, 12);
		#endif

                /* Parity Check Configuration  */
		#if   USART1_PARITY == PARITY_DISABLE
					CLR_BIT(USART1_Ptr -> USART_CR1, 10);

		#elif USART1_PARITY == EVEN_PARITY
					SET_BIT(USART1_Ptr -> USART_CR1, 10);
					CLR_BIT(USART1_Ptr -> USART_CR1, 11);

		#elif USART1_PARITY == ODD_PARITY
					SET_BIT(USART1_Ptr -> USART_CR1, 10);
					SET_BIT(USART1_Ptr -> USART_CR1, 11);
		#endif

             /* Interrupt Configuration */
		#if  USART1_INTERRUPT == INT_DISABLE
					CLR_BIT(USART1_Ptr -> USART_CR1, 5);
					CLR_BIT(USART1_Ptr -> USART_CR1, 6);
					CLR_BIT(USART1_Ptr -> USART_CR1, 7);

		#elif USART1_INTERRUPT == TXE_INT_ENABLE
					SET_BIT(USART1_Ptr -> USART_CR1, 7);

		#elif USART1_INTERRUPT == TCE_INT_ENABLE
					SET_BIT(USART1_Ptr -> USART_CR1, 6);

		#elif USART1_INTERRUPT == RXNE_INT_ENABLE
					SET_BIT(USART1_Ptr -> USART_CR1, 5);
		#endif

            /* USART_1 Trasmitter Configeration */
		#if   USART1_TRANSMITTER == TRANSMITTER_ENABLE
					SET_BIT(USART1_Ptr -> USART_CR1, 3);

		#elif USART1_TRANSMITTER == TRANSMITTER_DISABLE
					CLR_BIT(USART1_Ptr -> USART_CR1, 3);
		#endif

            /* USART_1 Trasmitter Configeration */
		#if   USART1_RECEIVER == RECEIVER_ENABLE
					SET_BIT(USART1_Ptr -> USART_CR1, 2);

		#elif USART1_RECEIVER == RECEIVER_DISBLE
					CLR_BIT(USART1_Ptr -> USART_CR1, 2);
		#endif

            /* USART_1 Stop Bit Configeration */
		#if   USART1_STOP_BITS == ONE_STOP_BIT
					CLR_BIT(USART1_Ptr -> USART_CR2, 12); 
                    CLR_BIT(USART1_Ptr -> USART_CR2, 13);

		#elif USART1_STOP_BITS == HALF_STOP_BIT
					SET_BIT(USART1_Ptr -> USART_CR2, 12); 
                    CLR_BIT(USART1_Ptr -> USART_CR2, 13);

		#elif USART1_STOP_BITS == TWO_STOP_BIT
					CLR_BIT(USART1_Ptr -> USART_CR2, 12); 
                    SET_BIT(USART1_Ptr -> USART_CR2, 13);

		#elif USART1_STOP_BITS == ONE_AND_HALF_STOP_BIT
					SET_BIT(USART1_Ptr -> USART_CR2, 12); 
                    SET_BIT(USART1_Ptr -> USART_CR2, 13);
		#endif


		USART1_Ptr -> USART_BRR = (Local_u32Mantissa << 4) | (Local_u32Fraction / 100);
		SET_BIT(USART1_Ptr -> USART_CR1, 13);


	#elif USART1_STATUS == USART1_DISABLE
		CLR_BIT(USART1_Ptr -> USART_CR1, 0);

	#endif

}

void MUSART1_voidSendCharSync(u8 Copy_u8Char)
{
    /* Insert the character to Data Register */
	USART1_Ptr -> USART_DR = Copy_u8Char;
    /* Hold for Transmission Completion */
	while(GET_BIT(USART1_Ptr -> USART_SR, 6) == 0);
    /* Clear Transmission flag */
	CLR_BIT(USART1_Ptr -> USART_SR, 6);
}

void MUSART1_voidSendStringSynch(u8 * Copy_ptrString)
{
    u8 Local_u8Iterator = 0;
    /* Insertion loop to insert string characters into the data register */
	while (Copy_ptrString[Local_u8Iterator] != '\0')
    {
		MUSART1_voidSendCharSync(Copy_ptrString[Local_u8Iterator]);
		Local_u8Iterator++ ;
	}

}


u8 MUSART1_u8RecCharSynch(void)
{
	u8  Local_u8Data  = 0 ;
	u32 Local_TimeOut = 0 ;

    /* Clear RXNE flag  */
	CLR_BIT(USART1_Ptr -> USART_SR, 5);

    /* Hold till shift register has been transferred to the USART_DR register */
	while((GET_BIT(USART1_Ptr -> USART_SR, 5) == 0) && (Local_TimeOut < THRESHOLD_VALUE))
	{
		Local_TimeOut++;
	}
	if(Local_TimeOut == THRESHOLD_VALUE)
	{
		Local_u8Data = 255;
	}
	else
	{
		Local_u8Data = USART1_Ptr -> USART_DR;
	}
	return Local_u8Data;
}

u8 String[20];
u8 * MUSART1_PtrReadStringSynch(void)
{
	u8 Local_Iterator = 0, Local_u8DataCome;

	while((Local_u8DataCome = MUSART1_u8RecCharSynch()) != 13)
    {
		String[Local_Iterator] = Local_u8DataCome;
		Local_Iterator++;
	}

	String[Local_Iterator] = '\0';

	return (String);
}


void MUSART1_voidSetCallBack(void (*ptr) (void))
{
	MUSART1_CallBack = ptr;
}

void USART1_IRQHandler(void)
{
	USART1_Ptr -> USART_SR = 0;
	MUSART1_CallBack();
}



