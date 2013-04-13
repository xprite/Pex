/** ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MK40DX256ZVLQ10
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-04-03, 22:08, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/* MODULE ProcessorExpert */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "PWMMotor.h"
#include "GPIO1.h"
#include "OdometryTimer.h"
#include "OdometryGPIO.h"
#include "CsIO1.h"
#include "IO1.h"
#include "Period.h"
#include "AD1.h"
#include "AD2.h"
#include "AS1.h"
#include "I2C2.h"
#include "GPIO2.h"
#include "GPIO3.h"
#include "CameraTimer.h"
#include "SiPin.h"
#include "ServoTimer.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "Odometry.h"
#include "Communication.h"
#include "Accelerometer.h"
#include "Camera.h"
#include "Map.h"
#include "Steering.h"

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
#include <cstdio>

/*********************************/
TCommunication Communication;
TOdometry Odometry;
TAccelerometer Accelerometer;
TCamera Camera;
TMap Map;
/********************************/




int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
  
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  
  /*Workarounds*/
  FTM0_POL |= (1<<0) | (1<<3); // New polarity 0 minimum 300 maximum
  FTM1_EXTTRIG |= FTM_EXTTRIG_CH1TRIG_MASK;
  ADC0_SC2 |= ADC_SC2_ADTRG_MASK ;
  
  ADC0_SC1A |= ADC_SC1_ADCH(0x0D); /* corresponding ADC0_RA */

  /*END workarounds*/
  
  
  /* Write your code here */
  /* For example: for(;;) { } */

 // GPIO1_SetFieldBits(GPIO1_DeviceData, EnableLeftMotor, 0x01);
 // GPIO1_SetFieldBits(GPIO1_DeviceData, EnableRightMotor, 0x01);
  
  PWMMotor_SetOffsetTicks(PWMMotor_DeviceData, 0, 1000);
  PWMMotor_SetOffsetTicks(PWMMotor_DeviceData, 1, 1000);
  
  MapInit(&Map);
  OdometryInit(&Odometry);
  CameraInit(&Camera);
  AccelerometerInit(&Accelerometer);
  AD1_SelectSampleGroup(AD1_DeviceData, 0);
  AD1_StartLoopTriggeredMeasurement(AD1_DeviceData);
 
  AS1_ReceiveBlock(AS1_DeviceData, &Communication.ReceivedPacket[0], PACKET_LENGTH);
  
  //int8_t Kernel[] = {-1,0,1};
  uint8_t minimum=0;  //TODO delete
  uint8_t maximum=0;  //TODO delete
  int32_t MaxValue = 0; //TODO delete
  uint8_t text[] = "!\n";
  
  for(;;)
  {
    
    Convolution(&Camera.ConvolutionResult[0], &Camera.readPointerToBuffer[0], PIXEL_NUM,  &Camera.Kernel[0], KERNEL_LENGTH);
    
    Convolution(&Camera.ConvolutionPatternResult[0], &Camera.readPointerToBuffer[0], PIXEL_NUM,  &Camera.FinishLinePattern[0], PATTERN_LENGTH);
    
    MaxValue = GetMaximumValue(&Camera.ConvolutionPatternResult[49], 78);
    if(MaxValue > 3800) {
      AS1_SendBlock(AS1_DeviceData, &text[0], strlen(text));
    }
    
    minimum = GetMinimumIndex(&Camera.ConvolutionResult[0], CONVOLUTIN_RESULT_LENGTH);
    maximum = GetMaximumIndex(&Camera.ConvolutionResult[0], CONVOLUTIN_RESULT_LENGTH);
    
    
    
    SetServoPosition(((minimum+maximum)/2)*20 + 3000);
    
	  if(Accelerometer.Received) {
	    Accelerometer.Received = FALSE;
      Accelerometer.X = (Accelerometer.ReceiveBuffer[0] << 8) | (Accelerometer.ReceiveBuffer[1]); 
      Accelerometer.Y = (Accelerometer.ReceiveBuffer[2] << 8) | (Accelerometer.ReceiveBuffer[3]);  
      Accelerometer.Z = (Accelerometer.ReceiveBuffer[4] << 8) | (Accelerometer.ReceiveBuffer[5]);
	  }
  }
  
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END ProcessorExpert */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
