/****************************************************************/
/*   Author             :    AbdElrahman Ibrahim Zaki		    */
/*	 Date 				:    5th of July 2020 					*/
/*	 Version 			:    1.0V 							 	*/
/*	 Description 		:    TIMER1 Program                     */
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER1_interface.h"
#include "TIMER1_private.h"
#include "TIMER1_config.h"

void (*TIMER1_OV_CallBack) (void);
void (*TIMER1_CTC_A_CallBack) (void);
void (*TIMER1_CTC_B_CallBack) (void);
void (*TIMER1_Cap_Event_CallBack) (void);

void TIMER1_Init(void)
{
    /* TIMER1 Waveform Generation Mode TCCR1A & TCCR1B */
    // TCCR1A Bits 0,1 && TCCR1A Bits 3,4 WGM10/WGM11/WGM12/WGM13
    #if (TIMER1_MODE == TIMER1_NORMAL)
        CLR_BIT(TCCR1A , 0);
        CLR_BIT(TCCR1A , 1);
        CLR_BIT(TCCR1B , 3);
        CLR_BIT(TCCR1B , 4);
    #elif (TIMER1_MODE == TIMER1_PWM_PHASE_CORRECT_8_BIT)
        SET_BIT(TCCR1A , 0);
        CLR_BIT(TCCR1A , 1);
        CLR_BIT(TCCR1B , 3);
        CLR_BIT(TCCR1B , 4);
    #elif (TIMER1_MODE == TIMER1_PWM_PHASE_CORRECT_9_BIT)
        CLR_BIT(TCCR1A , 0);
        SET_BIT(TCCR1A , 1);
        CLR_BIT(TCCR1B , 3);
        CLR_BIT(TCCR1B , 4);  
    #elif (TIMER1_MODE == TIMER1_PWM_PHASE_CORRECT_10_BIT)
        SET_BIT(TCCR1A , 0);
        SET_BIT(TCCR1A , 1);
        CLR_BIT(TCCR1B , 3);
        CLR_BIT(TCCR1B , 4);
    #elif (TIMER1_MODE == TIMER1_CTC_OCR1A_TOP)
        CLR_BIT(TCCR1A , 0);
        CLR_BIT(TCCR1A , 1);
        SET_BIT(TCCR1B , 3);
        CLR_BIT(TCCR1B , 4);                 
    #elif (TIMER1_MODE == TIMER1_FAST_PWM_8_BIT)
        SET_BIT(TCCR1A , 0);
        CLR_BIT(TCCR1A , 1);
        SET_BIT(TCCR1B , 3);
        CLR_BIT(TCCR1B , 4);
    #elif (TIMER1_MODE == TIMER1_FAST_PWM_9_BIT)
        CLR_BIT(TCCR1A , 0);
        SET_BIT(TCCR1A , 1);
        SET_BIT(TCCR1B , 3);
        CLR_BIT(TCCR1B , 4);  
    #elif (TIMER1_MODE == TIMER1_FAST_PWM_10_BIT)
        SET_BIT(TCCR1A , 0);
        SET_BIT(TCCR1A , 1);
        SET_BIT(TCCR1B , 3);
        CLR_BIT(TCCR1B , 4);
    #elif (TIMER1_MODE == TIMER1_PWM_PHASE_FREQ_CORRECT_ICR1_TOP)
        CLR_BIT(TCCR1A , 0);
        CLR_BIT(TCCR1A , 1);
        CLR_BIT(TCCR1B , 3);
        SET_BIT(TCCR1B , 4);  
    #elif (TIMER1_MODE == TIMER1_PWM_PHASE_FREQ_CORRECT_OCR1A_TOP)
        SET_BIT(TCCR1A , 0);
        CLR_BIT(TCCR1A , 1);
        CLR_BIT(TCCR1B , 3);
        SET_BIT(TCCR1B , 4);   
    #elif (TIMER1_MODE == TIMER1_PWM_PHASE_CORRECT_ICR1_TOP)
        CLR_BIT(TCCR1A , 0);
        SET_BIT(TCCR1A , 1);
        CLR_BIT(TCCR1B , 3);
        SET_BIT(TCCR1B , 4);    
    #elif (TIMER1_MODE == TIMER1_PWM_PHASE_CORRECT_OCR1A_TOP)
        SET_BIT(TCCR1A , 0);
        SET_BIT(TCCR1A , 1);
        CLR_BIT(TCCR1B , 3);
        SET_BIT(TCCR1B , 4);
    #elif (TIMER1_MODE == TIMER1_CTC_ICR1_TOP)
        CLR_BIT(TCCR1A , 0);
        CLR_BIT(TCCR1A , 1);
        SET_BIT(TCCR1B , 3);
        SET_BIT(TCCR1B , 4);  
    #elif (TIMER1_MODE == TIMER1_FAST_PWM_ICR1_TOP)
        CLR_BIT(TCCR1A , 0);
        SET_BIT(TCCR1A , 1);
        SET_BIT(TCCR1B , 3);
        SET_BIT(TCCR1B , 4);
    #elif (TIMER1_MODE == TIMER1_FAST_PWM_OCR1A_TOP)
        SET_BIT(TCCR1A , 0);
        SET_BIT(TCCR1A , 1);
        SET_BIT(TCCR1B , 3);
        SET_BIT(TCCR1B , 4);           
    #else 

        #error "Wrong Waveform Generation Mode Selection "   
    
    #endif 


    /* TIMER1 Prescaler Selection TCCR1B */
    // Bits 0,1,2 CS10,CS11,CS12  
    #if (TIMER1_PRESCALER == TIMER1_DIV_FAC_1)
        SET_BIT(TCCR1B , 0);
        CLR_BIT(TCCR1B , 1);
        CLR_BIT(TCCR1B , 2);

    #elif (TIMER1_PRESCALER == TIMER1_DIV_FAC_8)
        CLR_BIT(TCCR1B , 0);
        SET_BIT(TCCR1B , 1);
        CLR_BIT(TCCR1B , 2);

    #elif (TIMER1_PRESCALER == TIMER1_DIV_FAC_64)
        SET_BIT(TCCR1B , 0);
        SET_BIT(TCCR1B , 1);
        CLR_BIT(TCCR1B , 2);  

    #elif (TIMER1_PRESCALER == TIMER1_DIV_FAC_256)
        CLR_BIT(TCCR1B , 0);
        CLR_BIT(TCCR1B , 1);
        SET_BIT(TCCR1B , 2);      
    
    #elif (TIMER1_PRESCALER == TIMER1_DIV_FAC_1024)
        SET_BIT(TCCR1B , 0);
        CLR_BIT(TCCR1B , 1);
        SET_BIT(TCCR1B , 2);     
    #elif (TIMER1_PRESCALER == TIMER1_FALLING_COUNTER1)
        CLR_BIT(TCCR1B , 0);
        SET_BIT(TCCR1B , 1);
        SET_BIT(TCCR1B , 2); 
    #elif (TIMER1_PRESCALER == TIMER1_RISING_COUNTER1)
        SET_BIT(TCCR1B , 0);
        SET_BIT(TCCR1B , 1);
        SET_BIT(TCCR1B , 2);        

    #else 

        #error "Wrong Prescaler Selection "   
    
    #endif 

    /* TIMER1 Channel A Compare Match Output Mode if non/Fast/Phase PWM Mode <CTC or Normal Mode> */
    // BITs 6,7  COM1A0 COM1A1
    // In case of TIMER1 Channel A in NON PWM MODE
    #if (TIMER1_CHA_COM_EVENT == TIMER1_CHA_NON_PWM_NO_ACTION)
        CLR_BIT(TCCR1A , 4);
        CLR_BIT(TCCR1A , 5);
        CLR_BIT(TCCR1A , 6);
        CLR_BIT(TCCR1A , 7);

    #elif (TIMER1_CHA_COM_EVENT == TIMER1_CHA_NON_PWM_SET)
        CLR_BIT(TCCR1A , 4);
        CLR_BIT(TCCR1A , 5);
        SET_BIT(TCCR1A , 6);
        SET_BIT(TCCR1A , 7);

    #elif (TIMER1_CHA_COM_EVENT == TIMER1_CHA_NON_PWM_TOGGLE)
        CLR_BIT(TCCR1A , 4);
        CLR_BIT(TCCR1A , 5);
        SET_BIT(TCCR1A , 6);
        CLR_BIT(TCCR1A , 7);

    #elif (TIMER1_CHA_COM_EVENT == TIMER1_CHA_NON_PWM_CLEAR)
        CLR_BIT(TCCR1A , 4);
        CLR_BIT(TCCR1A , 5);
        CLR_BIT(TCCR1A , 6);
        SET_BIT(TCCR1A , 7);

    // In case of TIMER1 Channel A in FAST PWM MODE
    #elif (TIMER1_CHA_COM_EVENT == TIMER1_CHA_FAST_PWM_NO_ACTION)
        CLR_BIT(TCCR1A , 4);
        CLR_BIT(TCCR1A , 5);
        CLR_BIT(TCCR1A , 6);
        CLR_BIT(TCCR1A , 7); 
        
    #elif (TIMER1_CHA_COM_EVENT == TIMER1_CHA_FAST_PWM_SET)
        CLR_BIT(TCCR1A , 4);
        CLR_BIT(TCCR1A , 5);
        SET_BIT(TCCR1A , 6);
        SET_BIT(TCCR1A , 7);

    #elif (TIMER1_CHA_COM_EVENT == TIMER1_CHA_FAST_PWM_TOGGLE)
        CLR_BIT(TCCR1A , 4);
        CLR_BIT(TCCR1A , 5);
        SET_BIT(TCCR1A , 6);
        CLR_BIT(TCCR1A , 7);    

    #elif (TIMER1_CHA_COM_EVENT == TIMER1_CHA_FAST_PWM_CLEAR)
        CLR_BIT(TCCR1A , 4);
        CLR_BIT(TCCR1A , 5);
        CLR_BIT(TCCR1A , 6);
        SET_BIT(TCCR1A , 7);              

    // In case of TIMER1 Channel A in PHASE-CORRECT PWM MODE
    #elif (TIMER1_CHA_COM_EVENT == TIMER1_CHA_PHCor_PWM_NO_ACTION)
        CLR_BIT(TCCR1A , 4);
        CLR_BIT(TCCR1A , 5);
        CLR_BIT(TCCR1A , 6);
        CLR_BIT(TCCR1A , 7);   
        
    #elif (TIMER1_CHA_COM_EVENT == TIMER1_CHA_PHCor_PWM_SET)
        CLR_BIT(TCCR1A , 4);
        CLR_BIT(TCCR1A , 5);
        SET_BIT(TCCR1A , 6);
        SET_BIT(TCCR1A , 7);

    #elif (TIMER1_CHA_COM_EVENT == TIMER1_CHA_PHCor_PWM_TOGGLE)
        CLR_BIT(TCCR1A , 4);
        CLR_BIT(TCCR1A , 5);
        SET_BIT(TCCR1A , 6);
        CLR_BIT(TCCR1A , 7);

    #elif (TIMER1_CHA_COM_EVENT == TIMER1_CHA_PHCor_PWM_CLEAR)
        CLR_BIT(TCCR1A , 4);
        CLR_BIT(TCCR1A , 5);
        CLR_BIT(TCCR1A , 6);
        SET_BIT(TCCR1A , 7);          

    #else 

        #error "Wrong Channel A Compare Match Output Mode Selection "   
    
    #endif 


    /* TIMER1 Channel B Compare Match Output Mode if non/Fast/Phase PWM Mode <CTC or Normal Mode> */
    // BITs 4,5  COM1B0 COM1B1
    // In case of TIMER1 Channel B in NON PWM MODE
    #if (TIMER1_CHB_COM_EVENT == TIMER1_CHB_NON_PWM_NO_ACTION)
        CLR_BIT(TCCR1A , 4);
        CLR_BIT(TCCR1A , 5);
        CLR_BIT(TCCR1A , 6);
        CLR_BIT(TCCR1A , 7);

    #elif (TIMER1_CHB_COM_EVENT == TIMER1_CHB_NON_PWM_SET)
        SET_BIT(TCCR1A , 4);
        SET_BIT(TCCR1A , 5);
        CLR_BIT(TCCR1A , 6);
        CLR_BIT(TCCR1A , 7);
        

    #elif (TIMER1_CHB_COM_EVENT == TIMER1_CHB_NON_PWM_TOGGLE)
        SET_BIT(TCCR1A , 4);
        CLR_BIT(TCCR1A , 5);
        CLR_BIT(TCCR1A , 6);
        CLR_BIT(TCCR1A , 7);

    #elif (TIMER1_CHB_COM_EVENT == TIMER1_CHB_NON_PWM_CLEAR)
        CLR_BIT(TCCR1A , 4);
        SET_BIT(TCCR1A , 5);
        CLR_BIT(TCCR1A , 6);
        CLR_BIT(TCCR1A , 7);

    // In case of TIMER1 Channel B in FAST PWM MODE
    #elif (TIMER1_CHB_COM_EVENT == TIMER1_CHB_FAST_PWM_NO_ACTION)
        CLR_BIT(TCCR1A , 4);
        CLR_BIT(TCCR1A , 5);
        CLR_BIT(TCCR1A , 6);
        CLR_BIT(TCCR1A , 7); 
        
    #elif (TIMER1_CHB_COM_EVENT == TIMER1_CHB_FAST_PWM_SET)
        SET_BIT(TCCR1A , 4);
        SET_BIT(TCCR1A , 5);
        CLR_BIT(TCCR1A , 6);
        CLR_BIT(TCCR1A , 7);

    #elif (TIMER1_CHB_COM_EVENT == TIMER1_CHB_FAST_PWM_TOGGLE)
        SET_BIT(TCCR1A , 4);
        CLR_BIT(TCCR1A , 5);
        CLR_BIT(TCCR1A , 6);
        CLR_BIT(TCCR1A , 7);    

    #elif (TIMER1_CHB_COM_EVENT == TIMER1_CHB_FAST_PWM_CLEAR)
        CLR_BIT(TCCR1A , 4);
        SET_BIT(TCCR1A , 5);
        CLR_BIT(TCCR1A , 6);
        CLR_BIT(TCCR1A , 7);              

    // In case of TIMER1 Channel B in PHASE-CORRECT PWM MODE
    #elif (TIMER1_CHB_COM_EVENT == TIMER1_CHB_PHCor_PWM_NO_ACTION)
        CLR_BIT(TCCR1A , 4);
        CLR_BIT(TCCR1A , 5);
        CLR_BIT(TCCR1A , 6);
        CLR_BIT(TCCR1A , 7);   
        
    #elif (TIMER1_CHB_COM_EVENT == TIMER1_CHB_PHCor_PWM_SET)
        SET_BIT(TCCR1A , 4);
        SET_BIT(TCCR1A , 5);
        CLR_BIT(TCCR1A , 6);
        CLR_BIT(TCCR1A , 7);

    #elif (TIMER1_CHB_COM_EVENT == TIMER1_CHB_PHCor_PWM_TOGGLE)
        SET_BIT(TCCR1A , 4);
        CLR_BIT(TCCR1A , 5);
        CLR_BIT(TCCR1A , 6);
        CLR_BIT(TCCR1A , 7);

    #elif (TIMER1_CHB_COM_EVENT == TIMER1_CHB_PHCor_PWM_CLEAR)
        CLR_BIT(TCCR1A , 4);
        SET_BIT(TCCR1A , 5);
        CLR_BIT(TCCR1A , 6);
        CLR_BIT(TCCR1A , 7);          

    #else 

        #error "Wrong Channel B Compare Match Output Mode Selection "   
    
    #endif 

    /* Disable interrupts 0 */
    // Overflow Interrupt 
    CLR_BIT(TIMSK , 2); 
    // CTC-A Interrupt
    CLR_BIT(TIMSK , 4); 
    // CTC-B Interrupt
    CLR_BIT(TIMSK , 3); 
    // Input Capture Interrupt
    CLR_BIT(TIMSK , 5);

    /* Clear Flags */
    // Overflow Flag
    SET_BIT(TIFR , 2); 
    // CTC-A Flag
    SET_BIT(TIFR , 4);
    // CTC-B Flag
    SET_BIT(TIFR , 3);
    // Input Capture Flag
    CLR_BIT(TIFR , 5);

    /* CLEAR REGISTERS */ 
    TCNT1 = 0;
    OCR1A = 0;
    OCR1B = 0;

}

