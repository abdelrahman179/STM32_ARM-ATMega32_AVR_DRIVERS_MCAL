/*******************************************************************************/
/* Author : AbdElrahman I.Zaki                                                 */
/* Date   : 03 September 2020                                                  */
/* Version: V01                                                                */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 Timer1 Program                         */
/*******************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIM1_private.h"
#include "TIM1_interface.h"
#include "TIM1_config.h"




void MTIM1_voidInit(void)
{
    /* Timer Counting Direction */
    #if (TIM1_DIR == UP_COUNTER)
        SET_BIT(TIM1_Ptr -> TIM1_CR1 , 4);

    #elif (TIM1_DIR == DOWN_COUNTER)
        CLR_BIT(TIM1_Ptr -> TIM1_CR1 , 4);

    #else 
        #error "Invalid Timer Counting Direction Configuration"
    #endif 

    /* Center Mode Aligned Configuration */
    #if (TIM1_CMS == EDGE_ALIGNED) 
        CLR_BIT(TIM1_Ptr -> TIM1_CR1 , 5);
        CLR_BIT(TIM1_Ptr -> TIM1_CR1 , 6);

    #elif (TIM1_CMS == CNT_DOWN_OP_COM_INT_FLAG)
        SET_BIT(TIM1_Ptr -> TIM1_CR1 , 5);
        CLR_BIT(TIM1_Ptr -> TIM1_CR1 , 6);

    #elif (TIM1_CMS == CNT_UP_OP_COM_INT_FLAG)
        CLR_BIT(TIM1_Ptr -> TIM1_CR1 , 5);
        SET_BIT(TIM1_Ptr -> TIM1_CR1 , 6);

    #elif (TIM1_CMS == CNT_UP_DOWN_OP_COM_INT_FLAG)
        SET_BIT(TIM1_Ptr -> TIM1_CR1 , 5);
        SET_BIT(TIM1_Ptr -> TIM1_CR1 , 6);

    #else 
        #error "Invalid Center Mode Aligned Configuration"
    #endif 
        

    /* ---------------- PWM Configuration ---------------- */
    
    /* PWM Channel Selection */
    #if (TIM1_PWM_OP_CHANNEL == CH_1)
        SET_BIT(TIM1_Ptr -> TIM1_CCER , 0);       // Channel 1 Capture/Compare Enable  
        

    #elif (TIM1_PWM_OP_CHANNEL == CH_2)
        SET_BIT(TIM1_Ptr -> TIM1_CCER , 4);       // Channel 2 Capture/Compare Enable 

    #elif (TIM1_PWM_OP_CHANNEL == CH_3)
        SET_BIT(TIM1_Ptr -> TIM1_CCER , 4);       // Channel 3 Capture/Compare Enable 

    #elif (TIM1_PWM_OP_CHANNEL == CH_4)
        SET_BIT(TIM1_Ptr -> TIM1_CCER , 4);       // Channel 4 Capture/Compare Enable 

    #else 
        #error "Invalid PWM Channel Selection"
    #endif  


    /* PWM Mode Selection */
    #if (TIM1_PWM_MODE == ACTIVE_HIGH) // TIMx_CNT < TIMx_CCR1 
        #if   (TIM1_PWM_OP_CHANNEL == CH_1)
              CLR_BIT(TIM1_Ptr -> TIM1_CCMR1 , 4);
              SET_BIT(TIM1_Ptr -> TIM1_CCMR1 , 5);
              SET_BIT(TIM1_Ptr -> TIM1_CCMR1 , 6);

        #elif (TIM1_PWM_OP_CHANNEL == CH_2)
              CLR_BIT(TIM1_Ptr -> TIM1_CCMR1 , 12);
              SET_BIT(TIM1_Ptr -> TIM1_CCMR1 , 13);
              SET_BIT(TIM1_Ptr -> TIM1_CCMR1 , 14);

        #elif (TIM1_PWM_OP_CHANNEL == CH_3)
              CLR_BIT(TIM1_Ptr -> TIM1_CCMR2 , 12);
              SET_BIT(TIM1_Ptr -> TIM1_CCMR2 , 13);
              SET_BIT(TIM1_Ptr -> TIM1_CCMR2 , 14);

        #elif (TIM1_PWM_OP_CHANNEL == CH_4)
              CLR_BIT(TIM1_Ptr -> TIM1_CCMR2 , 12);
              SET_BIT(TIM1_Ptr -> TIM1_CCMR2 , 13);
              SET_BIT(TIM1_Ptr -> TIM1_CCMR2 , 14);
        #endif
    
    #elif (TIM1_PWM_MODE == ACTIVE_LOW) // TIMx_CNT > TIMx_CCR1 
        #if   (TIM1_PWM_OP_CHANNEL == CH_1)
              SET_BIT(TIM1_Ptr -> TIM1_CCMR1 , 4);
              SET_BIT(TIM1_Ptr -> TIM1_CCMR1 , 5);
              SET_BIT(TIM1_Ptr -> TIM1_CCMR1 , 6);

        #elif (TIM1_PWM_OP_CHANNEL == CH_2)
              SET_BIT(TIM1_Ptr -> TIM1_CCMR1 , 12);
              SET_BIT(TIM1_Ptr -> TIM1_CCMR1 , 13);
              SET_BIT(TIM1_Ptr -> TIM1_CCMR1 , 14);

        #elif (TIM1_PWM_OP_CHANNEL == CH_3)
              SET_BIT(TIM1_Ptr -> TIM1_CCMR2 , 12);
              SET_BIT(TIM1_Ptr -> TIM1_CCMR2 , 13);
              SET_BIT(TIM1_Ptr -> TIM1_CCMR2 , 14);

        #elif (TIM1_PWM_OP_CHANNEL == CH_4)
              SET_BIT(TIM1_Ptr -> TIM1_CCMR2 , 12);
              SET_BIT(TIM1_Ptr -> TIM1_CCMR2 , 13);
              SET_BIT(TIM1_Ptr -> TIM1_CCMR2 , 14);
        #endif


    #elif (TIM1_PWM_MODE == FROZEN) // Generate a Timing Base
        #if   (TIM1_PWM_OP_CHANNEL == CH_1)
              CLR_BIT(TIM1_Ptr -> TIM1_CCMR1 , 4);
              CLR_BIT(TIM1_Ptr -> TIM1_CCMR1 , 5);
              CLR_BIT(TIM1_Ptr -> TIM1_CCMR1 , 6);

        #elif (TIM1_PWM_OP_CHANNEL == CH_2)
              CLR_BIT(TIM1_Ptr -> TIM1_CCMR1 , 12);
              CLR_BIT(TIM1_Ptr -> TIM1_CCMR1 , 13);
              CLR_BIT(TIM1_Ptr -> TIM1_CCMR1 , 14);

        #elif (TIM1_PWM_OP_CHANNEL == CH_3)
              CLR_BIT(TIM1_Ptr -> TIM1_CCMR2 , 12);
              CLR_BIT(TIM1_Ptr -> TIM1_CCMR2 , 13);
              CLR_BIT(TIM1_Ptr -> TIM1_CCMR2 , 14);

        #elif (TIM1_PWM_OP_CHANNEL == CH_4)
              CLR_BIT(TIM1_Ptr -> TIM1_CCMR2 , 12);
              CLR_BIT(TIM1_Ptr -> TIM1_CCMR2 , 13);
              CLR_BIT(TIM1_Ptr -> TIM1_CCMR2 , 14);
        #endif

    #else 
        #error "Invalid PWM Mode Selection"
    #endif

    /* ---------------- Setting PSC , ARR ---------------- */
    
    /* Timer Conter Start : Auto Reload Register */
    TIM1_Ptr -> TIM1_ARR = TIM1_SET_COUNT;

    /* Timer Prescaler */
    TIM1_Ptr -> TIM1_PRE_SC_VAL = TIM1_PSC;


}

/* Enable Timer1 */
void MTIM1_voidEnableTimer1(void)
{
    SET_BIT(TIM1_Ptr -> TIM1_CR1 , 0);
}

/* Disable Timer1 */
void MTIM1_voidDisableTimer1(void)
{
    CLR_BIT(TIM1_Ptr -> TIM1_CR1 , 0);
}



void MTIM1_voidLoadOPCCR(u16 Copy_u16Value)
{
    if (TIM1_PWM_OP_CHANNEL == CH_1)
        TIM1_Ptr -> TIM1_CCR1 = Copy_u16Value; // Load the CCR with the value entered by the user

    else if (TIM1_PWM_OP_CHANNEL == CH_2)
        TIM1_Ptr -> TIM1_CCR2 = Copy_u16Value; // Load the CCR with the value entered by the user

    else if (TIM1_PWM_OP_CHANNEL == CH_3)
        TIM1_Ptr -> TIM1_CCR3 = Copy_u16Value; // Load the CCR with the value entered by the user

    else if (TIM1_PWM_OP_CHANNEL == CH_4)
        TIM1_Ptr -> TIM1_CCR4 = Copy_u16Value; // Load the CCR with the value entered by the user

    else 
}
