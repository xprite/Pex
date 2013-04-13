/*
 * Communication.c
 *
 *  Created on: Mar 16, 2013
 *      Author: z
 */

#include "Communication.h"
#include "AS1.h"
#include "Accelerometer.h"
#include "Camera.h"
#include "Odometry.h"
#include "PE_Types.h"

extern TOdometry Odometry;
extern TCamera Camera;
extern TAccelerometer Accelerometer;
extern TCommunication Communication;

uint8_t GetCameraDataPacket[PACKET_LENGTH] = "gcameraimg";
uint8_t GetAccelerometerDataPacket[PACKET_LENGTH] = "gacceldata";
uint8_t GetOdometryTotalDistancePacket[PACKET_LENGTH] = "gtdistance";
uint8_t GetConvolutionResultPacket[PACKET_LENGTH] = "gconvolres";


void CommunicationHandler(TCommunication* CommunicationStruct)
{
  int compare;
  // Camera
  compare = memcmp(CommunicationStruct->ReceivedPacket, GetCameraDataPacket, PACKET_LENGTH);
  if(compare == 0)
  {
    GetCameraDataPacketHandler();
  }
  
  //Convolution Result
  compare = memcmp(CommunicationStruct->ReceivedPacket, GetConvolutionResultPacket, PACKET_LENGTH);
    if(compare == 0)
    {
      GetConvolutionResultPacketHandler();
    }
  
  // Accelerometer
  compare = memcmp(CommunicationStruct->ReceivedPacket, GetAccelerometerDataPacket, PACKET_LENGTH);
  if(compare == 0)
  {
    GetAccelerometerDataPacketHandler();
  }
  
  // Odometry
  compare = memcmp(CommunicationStruct->ReceivedPacket, GetOdometryTotalDistancePacket, PACKET_LENGTH);
  if(compare == 0)
  {
    GetOdometryTotalDistancePacketHandler();
  }
}

void GetCameraDataPacketHandler(void)
{
  Communication.Error = AS1_SendBlock(AS1_DeviceData, &Camera.readPointerToBuffer[0], PIXEL_NUM);
  if(Communication.Error) {

  }
}

void GetOdometryTotalDistancePacketHandler(void)
{
  sprintf(&Communication.CommunicationString[0], "%lu\n", Odometry.TotalDistance);
  Communication.Error = AS1_SendBlock(AS1_DeviceData, &Communication.CommunicationString[0], strlen(Communication.CommunicationString));
}

void GetAccelerometerDataPacketHandler(void)
{
  sprintf(&Communication.CommunicationString[0], "%i %i %i\n", Accelerometer.X, Accelerometer.Y, Accelerometer.Z);
  Communication.Error = AS1_SendBlock(AS1_DeviceData, &Communication.CommunicationString[0], strlen(Communication.CommunicationString));
  if(Communication.Error) {

  }
}

void GetConvolutionResultPacketHandler(void)
{
  Communication.Error = AS1_SendBlock(AS1_DeviceData, &Camera.ConvolutionResult[0], PIXEL_NUM);
  if(Communication.Error) {

  }  
}
