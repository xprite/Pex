/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : AD2.c
**     Project     : ProcessorExpert
**     Processor   : MK40DX256ZVLQ10
**     Component   : ADC_LDD
**     Version     : Component 01.115, Driver 01.07, CPU db: 3.00.001
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-04-11, 15:40, # CodeGen: 91
**     Abstract    :
**         This device "ADC_LDD" implements an A/D converter,
**         its control methods and interrupt/event handling procedure.
**     Settings    :
**          Component name                                 : AD2
**          A/D converter                                  : ADC1
**          Discontinuous mode                             : no
**          Converter mode                                 : Sequential
**          Interrupt service/event                        : Disabled
**          A/D channel list                               : 1
**            Channel 0                                    : 
**              Channel mode                               : Single Ended
**                Input                                    : 
**                  A/D channel (pin)                      : PTB4/FTM1_FLT0/LCD_P4/ADC1_SE10
**                  A/D channel (pin) signal               : 
**          Static sample groups                           : Disabled
**          A/D resolution                                 : Autoselect
**          Low-power mode                                 : Disabled
**          High-speed conversion mode                     : Disabled
**          Asynchro clock output                          : Disabled
**          Sample time                                    : 4 clock periods
**          Number of conversions                          : 1
**          Conversion time                                : 6.25 �s
**          ADC clock                                      : 4 MHz (250 ns)
**          Single conversion time - Single-ended          : 7.604 us
**          Single conversion time - Differential          : 9.854 us
**          Additional conversion time - Single-ended      : 6.25 us
**          Additional conversion time - Differential      : 8.5 us
**          Result type                                    : unsigned 16 bits, right justified
**          Trigger                                        : Disabled
**          Voltage reference                              : 
**            High voltage reference                       : 
**              Volt. ref. pin                             : VREFH
**              Volt. ref pin signal                       : 
**            Low voltage reference                        : 
**              Volt. ref. pin                             : VREFL
**              Volt. ref pin signal                       : 
**          Initialization                                 : 
**            Enabled in init. code                        : yes
**            Auto initialization                          : no
**            Event mask                                   : 
**              OnMeasurementComplete                      : Disabled
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
**         Init                   - LDD_TDeviceData* AD2_Init(LDD_TUserData *UserDataPtr);
**         Deinit                 - void AD2_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         StartSingleMeasurement - LDD_TError AD2_StartSingleMeasurement(LDD_TDeviceData *DeviceDataPtr);
**         CreateSampleGroup      - LDD_TError AD2_CreateSampleGroup(LDD_TDeviceData *DeviceDataPtr,...
**         GetMeasuredValues      - LDD_TError AD2_GetMeasuredValues(LDD_TDeviceData *DeviceDataPtr, LDD_TData...
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE AD2. */

#include "AD2.h"
/* {Default RTOS Adapter} No RTOS includes */

#define AD2_AVAILABLE_CHANNEL0_31_PIN_MASK (LDD_ADC_CHANNEL_0_PIN) /* Mask of all allocated channel pins from 0 to 31 */
#define AD2_AVAILABLE_CHANNEL32_63_PIN_MASK 0x00U /* Mask of all allocated channel pins from 32 to 63 */
#define AD2_AVAILABLE_TRIGGER_PIN_MASK 0x00U /* Mask of all allocated trigger pins */
#define AD2_AVAILABLE_VOLT_REF_PIN_MASK (LDD_ADC_LOW_VOLT_REF_PIN | LDD_ADC_HIGH_VOLT_REF_PIN) /* Mask of all allocated voltage reference pins */

static const uint8_t ChannelToPin[] = { /* Channel to pin conversion table */
  /* ADC1_SC1A: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,COCO=0,AIEN=0,DIFF=0,ADCH=0x0A */
  0x0AU                                /* Status and control register value */
};

typedef struct {
  uint8_t SampleCount;                 /* Number of samples in the last selected/created sample group */
  uint8_t FirstSample;                 /* First sample of group store */
  LDD_TUserData *UserData;             /* RTOS device data structure */
} AD2_TDeviceData;                     /* Device data structure type */

typedef AD2_TDeviceData* AD2_TDeviceDataPtr ; /* Pointer to the device data structure. */

/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static AD2_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;
/*
** ===================================================================
**     Method      :  AD2_Init (component ADC_LDD)
**
**     Description :
**         Initializes the device. Allocates memory for the device data
**         structure, allocates interrupt vectors and sets interrupt
**         priority, sets pin routing, sets timing, etc.
**         If the "Enable in init. code" is set to "yes" value then the
**         device is also enabled(see the description of the Enable()
**         method). In this case the Enable() method is not necessary
**         and needn't to be generated. 
**         This method can be called only once. Before the second call
**         of Init() the Deinit() must be called first.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the user or
**                           RTOS specific data. This pointer will be
**                           passed as an event or callback parameter.
**     Returns     :
**         ---             - Device data structure pointer.
** ===================================================================
*/
LDD_TDeviceData* AD2_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate LDD device structure */
  AD2_TDeviceDataPtr DeviceDataPrv;

  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;
  DeviceDataPrv->UserData = UserDataPtr; /* Store the RTOS device structure */
  DeviceDataPrv->SampleCount = 0U;     /* Initializing SampleCount for right access of some methods to SC1n registers before first conversion is done */
  /* SIM_SCGC3: ADC1=1 */
  SIM_SCGC3 |= SIM_SCGC3_ADC1_MASK;                                                   
  /* PORTB_PCR4: ISF=0,MUX=0 */
  PORTB_PCR4 &= (uint32_t)~(uint32_t)((PORT_PCR_ISF_MASK | PORT_PCR_MUX(0x07)));                                                   
  /* ADC1_CFG1: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,ADLPC=0,ADIV=0,ADLSMP=0,MODE=3,ADICLK=2 */
  ADC1_CFG1 = (ADC_CFG1_MODE(0x03) | ADC_CFG1_ADICLK(0x02));                                                   
  /* ADC1_CFG2: ADACKEN=0,ADHSC=0,ADLSTS=0 */
  ADC1_CFG2 &= (uint32_t)~(uint32_t)(
                ADC_CFG2_ADACKEN_MASK |
                ADC_CFG2_ADHSC_MASK |
                ADC_CFG2_ADLSTS(0x03)
               );                                                   
  /* ADC1_SC2: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,ADACT=0,ADTRG=0,ACFE=0,ACFGT=0,ACREN=0,DMAEN=0,REFSEL=0 */
  ADC1_SC2 = 0x00U;                                                   
  /* ADC1_SC3: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CAL=0,CALF=1,??=0,??=0,ADCO=0,AVGE=0,AVGS=0 */
  ADC1_SC3 = ADC_SC3_CALF_MASK;                                                   
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_AD2_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv); /* Return pointer to the data data structure */
}