/* ------------------ SET TCNTA / TCNTB Value ------------------ */
void TIMER1_SetTimerReg(u16 copy_uint16val)
{
    TCNT1 = copy_uint16val;
}

void TIMER1H_SetTimerReg(u8 copy_uint8val)
{
    TCNT1H = copy_uint8val;
}

void TIMER1L_SetTimerReg(u8 copy_uint8val)
{
    TCNT1L = copy_uint8val;
}

/* ----------------- SET OCRA / OCRAH / OCRAL Value ------------------ */

void TIMER1A_SetCompareVal(u16 copy_unit16val)
{
    OCR1A = copy_unit16val;
}

void TIMER1AH_SetCompareVal(u8 copy_unit8val)
{
    OCR1AH = copy_unit8val;
}

void TIMER1AL_SetCompareVal(u8 copy_unit8val)
{
    OCR1AL = copy_unit8val;
}

/* ----------------- SET OCRB / OCRBH / OCRBL Value ------------------ */

void TIMER1B_SetCompareVal(u16 copy_unit16val)
{
    OCR1B = copy_unit16val;
}

void TIMER1BH_SetCompareVal(u8 copy_unit8val)
{
    OCR1BH = copy_unit8val;
}

void TIMER1BL_SetCompareVal(u8 copy_unit8val)
{
    OCR1BL = copy_unit8val;
}

