/****************************************************************************/
/* Author : AbdElrahman I.Zaki                                              */
/* Date   : 7 September 2020                                                */
/* Version: V02                                                             */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 DAC Program File                    */
/****************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "DAC_interface.h"
#include "DAC_config.h"

/* Song array */
#include "file.h"




/* Make sure to make the array const to be save in flash not the 
    RAM as RAM = 20kByte & Flash = 64KByte */

volatile u32 Song_Counter = 0;

void DAC_CALLBACK(void)
{
    /* Every 125uS insert one array element in the DR register */
	MGPIO_voidSetPortValue(DAC_PORT, DAC_PORT_LH, CAS_raw[Song_Counter]);
    /* Play a new sample */
	Song_Counter++;
    /* array max, reset */
	if(Song_Counter == SONG_LENGTH)
    {
		Song_Counter = 0;
	}
}

void MDAC_voidInit(void)
{
    /* Output push pull 10MHz PIN0 - PIN7 */
    MGPIO_voidSetPortDirection(DAC_PORT, DAC_PORT_LH, OUTPUT_SPEED_10MHZ_PP);
    /* Initialize the Systick */
	MSTK_voidInit();
}

void MDAC_voidPlay(void)
{
	MSTK_voidSetCallBack(DAC_CALLBACK);
    /* Signal output every 125uS call voidSetDAC function */
	MSTK_voidStart(TIME_PER_SAMPLE);
}

void MDAC_voidChangeFreq(u8 Copy_u8Time)
{
	MSTK_voidSetCallBack(DAC_CALLBACK);
	    /* Signal output every 125uS call voidSetDAC function */
	MSTK_voidStart(Copy_u8Time);
}

