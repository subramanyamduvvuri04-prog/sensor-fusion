#ifndef LSM6DS3_H
#define LSM6DS3_H

#include "stm32f4xx_hal.h"


#define LSM6DS3_ADDR        (0x6A << 1)  // 8-bit address
#define LSM6DS3_WHO_AM_I    0x0F
#define LSM6DS3_CTRL1_XL    0x10
#define LSM6DS3_CTRL2_G     0x11
#define LSM6DS3_OUTX_L_G    0x22  // Gyro + Accel start here

void LSM6DS3_Init(I2C_HandleTypeDef *hi2c);
uint8_t LSM6DS3_ReadID(I2C_HandleTypeDef *hi2c);
void LSM6DS3_ReadNonBlocking(void);

extern uint8_t rx_buffer[12];
extern I2C_HandleTypeDef *i2c_lsm6;
extern volatile uint8_t imu_data_ready;

#endif
