/****************************************************************/
/*   Author             :    AbdElrahman Ibrahim Zaki		    */
/*	 Date 				:    1st of July 2020 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    TIMER0 Program file                */
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER0_interface.h"
#include "TIMER0_private.h"
#include "TIMER0_config.h"

void (*TIMER0_OV_CallBack) (void);
void (*TIMER0_CTC_CallBack) (void);

void TIMER0_Init(void)
{
    /* TIMER0 Waveform Generation Mode TCCR0 */
    // BITs 3/6 WGM01/WGM00
    #if (TIMER0_MODE == TIMER0_NORMAL)
        CLR_BIT(TCCR0 , 6);
        CLR_BIT(TCCR0 , 6);
    #elif (TIMER0_MODE == TIMER0_CTC)
        SET_BIT(TCCR0 , 3);
        CLR_BIT(TCCR0 , 6);
    #elif (TIMER0_MODE == TIMER0_FAST_PWM)
        SET_BIT(TCCR0 , 3);
        SET_BIT(TCCR0 , 6);    
    #elif (TIMER0_MODE == TIMER0_PHASE_PWM)
        CLR_BIT(TCCR0 , 3);
        SET_BIT(TCCR0 , 6); 
    #else 

        #error "Wrong Waveform Generation Mode Selection "   
    
    #endif 


    /* TIMER0 Prescaler Selection TCCR0 */
    // BITs 0,1,2 Clock Select CS00,CS01,CS02  
    #if (TIMER0_PRESCALER == TIMER0_DIV_FAC_1)
        SET_BIT(TCCR0 , 0);
        CLR_BIT(TCCR0 , 1);
        CLR_BIT(TCCR0 , 2);

    #elif (TIMER0_PRESCALER == TIMER0_DIV_FAC_8)
        CLR_BIT(TCCR0 , 0);
        SET_BIT(TCCR0 , 1);
        CLR_BIT(TCCR0 , 2);

    #elif (TIMER0_PRESCALER == TIMER0_DIV_FAC_64)
        SET_BIT(TCCR0 , 0);
        SET_BIT(TCCR0 , 1);
        CLR_BIT(TCCR0 , 2);  

    #elif (TIMER0_PRESCALER == TIMER0_DIV_FAC_256)
        CLR_BIT(TCCR0 , 0);
        CLR_BIT(TCCR0 , 1);
        SET_BIT(TCCR0 , 2);      
    
    #elif (TIMER0_PRESCALER == TIMER0_DIV_FAC_1024)
        SET_BIT(TCCR0 , 0);
        CLR_BIT(TCCR0 , 1);
        SET_BIT(TCCR0 , 2);     
    #elif (TIMER0_PRESCALER == TIMER0_FALLING_COUNTER0)
        CLR_BIT(TCCR0 , 0);
        SET_BIT(TCCR0 , 1);
        SET_BIT(TCCR0 , 2); 
    #elif (TIMER0_PRESCALER == TIMER0_RISING_COUNTER0)
        SET_BIT(TCCR0 , 0);
        SET_BIT(TCCR0 , 1);
        SET_BIT(TCCR0 , 2);        

    #else 

        #error "Wrong Prescaler Selection "   
    
    #endif 

    /* TIMER0 Compare Match Output Mode if non/Fast/Phase PWM Mode <CTC or Normal Mode> */
    // BITs 4 & 5  COM00 COM01  
    #if (TIMER0_COM_EVENT == TIMER0_NON_PWM_NO_ACTION)
        CLR_BIT(TCCR0 , 4);
        CLR_BIT(TCCR0 , 5);

    #elif (TIMER0_COM_EVENT == TIMER0_NON_PWM_SET)
        SET_BIT(TCCR0 , 4);
        SET_BIT(TCCR0 , 5);

    #elif (TIMER0_COM_EVENT == TIMER0_NON_PWM_TOGGLE)
        SET_BIT(TCCR0 , 4);
        CLR_BIT(TCCR0 , 5);

    #elif (TIMER0_COM_EVENT == TIMER0_NON_PWM_CLEAR)
        CLR_BIT(TCCR0 , 4);
        SET_BIT(TCCR0 , 5);

    // In case TIME0 in FAST PWM MODE
    #elif (TIMER0_COM_EVENT == TIMER0_FAST_PWM_NO_ACTION)
        CLR_BIT(TCCR0 , 4);
        CLR_BIT(TCCR0 , 5);  
        
    #elif (TIMER0_COM_EVENT == TIMER0_FAST_PWM_SET)
        SET_BIT(TCCR0 , 4);
        SET_BIT(TCCR0 , 5);

    #elif (TIMER0_COM_EVENT == TIMER0_FAST_PWM_CLEAR)
        CLR_BIT(TCCR0 , 4);
        SET_BIT(TCCR0 , 5);               

    // In case TIME0 in PHASE-CORRECT PWM MODE
    #elif (TIMER0_COM_EVENT == TIMER0_PHCor_PWM_NO_ACTION)
        CLR_BIT(TCCR0 , 4);
        CLR_BIT(TCCR0 , 5);  
        
    #elif (TIMER0_COM_EVENT == TIMER0_PHCor_PWM_SET)
        SET_BIT(TCCR0 , 4);
        SET_BIT(TCCR0 , 5);

    #elif (TIMER0_COM_EVENT == TIMER0_PHCor_PWM_CLEAR)
        CLR_BIT(TCCR0 , 4);
        SET_BIT(TCCR0 , 5);            

    #else 

        #error "Wrong Compare Match Output Mode Selection "   
    
    #endif 

    /* Disable interrupts 0 */
    // Overflow Interrupt 
    CLR_BIT(TIMSK , 0); 
    // CTC Interrupt
    CLR_BIT(TIMSK , 1); 

    /* Clear Flags */
    // Overflow Flag
    SET_BIT(TIFR , 0); 
    // CTC Flag
    SET_BIT(TIFR , 1);

    /* CLEAR REGISTERS */ 
    TCNT0 = 0;
    OCR0 = 0;

}

