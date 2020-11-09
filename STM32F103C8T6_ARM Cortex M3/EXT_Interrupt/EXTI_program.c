/**********************************************************************************/
/* Author : AbdElrahman I.Zaki                                                    */
/* Date   : 21 August 2020                                                        */
/* Version: V01                                                                   */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 EXT Int program                           */
/**********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

#include "AFIO_interface.h"

static void (* EXTI_CallBack[16]) (void);

/* EXTI Preprossing Signal Latch Initialization, cannot be configured during run time */
void MEXTI_voidInit(u8 Copy_u8EXILine, u8 Copy_u8EXIMode)
{
    switch(Copy_u8EXIMode)
	{
	case RISING_EDGE:
		SET_BIT(EXTI_Ptr -> EXTI_RTSR , Copy_u8EXILine); break;
	case FALLING_EDGE:
		SET_BIT(EXTI_Ptr -> EXTI_FTSR , Copy_u8EXILine); break;
	case ON_CHANGE:
		SET_BIT(EXTI_Ptr -> EXTI_RTSR , Copy_u8EXILine);
		SET_BIT(EXTI_Ptr -> EXTI_FTSR , Copy_u8EXILine); break;
	}
	SET_BIT(EXTI_Ptr -> EXTI_IMR , Copy_u8EXILine); /* Enable EXTI */
}

/* Enable EXTI on Linex */
void MEXTI_voidEnableEXTI(u8 Copy_u8EXTILine)
{
     SET_BIT(EXTI_Ptr -> EXTI_IMR , Copy_u8EXTILine);
}

/* Disable EXTI on Linex */
void MEXTI_voidDisableEXTI(u8 Copy_u8EXTILine)
{
     CLR_BIT(EXTI_Ptr -> EXTI_IMR , Copy_u8EXTILine);
}

/*  - Enable Interrupt line in the EXTI_IMR, writing a '1' to this bit when it is set to
    '0' sets the corresponding pending bit in EXTI_PR resulting in an interrupt request generation.
    This bit is cleared by clearing the corresponding bit of EXTI_PR will clear this register (by writing a 1 into the bit). */
void MEXTI_voidSoftwareTrigger(u8 Copy_u8EXTILine)
{
     SET_BIT(EXTI_Ptr -> EXTI_SWIER , Copy_u8EXTILine);
}

/* This function is being called in main.c to hold an address of another function that have the ISR written by user */
void MEXTI_voidSetCallBack(void (*ptr) (void), u8 Copy_u8EXTILine)
{
    /* Since the function is being passed to CB function is local we use the global varible "pointer to function" 
        to assign to it the address of the ISR function passed to CallBack function */
    switch(Copy_u8EXTILine)
	{
		case LINE0:
			EXTI_CallBack[0] = ptr;
			break;
		case LINE1:
			EXTI_CallBack[1] = ptr;
			break;
		case LINE2:
			EXTI_CallBack[2] = ptr;
			break;
		case LINE3:
			EXTI_CallBack[3] = ptr;
			break;
		case LINE4:
			EXTI_CallBack[4] = ptr;
			break;
		case LINE5:
			EXTI_CallBack[5] = ptr;
			break;
		case LINE6:
			EXTI_CallBack[6] = ptr;
			break;
		case LINE7:
			EXTI_CallBack[7] = ptr;
			break;
		case LINE8:
			EXTI_CallBack[8] = ptr;
			break;
		case LINE9:
			EXTI_CallBack[9] = ptr;
			break;
		case LINE10:
			EXTI_CallBack[10] = ptr;
			break;
		case LINE11:
			EXTI_CallBack[11] = ptr;
			break;
		case LINE12:
			EXTI_CallBack[12] = ptr;
			break;
		case LINE13:
			EXTI_CallBack[13] = ptr;
			break;
		case LINE14:
			EXTI_CallBack[14] = ptr;
			break;
		case LINE15:
			EXTI_CallBack[15] = ptr;
			break;	
	}
}

/* EXI 0 IRQ Handler */
void EXTI0_IRQHandler(void)
{
    EXTI_CallBack[0]();
    // Clear pending bit of EXTI0 by setting it to 1
    SET_BIT(EXTI_Ptr -> EXTI_PR , 0);
}


