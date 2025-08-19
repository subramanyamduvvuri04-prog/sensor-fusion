#ifndef LSM6DS3_H
#define LSM6DS3_H

#include "stm32f4xx_hal.h"

// I2C address (0x6A << 1) for HAL
#define LSM6DS3_ADDR         (0x6A << 1)

// Register map
#define LSM6DS3_WHO_AM_I     0x0F
#define LSM6DS3_CTRL1_XL     0x10
#define LSM6DS3_CTRL2_G      0x11
#define LSM6DS3_OUTX_L_G     0x22
#define LSM6DS3_OUTX_L_XL    0x28

// Function declarations
uint8_t LSM6DS3_ReadID(I2C_HandleTypeDef *hi2c);
void LSM6DS3_Init(I2C_HandleTypeDef *hi2c);
void LSM6DS3_ReadAccel(I2C_HandleTypeDef *hi2c, int16_t *ax, int16_t *ay, int16_t *az);
void LSM6DS3_ReadGyro(I2C_HandleTypeDef *hi2c, int16_t *gx, int16_t *gy, int16_t *gz);

#endif
