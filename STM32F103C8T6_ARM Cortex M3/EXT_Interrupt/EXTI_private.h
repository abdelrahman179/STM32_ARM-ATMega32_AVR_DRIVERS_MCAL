/**********************************************************************************/
/* Author : AbdElrahman I.Zaki                                                    */
/* Date   : 21 August 2020                                                        */
/* Version: V01                                                                   */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 EXT Int Prototypes of private Functions   */
/**********************************************************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

/* Typedef define a new data type based on an old data type  typdef  unsigned char   u8
                                                                        old          new 
    in struct EXTI_Type is the new data type and struct with all its content is old data type */

typedef stuct{

     volatile u32 EXTI_IMR;          // Interrupt Mask Register               -> Interrupt on Line x, Enable 1/Disable 0
     volatile u32 EXTI_EMR;          // Event Mask Register                   -> 
     volatile u32 EXTI_RTSR;         // Rising Trigger Selection Register     -> Rising mode on Line x, Enable 1/Disable 0
     volatile u32 EXTI_FTSR;         // Falling Trigger Selection Register    -> Falling mode on Line x, Enable 1/Disable 0
     volatile u32 EXTI_SWIER;        // Software Interrupt Event Register     -> Software Interrupt 
     volatile u32 EXTI_PR;           // Pending Register                      -> 

}EXTI_Type;

// EXT Interrupt Base Address 0x4001 0400
/* Pointer to struct that points to the base address of EXT Interrupt
    and the first register offset noting that each step is by 32bits */
#define EXTI_Ptr    ((volatile EXTI_Type*) 0x40010400) 

/* EXTI16 -> PVD , EXTI17 -> RTC , EXTI18 -> USB , EXTI19 -> Ethernet wakeup */
/* Line0 = GPIOA0 GPIOB0 GPIOC0 and so on */
#define LINE0       0
#define LINE1       1
#define LINE2       2
#define LINE3       3
#define LINE4       4
#define LINE5       5
#define LINE6       6
#define LINE7       7
#define LINE8       8
#define LINE9       9
#define LINE10      10
#define LINE11      11
#define LINE12      12
#define LINE13      13
#define LINE14      14
#define LINE15      15


#define RISING_EDGE         0
#define FALLING_EDGE        1
#define ON_CHANGE           2



#endif
