/**************************************************************************************/
/* Author : AbdElrahman I.Zaki                                                        */
/* Date   : 19 August 2020                                                            */
/* Version: V01                                                                       */
/* Desc.  : STM32F103C8T6 ARM Cortex M3 NVIC Register addresses and private functions */
/**************************************************************************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H


                /* Base address of NVIC 0xE000E100 */ 
/* Noting that it's memory mapped as it's a core peripheral with no address */ 



#define NVIC_ISER0     *((u32 *) 0xE000E100) /* Interrupt Set-Enable Reg, Enable external interrupts from 0 to 31     */
#define NVIC_ISER1     *((u32 *) 0xE000E104) /* Interrupt Set-Enable Reg, Enable external interrupts from 32 to 63    */

#define NVIC_ICER0     *((u32 *) 0xE000E180) /* Interrupt Clear-Enable Reg, Disable external interrupts from 32 to 63 */
#define NVIC_ICER1     *((u32 *) 0xE000E184) /* Interrupt Clear-Enable Reg, Disable external interrupts from 32 to 63 */

#define NVIC_ISPR0     *((u32 *) 0xE000E200) /* Interrupt Set Pending Register, Enable pending flag from 0 to 31      */
#define NVIC_ISPR1     *((u32 *) 0xE000E204) /* Interrupt Set Pending Register, Enable pending flag from 32 to 63     */

#define NVIC_ICPR0     *((u32 *) 0xE000E280) /* Interrupt Clear Pending Register, Enable pending flag from 0 to 31    */
#define NVIC_ICPR1     *((u32 *) 0xE000E284) /* Interrupt Clear Pending Register, Enable pending flag from 32 to 63   */ 

// Read only register we have to wirte volatile
#define NVIC_IABR0     *((volatile u32 *) 0xE000E300) /* Interrupt Active Bit Register, Reads active flag status 0 to 32    */ 
#define NVIC_IABR1     *((volatile u32 *) 0xE000E304) /* Interrupt Active Bit Register, Reads active flag status 32 to 63   */ 



#endif 
