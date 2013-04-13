/*
 * Steering.c
 *
 *  Created on: Apr 11, 2013
 *      Author: x
 */

#include "Steering.h"
#include "ServoTimer.h"

void SetServoPosition(int32_t aServoPosition)
{
  if( (aServoPosition >= SERVO_MIN) && (aServoPosition <= SERVO_MAX) )
  {
    ServoTimer_SetOffsetTicks(ServoTimer_DeviceData, 0, aServoPosition);
  }
}
