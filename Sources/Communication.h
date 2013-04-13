/*
 * Communication.h
 *
 *  Created on: Mar 16, 2013
 *      Author: z
 */

#ifndef COMMUNICATION_H_
#define COMMUNICATION_H_

#include <stdint.h>
#include <cstring>
#include "PE_Types.h"

#define PACKET_LENGTH 10
#define MAX_STRING_LENGTH 1024

typedef struct Communication{
  uint16_t Error;
  bool CommandReceived;
  bool CommandDone;
  char CommunicationString[MAX_STRING_LENGTH]; // 1024 bytes is the MAX 
  uint8_t ReceivedPacket[PACKET_LENGTH];
}TCommunication, *TCommunicationPtr;


void CommunicationHandler(TCommunication* CommunicationStruct);

void GetConvolutionResultStringPacketHandler(void);
void GetOdometryTotalDistancePacketHandler(void);
void GetCameraDataPacketHandler(void);
void GetAccelerometerDataPacketHandler(void);
void GetConvolutionResultPacketHandler(void);


#endif /* COMMUNICATION_H_ */
