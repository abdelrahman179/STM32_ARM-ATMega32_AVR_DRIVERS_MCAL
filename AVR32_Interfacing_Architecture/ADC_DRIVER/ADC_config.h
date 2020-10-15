/****************************************************************/
/*    Author       :    AbdElrahman Ibrahim Zaki		*/
/*    Date 	   :    23rd of June 2020                       */
/*    Version      :    1.0V 		                        */
/*    Description  :    ADC User Manual                         */
/****************************************************************/

#ifndef  ADC_CONFIG_H
#define  ADC_CONFIG_H

/* Vref Might be AVCC     = 5 volt  
                 INTERNAL = 2.56 volt  
		 AREF                  */	 
#define   VREF                     AVCC  
/* Channel Selection 
Range :   ADC0 - ADC7		                	
          ADC1_pos_ADC0_neg_Gain_x10      
          ADC1_pos_ADC0_neg_Gain_x200     
          ADC3_pos_ADC2_neg_Gain_x10      
          ADC3_pos_ADC2_neg_Gain_x200     
          ADC0_pos_ADC1_neg_Gain_x1       
          ADC2_pos_ADC1_neg_Gain_x1       
          ADC3_pos_ADC1_neg_Gain_x1       
          ADC4_pos_ADC1_neg_Gain_x1       
          ADC5_pos_ADC1_neg_Gain_x1       
	  ADC6_pos_ADC1_neg_Gain_x1       
	  ADC7_pos_ADC1_neg_Gain_x1       
	  ADC0_pos_ADC2_neg_Gain_x1       
  	  ADC1_pos_ADC2_neg_Gain_x1       
          ADC3_pos_ADC2_neg_Gain_x1       
	  ADC4_pos_ADC2_neg_Gain_x1       
	  ADC5_pos_ADC2_neg_Gain_x1    */ 
#define   CHANNEL                  ADC0

/* ADCL Must Read First - Recommended Left Adjustment for 10 Bits Resolution
	 *     Right Adjustment for 8 Bits Resolution as only ADCH will be read */
 
/* Range : - RIGHT_ADJUSTMENT
           - LEFT_ADJUSTMENT
*/

#define   ADJUSTMENT               LEFT_ADJUSTMENT

// Trigger Mode

/* Range :         - FREE_RUNNING_MODE           > ADC Start Continuously
		   - ANALOG_COMPARATOR           > Compare two Analog Signals to start the ADC
		   - EXT_INTERRUPT               > Can be configured by clicking on a button to start the conversion
		   - TIMER_COUNTER0_COM_MATCH    > Start the conversion on Timer/Counter0 Compare Match
		   - TIMER_COUNTER0_OVERFLOW     > Start the conversion on Timer/Counter0 Overflow 
		   - TIMER_COUNTER0_COM_MATCH_B  > Start the conversion on Timer/Counter Compare Match B
		   - TIMER_COUNTER1_OVERFLOW     > Start the conversion on Timer/Counter1 Overflow
		   - TIMER_COUNTER1_CAP_EVENT    > Start the conversion when Timer/Counter1 Capture Event
		   */
#define   ADC_AUTO_TRIGGER_SRC     FREE_RUNNING_MODE

// PreScaler Selection

/* ADC AVR Max speed is 200KHz 
   64 Division Factor gives lower conversion time and higher power consumption
   128 Division Factor gives higher conversion time and lower power consumption  */	

/* Range :         - DIV_FAC_2
		   - DIV_FAC_4
		   - DIV_FAC_8
		   - DIV_FAC_16
		   - DIV_FAC_32
		   - DIV_FAC_64
		   - DIV_FAC_128
*/ 
#define   ADC_PRE_SCALER           DIV_FAC_64

/* Range :         - EN_INTERRUPT   > after the ADC conversion complete the processor will fire an ADC interrupt
							  so we need to set an action inside of the ADC ISR
 		   - POLLING        > Wait the ADC conversion Complete
*/ 
#define   ADC_INTERRUPT            POLLING

#endif
