/*****************************************************/
/* Author      : AbdElrahman I.Zaki                  */
/* Version     : v02                                 */
/* date        : 14/9/2020                           */
/* Description : Delay funtion program		          */
/*****************************************************/



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"

#include "DELAY_interface.h"


void _delay_mS(u32 Copy_u32Time)
{
	MSTK_voidInit();
	/* Disable INT */
	MSTK_voidIntStatus(STK_INT_DIS);

	MSTK_voidStart(Copy_u32Time * 1000);

	/* Wiat Flag Polling */
	while( MSTK_u8ReadFlag() == 0 );

}


/* Suppose That The Clock System (AHB) = 8MHZ EXT & The Systick Clock Is = AHB/8 */
void _delay_uS(u32 Copy_u32Time)
{
	MSTK_voidInit();
	/* Disable INT */
	MSTK_voidIntStatus(STK_INT_DIS);

	MSTK_voidStart(Copy_u32Time);

	/* Wiat Flag Polling */
	while( MSTK_u8ReadFlag() == 0 );
}
