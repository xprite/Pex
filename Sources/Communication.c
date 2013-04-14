/*
 * Communication.c
 *
 *  Created on: Mar 16, 2013
 *      Author: z
 */

#include "Controller.h"
#include "Communication.h"
#include "AS1.h"
#include "Accelerometer.h"
#include "Camera.h"
#include "Odometry.h"
#include "Steering.h"
#include "PE_Types.h"

extern TController Controller;
extern TOdometry Odometry;
extern TCamera Camera;
extern TAccelerometer Accelerometer;
extern TCommunication Communication;
extern TSteering Steering;

/*
 * Commands from old project
 * */

/* Read Requests */
uint8_t GetLinePositionPacket[]   = "?L00000000";   // Request the vehicle for Line Position.
uint8_t GetCamera1ImagePacket[]   = "?C10000000";   // Request camera1 Live Image.
uint8_t GetCamera2ImagePacket[]   = "?C20000000";   // Request Camera2 Live Image.
uint8_t GetCamerasImagePacket[]   = "?CA0000000";   // Request Both Camera Images.
uint8_t GetServoPositionPacket[]  = "?SP0000000";   // Request Servo Position.
uint8_t GetAllDataPacket[]      = "?ALLDATA00";
uint8_t GetAccelerationPacket[] = "?ACCDATA00";

/* Write Requests */
uint8_t SetRightMotorSpeedPacket[]  = "!MRXXX0000"; // Set the Left Motor speed to 3 digit value following the M character(is the value).  
uint8_t SetLeftMotorSpeedPacket[] = "!MLXXX0000"; // Set the Left Motor speed to 3 digit value following the M character(is the value).
uint8_t SetBothMotorSpeedPacket[]   = "!DCSSXXXXX";
uint8_t SetDesiredSpeedPacket[]   = "!RDCVXXX00"; //set regulator desired value
uint8_t SetRegulatorRecoverPacket[] = "!RCVR00000"; //recover suspended regulator and re-enable motors
uint8_t DecrementServoCenterPacket[] = "!DECSERVOC";
uint8_t IncrementServoCenterPacket[] = "!INCSERVOC";

// Speed Controller Packets
uint8_t SetControllerKpPacket[] = "!SETKPXXXX";
uint8_t SetControllerKiPacket[] = "!SETKIXXXX";
uint8_t SetControllerKdPacket[] = "!SETKDXXXX";
uint8_t SetControllerDesiredSpeedPacket[] = "!SSPEEDXXX";
uint8_t SetAntiWindupLevelPacket[] = "!SAWINXXXX";


uint8_t SetServoSensitivityPacket[] = "!SSSXX0000";
uint8_t SetServoPositionPacket[]  = "!SSXXXX000"; // Set Servo to Position.
uint8_t EnableRightDCMotorPacket[]  = "!EDCMOTORR"; // Enable Right DC Motor.
uint8_t DisableRightDCMotorPacket[] = "!DDCMOTORR"; // Enable Right DC Motor.
uint8_t EnableLeftDCMotorPacket[] = "!EDCMOTORL"; // Enable Left DC Motor.
uint8_t DisableLeftDCMotorPacket[]  = "!DDCMOTORL"; // Enable Left DC Motor.
uint8_t DisableBothDCMotorsPacket[] = "!DBDCM0000"; // Disable Both DC Motors.
uint8_t ClearDistanceCounterPacket[]= "!CLRDST000"; // Clear Distance
uint8_t SetServoCenterPacket[]    = "!SSCXXXX00"; // Set Servo Center.
uint8_t SetServoMaxLeftPacket[]   = "!SSMLXXXX0"; // Set Servo Max Left Value.
uint8_t SetServoMaxRightPacket[]  = "!SSMRXXXX0"; // Set Servo Max Right Value.
uint8_t GetMinMaxLine[]       = "!GMML00000"; // Get line Min and Max Value.

uint8_t GetCameraDataPacket[PACKET_LENGTH] = "gcameraimg";
uint8_t GetAccelerometerDataPacket[PACKET_LENGTH] = "gacceldata";
uint8_t GetOdometryTotalDistancePacket[PACKET_LENGTH] = "gtdistance";
uint8_t GetConvolutionResultPacket[PACKET_LENGTH] = "gconvolres";



uint16_t GetNumberFromCommandBuffer(TCommunication* CommunicationStruct, uint8_t StartIndex, uint8_t Length)
{
  int i;
  char DynamicArray[10];
  for(i=0 ; i<Length ; i++)
  {
    DynamicArray[i] = CommunicationStruct->ReceivedPacket[i+StartIndex];
  }
  DynamicArray[Length] = '\0';
  
  return atoi(DynamicArray);
}

