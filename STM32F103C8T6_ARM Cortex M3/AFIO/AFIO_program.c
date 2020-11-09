/*******************************************************************************/
/* Author : AbdElrahman I.Zaki                                                 */
/* Date   : 17 August 2020                                                     */
/* Version: V01                                                                */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 AFIO Program 	             		   */
/*******************************************************************************/



/* Library includes */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

/* Module includes */
#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"
#include "GPIO_interface.h"


void AFIO_voidSetEXTIConfiguration(u8 Copy_u8EXTI_Line ,u8 Copy_u8PortMap)
{
	
	u8 LOC_u8RegIndex = 0;

	if( Copy_u8EXTI_Line <= 3 )
	{
		LOC_u8RegIndex    = 0 ;
	}
	else if( Copy_u8EXTI_Line <= 7 )
	{
		LOC_u8RegIndex    = 1 ;
		Copy_u8EXTI_Line -= 4 ;
	}
	else if( Copy_u8EXTI_Line <= 11 )
	{
		LOC_u8RegIndex    = 2 ;
		Copy_u8EXTI_Line -= 8 ;
	}
	else if( Copy_u8EXTI_Line <= 15 )
	{
		LOC_u8RegIndex    = 3  ;
		Copy_u8EXTI_Line -= 12 ;
	}

	/* Clear the four bits first */
	AFIO_Ptr -> EXTICRx[LOC_u8RegIndex] &= ~(( 0b1111) << (Copy_u8EXTI_Line * 4));
	/* Write into the four bits */
	AFIO_Ptr -> EXTICRx[LOC_u8RegIndex] |= (Copy_u8PortMap) << (Copy_u8EXTI_Line * 4);
}
