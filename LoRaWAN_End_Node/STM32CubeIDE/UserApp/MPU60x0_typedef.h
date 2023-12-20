/**********************************************************************
* File Name : MPU60x0_typedef.h
* 
* Description : Header File for the user types related to MPU60x0
*
* Author : Mohamed Bedair
*
* Date : 04 Dec 2023
*
**********************************************************************/


#ifndef MPU60X0_TYPEDEF_H_
#define MPU60X0_TYPEDEF_H_

#include "stm32wlxx_hal.h"


typedef enum
{
    MPU60X0_NOT_OK,
    MPU60X0_OK
}MPU60x0_Return_type;


typedef enum{
    MPU60X0_GYRO_RANGE_250 = 0,
    MPU60X0_GYRO_RANGE_500,
    MPU60X0_GYRO_RANGE_1000,
    MPU60X0_GYRO_RANGE_2000
}MPU60x0_GyroRange_T;

typedef enum{
    MPU60X0_ACCEL_RANGE_2 = 0,
    MPU60X0_ACCEL_RANGE_4,
    MPU60X0_ACCEL_RANGE_8,
    MPU60X0_ACCEL_RANGE_16
}MPU60x0_AccelRange_T;



typedef struct {
    int16_t X;
    int16_t Y;
    int16_t Z;
}Gyro_Data_T;


typedef struct {
    int16_t X;
    int16_t Y;
    int16_t Z;
}Accel_Data_T;

                                    

#endif