uint8_t GetMatchCharNum(uint8_t* PacketPattern)
{
  uint8_t i;
  for(i=0 ; i<PACKET_LENGTH ; i++)
  {
    if((PacketPattern[i] == 'X')  || (i>=9))
      break;
  }
  return i;
}

uint8_t GetParameterLength(uint8_t* PacketPattern)
{
  uint8_t i;
  uint8_t ParameterLength = 0;
  for(i=0 ; i<PACKET_LENGTH ; i++)
  {
    if(PacketPattern[i] == 'X') ParameterLength++;
  }
  return ParameterLength;
}


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
  
  compare = memcmp(CommunicationStruct->ReceivedPacket, SetBothMotorSpeedPacket, GetMatchCharNum(SetBothMotorSpeedPacket));
  if(compare == 0)
  {
    SetBothMotorSpeedCommandHandler(SetBothMotorSpeedPacket);
  }
  
  compare = memcmp(CommunicationStruct->ReceivedPacket, SetServoCenterPacket, GetMatchCharNum(SetServoCenterPacket));
  if(compare == 0)
  {
    SetServoCenterCommandHandler(SetServoCenterPacket);
  }

  // Controller Kp
  compare = memcmp(CommunicationStruct->ReceivedPacket, SetControllerKpPacket, GetMatchCharNum(SetControllerKpPacket));
  if(compare == 0)
  {
    SetControllerKpCommandHandler(SetControllerKpPacket);
  }
  
  //Controller Ki
  compare = memcmp(CommunicationStruct->ReceivedPacket, SetControllerKiPacket, GetMatchCharNum(SetControllerKiPacket));
  if(compare == 0)
  {
    SetControllerKiCommandHandler(SetControllerKiPacket);
  }
  
  //Controller Kd
  compare = memcmp(CommunicationStruct->ReceivedPacket, SetControllerKdPacket, GetMatchCharNum(SetControllerKdPacket));
  if(compare == 0)
  {
    SetControllerKdCommandHandler(SetControllerKdPacket);
  }
  
  //Controller   
  
  compare = memcmp(CommunicationStruct->ReceivedPacket, SetControllerDesiredSpeedPacket, GetMatchCharNum(SetControllerDesiredSpeedPacket));
  if(compare == 0)
  {
    SetControllerDesiredSpeedCommandHandler(SetControllerDesiredSpeedPacket);
  }
  
  compare = memcmp(CommunicationStruct->ReceivedPacket, SetAntiWindupLevelPacket, GetMatchCharNum(SetAntiWindupLevelPacket));
  if(compare == 0)
  {
    SetAntiWindupLevelCommandHandler(SetAntiWindupLevelPacket);
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

void SetBothMotorSpeedCommandHandler(uint8_t* PacketPattern)
{

}

void SetServoCenterCommandHandler(uint8_t* PacketPattern)
{
  Steering.ServoCenter = GetNumberFromCommandBuffer(&Communication, GetMatchCharNum(PacketPattern), GetParameterLength(PacketPattern));  
}

void IncrementServoCenterCommandHandler(uint8_t* PacketPattern)
{
  Steering.ServoCenter += SERVO_INCREMENT;  
}

void DecrementServoCenterCommandHandler(uint8_t* PacketPattern)
{
  Steering.ServoCenter -= SERVO_INCREMENT;  
}

// Set Kp constant of controller
void SetControllerKpCommandHandler(uint8_t* PacketPattern)
{
  Controller.Kp = GetNumberFromCommandBuffer(&Communication, GetMatchCharNum(PacketPattern), GetParameterLength(PacketPattern));
}

// Set Ki constant of controller
void SetControllerKiCommandHandler(uint8_t* PacketPattern)
{
  Controller.Ki = GetNumberFromCommandBuffer(&Communication, GetMatchCharNum(PacketPattern), GetParameterLength(PacketPattern));
}

// Set Kd constant of controller
void SetControllerKdCommandHandler(uint8_t* PacketPattern)
{
  Controller.Kd = GetNumberFromCommandBuffer(&Communication, GetMatchCharNum(PacketPattern), GetParameterLength(PacketPattern));
}

// Set desired value of speed controller
void SetControllerDesiredSpeedCommandHandler(uint8_t* PacketPattern)
{
  Controller.DesiredValue = GetNumberFromCommandBuffer(&Communication, GetMatchCharNum(PacketPattern), GetParameterLength(PacketPattern));
}

// Set antiwindup level
void SetAntiWindupLevelCommandHandler(uint8_t* PacketPattern)
{
  Controller.AntiWindup = GetNumberFromCommandBuffer(&Communication, GetMatchCharNum(PacketPattern), GetParameterLength(PacketPattern));
}



