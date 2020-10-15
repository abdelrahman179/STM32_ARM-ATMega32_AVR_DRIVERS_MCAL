/****************************************************************/
/*   Author       :    AbdElrahman Ibrahim Zaki		              */
/*	 Date 				:    5th of July 2020 				               	*/
/*	 Version 			:    1.0V 							                     	*/
/*	 Description 	:    TIMER1 Interface File                    */
/****************************************************************/

#ifndef TIMER1_INTERFACE_H
#define TIMER1_INTERFACE_H

// TIMER1 Waveform Generation Modes
#define TIMER1_NORMAL                                   1 
#define TIMER1_PWM_PHASE_CORRECT_8_BIT                  2 
#define TIMER1_PWM_PHASE_CORRECT_9_BIT                  3
#define TIMER1_PWM_PHASE_CORRECT_10_BIT                 4  
#define TIMER1_CTC_OCR1A_TOP                            5 
#define TIMER1_FAST_PWM_8_BIT                           6 
#define TIMER1_FAST_PWM_9_BIT                           7 
#define TIMER1_FAST_PWM_10_BIT                          8 
#define TIMER1_PWM_PHASE_FREQ_CORRECT_ICR1_TOP          9 
#define TIMER1_PWM_PHASE_FREQ_CORRECT_OCR1A_TOP         10 
#define TIMER1_PWM_PHASE_CORRECT_ICR1_TOP               11 
#define TIMER1_PWM_PHASE_CORRECT_OCR1A_TOP              12 
#define TIMER1_CTC_ICR1_TOP                             13 
#define TIMER1_FAST_PWM_ICR1_TOP                        14 
#define TIMER1_FAST_PWM_OCR1A_TOP                       15 


// TIMER1 Prescaler Division Factor 
#define TIMER1_DIV_FAC_1                16  
#define TIMER1_DIV_FAC_8                17  
#define TIMER1_DIV_FAC_64               18  
#define TIMER1_DIV_FAC_256              19  
#define TIMER1_DIV_FAC_1024             20
// TIMER1 as a COUNTER1
#define TIMER1_FALLING_COUNTER1         21
#define TIMER1_RISING_COUNTER1          22



/* TIMER1 Channel A Compare Match Output Mode if non/Fast/Phase PWM Mode <CTC or Normal Mode> */
// In case of TIMER1 Channel A in NON PWM MODE
#define TIMER1_CHA_NON_PWM_NO_ACTION                 30
#define TIMER1_CHA_NON_PWM_SET                       31
#define TIMER1_CHA_NON_PWM_TOGGLE                    32
#define TIMER1_CHA_NON_PWM_CLEAR                     33
// In case of TIMER1 Channel A in FAST PWM MODE
#define TIMER1_CHA_FAST_PWM_NO_ACTION                34
#define TIMER1_CHA_FAST_PWM_SET                      35
#define TIMER1_CHA_FAST_PWM_TOGGLE                   36
#define TIMER1_CHA_FAST_PWM_CLEAR                    37
// In case of TIMER1 Channel A in PHASE-CORRECT PWM MODE
#define TIMER1_CHA_PHCor_PWM_NO_ACTION               38 
#define TIMER1_CHA_PHCor_PWM_SET                     39
#define TIMER1_CHA_PHCor_PWM_TOGGLE                  40
#define TIMER1_CHA_PHCor_PWM_CLEAR                   41

/* TIMER1 Channel B Compare Match Output Mode if non/Fast/Phase PWM Mode <CTC or Normal Mode> */
// In case of TIMER1 Channel B in NON PWM MODE
#define TIMER1_CHB_NON_PWM_NO_ACTION                 42
#define TIMER1_CHB_NON_PWM_SET                       43
#define TIMER1_CHB_NON_PWM_TOGGLE                    44
#define TIMER1_CHB_NON_PWM_CLEAR                     45
// In case of TIMER1 Channel A in FAST PWM MODE
#define TIMER1_CHB_FAST_PWM_NO_ACTION                46
#define TIMER1_CHB_FAST_PWM_SET                      47
#define TIMER1_CHB_FAST_PWM_TOGGLE                   48
#define TIMER1_CHB_FAST_PWM_CLEAR                    49
// In case of TIMER1 Channel A in PHASE-CORRECT PWM MODE
#define TIMER1_CHB_PHCor_PWM_NO_ACTION               50 
#define TIMER1_CHB_PHCor_PWM_SET                     51
#define TIMER1_CHB_PHCor_PWM_TOGGLE                  52
#define TIMER1_CHB_PHCor_PWM_CLEAR                   53




