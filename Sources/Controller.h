/*
 * Controller.h
 *
 *  Created on: Apr 13, 2013
 *      Author: z
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "PE_Types.h"

#define FLOAT_SUPPORT FALSE

#define KP 0.005
#define KI 0.12
#define KD 0.0001

#define ANTI_WINDUP 500

typedef struct Controller{
#if FLOAT_SUPPORT
  float Kp; //proportional
  float Ki; //integration
  float Kd; //derivation
  
  float AntiWindup;
  
  float lastError;
  float Integrator;
  float Error;  // DesiredValue - RealValue;
  float RealValue;  // Real value from feedback
  float DesiredValue; // Desired value
  float Output; // Output value written to HW register, conversion to integer type needed

#else
  int32_t Kp; //proportional
  int32_t Ki; //integration
  int32_t Kd; //derivation
  
  int32_t AntiWindup;
  
  int32_t lastError;
  
  int32_t Integrator;
  int32_t Error;  // DesiredValue - RealValue;
  int32_t RealValue;  // Real value from feedback
  int32_t DesiredValue; // Desired value
  int32_t Output; // Output value written to HW register, conversion to integer type needed
#endif  
  
}TController;

void ControllerInit(TController* aController);
void ControllerMain(TController* aController);

#endif /* CONTROLLER_H_ */
