/**********************************************************************
* File Name : App_Vibration.h
* 
* Description : Header File to calculate the vibration values
*
* Author : Mohamed Bedair
*
* Date : 06 Dec 2023
*
**********************************************************************/


#ifndef APP_VIBRTION_H_
#define APP_VIBRTION_H_

#include "stm32wlxx_hal.h"

#define VIBRATION_THRESHOLD       (30)


typedef enum
{
    NO_VIBRATION,
    VIBRATION
}Vibration_State_T;



/*
* Funcation Name : App_Vibration_Init
* Description    : Initialize the vibration module (Initialize the IMU, and calculate the baseline)
* Parameters     : NA
* Return         : NA
*/
void App_Vibration_Init(void);


/*
* Funcation Name : App_Vibration_Get_Vibration_Level
* Description    : Used to calculate the Vibration level
* Parameters     : NA
* Return         : Vibration level
*/
Vibration_State_T App_Vibration_Get_Vibration_Level(void);
                          

#endif