// Timer1 Initialization configureation 
void TIMER1_Init(void);

/* ------------------ SET TCNTA / TCNTB Value ------------------ */

// To write a value into TCNT1 <TCNT1A + TCNT1B> Register
void TIMER1_SetTimerReg(u16 copy_uint16val);  

// To write a value into TCNT1H Register
void TIMER1H_SetTimerReg(u8 copy_uint8val);

// To write a value into TCNT1L Register
void TIMER1L_SetTimerReg(u8 copy_uint8val);

/* ----------------- SET OCRA / OCRAH / OCRAL Value ------------------ */

// To write a value into OC1A <OCR1AH + OCR1AL> Register compare value 
void TIMER1A_SetCompareVal(u16 copy_unit16val);

// To write a value into OCR1AH Register compare value 
void TIMER1AH_SetCompareVal(u8 copy_unit8val);

// To write a value into OCR1AL Register compare value
void TIMER1AL_SetCompareVal(u8 copy_unit8val);

/* ----------------- SET OCRB / OCRBH / OCRBL Value ------------------ */

// To write a value into OC1B <OCR1BH + OCR1BL> Register compare value 
void TIMER1B_SetCompareVal(u16 copy_unit16val);

// To write a value into OCR1BH Register compare value
void TIMER1BH_SetCompareVal(u8 copy_unit8val);

// To write a value into OCR1BL Register compare value
void TIMER1BL_SetCompareVal(u8 copy_unit8val);

/* ----------------- Timer1/Counter1 Interrupt Mask Register – TIMSK ---------------------- */

// TOIE1: Timer1/Counter1, Overflow Interrupt Enable
void TIMER1_EnableOVInt(void);

// TOIE1: Timer1/Counter1, Overflow Interrupt Disable
void TIMER1_DisableOVInt(void);

/* -------------------------- OCIE1A ---------------------------- */

// OCIE1A: Timer/Counter1, Output Compare A Match Interrupt Enable
void TIMER1_EnableCTC_A_Int(void);

// OCIE1A: Timer/Counter1, Output Compare A Match Interrupt Disable
void TIMER1_DisableCTC_A_Int(void);

/* -------------------------- OCIE1B ---------------------------- */

// OCIE1B: Timer/Counter1, Output Compare B Match Interrupt Enable
void TIMER1_EnableCTC_B_Int(void);

// OCIE1B: Timer/Counter1, Output Compare B Match Interrupt Disable
void TIMER1_DisableCTC_B_Int(void);

/* ------------------------ TICIE1 --------------------------- */ 

// TICIE1: Timer/Counter1, Input Capture Interrupt Enable
void TIMER1_In_CAP_INT_Enable(void);

// TICIE1: Timer/Counter1, Input Capture Interrupt Disable
void TIMER1_In_CAP_INT_Disable(void);

/* --------------------- CallBack Functions --------------------------- */ 

// To call OV ISR function from Application Layer
void TIMER1_voidSetOVCallBack(void (*Copy_ptr) (void));

// To call CTC_A ISR function from Application Layer
void TIMER1_voidSetCTC_A_CallBack(void (*Copy_ptr) (void));

// To call CTC_B ISR function from Application Layer
void TIMER1_voidSetCTC_B_CallBack(void (*Copy_ptr) (void));

// To call Input_Capture_Event ISR function from Application Layer
void TIMER1_voidSetCap_Ev_CallBack(void (*Copy_ptr) (void));


#endif 
