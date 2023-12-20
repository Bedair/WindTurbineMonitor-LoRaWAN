/**********************************************************************
* File Name : User_App.c
* 
* Description : Source file for the main user application component 
*
* Author : Mohamed Bedair
*
* Date : 19 Dec 2023
*
**********************************************************************/

/**********************************************************************
*                            Macro Section                            *
**********************************************************************/
#include "User_App.h"

#include "platform.h"
#include "sys_app.h"
#include "utilities_def.h"


#include "App_Vibration.h"

/**********************************************************************
*                          Global Variables                           *
**********************************************************************/


/**********************************************************************
*                          Local Variables                           *
**********************************************************************/


/**********************************************************************
*                           Local Functions                           *
**********************************************************************/




/**********************************************************************
*                          Global Functions                           *
**********************************************************************/

/*
* Funcation Name : UserApp_Init
* Description    : Init Function for the User Application SW
* Parameters     : NA
* Return         : NA
*/
void UserApp_Init(void)
{
    APP_LOG(TS_ON, VLEVEL_M, " UserAppInit\r\n");
    App_Vibration_Init();
}



/*
* Funcation Name : UserApp_Mainfunction
* Description    : Main function for the User Application SW
* Parameters     : NA
* Return         : NA
*/
void UserApp_Mainfunction(void)
{
    APP_LOG(TS_ON, VLEVEL_H, " UserApp_MainFunction\r\n");

    App_Vibration_Get_Vibration_Level();
}


