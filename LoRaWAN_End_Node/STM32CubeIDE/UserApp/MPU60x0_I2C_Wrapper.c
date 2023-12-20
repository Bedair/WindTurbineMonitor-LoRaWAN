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

#include "MPU60x0_I2C_Wrapper.h"




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
* Funcation Name : MPU60x0_Read
* Description    : Used to Read MPU60x0 Registers
* Parameters     : MemAddress : Address to start reading from
                 : pData      : Point to the variable to read the data in
                 : Size       : Size of the data to be read
* Return         : Operation status (Pass / Failed)
*/
MPU60x0_Return_type MPU60x0_Read(uint8_t MemAddress, uint8_t *pData, uint8_t Size)
{
    MPU60x0_Return_type status = MPU60X0_NOT_OK;

    /* Use the HAL API to read the MPU60x0 register via I2C */
    HAL_StatusTypeDef ret;

    ret = HAL_I2C_Mem_Read(&hi2c1, MPU60x0_I2C_ADDRESS, MemAddress, MPU60x0_MEM_ADDRESS_SIZE, pData, Size, HAL_MAX_DELAY);

    if (ret == HAL_OK)
	{
	  status = MPU60X0_OK;
	}

    return status;
}


/*
* Funcation Name : MPU60x0_Write
* Description    : Used to Write MPU60x0 Registers
* Parameters     : MemAddress : Address to start Writing to
                 : pData      : Point to the variablehold the data to be written
                 : Size       : Size of the data to be written
* Return         : Operation status (Pass / Failed)
*/
MPU60x0_Return_type MPU60x0_Write(uint8_t MemAddress, uint8_t *pData, uint8_t Size)
{
    MPU60x0_Return_type status = MPU60X0_NOT_OK;

    /* Use the HAL API to read the MPU60x0 register via I2C */
    HAL_StatusTypeDef ret;

    ret = HAL_I2C_Mem_Write(&hi2c1, MPU60x0_I2C_ADDRESS, MemAddress, MPU60x0_MEM_ADDRESS_SIZE, pData, Size, HAL_MAX_DELAY);

    if (ret == HAL_OK)
	{
	  status = MPU60X0_OK;
	}

    return status;
}