void TIMER0_Disabled(void)
{
    CLR_BIT(TCCR0 , 0); 
    CLR_BIT(TCCR0 , 1); 
    CLR_BIT(TCCR0 , 2); 
}

void TIMER0_SetTimerReg(u8 copy_uint8val)
{
    TCNT0 = copy_uint8val;
}

void TIMER0_SetCompareVal(u8 copy_unit8val)
{
    OCR0 = copy_unit8val;
}

void TIMER0_EnableOVInt(void)
{
    // Set TOIE0 TIMER0/COUNTER0 Overflow Interrupt Enable
    SET_BIT(TIMSK , 0);
}

void TIMER0_DisableOVInt(void)
{
    // Clear TOIE0 TIMER0/COUNTER0 Overflow Interrupt Enable
    CLR_BIT(TIMSK , 0);
}

void TIMER0_EnableCTVInt(void)
{
    // Set OCIE0 TIMER0/COUNTER0 Output Compare Match Interrupt Enable
    SET_BIT(TIMSK , 1);
}

void TIMER0_DisableCTCInt(void)
{
    // Clear OCIE0 TIMER0/COUNTER0 Output Compare Match Interrupt Enable
    CLR_BIT(TIMSK , 1);
}

void TIMER0_voidSetOVCallBack(void (*Copy_ptr) (void))
{
     TIMER0_OV_CallBack = Copy_ptr;
}

void TIMER0_voidSetCTCCallBack(void (*Copy_ptr) (void))
{
     TIMER0_CTC_CallBack = Copy_ptr;
}

// Interrupt Vector Table Vector10 TIMER0 COMP 
void __vector_10(void)  __attribute__((signal , used));
void __vector_10(void)
{
    TIMER0_CTC_CallBack();
}

// Interrupt Vector Table Vector11 TIMER0 COMP 
void __vector_11(void)  __attribute__((signal , used));
void __vector_11(void)
{
    TIMER0_OV_CallBack();
}

