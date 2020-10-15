/****************************************************************/
/*   Author          :    AbdElrahman Ibrahim Zaki		    */
/*	 Date 				:    25th of June 2020 				      	*/
/*	 Version 			:    1.0V 							 	              */
/*	 Description 		:    General Interrupt Program Configuration    */
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_interface.h"
#include "GIE_private.h"

// enable and disable global interrupt through these functions
void GIE_voidEnable(void)
{
	SET_BIT(SREG , 7);
}

void GIE_voidDisable(void)
{
	CLR_BIT(SREG , 7);
}
