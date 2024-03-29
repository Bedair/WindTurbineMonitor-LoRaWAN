/**********************************************************************
* File Name : User_App.h
* 
* Description : Source file for the main user application component 
*
* Author : Mohamed Bedair
*
* Date : 19 Dec 2023
*
**********************************************************************/


#ifndef USER_APP_H
#define USER_APP_H



#define MOTOR_ENCODER_PIN       GPIO_PIN_5
#define MOTOR_COUNTS_PER_CYCLE  (11)


/*
* Funcation Name : UserApp_Init
* Description    : Init Function for the User Application SW
* Parameters     : NA
* Return         : NA
*/
void UserApp_Init(void);


/*
* Funcation Name : UserApp_Mainfunction
* Description    : Main function for the User Application SW
* Parameters     : NA
* Return         : NA
*/
void UserApp_Mainfunction(void);


void UserApp_Motor_Encoder_Event(void);

#endif