/*
 * lsm6ds3.c
 *
 *  Created on: Aug 5, 2025
 *      Author: duvvu
 */


#include "lsm6ds3.h"
uint8_t rx_buffer[12];
I2C_HandleTypeDef *i2c_lsm6 = NULL;
volatile uint8_t imu_data_ready = 0;

void LSM6DS3_Init(I2C_HandleTypeDef *hi2c) {
    i2c_lsm6 = hi2c;

    uint8_t ctrl1 = 0x60; // ODR = 416Hz, FS = 2g
    HAL_I2C_Mem_Write(hi2c, LSM6DS3_ADDR, LSM6DS3_CTRL1_XL,
                      I2C_MEMADD_SIZE_8BIT, &ctrl1, 1, HAL_MAX_DELAY);

    uint8_t ctrl2 = 0x60; // ODR = 416Hz, FS = 2000 dps
    HAL_I2C_Mem_Write(hi2c, LSM6DS3_ADDR, LSM6DS3_CTRL2_G,
                      I2C_MEMADD_SIZE_8BIT, &ctrl2, 1, HAL_MAX_DELAY);
}

uint8_t LSM6DS3_ReadID(I2C_HandleTypeDef *hi2c) {
    uint8_t id;
    HAL_I2C_Mem_Read(hi2c, LSM6DS3_ADDR, LSM6DS3_WHO_AM_I,
                     I2C_MEMADD_SIZE_8BIT, &id, 1, HAL_MAX_DELAY);
    return id;
}

void LSM6DS3_ReadNonBlocking(void) {
    imu_data_ready = 0;
    HAL_I2C_Mem_Read_IT(i2c_lsm6, LSM6DS3_ADDR,
                        LSM6DS3_OUTX_L_G, I2C_MEMADD_SIZE_8BIT,
                        rx_buffer, 12);
}
