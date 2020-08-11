/****************************************************************/
/*   Author             :    AbdElrahman Ibrahim Zaki		    */
/*	 Date 				:    10th of July 2020 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    TIMER2 Program                       */
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER2_int.h"
#include "TIMER2_reg.h"
#include "TIMER2_config.h"

void (*TIMER2_OV_CallBack) (void);
void (*TIMER2_CTC_CallBack) (void);

void TIMER2_Init(void)
{
    /* TIMER2 Waveform Generation Mode TCCR2 */
    // BITs 3/6 WGM01/WGM00
    #if (TIMER2_MODE == TIMER2_NORMAL)
        CLR_BIT(TCCR2 , 3);
        CLR_BIT(TCCR2 , 6);
    #elif (TIMER2_MODE == TIMER2_CTC)
        SET_BIT(TCCR2 , 3);  
        CLR_BIT(TCCR2 , 6);
    #elif (TIMER2_MODE == TIMER2_FAST_PWM)
        SET_BIT(TCCR2 , 3);
        SET_BIT(TCCR2 , 6);    
    #elif (TIMER2_MODE == TIMER2_PHASE_PWM)
        CLR_BIT(TCCR2 , 3);
        SET_BIT(TCCR2 , 6); 
    #else 

        #error "Wrong Waveform Generation Mode Selection "   
    
    #endif 


    /* TIMER2 Prescaler Selection TCCR2 */
    // BITs 0,1,2 Clock Select CS00,CS01,CS02  
    #if (TIMER2_PRESCALER == TIMER2_DIV_FAC_1)
        SET_BIT(TCCR2 , 0);
        CLR_BIT(TCCR2 , 1);
        CLR_BIT(TCCR2 , 2);

    #elif (TIMER2_PRESCALER == TIMER2_DIV_FAC_8)
        CLR_BIT(TCCR2 , 0);
        SET_BIT(TCCR2 , 1);
        CLR_BIT(TCCR2 , 2);

    #elif (TIMER2_PRESCALER == TIMER2_DIV_FAC_32)
        SET_BIT(TCCR2 , 0);
        SET_BIT(TCCR2 , 1);
        CLR_BIT(TCCR2 , 2);    

    #elif (TIMER2_PRESCALER == TIMER2_DIV_FAC_64)
        CLR_BIT(TCCR2 , 0);
        CLR_BIT(TCCR2 , 1);
        SET_BIT(TCCR2 , 2);  

    #elif (TIMER2_PRESCALER == TIMER2_DIV_FAC_128)
        SET_BIT(TCCR2 , 0);
        CLR_BIT(TCCR2 , 1);
        SET_BIT(TCCR2 , 2);    

    #elif (TIMER2_PRESCALER == TIMER2_DIV_FAC_256)
        CLR_BIT(TCCR2 , 0);
        SET_BIT(TCCR2 , 1);
        SET_BIT(TCCR2 , 2);      
    
    #elif (TIMER2_PRESCALER == TIMER2_DIV_FAC_1024)
        SET_BIT(TCCR2 , 0);
        SET_BIT(TCCR2 , 1);
        SET_BIT(TCCR2 , 2);     
          

    #else 

        #error "Wrong Prescaler Selection "   
    
    #endif 

    /* TIMER2 Compare Match Output Mode if non/Fast/Phase PWM Mode <CTC or Normal Mode> */
    // BITs 4 & 5  COM00 COM01  
    #if (TIMER2_COM_EVENT == TIMER2_NON_PWM_NO_ACTION)
        CLR_BIT(TCCR2 , 4);
        CLR_BIT(TCCR2 , 5);

    #elif (TIMER2_COM_EVENT == TIMER2_NON_PWM_SET)
        SET_BIT(TCCR2 , 4);
        SET_BIT(TCCR2 , 5);

    #elif (TIMER2_COM_EVENT == TIMER2_NON_PWM_TOGGLE)
        SET_BIT(TCCR2 , 4);
        CLR_BIT(TCCR2 , 5);

    #elif (TIMER2_COM_EVENT == TIMER2_NON_PWM_CLEAR)
        CLR_BIT(TCCR2 , 4);
        SET_BIT(TCCR2 , 5);

    // In case TIME2 in FAST PWM MODE
    #elif (TIMER2_COM_EVENT == TIMER2_FAST_PWM_NO_ACTION)
        CLR_BIT(TCCR2 , 4);
        CLR_BIT(TCCR2 , 5);  
        
    #elif (TIMER2_COM_EVENT == TIMER2_FAST_PWM_SET)
        SET_BIT(TCCR2 , 4);
        SET_BIT(TCCR2 , 5);

    #elif (TIMER2_COM_EVENT == TIMER2_FAST_PWM_CLEAR)
        CLR_BIT(TCCR2 , 4);
        SET_BIT(TCCR2 , 5);               

    // In case TIME2 in PHASE-CORRECT PWM MODE
    #elif (TIMER2_COM_EVENT == TIMER2_PHCor_PWM_NO_ACTION)
        CLR_BIT(TCCR2 , 4);
        CLR_BIT(TCCR2 , 5);  
        
    #elif (TIMER2_COM_EVENT == TIMER2_PHCor_PWM_SET)
        SET_BIT(TCCR2 , 4);
        SET_BIT(TCCR0 , 5);

    #elif (TIMER2_COM_EVENT == TIMER2_PHCor_PWM_CLEAR)
        CLR_BIT(TCCR2 , 4);
        SET_BIT(TCCR2 , 5);            

    #else 

        #error "Wrong Compare Match Output Mode Selection "   
    
    #endif 


    /* TIMER2 Asynchronous Operation */
    #if (TIMER2_ASYNCH_MODE == TIMER2_INTERNAL_CK)
        CLR_BIT(ASSR , 3);

    /* Connect the O/P pin of external oscillator with TOSC1
    and the I/P pin with TOSC2 */ 
    #elif (TIMER2_ASYNCH_MODE == TIMER2_EXTERNAL_CK)   
        SET_BIT(ASSR , 3);

    #else 

        #error "Wrong Asynchronous Operation Mode Selection "   
    
    #endif 

    /* Disable interrupts 0 */
    // Overflow Interrupt 
    CLR_BIT(TIMSK , 6); 
    // CTC Interrupt
    CLR_BIT(TIMSK , 7); 

    /* Clear Flags */
	// Overflow Flag 
    SET_BIT(TIFR , 6);
	// CTC Flag
    SET_BIT(TIFR , 7);

    /* CLEAR REGISTERS */ 
    TCNT2 = 0;
    OCR2 = 0;

}

