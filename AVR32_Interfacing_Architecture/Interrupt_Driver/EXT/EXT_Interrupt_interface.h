/****************************************************************/
/*   Author          :    AbdElrahman Ibrahim Zaki		    */
/*	 Date 				:    25th of June 2020 				          	*/
/*	 Version 			:    1.0V 							                	*/
/*	 Description 		:  External Interrupt Interface file   */
/****************************************************************/


// functions to be given to the user

#ifndef  EXT_INT_H
#define  EXT_INT_H

#define   EXT0               1
#define   EXT1               2
#define   EXT2               3
#define   EXT0_EXT1          4
#define   EXT0_EXT2          5
#define   EXT1_EXT2          6
#define   EXT0_EXT1_EXT2     7


#define   LOW_LEVEL     1
#define   IOC           3    // interrupt of change
#define   FALLING       5  
#define   RISING        7

void EXT_INT_voidInit(void);
void EXT_INT_voidEnable(void);
void EXT_INT_voidDisable(void);
void EXT0_INT_voidSetCallBack(void (*pf)(void));
void EXT1_INT_voidSetCallBack(void (*pf)(void));
void EXT2_INT_voidSetCallBack(void (*pf)(void));

#endif
