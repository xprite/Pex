/*
 * Odometry.c
 *
 *  Created on: Apr 10, 2013
 *      Author: x
 */

#include "Odometry.h"

void OdometryInit(TOdometry* aOdometry)
{
  aOdometry->TotalDistance = 0;
  aOdometry->SpeedCounter = 0;
  aOdometry->Speed = 0;
}

