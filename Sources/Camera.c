/*
 * Common.c
 *
 *  Created on: Mar 13, 2013
 *      Author: z
 */

#include "Camera.h"

void CameraInit(TCamera* aCamera)
{
  int i=0;	
  aCamera->clockExposureOffset = DEFAULT_EXPOSURE_OFFSET;
  aCamera->pixelClockCounter = 0;
  aCamera->readPointerToBuffer = aCamera->cameraRawData0;
  aCamera->writePointerToBuffer = aCamera->cameraRawData0;
  memset(&aCamera->cameraRawData0[0], PIXEL_NUM + ((KERNEL_LENGTH/2)*4), 0);
  memset(&aCamera->cameraRawData1[0], PIXEL_NUM + ((KERNEL_LENGTH/2)*4), 0);

#if 0 
  aCamera->Kernel[0] = 1;
  aCamera->Kernel[1] = 1;
  aCamera->Kernel[2] = 1;
  aCamera->Kernel[3] = 1;
  aCamera->Kernel[4] =  0;
  aCamera->Kernel[5] =  -1;
  aCamera->Kernel[6] =  -1;
  aCamera->Kernel[7] =  -1;
  aCamera->Kernel[8] =  -1;
#endif
  
// fill the pattern  
  for(i=0 ; i<50 ; i++)
  {
    switch(i/10)
    {
    case 0:
      aCamera->FinishLinePattern[i] = -2;
      break;
    case 1:
      aCamera->FinishLinePattern[i] = 3;
      break;
    case 2:
      aCamera->FinishLinePattern[i] = -2;
      break;
    case 3:
      aCamera->FinishLinePattern[i] = 3;
      break;
    case 4:
      aCamera->FinishLinePattern[i] = -2;
      break;
    }
  }
  
  aCamera->Kernel[0] =  1;
  aCamera->Kernel[1] =  0;
  aCamera->Kernel[2] = -1;
  
  
}

void Convolution(int32_t* OutputData, uint8_t* InputData, uint8_t DataLength, int32_t* Kernel, uint8_t KernelLength)
{
  int i;
  int j;
  int32_t Temp[PIXEL_NUM + PATTERN_LENGTH - 1];

  for(i=0 ; i<DataLength+KernelLength - 1 ; i++)
  {
    Temp[i] = 0;
    for(j=0 ; j<KernelLength ; j++)
    {
      if((i-j)>=0) {  // TODO , check - modified condition from < to <=
        Temp[i] += (int32_t) (InputData[i-j] * Kernel[j]);  //TODO - Optimize by CMSIS Convolution library
      }
    } 
  OutputData[i] = (int32_t) Temp[i];
  }
}

uint8_t GetMinimumIndex(int32_t* InputVector, uint8_t VectorLength)
{
  int i;
  uint8_t Minimum = 0;
  for(i=0 ; i< VectorLength ; i++)
  {
    if(InputVector[Minimum] > InputVector[i]) {
      Minimum=i;
    }
  }
  return Minimum;
}

uint8_t GetMaximumIndex(int32_t* InputVector, uint8_t VectorLength)
{
  int i;
  uint8_t Maximum = 0;
  for(i=0 ; i<VectorLength ; i++)
  {
    if(InputVector[Maximum] < InputVector[i])
    {
      Maximum=i;
    }
  }
  return Maximum;  
}

int32_t GetMaximumValue(int32_t* InputVector, uint8_t VectorLength)
{
  int i;
  int32_t Maximum = InputVector[0];
  for(i=0 ; i<VectorLength ; i++)
  {
    if(Maximum < InputVector[i])
    {
      Maximum = InputVector[i];
    }
  }
  return Maximum;
}
