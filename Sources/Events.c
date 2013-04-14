/** ###################################################################
**     Filename    : Events.c
**     Project     : ProcessorExpert
**     Processor   : MK40DX256ZVLQ10
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-04-03, 22:08, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Cpu_OnNMIINT - void Cpu_OnNMIINT(void);
**
** ###################################################################*/
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"

#include "Controller.h"
#include "Odometry.h"
#include "Accelerometer.h"
#include "Communication.h"
#include "Camera.h"
#include "Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */


extern TController Controller;
extern TCamera Camera;
extern TOdometry Odometry;
extern TCommunication Communication;
extern TAccelerometer Accelerometer;
extern TMap Map;

/*
** ===================================================================
**     Event       :  OdometryTimer_OnCounterRestart (module Events)
**
**     Component   :  OdometryTimer [TimerUnit_LDD]
**     Description :
**         Called if counter overflow/underflow or counter is
**         reinitialized by modulo or compare register matching.
**         OnCounterRestart event and Timer unit must be enabled. See
**         <SetEventMask> and <GetEventMask> methods. This event is
**         available only if a <Interrupt> is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer passed as
**                           the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void OdometryTimer_OnCounterRestart(LDD_TUserData *UserDataPtr)
{
  Odometry.Speed = Odometry.SpeedCounter;
  Controller.RealValue = Odometry.Speed;
  ControllerMain(&Controller);
  Odometry.SpeedCounter = 0;  
}

/*
** ===================================================================
**     Event       :  PWMMotor_OnCounterRestart (module Events)
**
**     Component   :  PWMMotor [TimerUnit_LDD]
**     Description :
**         Called if counter overflow/underflow or counter is
**         reinitialized by modulo or compare register matching.
**         OnCounterRestart event and Timer unit must be enabled. See
**         <SetEventMask> and <GetEventMask> methods. This event is
**         available only if a <Interrupt> is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer passed as
**                           the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void PWMMotor_OnCounterRestart(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  OdometryGPIO_OnPortEvent (module Events)
**
**     Component   :  OdometryGPIO [GPIO_LDD]
**     Description :
**         Called if defined event on any pin of the port occured.
**         OnPortEvent event and GPIO interrupt must be enabled. See
**         SetPortEventMask() and GetPortEventMask() methods. This
**         event is enabled if <Interrupt service/event> is Enabled and
**         disabled if <Interrupt service/event> is Disabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to RTOS device
**                           data structure pointer.
**     Returns     : Nothing
** ===================================================================
*/
void OdometryGPIO_OnPortEvent(LDD_TUserData *UserDataPtr)
{
  MapMain(&Map, &Odometry, &Accelerometer);
  Odometry.SpeedCounter++;
  Odometry.TotalDistance++;
}

/*
** ===================================================================
**     Event       :  Period_OnCounterRestart (module Events)
**
**     Component   :  Period [TimerUnit_LDD]
**     Description :
**         Called if counter overflow/underflow or counter is
**         reinitialized by modulo or compare register matching.
**         OnCounterRestart event and Timer unit must be enabled. See
**         <SetEventMask> and <GetEventMask> methods. This event is
**         available only if a <Interrupt> is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer passed as
**                           the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void Period_OnCounterRestart(LDD_TUserData *UserDataPtr)
{

}


/*
** ===================================================================
**     Event       :  AS1_OnBlockReceived (module Events)
**
**     Component   :  AS1 [Serial_LDD]
**     Description :
**         This event is called when the requested number of data is
**         moved to the input buffer.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void AS1_OnBlockReceived(LDD_TUserData *UserDataPtr)
{
  CommunicationHandler(&Communication);
  AS1_ReceiveBlock(AS1_DeviceData, &Communication.ReceivedPacket[0], PACKET_LENGTH);
//  AS1_ReceiveBlock(AS1_DeviceData, &Communication.ReceivedPacket[0], PACKET_LENGTH);
}

/*
** ===================================================================
**     Event       :  AS1_OnBlockSent (module Events)
**
**     Component   :  AS1 [Serial_LDD]
**     Description :
**         This event is called after the last character from the
**         output buffer is moved to the transmitter. 
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/    
void AS1_OnBlockSent(LDD_TUserData *UserDataPtr)
{
  
}

/*
** ===================================================================
**     Event       :  I2C2_OnMasterBlockSent (module Events)
**
**     Component   :  I2C2 [I2C_LDD]
**     Description :
**         This event is called when I2C in master mode finishes the
**         transmission of the data successfully. This event is not
**         available for the SLAVE mode and if MasterSendBlock is
**         disabled. 
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void I2C2_OnMasterBlockSent(LDD_TUserData *UserDataPtr)
{
  Accelerometer.Sent = TRUE;
}

/*
** ===================================================================
**     Event       :  I2C2_OnMasterBlockReceived (module Events)
**
**     Component   :  I2C2 [I2C_LDD]
**     Description :
**         This event is called when I2C is in master mode and finishes
**         the reception of the data successfully. This event is not
**         available for the SLAVE mode and if MasterReceiveBlock is
**         disabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void I2C2_OnMasterBlockReceived(LDD_TUserData *UserDataPtr)
{
  Accelerometer.Received = TRUE;
}

/*
** ===================================================================
**     Event       :  I2C2_OnError (module Events)
**
**     Component   :  I2C2 [I2C_LDD]
**     Description :
**         This event is called when an error (e.g. Arbitration lost)
**         occurs. The errors can be read with GetError method.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer is passed
**                           as the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void I2C2_OnError(LDD_TUserData *UserDataPtr)
{
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  GPIO3_OnPortEvent (module Events)
**
**     Component   :  GPIO3 [GPIO_LDD]
**     Description :
**         Called if defined event on any pin of the port occured.
**         OnPortEvent event and GPIO interrupt must be enabled. See
**         SetPortEventMask() and GetPortEventMask() methods. This
**         event is enabled if <Interrupt service/event> is Enabled and
**         disabled if <Interrupt service/event> is Disabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to RTOS device
**                           data structure pointer.
**     Returns     : Nothing
** ===================================================================
*/
void GPIO3_OnPortEvent(LDD_TUserData *UserDataPtr)
{
  Accelerometer.TransmitBuffer[0] = 0x01;
  Accelerometer.Sent = FALSE;
  Accelerometer.Error = I2C2_MasterSendBlock(I2C2_DeviceData, &Accelerometer.TransmitBuffer[0], 0x01U, LDD_I2C_NO_SEND_STOP);
  while(!Accelerometer.Sent);
  
  Accelerometer.Received = FALSE;
  Accelerometer.Error = I2C2_MasterReceiveBlock(I2C2_DeviceData, &Accelerometer.ReceiveBuffer[0], 0x06U, LDD_I2C_SEND_STOP);

}

