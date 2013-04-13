/*
 * Accelerometer.c
 *
 *  Created on: Apr 9, 2013
 *      Author: z
 */

#include "Accelerometer.h"

void AccelerometerInit(TAccelerometer* aAccelerometer)
{
  aAccelerometer->Received = FALSE;
  aAccelerometer->Sent = FALSE;
  
  uint8_t temp[10];
    temp[0] = CTRL_REG1;
    temp[1] = 0x00;
    aAccelerometer->Sent = FALSE;
    aAccelerometer->Error = I2C2_MasterSendBlock(I2C2_DeviceData, &temp[0], 0x02U, LDD_I2C_SEND_STOP);
    if(aAccelerometer->Error) PE_DEBUGHALT();
    while(!aAccelerometer->Sent);
    aAccelerometer->Sent = FALSE;
    
    do{
      I2C2_CheckBus(I2C2_DeviceData, &aAccelerometer->BusState);
    }
    while(aAccelerometer->BusState != LDD_I2C_IDLE);
      
    temp[0] = CTRL_REG4;
    temp[1] = INT_EN_DRDY;
    aAccelerometer->Sent = FALSE;
    aAccelerometer->Error = I2C2_MasterSendBlock(I2C2_DeviceData, &temp[0], 0x02U, LDD_I2C_SEND_STOP);
    if(aAccelerometer->Error) PE_DEBUGHALT();
    while(!aAccelerometer->Sent);
    aAccelerometer->Sent = FALSE;
   
    do{
      I2C2_CheckBus(I2C2_DeviceData,  &aAccelerometer->BusState);
    }
    while(aAccelerometer->BusState!= LDD_I2C_IDLE);
    
    temp[0] = CTRL_REG5;
    temp[1] = INT_CFG_DRDY;
    aAccelerometer->Sent = FALSE;
    aAccelerometer->Error = I2C2_MasterSendBlock(I2C2_DeviceData, &temp[0], 0x02U, LDD_I2C_SEND_STOP);
    if(aAccelerometer->Error) PE_DEBUGHALT();
    while(!aAccelerometer->Sent);
    aAccelerometer->Sent = FALSE;
    
    do{
      I2C2_CheckBus(I2C2_DeviceData, &aAccelerometer->BusState);
    }
    while(aAccelerometer->BusState != LDD_I2C_IDLE);
    
    
    temp[0] = CTRL_REG3;
    temp[1] = 0x01;
    aAccelerometer->Sent = FALSE;
    aAccelerometer->Error = I2C2_MasterSendBlock(I2C2_DeviceData, &temp[0], 0x02U, LDD_I2C_SEND_STOP);
    if(aAccelerometer->Error) PE_DEBUGHALT();
    while(!aAccelerometer->Sent);
    aAccelerometer->Sent = FALSE;
    
    do{
      I2C2_CheckBus(I2C2_DeviceData, &aAccelerometer->BusState);
    }
    while(aAccelerometer->BusState != LDD_I2C_IDLE);
    
    
    temp[0] = CTRL_REG1;
    temp[1] = 0x31;
    aAccelerometer->Sent = FALSE;
    aAccelerometer->Error = I2C2_MasterSendBlock(I2C2_DeviceData, &temp[0], 0x02U, LDD_I2C_SEND_STOP);
    if(aAccelerometer->Error) PE_DEBUGHALT();
    while(!aAccelerometer->Sent);
    aAccelerometer->Sent = FALSE;
    
    do{
      I2C2_CheckBus(I2C2_DeviceData, &aAccelerometer->BusState);
    }
    while(aAccelerometer->BusState != LDD_I2C_IDLE);
}
