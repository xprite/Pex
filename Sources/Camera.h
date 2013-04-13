/*
 * Common.h
 *
 *  Created on: Mar 13, 2013
 *      Author: z
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <stdint.h>
#include <cstring>

#define PATTERN_LENGTH 50
#define PIXEL_NUM 128
#define KERNEL_LENGTH 3
#define CONVOLUTIN_RESULT_LENGTH (PIXEL_NUM+KERNEL_LENGTH-1)
#define DEFAULT_EXPOSURE_OFFSET 100

typedef struct{
  int32_t FinishLinePattern[PATTERN_LENGTH];
  int32_t ConvolutionPatternResult[PIXEL_NUM+PATTERN_LENGTH-1];
  uint32_t clockExposureOffset;
  uint8_t *writePointerToBuffer;
  uint8_t *readPointerToBuffer;
	uint8_t cameraRawData0[PIXEL_NUM + ((KERNEL_LENGTH/2)*4)];
	uint8_t cameraRawData1[PIXEL_NUM + ((KERNEL_LENGTH/2)*4)];
  uint32_t pixelClockCounter;
  int32_t ConvolutionResult[PIXEL_NUM + KERNEL_LENGTH -1];
  int32_t Kernel[KERNEL_LENGTH];  
} TCamera;



uint8_t GetMaximumIndex(int32_t* InputVector, uint8_t VectorLength);  // Gets index of maximum vector element
uint8_t GetMinimumIndex(int32_t* InputVector, uint8_t VectorLength);  // Gets index of minimum vector element
int32_t GetMaximumValue(int32_t* InputVector, uint8_t VectorLength);
void CameraInit(TCamera* Camera);
void Convolution(int32_t* OutputData, uint8_t* InputData, uint8_t DataLength, int32_t* Kernel, uint8_t KernelLength);

#endif /* COMMON_H_ */