/*
** ===================================================================
**     Method      :  AD2_Deinit (component ADC_LDD)
**
**     Description :
**         Deinitializes the device. Switches off the device, frees the
**         device data structure memory, interrupts vectors, etc.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     : Nothing
** ===================================================================
*/
void AD2_Deinit(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  /* ADC1_SC1A: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,COCO=0,AIEN=0,DIFF=0,ADCH=0x1F */
  ADC1_SC1A = ADC_SC1_ADCH(0x1F);                                                   
  /* Unregistration of the device structure */
  PE_LDD_UnregisterDeviceStructure(PE_LDD_COMPONENT_AD2_ID);
  /* Deallocation of the device structure */
  /* {Default RTOS Adapter} Driver memory deallocation: Dynamic allocation is simulated, no deallocation code is generated */
  /* SIM_SCGC3: ADC1=0 */
  SIM_SCGC3 &= (uint32_t)~(uint32_t)(SIM_SCGC3_ADC1_MASK);                                                   
}

/*
** ===================================================================
**     Method      :  AD2_StartSingleMeasurement (component ADC_LDD)
**
**     Description :
**         This method starts one measurement of the selected group of
**         samples and exits immediately. The group of samples for
**         measurement is specified by preceding call to
**         <SelectSampleGroup()> or <SelectSampleGroup()> method. The
**         <OnMeasurementComplete() > event is invoked after the
**         measurement is done and the event is enabled. The state of
**         the measurement can be also polled by the
**         <GetMeasurementCompleteStatus()> method. Results of the
**         measurement can be read by the <GetMeasuredValues()> method.
**         The <Discontinuous mode> doesn't support this method.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The device doesn't work in the
**                           active clock configuration
**                           ERR_DISABLED - Component is disabled
**                           ERR_BUSY - A measurement is in progress 
** ===================================================================
*/
LDD_TError AD2_StartSingleMeasurement(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  if ((ADC_PDD_GetConversionActiveFlag(ADC1_BASE_PTR) != 0U)) { /* Last measurement still pending? */
    return ERR_BUSY;                   /* Yes, return ERR_BUSY */
  }
  ADC_PDD_SetContinuousMode(ADC1_BASE_PTR, ADC_PDD_ONE_CONVERSION); /* Set one conversion mode */
  ADC_PDD_SetConversionTriggerType(ADC1_BASE_PTR, ADC_PDD_SW_TRIGGER); /* Select SW triggering */
  ADC_PDD_WriteStatusControl1Reg(ADC1_BASE_PTR, 0U, ((AD2_TDeviceDataPtr)DeviceDataPtr)->FirstSample); /* Set sample 0 and start conversion */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  AD2_CreateSampleGroup (component ADC_LDD)
**
**     Description :
**         This method prepares HW for next measurement according to
**         array of samples defined during run-time. The array of
**         samples should be prepared prior to calling this method.
**         Pointer to the array is passed into this method in parameter
**         SampleGroupPtr. The number of samples is defined by
**         parameter SampleCount. Once any group is prepared, the
**         measurement can be started multiple times. Note: This method
**         works only with the sample groups defined during run-time.
**         For design-time defined groups use <SelectSampleGroup()>
**         method.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**       * SampleGroupPtr  - Pointer to the
**                           sample definition array. This array can be
**                           released as soon as the method ends.
**         SampleCount     - Number of items in the
**                           sample definition array. Must be less than
**                           or equal to
**                           ComponentName_MAX_HW_SAMPLE_COUNT.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The device doesn't work in the
**                           active clock configuration
**                           ERR_DISABLED - Component is disabled
**                           ERR_PARAM_INDEX - Channel index in
**                           SampleGroup structure is out of range
**                           ERR_PARAM_SAMPLE_COUNT - SampleCount
**                           variable value is out of range
**                           ERR_BUSY - Measurement is in progress 
** ===================================================================
*/
LDD_TError AD2_CreateSampleGroup(LDD_TDeviceData *DeviceDataPtr, LDD_ADC_TSample *SampleGroupPtr, uint8_t SampleCount)
{
  AD2_TDeviceDataPtr DeviceDataPrv = (AD2_TDeviceDataPtr)DeviceDataPtr;

  /* Sample count test - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if ((SampleCount > AD2_MAX_HW_SAMPLE_COUNT) || (SampleCount == 0U)) { /* Is number of sample greather then supported by the HW? */
    return ERR_PARAM_SAMPLE_COUNT;     /* Yes, return ERR_PARAM_SAMPLE_COUNT */
  }
  if ((ADC_PDD_GetConversionActiveFlag(ADC1_BASE_PTR) != 0U)) { /* Last measurement still pending? */
    return ERR_BUSY;                   /* Yes, return ERR_BUSY */
  }
  DeviceDataPrv->SampleCount = SampleCount; /* Remember sample count */
  /* Channel index test - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if (SampleGroupPtr[0].ChannelIdx >= AD2_CHANNEL_COUNT) { /* Is channel index out of range? */
    return ERR_PARAM_INDEX;            /* Yes, return ERR_PARAM_INDEX */
  }
  DeviceDataPrv->FirstSample = ChannelToPin[SampleGroupPtr[0].ChannelIdx]; /* Remember first sample */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  AD2_GetMeasuredValues (component ADC_LDD)
