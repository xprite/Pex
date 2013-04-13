/*
 * Steering.h
 *
 *  Created on: Apr 11, 2013
 *      Author: x
 */

#ifndef STEERING_H_
#define STEERING_H_

#include "PE_Types.h"

#define SERVO_MAX 5500
#define SERVO_CENTER  4500
#define SERVO_MIN 3500


typedef struct Steering
{
  int32_t ServoPosition;  // ServoPosition in +/- Values
  
}TSteering;

void SetServoPosition(int32_t aServoPosition);

#endif /* STEERING_H_ */
