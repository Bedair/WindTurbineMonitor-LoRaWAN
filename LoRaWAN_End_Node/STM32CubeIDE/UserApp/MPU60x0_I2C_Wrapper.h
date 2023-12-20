/**********************************************************************
* File Name : MPU60x0_I2C_Wrapper.h
* 
* Description : Header File which Handle I2C communication with MPU60x0
*
* Author : Mohamed Bedair
*
* Date : 04 Dec 2023
*
**********************************************************************/


#ifndef MPU60X0_I2C_WRAPPER_H_
#define MPU60X0_I2C_WRAPPER_H_

#include "stm32wlxx_hal.h"
#include "stm32wlxx_hal_i2c.h"

#include "MPU60x0_typedef.h"


#define MPU60x0_I2C_ADDRESS         (0x68 << 1)
#define MPU60x0_MEM_ADDRESS_SIZE    (1)


extern I2C_HandleTypeDef hi2c1;


/*
* Funcation Name : MPU60x0_Read
* Description    : Used to Read MPU60x0 Registers
* Parameters     : MemAddress : Address to start reading from
                 : pData      : Point to the variable to read the data in
                 : Size       : Size of the data to be read
* Return         : Operation status (Pass / Failed)
*/
MPU60x0_Return_type MPU60x0_Read(uint8_t MemAddress, uint8_t *pData, uint8_t Size);


/*
* Funcation Name : MPU60x0_Write
* Description    : Used to Write MPU60x0 Registers
* Parameters     : MemAddress : Address to start Writing to
                 : pData      : Point to the variablehold the data to be written
                 : Size       : Size of the data to be written
* Return         : Operation status (Pass / Failed)
*/
MPU60x0_Return_type MPU60x0_Write(uint8_t MemAddress, uint8_t *pData, uint8_t Size);
                                    

#endif