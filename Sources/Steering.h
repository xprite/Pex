/*
 * Steering.h
 *
 *  Created on: Apr 11, 2013
 *      Author: x
 */

#ifndef STEERING_H_
#define STEERING_H_

#include "PE_Types.h"

#define SERVO_INCREMENT 10
#define SERVO_MAX 5500
#define SERVO_CENTER  4500
#define SERVO_MIN 3500

#define SERVO_SENSITIVITY 20


typedef struct Steering
{
  uint16_t ServoCenter;
  int32_t ServoSensitivity;
  int32_t ServoPosition;  // ServoPosition in +/- Values
  int32_t LinePosition;
  
  int32_t Integrator;
  int32_t DesiredValue;
  int32_t Error;
  int32_t Output;
  
  int32_t AntiWindUp;
  int32_t lastError;
  
  int32_t Kp;
  int32_t Ki;
  int32_t Kd;
  
  
}TSteering;

void SteeringInit(TSteering* aSteering);
void SetServoPosition(int32_t aServoPosition);
void SteeringControll(TSteering* aSteering);



#endif /* STEERING_H_ */
