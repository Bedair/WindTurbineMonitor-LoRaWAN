/**********************************************************************
* File Name : MPU60x0.h
* 
* Description : Header File control the MPU60x0
*
* Author : Mohamed Bedair
*
* Date : 04 Dec 2023
*
**********************************************************************/


#ifndef MPU60X0_H_
#define MPU60X0_H_

#include "MPU60x0_I2C_Wrapper.h"
#include "MPU60x0_typedef.h"


/*
* Funcation Name : MPU60x0_Start
* Description    : Used to set the device out of Sleep mode
* Parameters     : NA
* Return         : NA
*/
void MPU60x0_Start(void);

/*
* Funcation Name : MPU60x0_Get_Gyroscope
* Description    : Used to get the latest Gyroscope Measurements
* Parameters     : Gyro : struct to hold the Gyro values
* Return         : NA
*/
void MPU60x0_Get_Gyroscope(Gyro_Data_T *Gyro);



/*
* Funcation Name : MPU60x0_Get_Accelerometer
* Description    : Used to get the latest Accelerometer Measurements
* Parameters     : Accel : struct to hold the Accel values
* Return         : NA
*/
void MPU60x0_Get_Accelerometer(Accel_Data_T *Accel);



/*
* Funcation Name : MPU60x0_Get_Temperature
* Description    : Used to get the chip temperature
* Parameters     : NA
* Return         : Chip temperature
*/
int16_t MPU60x0_Get_Temperature(void);



/*
* Funcation Name : MPU60x0_Set_GyroRange
* Description    : Used to set the Gyroscope Range
* Parameters     : Gyroscope range
* Return         : NA
*/
void MPU60x0_Set_GyroRange(MPU60x0_GyroRange_T range);


/*
* Funcation Name : MPU60x0_Set_AccelRange
* Description    : Used to set the Accelerometer Range
* Parameters     : Accelerometer range
* Return         : NA
*/
void MPU60x0_Set_AccelRange(MPU60x0_AccelRange_T range);

                                 

#endif