**
**     Description :
**         This method copies results of the last measurement to the
**         user supplied buffer. Data size depends on the size of
**         measured sample group (see <SelectSampleGroup()> or
**         <CreateSampleGroup()> method). Data representation is
**         defined by the <Result type> property. Typically this method
**         is called from <OnMeasurementComplete> event to get results
**         of the last measurement.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**       * BufferPtr       - Pointer to the start of the
**                           buffer for new results. Count of stored
**                           measured values equals to the count of the
**                           samples in the active sample group. It is
**                           in the user responsibility to provide
**                           buffer with appropriate size.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - The device doesn't work in the
**                           active clock configuration
**                           ERR_DISABLED - Component is disabled
** ===================================================================
*/
LDD_TError AD2_GetMeasuredValues(LDD_TDeviceData *DeviceDataPtr, LDD_TData *BufferPtr)
{
  uint8_t Sample;
  AD2_TResultData *pBuffer = (AD2_TResultData *)BufferPtr;

  /* Copy values from result registers defined in the active sample
     group to the user supplied buffer */
  for (Sample = 0U; Sample < ((AD2_TDeviceDataPtr)DeviceDataPtr)->SampleCount; Sample++) {
    pBuffer[Sample] = (uint16_t)(ADC_PDD_GetResultValueRaw(ADC1_BASE_PTR, Sample));
  }
  return ERR_OK;                       /* OK */
}

/* END AD2. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
