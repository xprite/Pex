/*
 * Map.c
 *
 *  Created on: Apr 10, 2013
 *      Author: x
 */

#include "Map.h"

void MapInit(TMap* aMap)
{
  int i;
  for(i=0 ; i<MAP_LENGTH ; i++)
  {
    aMap->MapNodes[i].AccelerometerX = 0;
    aMap->MapNodes[i].AccelerometerY = 0;
    aMap->MapNodes[i].AccelerometerZ = 0;    
  }
}

//Called when impulse from Odometry sensor is received
void MapMain(TMap* aMap, TOdometry* aOdometry, TAccelerometer* aAccelerometer)
{
  // if is in range - the impulse counter gives index to map
  if(aOdometry->TotalDistance < MAP_LENGTH) {
    aMap->MapNodes[aOdometry->TotalDistance].AccelerometerX = aAccelerometer->X;
    aMap->MapNodes[aOdometry->TotalDistance].AccelerometerY = aAccelerometer->Y;
    aMap->MapNodes[aOdometry->TotalDistance].AccelerometerZ = aAccelerometer->Z;
  }
}
