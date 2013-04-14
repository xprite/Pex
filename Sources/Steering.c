/*
 * Steering.c
 *
 *  Created on: Apr 11, 2013
 *      Author: x
 */

#include "Steering.h"
#include "ServoTimer.h"

extern TSteering Steering;



void SetServoPosition(int32_t aServoPosition)
{
 
  int32_t temp = ((aServoPosition)) + Steering.ServoCenter; //  ServoCenter gives an offset to allow calling SetServoPosition with parameters in range of <-1000 ; +1000>

  if( (temp >= SERVO_MIN) && (temp <= SERVO_MAX) ) // Checking if the servo is in range.
  {
    ServoTimer_SetOffsetTicks(ServoTimer_DeviceData, 0, temp); // Writing servo position to HW register;
  }
}

void SteeringInit(TSteering* aSteering) // Init constants after reset
{
  aSteering->ServoCenter = SERVO_CENTER;  // servo center
  aSteering->ServoSensitivity = SERVO_SENSITIVITY;
  aSteering->Kp = 3;
  aSteering->Ki = 5;
  aSteering->Kd = 3;
  aSteering->DesiredValue = 0;
  aSteering->AntiWindUp = 300;
}

void SteeringControll(TSteering* aSteering)
{
  aSteering->Error = aSteering->DesiredValue - aSteering->LinePosition;
  aSteering->Integrator += aSteering->Error;
  
  if(aSteering->Integrator > aSteering->AntiWindUp) {
    aSteering->Integrator = aSteering->AntiWindUp;
  }
  
  if(aSteering->Integrator < - aSteering->AntiWindUp) {
   aSteering->Integrator = - aSteering->AntiWindUp; 
  }
  
  aSteering->Output = (aSteering->Error*aSteering->Kp) + (aSteering->Integrator*aSteering->Ki) + (aSteering->Error - aSteering->lastError)*aSteering->Kd;
  SetServoPosition(aSteering->Output);
  
  aSteering->lastError = aSteering->Error;
}
