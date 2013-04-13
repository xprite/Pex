/*
 * TMap.h
 *
 *  Created on: Apr 10, 2013
 *      Author: x
 */

#ifndef TMAP_H_
#define TMAP_H_

#include "PE_Types.h"
#include "Odometry.h"
#include "Accelerometer.h"

#define MAP_LENGTH 1000


typedef struct MapNode
{
  int16_t AccelerometerX, AccelerometerY, AccelerometerZ;
  int16_t ServoPosition;
  int8_t LinePosition;
}TMapNode;

typedef struct Map
{
  TMapNode MapNodes[MAP_LENGTH];
}TMap;


void MapInit(TMap* aMap);
void MapMain(TMap* aMap, TOdometry* aOdometry, TAccelerometer* aAccelerometer);

#endif /* TMAP_H_ */



