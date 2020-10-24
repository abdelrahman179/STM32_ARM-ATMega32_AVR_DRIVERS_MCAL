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

static void (* EXTI0_CallBack) (void) = NULL;

/* EXTI Preprossing Signal Latch Initialization, cannot be configured during run time */
void MEXTI_voidInit(void)
{
    #if  (EXTI_LINE == LINE0)
        SET_BIT(EXTI_Ptr -> EXTI_IMR , LINE0);
    #elif(EXTI_LINE == LINE1)
        SET_BIT(EXTI_Ptr -> EXTI_IMR , LINE1);
    #elif(EXTI_LINE == LINE2)
        SET_BIT(EXTI_Ptr -> EXTI_IMR , LINE2);
    #elif(EXTI_LINE == LINE3)
        SET_BIT(EXTI_Ptr -> EXTI_IMR , LINE3);
    #elif(EXTI_LINE == LINE4)
        SET_BIT(EXTI_Ptr -> EXTI_IMR , LINE4);
    #elif(EXTI_LINE == LINE5)
        SET_BIT(EXTI_Ptr -> EXTI_IMR , LINE5);
    #elif(EXTI_LINE == LINE6)
        SET_BIT(EXTI_Ptr -> EXTI_IMR , LINE6);
    #elif(EXTI_LINE == LINE7)
        SET_BIT(EXTI_Ptr -> EXTI_IMR , LINE7);
    #elif(EXTI_LINE == LINE8)
        SET_BIT(EXTI_Ptr -> EXTI_IMR , LINE8);
    #elif(EXTI_LINE == LINE9)
        SET_BIT(EXTI_Ptr -> EXTI_IMR , LINE9);
    #elif(EXTI_LINE == LINE10)
        SET_BIT(EXTI_Ptr -> EXTI_IMR , LINE10);
    #elif(EXTI_LINE == LINE11)
        SET_BIT(EXTI_Ptr -> EXTI_IMR , LINE11);
    #elif(EXTI_LINE == LINE12)
        SET_BIT(EXTI_Ptr -> EXTI_IMR , LINE12);
    #elif(EXTI_LINE == LINE13)
        SET_BIT(EXTI_Ptr -> EXTI_IMR , LINE13);
    #elif(EXTI_LINE == LINE14)
        SET_BIT(EXTI_Ptr -> EXTI_IMR , LINE14);
    #elif(EXTI_LINE == LINE15)
        SET_BIT(EXTI_Ptr -> EXTI_IMR , LINE15);
    #else
        #error "Invalid EXTI Line Input"
    #endif


    #if   (EXTI_MODE == RISING_EDGE)
        SET_BIT(EXTI_Ptr -> EXTI_RTSR , EXTI_LINE);
    #elif (EXTI_MODE == FALLING_EDGE)
        SET_BIT(EXTI_Ptr -> EXTI_FTSR , EXTI_LINE);
    #elif (EXTI_MODE == ON_CHANGE)
        SET_BIT(EXTI_Ptr -> EXTI_RTSR , EXTI_LINE);
        SET_BIT(EXTI_Ptr -> EXTI_FTSR , EXTI_LINE);
    #else
        #error "Invalid Sense Mode Input"
    #endif
}

// To change Sense Mode and EXTI Line during run time as it's not possible using preprosessing
void MEXTI_voidSetSignalLatch(u8 Copy_u8EXTILine , u8 Copy_u8EXTISenseMode)
{
    swtich(Copy_u8EXTISenseMode)
    {
        case RISING_EDGE   : SET_BIT(EXTI_Ptr -> EXTI_RTSR , EXTI_LINE);  break;
        case FALLING_EDGE  : SET_BIT(EXTI_Ptr -> EXTI_FTSR , EXTI_LINE);  break;
        case ON_CHANGE     : SET_BIT(EXTI_Ptr -> EXTI_RTSR , EXTI_LINE);
                             SET_BIT(EXTI_Ptr -> EXTI_FTSR , EXTI_LINE);  break;
        default            :                                              break;
    }

    // Enable EXTI Linex passed to the function 
    SET_BIT(EXTI_Ptr -> EXTI_IMR , Copy_u8EXTILine)
}

// Enable EXTI on Linex
void MEXTI_voidEnableEXTI(u8 Copy_u8EXTILine)
{
     SET_BIT(EXTI_Ptr -> EXTI_IMR , Copy_u8EXTILine)
}

// Disable EXTI on Linex
void MEXTI_voidDisableEXTI(u8 Copy_u8EXTILine)
{
     CLR_BIT(EXTI_Ptr -> EXTI_IMR , Copy_u8EXTILine);
}

/*  - Enable Interrupt line in the EXTI_IMR, writing a '1' to this bit when it is set to
    '0' sets the corresponding pending bit in EXTI_PR resulting in an interrupt request generation.
    This bit is cleared by clearing the corresponding bit of EXTI_PR will clear this register (by writing a 1 into the bit). */
void MEXTI_voidSoftwareTrigger(u8 Copy_u8EXTILine);
{
     SET_BIT(EXTI_Ptr -> EXTI_SWIER , Copy_u8EXTILine);
}

/* This function is being called in main.c to hold an address of another function that have the ISR written by user */
void MEXTI_voidSetCallBack(void (*ptr) (void))
{
    /* Since the function is being passed to CB function is local we use the global varible "pointer to function" 
        to assign to it the address of the ISR function passed to CallBack function */
    EXTI0_CallBack = ptr;
}


void EXTI0_IRQHandler(void)
{
    EXTI0_CallBack();
    // Clear pending bit of EXTI0 by setting it to 1
    SET_BIT(EXTI_Ptr -> EXTI_PR , 0)
}



 // Example of ISR function that toggle LED in main.c
/*void main_ISR(void)
{
    // Setting Pin 2 high
    MGPIO_voidSetPinValue(GPIOA , PIN2 , HIGH);
    // Delay for 1 sec
    MSTK_voidSetBusyWait(1000000);

    // Setting Pin 2 high
    MGPIO_voidSetPinValue(GPIOA , PIN2 , LOW);
    // Delay for 1 sec
    MSTK_voidSetBusyWait(1000000);
}*/
