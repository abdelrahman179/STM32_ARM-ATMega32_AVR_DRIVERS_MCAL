/****************************************************************************/
/* Author : AbdElrahman I.Zaki                                              */
/* Date   : 10 August 2020                                                  */
/* Version: V01                                                             */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 GPIO Prototypes of Public Functions */
/****************************************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


#define HIGH  1
#define LOW   0

        /* ---------------- GPIO Ports ----------------- */
typedef enum
{
    GPIOA = 0,
    GPIOB,
    GPIOC
}GPIO_Port_ID;
 
        /* ---------------- GPIO Pins ----------------- */
typedef enum
{
    PIN0 = 0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
    PIN8,
    PIN9,
    PIN10,
    PIN11,
    PIN12,
    PIN13,
    PIN14,
    PIN15
}GPIO_Pin_No;

                
typedef enum 
{
                /* ------------- Pins Output Mode/Configuration ---------------- */

    OUTPUT_SPEED_10MHZ_PP       = 0b0001,   /* Output Mode, 10MHz Config, Push-Pull                        */
    OUTPUT_SPEED_10MHZ_OD       = 0b0101,   /* Output Mode, 10MHz Config, Open Drain                       */
    OUTPUT_SPEED_10MHZ_AFPP     = 0b1001,   /* Output Mode, 10MHz Config, Alternative Function Push Pull   */
    OUTPUT_SPEED_10MHZ_AFOD     = 0b1101,   /* Output Mode, 10MHz Config, Alternative Function Open Drain  */

    OUTPUT_SPEED_2MHZ_PP        = 0b0010,   /* Output Mode, 2MHz Config, Push-Pull                         */
    OUTPUT_SPEED_2MHZ_OD        = 0b0110,   /* Output Mode, 2MHz Config, Open Drain                        */
    OUTPUT_SPEED_2MHZ_AFPP      = 0b1010,   /* Output Mode, 2MHz Config, Alternative Function Push Pull    */
    OUTPUT_SPEED_2MHZ_AFOD      = 0b1110,   /* Output Mode, 2MHz Config, Alternative Function Open Drain   */

    OUTPUT_SPEED_50MHZ_PP       = 0b0011,   /* Output Mode, 50MHz Config, Push-Pull                        */
    OUTPUT_SPEED_50MHZ_OD       = 0b0111,   /* Output Mode, 50MHz Config, Open Drain                       */
    OUTPUT_SPEED_50MHZ_AFPP     = 0b1011,   /* Output Mode, 50MHz Config, Alternative Function Push Pull   */
    OUTPUT_SPEED_50MHZ_AFOD     = 0b1111,   /* Output Mode, 50MHz Config, Alternative Function Open Drain  */

                /* ------------- Pins Input Mode/Configuration ---------------- */

    INPUT_ANALOG                = 0b0000,   /* Input Mode Config: Analog                                   */
    INPUT_FLOATING              = 0b0100,   /* Input Mode Config: Floating "Sensors"                       */
    INPUT_PULL_UP_OR_DOWN       = 0b1000    /* Input Mode Config: Pull Up/Down                             */
}GPIO_Modes;


/* number of pins to write into */
typedef enum 
{
	PINS_2       =   0x03  ,
	PINS_3       =   0x07  ,
	PINS_4       =   0x0f  ,
	PINS_5       =   0x1f  ,
	PINS_6       =   0x3f  ,
	PINS_7       =   0x7f  ,
	PINS_8       =   0xff  
}GPIO_No_Of_Pins;



/* ------ Function that sets the pin "mode and configuration" ------- */
void MGPIO_voidSetPinDirection(u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8MODE);

/* ----- Function that sets the pin value either "High or Low" ------ */
void MGPIO_voidSetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8VALUE);

/* ----- Function that get the pin value either "High or Low" ------- */
u8 MGPIO_u8GetPinValue(u8 Copy_u8PORT , u8 Copy_u8PIN);

void MGPIO_voidTogglePinValue (GPIO_Port_ID Copy_PORT , GPIO_Pin_No Copy_PIN);

void GPIO_voidSetPortMode(GPIO_Port_ID Copy_PORT , GPIO_Modes Copy_MODE);

void MGPIO_voidSetPortValue(GPIO_Port_ID Copy_PORT , u16 Copy_u16Value);

void GPIO_voidWritePins(GPIO_Port_ID Copy_PORT , GPIO_Pin_No CopyStartPinNumber , GPIO_No_Of_Pins CopyNumOfPins , u8 Copy_u8Value);

/* -----  Function that locks pin mode untill the next reset  ------- */
void MGPIO_u8LockPin(u8 Copy_u8PORT , u8 Copy_u8PIN);

#endif
