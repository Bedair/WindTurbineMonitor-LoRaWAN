/**********************************************************************
* File Name : App_Vibration.h
* 
* Description : Sources File to calculate the vibration values
*
* Author : Mohamed Bedair
*
* Date : 06 Dec 2023
*
**********************************************************************/

/**********************************************************************
*                            Macro Section                            *
**********************************************************************/

#include "App_Vibration.h"
#include "MPU60x0.h"
#include <stdlib.h>

#include "platform.h"
#include "sys_app.h"
#include "utilities_def.h"

#define LOG_ENABLED                     (1)
#define LOG_DISABLED                    (0)
#define LOG_STATE                       (LOG_ENABLED)


/**********************************************************************
*                           Local Functions                           *
**********************************************************************/



/**********************************************************************
*                          Global Variables                           *
**********************************************************************/
static Accel_Data_T Accel_Baseline; 


/**********************************************************************
*                          Global Functions                           *
**********************************************************************/
/*
* Funcation Name : App_Vibration_Init
* Description    : Initialize the vibration module (Initialize the IMU, and calculate the baseline)
* Parameters     : NA
* Return         : NA
*/
void App_Vibration_Init(void)
{
    int32_t Accel_X_Sum = 0;
    int32_t Accel_Y_Sum = 0;
    int32_t Accel_Z_Sum = 0;
    Accel_Data_T Accel_Temp; 

    MPU60x0_Start();

    MPU60x0_Set_GyroRange(MPU60X0_GYRO_RANGE_2000);
    MPU60x0_Set_AccelRange(MPU60X0_ACCEL_RANGE_16);

    for (uint8_t i = 0; i < 10 ; i++)
    {
        MPU60x0_Get_Accelerometer(&Accel_Temp);
        Accel_X_Sum += Accel_Temp.X;
        Accel_Y_Sum += Accel_Temp.Y;
        Accel_Z_Sum += Accel_Temp.Z;
    }

    Accel_Baseline.X = Accel_X_Sum / 10;
    Accel_Baseline.Y = Accel_Y_Sum / 10;
    Accel_Baseline.Z = Accel_Z_Sum / 10;

    
#if LOG_STATE == LOG_ENABLED
    APP_LOG(TS_ON, VLEVEL_M, "Baseline: %d , %d , %d \r\n", Accel_Baseline.X, Accel_Baseline.Y, Accel_Baseline.Z);
#endif
}


/*
* Funcation Name : App_Vibration_Get_Vibration_Level
* Description    : Used to calculate the Vibration level
* Parameters     : NA
* Return         : Vibration level
*/
Vibration_Level_T App_Vibration_Get_Vibration_Level(void)
{
    Accel_Data_T Accel_Temp; 
    Vibration_Level_T returnValue = NO_VIBRATION;
    uint16_t Difference_Sum = 0;

    /* Read the Current Accelerometer Values */
    MPU60x0_Get_Accelerometer(&Accel_Temp);

    /* Check the difference between current level and baseline values */
    Accel_Temp.X = abs(abs(Accel_Baseline.X) - abs(Accel_Temp.X));
    Accel_Temp.Y = abs(abs(Accel_Baseline.Y) - abs(Accel_Temp.Y));
    Accel_Temp.Z = abs(abs(Accel_Baseline.Z) - abs(Accel_Temp.Z));


    /* Calculate the average values of change accelerometer accross different axes */
    Difference_Sum = (Accel_Temp.X + Accel_Temp.Y + Accel_Temp.Z) / 3;


    /* Select the corrosponding vibration level */
    if (Difference_Sum > BIG_VIBRATION_THRESHOLD)
    {
        returnValue = BIG_VIBRATION;
    }
    else if (Difference_Sum > MEDIUM_VIBRATION_THRESHOLD)
    {
        returnValue = MEDIUM_VIBRATION;
    } 
    else if (Difference_Sum > SMALL_VIBRATION_THRESHOLD)
    {
        returnValue = SMALL_VIBRATION;
    } 
    else
    {
        returnValue = NO_VIBRATION;
    } 


#if LOG_STATE == LOG_ENABLED
    APP_LOG(TS_ON, VLEVEL_M, "Diffference: %d , %d , %d \r\n", Accel_Temp.X, Accel_Temp.Y, Accel_Temp.Z);
    APP_LOG(TS_ON, VLEVEL_M, "Vibration Level : %d \r\n\r\n", returnValue);
#endif

    return returnValue;
}
