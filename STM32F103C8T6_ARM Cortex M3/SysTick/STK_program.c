/**********************************************************************************/
/* Author : AbdElrahman I.Zaki                                                    */
/* Date   : 26 August 2020                                                        */
/* Version: V01                                                                   */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 Systick program                           */
/**********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

u32 Global_u32CLK = 0;

/* Global variable pointer to function */
static void (*MSTK_Callback) (void);   

/* Configure Clock Type from configuration file 
    disable systick interrupt, systick itself */
void MSTK_voidInit(void)  // AHB or AHB/8
{
    #if   (STK_CLOCK_SRC == AHB_CLK_SRC)
          SET_BIT(MSTK_Ptr -> STK_CTRL , STK_CLOCK_SRC);
		  /* Set the Global variable exact CLK SRC value */
		  Global_u32CLK = STK_AHB_CLK;

    #elif (STK_CLOCK_SRC == AHB_CLK_SRC_Div_8)
		  CLR_BIT (MSTK_Ptr -> STK_CTRL , STK_CLOCK_SRC);
		  /* Set the Global variable exact CLK SRC value */
		  Global_u32CLK = STK_AHB_CLK / 8;
	
	#else 
		#error "Invalid SysTick Configuration error"
	#endif 
}  

/* Synchronous function to stop the processor from 
    doing anything untill the timer finish counting "Polling" 
	i/p : time in uSec */
void MSTK_voidSetBusyWait(u32 Copy_u32Time)
{
	/* Reset Timer */
    MSTK_Ptr -> STK_VAL = 0;

	/* Set Load Register */
    MSTK_Ptr -> STK_LOAD = Copy_u32Time;      

    /* Start SysTick Timer */
    SET_BIT(MSTK_Ptr -> STK_CTRL, STK_CTRL_ENABLE);

    /* Wait till flag is raised "Polling" */
    while( !(GET_BIT(MSTK_Ptr -> STK_CTRL , STK_CTRL_COUNTFLAG))); 

    /* Stop Timer */
    CLR_BIT(MSTK_Ptr -> STK_CTRL, STK_CTRL_ENABLE);
}



        /* Asynchronous function to let the timer start counting and 
             fire an interrupt and keep repeating "el le3b f el ISR" */
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Time , void (*Copy_Func)(void))
{
	/* Reset Timer */
	MSTK_Ptr -> STK_VAL = 0;

	/* Set Load Register */
    MSTK_Ptr -> STK_LOAD = Copy_u32Time;  
	 								
	/* Pass the function to ISR */
	MSTK_Callback = Copy_Func;
	
	/* Start Timer */
	SET_BIT(MSTK_Ptr -> STK_CTRL , STK_CTRL_ENABLE);
	
	/* Enable Interrupt */
	SET_BIT(MSTK_Ptr -> STK_CTRL , STK_CTRL_TICKINT);
}


/* Function that stop timer counting down "Only for Asynchronous functions" */
void MSTK_voidStopTimer(void)
{
	/* Stop Timer */
	CLR_BIT(MSTK_Ptr -> STK_CTRL , STK_CTRL_ENABLE);
	
	/* Disable Interrupt */
	CLR_BIT(MSTK_Ptr -> STK_CTRL , STK_CTRL_TICKINT);	
}

void MSTK_voidResumeTimer(void)
{
	/* Start Timer */
	SET_BIT(MSTK_Ptr -> STK_CTRL , STK_CTRL_ENABLE);
	
	/* Enable Interrupt */
	SET_BIT(MSTK_Ptr -> STK_CTRL , STK_CTRL_TICKINT);	
}

/* To get number of counts already been counted */
u32 MSTK_u32GetElapsedTime()
{
	/* Num of counts give - Num of counts consumed */
	u32 Local_u32ElapsedTime =  (MSTK_Ptr -> STK_LOAD) - (MSTK_Ptr -> STK_VAL);

	return Local_u32ElapsedTime;
}

/* To get the remaining counts prior the interrupt */
u32 MSTK_u32GetRemainingTime()
{
	u32 Local_u32RemainingTime = MSTK_Ptr -> STK_VAL;

	return Local_u32RemainingTime ;
}


/* Called by HW */
void SysTick_Handler(void)
{
    MSTK_Callback();
}
