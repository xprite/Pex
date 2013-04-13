/*
 * Accelerometer.h
 *
 *  Created on: Apr 9, 2013
 *      Author: z
 */

#ifndef ACCELEROMETER_H_
#define ACCELEROMETER_H_

#include "PE_Types.h"
#include "I2C2.h"

#define OUT_X_MSB 0x01
#define WHO_AM_I 0x0D
#define CTRL_REG1 0x2A
#define CTRL_REG2 0x2B
#define CTRL_REG3 0x2C
#define CTRL_REG4 0x2D
#define CTRL_REG5 0x2E

/* MMA8451Q bits */
#define RST (1<<6)
#define DR1 (1<<4)
#define PP_OD (1<<0)
#define INT_EN_DRDY 0x01
#define INT_CFG_DRDY 0x01
#define ACTIVE (1<<0)
#define IPOL (1<<1)

typedef struct Accelerometer{
  int16_t X;
  int16_t Y;
  int16_t Z;  
  int16_t Acceleration[3];  // Data Converted to Signed Char x, y, z
  uint8_t ReceiveBuffer[6];  // Receive Buffer;
  uint8_t TransmitBuffer[6];
  volatile bool Sent;  // Flag Data Sent
  volatile bool Received; //Flag Data Received
  LDD_TError Error;
  LDD_I2C_TBusState BusState;
}TAccelerometer;

void AccelerometerInit(TAccelerometer* aAccelerometer);

#endif /* ACCELEROMETER_H_ */
