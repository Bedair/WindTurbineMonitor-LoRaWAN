/**********************************************************************
* File Name : MPU60x0_I2C_Wrapper.c
* 
* Description : Source File which Handle I2C communication with MPU60x0
*
* Author : Mohamed Bedair
*
* Date : 04 Dec 2023
*
**********************************************************************/

/**********************************************************************
*                            Macro Section                            *
**********************************************************************/

#include "MPU60x0.h"


#define MPU60X0_ACCELR_MEASUREMENTS_ADDRESS             (0x3B)
#define MPU60X0_TEMPERATURE_MEASUREMENTS_ADDRESS        (0x41)
#define MPU60X0_GYRO_MEASUREMENTS_ADDRESS               (0x43)
#define MPU60X0_GYRO_CONFIG_ADDRESS                     (0x1B)
#define MPU60X0_ACCEL_CONFIG_ADDRESS                    (0x1C)
#define MPU60X0_PWR_MGMT_1_ADDRESS                      (0x6B)

/**********************************************************************
*                           Local Functions                           *
**********************************************************************/


/**********************************************************************
*                          Global Variables                           *
**********************************************************************/



/**********************************************************************
*                          Global Functions                           *
**********************************************************************/

/*
* Funcation Name : MPU60x0_Start
* Description    : Used to set the device out of Sleep mode
* Parameters     : NA
* Return         : NA
*/
void MPU60x0_Start(void)
{
    uint8_t Tx_Data = 0;

    MPU60x0_Write(MPU60X0_PWR_MGMT_1_ADDRESS, &Tx_Data, 1);
}



/*
* Funcation Name : MPU60x0_Get_Gyroscope
* Description    : Used to get the latest Gyroscope Measurements
* Parameters     : Gyro : struct to hold the Gyro values
* Return         : NA
*/
void MPU60x0_Get_Gyroscope(Gyro_Data_T *Gyro)
{
    uint8_t RX_Buffer[6];

    MPU60x0_Read(MPU60X0_GYRO_MEASUREMENTS_ADDRESS, RX_Buffer, 6);
    
    Gyro->X = (((int16_t)RX_Buffer[0]) << 8) | RX_Buffer[1];
    Gyro->Y = (((int16_t)RX_Buffer[2]) << 8) | RX_Buffer[3];
    Gyro->Z = (((int16_t)RX_Buffer[4]) << 8) | RX_Buffer[5];
}



/*
* Funcation Name : MPU60x0_Get_Accelerometer
* Description    : Used to get the latest Accelerometer Measurements
* Parameters     : Accel : struct to hold the Accel values
* Return         : NA
*/
void MPU60x0_Get_Accelerometer(Accel_Data_T *Accel)
{
    uint8_t RX_Buffer[6];

    MPU60x0_Read(MPU60X0_ACCELR_MEASUREMENTS_ADDRESS, RX_Buffer, 6);

    Accel->X = (((int16_t)RX_Buffer[0]) << 8) | RX_Buffer[1];
    Accel->Y = (((int16_t)RX_Buffer[2]) << 8) | RX_Buffer[3];
    Accel->Z = (((int16_t)RX_Buffer[4]) << 8) | RX_Buffer[5];
}



/*
* Funcation Name : MPU60x0_Get_Temperature
* Description    : Used to get the latest Accelerometer Measurements
* Parameters     : NA
* Return         : Chip temperature
*/
int16_t MPU60x0_Get_Temperature(void)
{
    uint8_t RX_Buffer[2];
    int16_t temperature;

    MPU60x0_Read(MPU60X0_TEMPERATURE_MEASUREMENTS_ADDRESS, RX_Buffer, 2);
    temperature = (((int16_t)RX_Buffer[0]) << 8) | RX_Buffer[1];
    temperature = temperature / 340.0 + 36.53;

    return temperature;
}



/*
* Funcation Name : MPU60x0_Set_GyroRange
* Description    : Used to set the Gyroscope Range
* Parameters     : Gyroscope range
* Return         : NA
*/
void MPU60x0_Set_GyroRange(MPU60x0_GyroRange_T range)
{
    uint8_t Tx_Data = ((uint8_t)range) << 3;

    MPU60x0_Write(MPU60X0_GYRO_CONFIG_ADDRESS, &Tx_Data, 1);
}


/*
* Funcation Name : MPU60x0_Set_AccelRange
* Description    : Used to set the Accelerometer Range
* Parameters     : Accelerometer range
* Return         : NA
*/
void MPU60x0_Set_AccelRange(MPU60x0_AccelRange_T range)
{
    uint8_t Tx_Data = ((uint8_t)range) << 3;

    MPU60x0_Write(MPU60X0_ACCEL_CONFIG_ADDRESS, &Tx_Data, 1);
}
