/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : OdometryTimer.c
**     Project     : ProcessorExpert
**     Processor   : MK40DX256ZVLQ10
**     Component   : TimerUnit_LDD
**     Version     : Component 01.139, Driver 01.09, CPU db: 3.00.001
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-04-13, 22:51, # CodeGen: 106
**     Abstract    :
**          This TimerUnit component provides a low level API for unified hardware access across
**          various timer devices using the Prescaler-Counter-Compare-Capture timer structure.
**     Settings    :
**          Component name                                 : OdometryTimer
**          Module name                                    : PIT
**          Counter                                        : PIT_CVAL0
**          Counter direction                              : Down
**          Counter width                                  : 32 bits
**          Value type                                     : Optimal
**          Input clock source                             : Internal
**            Counter frequency                            : 48 MHz
**          Counter restart                                : On-match
**            Period device                                : PIT_LDVAL0
**            Period                                       : 30 ms
**            Interrupt                                    : Enabled
**              Interrupt                                  : INT_PIT0
**              Interrupt priority                         : medium priority
**          Channel list                                   : 0
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnCounterRestart                           : Enabled
**              OnChannel0                                 : Disabled
**              OnChannel1                                 : Disabled
**              OnChannel2                                 : Disabled
**              OnChannel3                                 : Disabled
**              OnChannel4                                 : Disabled
**              OnChannel5                                 : Disabled
**              OnChannel6                                 : Disabled
**              OnChannel7                                 : Disabled
**          CPU clock/configuration selection              : 
**            Clock configuration 0                        : This component enabled
**            Clock configuration 1                        : This component disabled
**            Clock configuration 2                        : This component disabled
**            Clock configuration 3                        : This component disabled
**            Clock configuration 4                        : This component disabled
**            Clock configuration 5                        : This component disabled
**            Clock configuration 6                        : This component disabled
**            Clock configuration 7                        : This component disabled
**     Contents    :
**         Init         - LDD_TDeviceData* OdometryTimer_Init(LDD_TUserData *UserDataPtr);
**         Deinit       - void OdometryTimer_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         ResetCounter - LDD_TError OdometryTimer_ResetCounter(LDD_TDeviceData *DeviceDataPtr);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE OdometryTimer. */

#include "Events.h"
#include "OdometryTimer.h"
/* {Default RTOS Adapter} No RTOS includes */
#include "IO_Map.h"


typedef struct {
  LDD_TUserData *UserDataPtr;          /* RTOS device data structure */
} OdometryTimer_TDeviceData;

typedef OdometryTimer_TDeviceData *OdometryTimer_TDeviceDataPtr; /* Pointer to the device data structure. */

/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static OdometryTimer_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;
/* {Default RTOS Adapter} Global variable used for passing a parameter into ISR */
static OdometryTimer_TDeviceDataPtr INT_PIT0__DEFAULT_RTOS_ISRPARAM;

#define AVAILABLE_EVENTS_MASK (LDD_TEventMask)(LDD_TIMERUNIT_ON_COUNTER_RESTART)

/* Internal method prototypes */
/*
** ===================================================================
**     Method      :  OdometryTimer_Init (component TimerUnit_LDD)
**
**     Description :
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc. If the
**         property <"Enable in init. code"> is set to "yes" value then
**         the device is also enabled (see the description of the
**         <Enable> method). In this case the <Enable> method is not
**         necessary and needn't to be generated. This method can be
**         called only once. Before the second call of Init the <Deinit>
**         must be called first.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     Returns     :
**         ---             - Pointer to the dynamically allocated
**                           private structure or NULL if there was an
**                           error.
** ===================================================================
*/
LDD_TDeviceData* OdometryTimer_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate device structure */
  OdometryTimer_TDeviceData *DeviceDataPrv;
  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;
  DeviceDataPrv->UserDataPtr = UserDataPtr; /* Store the RTOS device structure */
  /* Interrupt vector(s) allocation */
  /* {Default RTOS Adapter} Set interrupt vector: IVT is static, ISR parameter is passed by the global variable */
  INT_PIT0__DEFAULT_RTOS_ISRPARAM = DeviceDataPrv;
  /* SIM_SCGC6: PIT=1 */
  SIM_SCGC6 |= SIM_SCGC6_PIT_MASK;                                                   
  /* PIT_MCR: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,MDIS=0,FRZ=0 */
  PIT_MCR = 0x00U;                     /* Enable device clock */
  /* PIT_TCTRL0: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,TIE=0,TEN=0 */
  PIT_TCTRL0 = 0x00U;                  /* Clear control register */
  /* PIT_TFLG0: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,TIF=1 */
  PIT_TFLG0 = PIT_TFLG_TIF_MASK;       /* Clear timer flag register */
  /* PIT_LDVAL0: TSV=0x0015F8FF */
  PIT_LDVAL0 = PIT_LDVAL_TSV(0x0015F8FF); /* Set up load register */
  /* NVICIP68: PRI68=0x80 */
  NVICIP68 = NVIC_IP_PRI68(0x80);                                                   
  /* NVICISER2: SETENA|=0x10 */
  NVICISER2 |= NVIC_ISER_SETENA(0x10);                                                   
  /* PIT_TCTRL0: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,TIE=1,TEN=1 */
  PIT_TCTRL0 = (PIT_TCTRL_TIE_MASK | PIT_TCTRL_TEN_MASK); /* Set up control register */
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_OdometryTimer_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv); /* Return pointer to the device data structure */
}

