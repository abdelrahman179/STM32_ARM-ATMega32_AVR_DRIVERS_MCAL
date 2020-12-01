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
#include "SONG.h"


/* Make sure to make the array const to be save in flash not the 
    RAM as RAM = 20kByte & Flash = 64KByte */

volatile u32 Song_Counter = 0;

void DAC_CALLBACK(void)
{
    /* Every 125uS insert one array element in the DR register */
	MGPIO_voidSetPortValue(DAC_PORT, DAC_PORT_LH, Song_Array[Song_Counter]);
    /* Play a new sample */
	Song_Counter++;
    /* array max, reset */
	if(Song_Counter == Song_Length)
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
	MSTK_voidStart(125);
}

/* int main()
{
    // HSE, 8MHz 
    MRCC_voidInit();
    // Enable GPIOA CLK 
    MRCC_voidEnablePeripheral(RCC_APB2, GPIOA);
    
    MGPIO_voidSetPortDirection(GPIOA, 0b0010);

    MSTK_voidInit();
    
    MSTK_voidSetIntervalPeriodic(125, voidSetDAC);
    while(1)
    {

    }
    return 0;
}*/
