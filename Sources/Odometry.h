/*
 * Odometry.h
 *
 *  Created on: Apr 3, 2013
 *      Author: z
 */

#ifndef ODOMETRY_H_
#define ODOMETRY_H_

#include "PE_Types.h"

#define MAX_SPEED 1000000
#define AVERAGE_SAMPLES_COUNT 5

typedef struct Odometry{
  volatile uint32_t TotalDistance;
  volatile uint32_t MeasuredSpeed[AVERAGE_SAMPLES_COUNT];
  volatile uint32_t Speed;
  volatile uint32_t SpeedCounter;
  volatile uint32_t DefaultValue;
  volatile bool SetReset;
}TOdometry;

void OdometryInit(TOdometry* aOdometry);

#endif /* ODOMETRY_H_ */
