/*
 * Controller.c
 *
 *  Created on: Apr 13, 2013
 *      Author: z
 */

#include "Controller.h"
#include "PWMMotor.h"

void ControllerInit(TController* aController)
{
  aController->DesiredValue = 20;
  aController->Integrator = 0;
  aController->Kp = 30;
  aController->Ki = 10;
  aController->Kd = 20;
  aController->AntiWindup = ANTI_WINDUP;
}

void ControllerMain(TController* aController)
{
  int32_t temp;
  
  aController->Error = aController->DesiredValue - aController->RealValue;
  aController->Integrator += aController->Error;

  /*Anti windup*/
  if(aController->Integrator > aController->AntiWindup) {
    aController->Integrator = aController->AntiWindup;
  }
  
  if(aController->Integrator < - aController->AntiWindup) {
    aController->Integrator = - aController->AntiWindup;
  }  

  
  aController->Output = (aController->Error * aController->Kp) + (aController->Integrator * aController->Ki) + ((aController->Error - aController->lastError)*aController->Kd);

  
  temp = (int32_t) aController->Output;
  if(temp < 0) {
    temp = 0;  
  }
  
  aController->lastError = aController->Error;
  
  PWMMotor_SetOffsetTicks(PWMMotor_DeviceData, 0, temp);
  PWMMotor_SetOffsetTicks(PWMMotor_DeviceData, 1, temp);
}