/*
** ===================================================================
**     Method      :  OdometryTimer_Deinit (component TimerUnit_LDD)
**
**     Description :
**         Deinitializes the device. Switches off the device, frees the
**         device data structure memory, interrupts vectors, etc.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by Init method
**     Returns     : Nothing
** ===================================================================
*/
void OdometryTimer_Deinit(LDD_TDeviceData *DeviceDataPtr)
{
  OdometryTimer_TDeviceData *DeviceDataPrv = (OdometryTimer_TDeviceData *)DeviceDataPtr;

  (void)DeviceDataPrv;
  PIT_PDD_EnableDevice(PIT_BASE_PTR, PIT_PDD_CHANNEL_0, PDD_DISABLE);
  /* Interrupt vector(s) deallocation */
  /* {Default RTOS Adapter} Restore interrupt vector: IVT is static, no code is generated */
  PIT_PDD_ModuleClock(PIT_BASE_PTR, PIT_PDD_CLOCK_DISABLED);
  /* Unregistration of the device structure */
  PE_LDD_UnregisterDeviceStructure(PE_LDD_COMPONENT_OdometryTimer_ID);
  /* Deallocation of the device structure */
  /* {Default RTOS Adapter} Driver memory deallocation: Dynamic allocation is simulated, no deallocation code is generated */
}

/*
** ===================================================================
**     Method      :  OdometryTimer_ResetCounter (component TimerUnit_LDD)
**
**     Description :
**         Resets counter. If counter is counting up then it is set to
**         zero. If counter is counting down then counter is updated to
**         the reload value.
**         The method is not available if HW doesn't allow resetting of
**         the counter.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK 
**                           ERR_SPEED - The component does not work in
**                           the active clock configuration
** ===================================================================
*/
LDD_TError OdometryTimer_ResetCounter(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  /* {Default RTOS Adapter} Critical section begin, general PE function is used */
  EnterCritical();
  if ((PIT_PDD_GetEnableDeviceStatus(PIT_BASE_PTR, PIT_PDD_CHANNEL_0)) != 0U) {
    PIT_PDD_EnableDevice(PIT_BASE_PTR, PIT_PDD_CHANNEL_0, PDD_DISABLE);
    PIT_PDD_EnableDevice(PIT_BASE_PTR, PIT_PDD_CHANNEL_0, PDD_ENABLE);
  }
  /* {Default RTOS Adapter} Critical section end, general PE function is used */
  ExitCritical();
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  OdometryTimer_Interrupt (component TimerUnit_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
PE_ISR(OdometryTimer_Interrupt)
{
  /* {Default RTOS Adapter} ISR parameter is passed through the global variable */
  OdometryTimer_TDeviceDataPtr DeviceDataPrv = INT_PIT0__DEFAULT_RTOS_ISRPARAM;

  PIT_PDD_ClearInterruptFlag(PIT_BASE_PTR, PIT_PDD_CHANNEL_0); /* Clear interrupt flag */
  OdometryTimer_OnCounterRestart(DeviceDataPrv->UserDataPtr); /* Invoke OnCounterRestart event */
}

/* END OdometryTimer. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