/*
** ===================================================================
**     Event       :  CameraTimer_OnCounterRestart (module Events)
**
**     Component   :  CameraTimer [TimerUnit_LDD]
**     Description :
**         Called if counter overflow/underflow or counter is
**         reinitialized by modulo or compare register matching.
**         OnCounterRestart event and Timer unit must be enabled. See
**         <SetEventMask> and <GetEventMask> methods. This event is
**         available only if a <Interrupt> is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer passed as
**                           the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void CameraTimer_OnCounterRestart(LDD_TUserData *UserDataPtr)
{
	  if(Camera.pixelClockCounter == ( PIXEL_NUM + Camera.clockExposureOffset-1)) {
	    SiPin_SetFieldBits(SiPin_DeviceData, Si, 0x01U);
	  }
}

/*
** ===================================================================
**     Event       :  CameraTimer_OnChannel0 (module Events)
**
**     Component   :  CameraTimer [TimerUnit_LDD]
**     Description :
**         Called if compare register match the counter registers or
**         capture register has a new content. OnChannel0 event and
**         Timer unit must be enabled. See <SetEventMask> and
**         <GetEventMask> methods. This event is available only if a
**         <Interrupt> is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer passed as
**                           the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void CameraTimer_OnChannel0(LDD_TUserData *UserDataPtr)
{
  Camera.pixelClockCounter++;
  Camera.pixelClockCounter %= (PIXEL_NUM + Camera.clockExposureOffset);

  //AD1_StartSingleMeasurement(AD1_DeviceData);
}
/*
** ===================================================================
**     Event       :  AD1_OnMeasurementComplete (module Events)
**
**     Component   :  AD1 [ADC_LDD]
**     Description :
**         Called after measurement is done, <Interrupt service/event>
**         is enabled, OnMeasurementComplete event is enabled and ADC
**         device is enabled. See <SetEventMask()> method or <Event
**         mask> property group to enable this event and <Enable>
**         method or <Enabled in init. code> property to enable ADC
**         device.  
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer is passed
**                           as the parameter of Init method. 
**     Returns     : Nothing
** ===================================================================
*/
void AD1_OnMeasurementComplete(LDD_TUserData *UserDataPtr)
{
  if(Camera.pixelClockCounter < PIXEL_NUM) {
    AD1_GetMeasuredValues(AD1_DeviceData, &Camera.writePointerToBuffer[Camera.pixelClockCounter]);
    if(Camera.pixelClockCounter == 127) {
      if(Camera.writePointerToBuffer == Camera.cameraRawData0) {
        Camera.writePointerToBuffer = Camera.cameraRawData1;
        Camera.readPointerToBuffer = Camera.cameraRawData0;
      }
      else if(Camera.writePointerToBuffer == Camera.cameraRawData1) {
        Camera.writePointerToBuffer = Camera.cameraRawData0;
        Camera.readPointerToBuffer = Camera.cameraRawData1;
      }
    }
    
  }
}

/*
** ===================================================================
**     Event       :  CameraTimer_OnChannel1 (module Events)
**
**     Component   :  CameraTimer [TimerUnit_LDD]
**     Description :
**         Called if compare register match the counter registers or
**         capture register has a new content. OnChannel1 event and
**         Timer unit must be enabled. See <SetEventMask> and
**         <GetEventMask> methods. This event is available only if a
**         <Interrupt> is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. The pointer passed as
**                           the parameter of Init method.
**     Returns     : Nothing
** ===================================================================
*/
void CameraTimer_OnChannel1(LDD_TUserData *UserDataPtr)
{
  SiPin_ClearFieldBits(SiPin_DeviceData, Si, 0x01U);
}

/*
** ===================================================================
**     Event       :  Cpu_OnNMIINT0 (module Events)
**
**     Component   :  Cpu [MK40N512LQ100]
**     Description :
**         This event is called when the Non maskable interrupt had
**         occurred. This event is automatically enabled when the <NMI
**         interrrupt> property is set to 'Enabled'.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Cpu_OnNMIINT0(void)
{
  /* Write your code here ... */
}

/* END Events */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