void TIMER2_Disabled(void)
{
    CLR_BIT(TCCR2 , 0); 
    CLR_BIT(TCCR2 , 1); 
    CLR_BIT(TCCR2 , 2); 
}

void TIMER2_SetTimerReg(u8 copy_uint8val2)
{
    TCNT2 = copy_uint8val2;
}

void TIMER2_SetCompareVal(u8 copy_unit8val2)
{
    OCR2 = copy_unit8val2;
}

void TIMER2_EnableOVInt(void)
{
     // Set TOIE2 TIMER2 Overflow Interrupt Enable
    SET_BIT(TIMSK , 6);
}

void TIMER2_DisableOVInt(void)
{
    // Clear TOIE2 TIMER2 Overflow Interrupt Enable
    CLR_BIT(TIMSK , 6);
}

void TIMER2_EnableCTCInt(void)
{
    // Set OCIE2 TIMER2 Output Compare Match Interrupt Enable
    SET_BIT(TIMSK , 7);
}

void TIMER2_DisableCTCInt(void)
{
    // Clear OCIE2 TIMER2 Output Compare Match Interrupt Enable
    CLR_BIT(TIMSK , 7);
}

void TIMER2_voidSetOVCallBack(void (*Copy_ptr2) (void))
{
     TIMER2_OV_CallBack = Copy_ptr2;
}

void TIMER2_voidSetCTCCallBack(void (*Copy_ptr2) (void))
{
     TIMER2_CTC_CallBack = Copy_ptr2;
}

// Interrupt Vector Table Vector10 TIMER0 COMP 
void __vector_4(void)  __attribute__((signal , used));
void __vector_4(void)
{
    TIMER2_CTC_CallBack();
}

// Interrupt Vector Table Vector11 TIMER0 COMP 
void __vector_5(void)  __attribute__((signal , used));
void __vector_5(void)
{
    TIMER2_OV_CallBack();
}

