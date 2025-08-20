/*
 * lsm6ds3.c
 *
 *  Created on: Aug 5, 2025
 *      Author: duvvu
 */


#include "lsm6ds3.h"

uint8_t LSM6DS3_ReadID(I2C_HandleTypeDef *hi2c) {
    uint8_t id;
    HAL_I2C_Mem_Read(hi2c, LSM6DS3_ADDR, 0X0F, I2C_MEMADD_SIZE_8BIT, &id, 1, HAL_MAX_DELAY);
    return id;
}

void LSM6DS3_Init(I2C_HandleTypeDef *hi2c) {
    uint8_t data;

    // Enable accelerometer: 104 Hz, 2g, BW = 50 Hz
    data = 0x40;
    HAL_I2C_Mem_Write(hi2c, LSM6DS3_ADDR, LSM6DS3_CTRL1_XL, 1, &data, 1, HAL_MAX_DELAY);

    // Enable gyroscope: 104 Hz, 245 dps
    data = 0x40;
    HAL_I2C_Mem_Write(hi2c, LSM6DS3_ADDR, LSM6DS3_CTRL2_G, 1, &data, 1, HAL_MAX_DELAY);
}

void LSM6DS3_ReadAccel(I2C_HandleTypeDef *hi2c, int16_t *ax, int16_t *ay, int16_t *az) {
    uint8_t buffer[6];
    HAL_I2C_Mem_Read(hi2c, LSM6DS3_ADDR, LSM6DS3_OUTX_L_XL, 1, buffer, 6, HAL_MAX_DELAY);
    *ax = (int16_t)(buffer[1] << 8 | buffer[0]);
    *ay = (int16_t)(buffer[3] << 8 | buffer[2]);
    *az = (int16_t)(buffer[5] << 8 | buffer[4]);
}

void LSM6DS3_ReadGyro(I2C_HandleTypeDef *hi2c, int16_t *gx, int16_t *gy, int16_t *gz) {
    uint8_t buffer[6];
    HAL_I2C_Mem_Read(hi2c, LSM6DS3_ADDR, LSM6DS3_OUTX_L_G, 1, buffer, 6, HAL_MAX_DELAY);
    *gx = (int16_t)(buffer[1] << 8 | buffer[0]);
    *gy = (int16_t)(buffer[3] << 8 | buffer[2]);
    *gz = (int16_t)(buffer[5] << 8 | buffer[4]);
}
