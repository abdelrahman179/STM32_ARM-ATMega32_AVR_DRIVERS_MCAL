/****************************************************************/
/*   Author       :    AbdElrahman Ibrahim Zaki		              */
/*	 Date 				:    23rd of June 2020 					              */
/*	 Version 			:    1.0V 							                    	*/
/*	 Description  :  Analog Digital Converter	Program           */
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_Config.h"
#include "ADC_Interface.h"
#include "ADC_Register.h"

u16 dig_result;

void ADC_Init(void)
{
	// Voltage Reference Setting
	#if    VREF   ==   AVCC 
	// Vref = 5v
	CLR_BIT(ADMUX , 7);
	SET_BIT(ADMUX , 6);
	#elif   VREF   ==   INTERNAL  
	// Vref = 2.56v
	SET_BIT(ADMUX , 7);
	SET_BIT(ADMUX , 6);
	#elif   VREF   ==   AREF  
	// External reference voltage applied to Aref Pin <5v
	CLR_BIT(ADMUX , 7);
	CLR_BIT(ADMUX , 6);
	#else 
		#error  "Vref Selection ERROR"
	#endif
	
	// Channel , +VE and -VE differential , Gain Selection Bits ADMUX MUX0:4
    #if   CHANNEL   ==   ADC0 
	CLR_BIT(ADMUX , 0);
	CLR_BIT(ADMUX , 1);
	CLR_BIT(ADMUX , 2);
	CLR_BIT(ADMUX , 3);
	CLR_BIT(ADMUX , 4);
	
	#elif   CHANNEL   ==   ADC1
	SET_BIT(ADMUX , 0);
	CLR_BIT(ADMUX , 1);
	CLR_BIT(ADMUX , 2);
	CLR_BIT(ADMUX , 3);
	CLR_BIT(ADMUX , 4);
	
	#elif   CHANNEL   ==   ADC2
	CLR_BIT(ADMUX , 0);
	SET_BIT(ADMUX , 1);
	CLR_BIT(ADMUX , 2);
	CLR_BIT(ADMUX , 3);
	CLR_BIT(ADMUX , 4);
	
	#elif   CHANNEL   ==   ADC3
	SET_BIT(ADMUX , 0);
	SET_BIT(ADMUX , 1);
	CLR_BIT(ADMUX , 2);
	CLR_BIT(ADMUX , 3);
	CLR_BIT(ADMUX , 4);
	
	#elif   CHANNEL   ==   ADC4
	CLR_BIT(ADMUX , 0);
	CLR_BIT(ADMUX , 1);
	SET_BIT(ADMUX , 2);
	CLR_BIT(ADMUX , 3);
	CLR_BIT(ADMUX , 4);
	
	#elif   CHANNEL   ==   ADC5
	SET_BIT(ADMUX , 0);
	CLR_BIT(ADMUX , 1);
	SET_BIT(ADMUX , 2);
	CLR_BIT(ADMUX , 3);
	CLR_BIT(ADMUX , 4);
	
	#elif   CHANNEL   ==   ADC6
	CLR_BIT(ADMUX , 0);
	SET_BIT(ADMUX , 1);
	SET_BIT(ADMUX , 2);
	CLR_BIT(ADMUX , 3);
	CLR_BIT(ADMUX , 4);
	
	#elif   CHANNEL   ==   ADC7
	SET_BIT(ADMUX , 0);
	SET_BIT(ADMUX , 1);
	SET_BIT(ADMUX , 2);
	CLR_BIT(ADMUX , 3);
	CLR_BIT(ADMUX , 4);

	#elif   CHANNEL   ==   ADC1_pos_ADC0_neg_Gain_x10
	SET_BIT(ADMUX , 0);
	CLR_BIT(ADMUX , 1);
	CLR_BIT(ADMUX , 2);
	SET_BIT(ADMUX , 3);
	CLR_BIT(ADMUX , 4);

	#elif   CHANNEL   ==   ADC1_pos_ADC0_neg_Gain_x200
	SET_BIT(ADMUX , 0);
	SET_BIT(ADMUX , 1);
	CLR_BIT(ADMUX , 2);
	SET_BIT(ADMUX , 3);
	CLR_BIT(ADMUX , 4);

	#elif   CHANNEL   ==   ADC3_pos_ADC2_neg_Gain_x10
	SET_BIT(ADMUX , 0);
	CLR_BIT(ADMUX , 1);
	SET_BIT(ADMUX , 2);
	SET_BIT(ADMUX , 3);
	CLR_BIT(ADMUX , 4);

	#elif   CHANNEL   ==   ADC3_pos_ADC2_neg_Gain_x200
	SET_BIT(ADMUX , 0);
	SET_BIT(ADMUX , 1);
	SET_BIT(ADMUX , 2);
	SET_BIT(ADMUX , 3);
	CLR_BIT(ADMUX , 4);

	#elif   CHANNEL   ==   ADC0_pos_ADC1_neg_Gain_x1
	CLR_BIT(ADMUX , 0);
	CLR_BIT(ADMUX , 1);
	CLR_BIT(ADMUX , 2);
	CLR_BIT(ADMUX , 3);
	SET_BIT(ADMUX , 4);

	#elif   CHANNEL   ==   ADC2_pos_ADC1_neg_Gain_x1
	CLR_BIT(ADMUX , 0);
	SET_BIT(ADMUX , 1);
	CLR_BIT(ADMUX , 2);
	CLR_BIT(ADMUX , 3);
	SET_BIT(ADMUX , 4);

	#elif   CHANNEL   ==   ADC3_pos_ADC1_neg_Gain_x1
	SET_BIT(ADMUX , 0);
	SET_BIT(ADMUX , 1);
	CLR_BIT(ADMUX , 2);
	CLR_BIT(ADMUX , 3);
	SET_BIT(ADMUX , 4);

	#elif   CHANNEL   ==   ADC4_pos_ADC1_neg_Gain_x1
	CLR_BIT(ADMUX , 0);
	CLR_BIT(ADMUX , 1);
	SET_BIT(ADMUX , 2);
	CLR_BIT(ADMUX , 3);
	SET_BIT(ADMUX , 4);

	#elif   CHANNEL   ==   ADC5_pos_ADC1_neg_Gain_x1
	SET_BIT(ADMUX , 0);
	CLR_BIT(ADMUX , 1);
	SET_BIT(ADMUX , 2);
	CLR_BIT(ADMUX , 3);
	SET_BIT(ADMUX , 4);

	#elif   CHANNEL   ==   ADC6_pos_ADC1_neg_Gain_x1
	CLR_BIT(ADMUX , 0);
	SET_BIT(ADMUX , 1);
	SET_BIT(ADMUX , 2);
	CLR_BIT(ADMUX , 3);
	SET_BIT(ADMUX , 4);

	#elif   CHANNEL   ==   ADC7_pos_ADC1_neg_Gain_x1
	SET_BIT(ADMUX , 0);
	SET_BIT(ADMUX , 1);
	SET_BIT(ADMUX , 2);
	CLR_BIT(ADMUX , 3);
	SET_BIT(ADMUX , 4);

	#elif   CHANNEL   ==   ADC0_pos_ADC2_neg_Gain_x1
	CLR_BIT(ADMUX , 0);
	CLR_BIT(ADMUX , 1);
	CLR_BIT(ADMUX , 2);
	SET_BIT(ADMUX , 3);
	SET_BIT(ADMUX , 4);

	#elif   CHANNEL   ==   ADC1_pos_ADC2_neg_Gain_x1
	SET_BIT(ADMUX , 0);
	CLR_BIT(ADMUX , 1);
	CLR_BIT(ADMUX , 2);
	SET_BIT(ADMUX , 3);
	SET_BIT(ADMUX , 4);

	#elif   CHANNEL   ==   ADC3_pos_ADC2_neg_Gain_x1
	SET_BIT(ADMUX , 0);
	SET_BIT(ADMUX , 1);
	CLR_BIT(ADMUX , 2);
	SET_BIT(ADMUX , 3);
	SET_BIT(ADMUX , 4);

	#elif   CHANNEL   ==   ADC4_pos_ADC2_neg_Gain_x1
	CLR_BIT(ADMUX , 0);
	CLR_BIT(ADMUX , 1);
	SET_BIT(ADMUX , 2);
	SET_BIT(ADMUX , 3);
	SET_BIT(ADMUX , 4);

	#elif   CHANNEL   ==   ADC5_pos_ADC2_neg_Gain_x1
	SET_BIT(ADMUX , 0);
	CLR_BIT(ADMUX , 1);
	SET_BIT(ADMUX , 2);
	SET_BIT(ADMUX , 3);
	SET_BIT(ADMUX , 4);
	
	#else 
		#error  "Channel Selection ERROR"
	#endif
	
	/* ----------------------------------------*/ 
	
	// Adjustment Setting 
	/* ADCL Must Read First - Recommended Left Adjustment for 10 Bits Resolution
	 *     Right Adjustment for 8 Bits Resolution as only ADCH will be read */

	// Clear ADLAR Left Adjust Result bit "Right Adjustment"
	#if    ADJUSTMENT ==  RIGHT_ADJUSTMENT 
	CLR_BIT(ADMUX , 5);
	

	// Set ADLAR Left Adjust Result bit "Left Adjustment"
	#elif  ADJUSTMENT ==  LEFT_ADJUSTMENT   
	SET_BIT(ADMUX , 5);
	// dig_result variable is u16 
	

	
	#else 
		#error  "Adjustment Selection Mode ERROR"
	#endif

    /* -------------------------------------------------------------------*/ 
	/* The ADC will star a conversion on a positive edge of the selected trigger signal */

	// Enable ADATE "Auto Trigger Enable"
	SET_BIT(ADCSRA , 5);
	
	/* Auto Trigger Source Selection */
	
	// Free Running Mode 
	/* ADC Start Continuously */
	#if    ADC_AUTO_TRIGGER_SRC ==  FREE_RUNNING_MODE 
	CLR_BIT(SFIOR , 5);
	CLR_BIT(SFIOR , 6);
	CLR_BIT(SFIOR , 7);
	// Analog Comparator
	/* Compare two Analog Signals to start the ADC */
	#elif  ADC_AUTO_TRIGGER_SRC ==  ANALOG_COMPARATOR   
	SET_BIT(SFIOR , 5);
	CLR_BIT(SFIOR , 6);
	CLR_BIT(SFIOR , 7);
	// External Interrupt
	/* Can be configured by clicking on a button to start the conversion */
	#elif  ADC_AUTO_TRIGGER_SRC ==  EXT_INTERRUPT   
	CLR_BIT(SFIOR , 5);
	SET_BIT(SFIOR , 6);
	CLR_BIT(SFIOR , 7);
	// Timer/Counter0 Compare Match 
	#elif  ADC_AUTO_TRIGGER_SRC ==  TIMER_COUNTER0_COM_MATCH   
	SET_BIT(SFIOR , 5);
	SET_BIT(SFIOR , 6);
	CLR_BIT(SFIOR , 7);
	// Timer/Counter0 Overflow
	#elif  ADC_AUTO_TRIGGER_SRC ==  TIMER_COUNTER0_OVERFLOW  
	CLR_BIT(SFIOR , 5);
	CLR_BIT(SFIOR , 6);
	SET_BIT(SFIOR , 7);
	// Timer/Counter Compare Match B 
	#elif  ADC_AUTO_TRIGGER_SRC ==  TIMER_COUNTER0_COM_MATCH_B   
	SET_BIT(SFIOR , 5);
	CLR_BIT(SFIOR , 6);
	SET_BIT(SFIOR , 7);
	// Timer/Counter1 Overflow
	#elif  ADC_AUTO_TRIGGER_SRC ==  TIMER_COUNTER1_OVERFLOW
	CLR_BIT(SFIOR , 5);
	SET_BIT(SFIOR , 6);
	SET_BIT(SFIOR , 7);
	// Timer/Counter1 Capture Event
	#elif  ADC_AUTO_TRIGGER_SRC ==  TIMER_COUNTER1_CAP_EVENT
	SET_BIT(SFIOR , 5);
	SET_BIT(SFIOR , 6);
	SET_BIT(SFIOR , 7);
	#else 
		#error  "TRIGGER MODE Selection ERROR"
	#endif
	
	/* ----------------------------------------*/ 
	
	/* ADC AVR Max speed is 200KHz 
    64 Division Factor gives lower conversion time and higher power consumption
    128 Division Factor gives higher conversion time and lower power consumption  */
	// Setting ADPS "Analog Digital Prescaler Bits0:2"
	// 2 Division Factor 	
	#if   ADC_PRE_SCALER    == DIV_FAC_2
	SET_BIT(ADCSRA , 0);
	CLR_BIT(ADCSRA , 1);
	CLR_BIT(ADCSRA , 2);
	// 4 Division Factor 	
	#elif   ADC_PRE_SCALER  == DIV_FAC_4
	CLR_BIT(ADCSRA , 0);
	SET_BIT(ADCSRA , 1);
	CLR_BIT(ADCSRA , 2);
	// 8 Division Factor 	
	#elif   ADC_PRE_SCALER  == DIV_FAC_8
	SET_BIT(ADCSRA , 0);
	SET_BIT(ADCSRA , 1);
	CLR_BIT(ADCSRA , 2);
	// 16 Division Factor 	
	#elif   ADC_PRE_SCALER  == DIV_FAC_16
	CLR_BIT(ADCSRA , 0);
	CLR_BIT(ADCSRA , 1);
	SET_BIT(ADCSRA , 2);
	// 32 Division Factor 	
	#elif   ADC_PRE_SCALER  == DIV_FAC_32
	SET_BIT(ADCSRA , 0);
	CLR_BIT(ADCSRA , 1);
	SET_BIT(ADCSRA , 2);
    // 64 Division Factor 	
	#elif   ADC_PRE_SCALER  == DIV_FAC_64
	CLR_BIT(ADCSRA , 0);
	SET_BIT(ADCSRA , 1);
	SET_BIT(ADCSRA , 2);
	// 128 Division Factor  
	#elif   ADC_PRE_SCALER  == DIV_FAC_128
	SET_BIT(ADCSRA , 0);
	SET_BIT(ADCSRA , 1);
	SET_BIT(ADCSRA , 2);
	#else 
		#error  "PRE_SCALER MODE Selection ERROR"
	#endif
	
	/* ----------------------------------------*/ 
	
	/* ADIF "ADC Interrupt Flag" if Polling Mode is enabled Set Bit4
       if Interrupt Mode is enabled Auto Clear	*/
	   
	// Polling mode enabled  "Wait the ADC conversion Complete"
	#if     ADC_INTERRUPT  ==  POLLING
	// Set ADIF interrupt flag to 1 to be XORed with the input flag giving o/p 0
	SET_BIT(ADCSRA , 4);
	// Disable ADIE interrupt enable bit "PIE"
	CLR_BIT(ADCSRA , 3);
	/* The Global Interrupt SREG has to be enabled first
	after the ADC conversion complete the processor will fire an ADC interrupt
	so we need to set an action inside of the ADC ISR */
	#elif   ADC_INTERRUPT  ==  EN_INTERRUPT
	// CLR ADIF interrupt flag 0 to be XORed with the input flag giving o/p 1
	CLR_BIT(ADCSRA , 4);
	// Enable ADIE interrupt enable bit "PIE"
	SET_BIT(ADCSRA , 3);
	#else 
		#error  "INTERRUPT MODE Selection ERROR"
	#endif
}

	/* ----------------------------------------*/ 

void ADC_Enable(void)
{
	// Set ADEN "ADC Enable Bit" 
  
	SET_BIT(ADCSRA , 7);
}

/* ----------------------------------------*/ 

void ADC_Disable(void)
{
	// Clear ADEN "ADC Enable Bit" 
  
	CLR_BIT(ADCSRA , 7);
}

    /* ----------------------------------------*/ 
	
void ADC_Start_Conv(void)
{
	/* ADSC "Start Conversion Bit" cleared by hardware after conversion ends 
	has to be written after enable ADC Fn*/
  
	SET_BIT(ADCSRA , 6);
}


    /* ----------------------------------------*/ 


u16 ADC_Read(u8 channel)
{
	// Acquisition time Delay
	_delay_ms(2);
	u16 mv_analog = 0;
	
	// Polling check the ADIF interrupt flag
	while(GET_BIT(ADCSRA , 4) == 0);


	// 5000UL means to store 5000mVolt in unsigned long as it's big number
	/* input Analog = Digital Value * StepSize "Vref/2^resolution"
	*/
	// Note: Do the multiplication fist
	mv_analog = (ADC_Register * (5000UL)) / (1024);
	
	return mv_analog;
}





