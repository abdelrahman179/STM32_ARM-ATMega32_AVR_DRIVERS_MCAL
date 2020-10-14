/****************************************************************************/
/* Author : AbdElrahman I.Zaki                                              */
/* Date   : 10 August 2020                                                  */
/* Version: V01                                                             */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 GPIO Prototypes of Public Functions */
/****************************************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define GPIO_HIGH  1
#define GPIO_LOW   0

#define GPIOA      0
#define GPIOB      1
#define GPIOC      2

#define PIN0       0
#define PIN1       1
#define PIN2       2
#define PIN3       3
#define PIN4       4
#define PIN5       5
#define PIN6       6
#define PIN7       7
#define PIN8       8
#define PIN9       9
#define PIN10      10
#define PIN11      11
#define PIN12      12
#define PIN13      13
#define PIN14      14
#define PIN15      15

/* ------ Function that sets the pin "mode and configuration" ------- */
void MGPIO_voidSetPinDirection(u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8MODE);

/* ----- Function that sets the pin value either "High or Low" ------ */
void MGPIO_voidSetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8VALUE);

/* ----- Function that get the pin value either "High or Low" ------- */
u8 MGPIO_u8GetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN);

/* -----  Function that locks pin mode untill the next reset  ------- */
void MGPIO_u8LockPin(u8 Copy_u8PORT , u8 Copy_u8PIN);


#endif