/* ----------------- Timer1/Counter1 Interrupt Mask Register – TIMSK ---------------------- */

// TOIE1: Timer1/Counter1, Overflow Interrupt Enable
void TIMER1_EnableOVInt(void)
{
    SET_BIT(TIMSK , 2);
}
// TOIE1: Timer1/Counter1, Overflow Interrupt Disable
void TIMER1_DisableOVInt(void)
{
    CLR_BIT(TIMSK , 2);
}

/* -------------------------- OCIE1A ---------------------------- */

// OCIE1A: Timer/Counter1, Output Compare A Match Interrupt Enable
void TIMER1_EnableCTC_A_Int(void)
{
    SET_BIT(TIMSK , 4);
}
// OCIE1A: Timer/Counter1, Output Compare A Match Interrupt Disable
void TIMER1_DisableCTC_A_Int(void)
{
    CLR_BIT(TIMSK , 4);
}

/* -------------------------- OCIE1B ---------------------------- */

// OCIE1B: Timer/Counter1, Output Compare B Match Interrupt Enable
void TIMER1_EnableCTC_B_Int(void)
{
    SET_BIT(TIMSK , 3);
}
// OCIE1B: Timer/Counter1, Output Compare B Match Interrupt Disable
void TIMER1_DisableCTC_B_Int(void)
{
    CLR_BIT(TIMSK , 3);
}

