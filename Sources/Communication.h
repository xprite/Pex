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
#include <stdlib.h>
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

uint16_t GetNumberFromCommandBuffer(TCommunication* CommunicationStruct, uint8_t StartIndex, uint8_t Length);
uint8_t GetMatchCharNum(uint8_t* PacketPattern);
uint8_t GetParameterLength(uint8_t* PacketPattern);




void CommunicationHandler(TCommunication* CommunicationStruct);

void GetConvolutionResultStringPacketHandler(void);
void GetOdometryTotalDistancePacketHandler(void);
void GetCameraDataPacketHandler(void);
void GetAccelerometerDataPacketHandler(void);
void GetConvolutionResultPacketHandler(void);
void SetBothMotorSpeedCommandHandler(uint8_t* PacketPattern);

//Steering
void SetServoCenterCommandHandler(uint8_t* PacketPattern);
void GetSteeringControllerConstantsCommandHandler(uint8_t* PacketPattern);
void IncrementSteeringKpCommandHandler(uint8_t* PacketPattern);
void IncrementSteeringKiCommandHandler(uint8_t* PacketPattern);
void IncrementSteeringKdCommandHandler(uint8_t* PacketPattern);
void IncrementSteeringWindupCommandHandler(uint8_t* PacketPattern);

void DecrementSteeringKpCommandHandler(uint8_t* PacketPattern);
void DecrementSteeringKiCommandHandler(uint8_t* PacketPattern);
void DecrementSteeringKdCommandHandler(uint8_t* PacketPattern);
void DecrementSteeringWindupCommandHandler(uint8_t* PacketPattern);







//Controller
void SetControllerKpCommandHandler(uint8_t* PacketPattern);
void SetControllerKiCommandHandler(uint8_t* PacketPattern);
void SetControllerKdCommandHandler(uint8_t* PacketPattern);
void SetControllerDesiredSpeedCommandHandler(uint8_t* PacketPattern);
void SetAntiWindupLevelCommandHandler(uint8_t* PacketPattern);





#endif /* COMMUNICATION_H_ */
