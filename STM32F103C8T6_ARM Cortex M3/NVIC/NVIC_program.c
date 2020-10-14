/********************************************************************/
/* Author : AbdElrahman I.Zaki                                      */
/* Date   : 19 August 2020                                          */
/* Version: V01                                                     */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 NVIC Program                */
/********************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNum)
{
    if(Copy_u8IntNum <= 31)
    {
        /* Since writing zero on the NVIC_ISER0 has no effect we can use the below line istead of SET_BIT to save processing cycles */
        NVIC_ISER0 = (1 << Copy_u8IntNum);
        // SET_BIT(NVIC_ISER0 , Copy_u8IntNum);
    }
    else if(Copy_u8IntNum <= 59)
    {
        /* As the ISER1 starts bits starts from 0 - 31 but the interrupt counting from 32 */
        Copy_u8IntNum -= 32; 
        NVIC_ISER1 = (1 << Copy_u8IntNum);
        // SET_BIT(NVIC_ISER1 , Copy_u8IntNum);
    }
    else
    {
         /* Return Error */
    }
}


void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNum)
{
    if(Copy_u8IntNum <= 31)
    {
        /* Since writing zero on the NVIC_ICER0 has no effect we can use the below line istead of SET_BIT to save processing cycles */
        NVIC_ICER0 = (1 << Copy_u8IntNum);
        // SET_BIT(NVIC_ICER0 , Copy_u8IntNum);
    }
    else if(Copy_u8IntNum <= 59)
    {
        /* As the ICER1 starts bits starts from 0 - 31 but the interrupt counting from 32 */
        Copy_u8IntNum -= 32; 
        NVIC_ICER1 = (1 << Copy_u8IntNum);
        // SET_BIT(NVIC_ICER1 , Copy_u8IntNum);
    }
    else
    {
         /* Return Error */
    }
}

void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNum)
{
    if(Copy_u8IntNum <= 31)
    {
        /* Since writing zero on the NVIC_ISPR0 has no effect we can use the below line istead of SET_BIT to save processing cycles */
        NVIC_ISPR0 = (1 << Copy_u8IntNum);
        // SET_BIT(NVIC_ISPR0 , Copy_u8IntNum);
    }
    else if(Copy_u8IntNum <= 59)
    {
        /* As the ISPR1 starts bits starts from 0 - 31 but the interrupt counting from 32 */
        Copy_u8IntNum -= 32; 
        NVIC_ISPR1 = (1 << Copy_u8IntNum);
        // SET_BIT(NVIC_ISPR1 , Copy_u8IntNum);
    }
    else
    {
         /* Return Error */
    }
}

void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNum)
{
    if(Copy_u8IntNum <= 31)
    {
        /* Since writing zero on the NVIC_ICPR0 has no effect we can use the below line istead of SET_BIT to save processing cycles */
        NVIC_ICPR0 = (1 << Copy_u8IntNum);
        // SET_BIT(NVIC_ICPR0 , Copy_u8IntNum);
    }
    else if(Copy_u8IntNum <= 59)
    {
        /* As the ICPR1 starts bits starts from 0 - 31 but the interrupt counting from 32 */
        Copy_u8IntNum -= 32;  
        NVIC_ICPR1 = (1 << Copy_u8IntNum);
        // SET_BIT(NVIC_ICPR1 , Copy_u8IntNum);
    }
    else
    {
         /* Return Error */
    }
}


u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNum)
{
    u8 Local_u8Result;
    if(Copy_u8IntNum <= 31)
    {
        Local_u8Result = GET_BIT(NVIC_IABR0 , Copy_u8IntNum);
    }
    else if(Copy_u8IntNum <= 59)
    {
        /* As the IABR1 starts bits starts from 0 - 31 but the interrupt counting from 32 */
        Copy_u8IntNum -= 32;  
        Local_u8Result = GET_BIT(NVIC_IABR1 , Copy_u8IntNum);
    }
    else
    {
         /* Return Error */
    }

    return Local_u8Result;
}