/* ------------------------ TICIE1 --------------------------- */ 

// TICIE1: Timer/Counter1, Input Capture Interrupt Enable
void TIMER1_In_CAP_INT_Enable(void)
{
    SET_BIT(TIMSK , 5);
}

// TICIE1: Timer/Counter1, Input Capture Interrupt Disable
void TIMER1_In_CAP_INT_Disable(void)
{
    CLR_BIT(TIMSK , 5);
}

/* --------------------- CallBack Functions --------------------------- */ 

void TIMER1_voidSetOVCallBack(void (*Copy_ptr) (void))
{
     TIMER1_OV_CallBack = Copy_ptr;
}

void TIMER1_voidSetCTC_A_CallBack(void (*Copy_ptr) (void))
{
     TIMER1_CTC_A_CallBack = Copy_ptr;
}

void TIMER1_voidSetCTC_B_CallBack(void (*Copy_ptr) (void))
{
     TIMER1_CTC_B_CallBack = Copy_ptr;
}

void TIMER1_voidSetCap_Ev_CallBack(void (*Copy_ptr) (void))
{
     TIMER1_Cap_Event_CallBack = Copy_ptr;
}


/* ---------------------- TIMER1 Vectors -------------------- */ 
// Interrupt Vector Table "Timer/Counter1 Capture Event"
void __vector_6(void)  __attribute__((signal , used));
void __vector_6(void)
{
    TIMER1_Cap_Event_CallBack();
}

// Interrupt Vector Table "Timer/Counter1 Compare Match A"
void __vector_7(void)  __attribute__((signal , used));
void __vector_7(void)
{
    TIMER1_CTC_A_CallBack();
}

// Interrupt Vector Table "Timer/Counter1 Compare Match B"
void __vector_8(void)  __attribute__((signal , used));
void __vector_8(void)
{
    TIMER1_CTC_B_CallBack();
}

// Interrupt Vector Table " Timer/Counter1 Overflow"
void __vector_9(void)  __attribute__((signal , used));
void __vector_9(void)
{
    TIMER1_OV_CallBack();
}

