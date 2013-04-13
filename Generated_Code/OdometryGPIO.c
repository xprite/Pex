/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : OdometryGPIO.c
**     Project     : ProcessorExpert
**     Processor   : MK40DX256ZVLQ10
**     Component   : GPIO_LDD
**     Version     : Component 01.126, Driver 01.06, CPU db: 3.00.001
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-04-11, 15:40, # CodeGen: 91
**     Abstract    :
**         The HAL GPIO component will provide a low level API for unified
**         access to general purpose digital input/output pins across
**         various device designs.
**
**         RTOS drivers using HAL GPIO API will be simpler and more
**         portable to various microprocessors.
**     Settings    :
**          Component name                                 : OdometryGPIO
**          Port                                           : PTD
**          Port width                                     : 32 bits
**          Mask of allocated pins                         : 40
**          Interrupt service/event                        : Enabled
**            Interrupt                                    : INT_PORTD
**            Interrupt priority                           : medium priority
**          Bit fields                                     : 1
**            Bit field                                    : 
**              Field name                                 : OdometryRightPin
**              Pins                                       : 1
**                Pin                                      : 
**                  Pin                                    : PTD6/SPI0_PCS3/UART0_RX/FTM0_CH6/FTM0_FLT0/LCD_P46/ADC0_SE7b
**                  Pin signal                             : 
**                  Initial pin direction                  : Input
**                  Initial pin event                      : Falling edge
**                  Lock initialization function           : no
**          Initialization                                 : 
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnPortEvent                                : Enabled
**     Contents    :
**         Init                    - LDD_TDeviceData* OdometryGPIO_Init(LDD_TUserData *UserDataPtr);
**         Deinit                  - void OdometryGPIO_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         SetFieldValue           - void OdometryGPIO_SetFieldValue(LDD_TDeviceData *DeviceDataPtr,...
**         GetFieldValue           - OdometryGPIO_TFieldValue OdometryGPIO_GetFieldValue(LDD_TDeviceData...
**         ClearFieldBits          - void OdometryGPIO_ClearFieldBits(LDD_TDeviceData *DeviceDataPtr,...
**         SetFieldBits            - void OdometryGPIO_SetFieldBits(LDD_TDeviceData *DeviceDataPtr,...
**         ToggleFieldBits         - void OdometryGPIO_ToggleFieldBits(LDD_TDeviceData *DeviceDataPtr,...
**         SetFieldInputDirection  - void OdometryGPIO_SetFieldInputDirection(LDD_TDeviceData *DeviceDataPtr,...
**         SetFieldOutputDirection - void OdometryGPIO_SetFieldOutputDirection(LDD_TDeviceData *DeviceDataPtr,...
**         ConnectPin              - LDD_TError OdometryGPIO_ConnectPin(LDD_TDeviceData *DeviceDataPtr,...
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE OdometryGPIO. */

#include "Events.h"
#include "OdometryGPIO.h"
/* {Default RTOS Adapter} No RTOS includes */
#include "IO_Map.h"

typedef struct {
  OdometryGPIO_TPortValue EventFlags;  /* Holds event flags */
  LDD_TUserData *UserData;             /* RTOS device data structure */
} OdometryGPIO_TDeviceData, *OdometryGPIO_TDeviceDataPtr; /* Device data structure type */
/* {Default RTOS Adapter} Static object used for simulation of dynamic driver memory allocation */
static OdometryGPIO_TDeviceData DeviceDataPrv__DEFAULT_RTOS_ALLOC;
/* {Default RTOS Adapter} Global variable used for passing a parameter into ISR */
static OdometryGPIO_TDeviceData * INT_PORTD__DEFAULT_RTOS_ISRPARAM;
/*
** ===================================================================
**     Method      :  OdometryGPIO_Init (component GPIO_LDD)
**
**     Description :
**         This method initializes the associated peripheral(s) and the
**         component internal variables. The method is called
**         automatically as a part of the application initialization
**         code.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * UserDataPtr     - Pointer to the RTOS device
**                           structure. This pointer will be passed to
**                           all events as parameter.
**     Returns     :
**         ---             - Pointer to the dynamically allocated
**                           private structure or NULL if there was an
**                           error.
** ===================================================================
*/
LDD_TDeviceData* OdometryGPIO_Init(LDD_TUserData *UserDataPtr)
{
  /* Allocate LDD device structure */
  OdometryGPIO_TDeviceData *DeviceDataPrv;

  /* {Default RTOS Adapter} Driver memory allocation: Dynamic allocation is simulated by a pointer to the static object */
  DeviceDataPrv = &DeviceDataPrv__DEFAULT_RTOS_ALLOC;
  /* Save RTOS Device structure */
  DeviceDataPrv->EventFlags = 0x00U;   /* Clears stored events */
  DeviceDataPrv->UserData = UserDataPtr; /* Store the RTOS device structure */
  /* Interrupt vector(s) allocation */
  /* {Default RTOS Adapter} Set interrupt vector: IVT is static, ISR parameter is passed by the global variable */
  INT_PORTD__DEFAULT_RTOS_ISRPARAM = DeviceDataPrv;
  /* GPIOD_PDDR: PDD&=~0x40 */
  GPIOD_PDDR &= (uint32_t)~(uint32_t)(GPIO_PDDR_PDD(0x40));                                                   
  /* Initialization of Port Control registers */
  /* PORTD_PCR6: ISF=0,LK=0,MUX=1 */
  PORTD_PCR6 = (uint32_t)((PORTD_PCR6 & (uint32_t)~(uint32_t)(
                PORT_PCR_ISF_MASK |
                PORT_PCR_LK_MASK |
                PORT_PCR_MUX(0x06)
               )) | (uint32_t)(
                PORT_PCR_MUX(0x01)
               ));                                                  
  /* PORTD_PCR6: ISF=1,IRQC=0x0A */
  PORTD_PCR6 = (uint32_t)((PORTD_PCR6 & (uint32_t)~(uint32_t)(
                PORT_PCR_IRQC(0x05)
               )) | (uint32_t)(
                PORT_PCR_ISF_MASK |
                PORT_PCR_IRQC(0x0A)
               ));                                                  
  /* NVICIP90: PRI90=0x80 */
  NVICIP90 = NVIC_IP_PRI90(0x80);                                                   
  /* NVICISER2: SETENA|=0x04000000 */
  NVICISER2 |= NVIC_ISER_SETENA(0x04000000);                                                   
  /* Registration of the device structure */
  PE_LDD_RegisterDeviceStructure(PE_LDD_COMPONENT_OdometryGPIO_ID,DeviceDataPrv);
  return ((LDD_TDeviceData *)DeviceDataPrv);
}

/*
** ===================================================================
**     Method      :  OdometryGPIO_Deinit (component GPIO_LDD)
**
**     Description :
**         This method disables the device and frees the device data
**         structure memory.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Pointer to device data
**                           structure pointer.
**     Returns     : Nothing
** ===================================================================
*/
void OdometryGPIO_Deinit(LDD_TDeviceData *DeviceDataPtr)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  /* PORTD_PCR6: IRQC=0 */
  PORTD_PCR6 &= (uint32_t)~(uint32_t)(PORT_PCR_IRQC(0x0F));                                                   
  /* GPIOD_PDDR: PDD&=~0x40 */
  GPIOD_PDDR &= (uint32_t)~(uint32_t)(GPIO_PDDR_PDD(0x40));                                                   
  /* Interrupt vector(s) deallocation */
  /* {Default RTOS Adapter} Restore interrupt vector: IVT is static, no code is generated */
  /* Unregistration of the device structure */
  PE_LDD_UnregisterDeviceStructure(PE_LDD_COMPONENT_OdometryGPIO_ID);
  /* Deallocation of the device structure */
  /* {Default RTOS Adapter} Driver memory deallocation: Dynamic allocation is simulated, no deallocation code is generated */
}

/*
** ===================================================================
**     Method      :  OdometryGPIO_SetFieldValue (component GPIO_LDD)
**
**     Description :
**         This method sets the output data value of the specified bit
**         field.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Field           - Bit field to write. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**         Value           - Aligned data value to writting to the
**                           specified bit field. The bit 0 corresponds
**                           with the pin which has index 0 within the
**                           given bit field, the bit 1 corresponds with
**                           the pin which has index 1 within the given
**                           bit field, etc.
**     Returns     : Nothing
** ===================================================================
*/
void OdometryGPIO_SetFieldValue(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, OdometryGPIO_TFieldValue Value)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case OdometryRightPin: {           /* bit field #0 */
      GPIO_PDD_SetPortDataOutput(OdometryGPIO_MODULE_BASE_ADDRESS,
        (
          GPIO_PDD_GetPortDataOutput(OdometryGPIO_MODULE_BASE_ADDRESS)
          & ((OdometryGPIO_TPortValue)(~((OdometryGPIO_TPortValue)OdometryGPIO_OdometryRightPin_MASK)))
        )
        | (
          ((OdometryGPIO_TPortValue)(Value << OdometryGPIO_OdometryRightPin_START_BIT))
          & ((OdometryGPIO_TPortValue)OdometryGPIO_OdometryRightPin_MASK)
        )
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  OdometryGPIO_GetFieldValue (component GPIO_LDD)
**
**     Description :
**         This method returns the current input data of the specified
**         field.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Field           - Bit field to reading. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**     Returns     :
**         ---             - Aligned current port input value masked
**                           for allocated pins of the field. The bit 0
**                           corresponds with the pin which has index 0
**                           within the given bit field, the bit 1
**                           corresponds with the pin which has index 1
**                           within the given bit field, etc.
** ===================================================================
*/
OdometryGPIO_TFieldValue OdometryGPIO_GetFieldValue(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case OdometryRightPin: {           /* bit field #0 */
      return
        (OdometryGPIO_TFieldValue)(
          (
            GPIO_PDD_GetPortDataInput(OdometryGPIO_MODULE_BASE_ADDRESS)
            & (OdometryGPIO_TPortValue)OdometryGPIO_OdometryRightPin_MASK
          )
          >> OdometryGPIO_OdometryRightPin_START_BIT
        );
    }
    default:
      break;                           /* Invalid BitField is not treated, result is undefined */
  } /* switch (Field) */
  return (OdometryGPIO_TFieldValue)0U;
}

/*
** ===================================================================
**     Method      :  OdometryGPIO_ClearFieldBits (component GPIO_LDD)
**
**     Description :
**         This method drives the specified bits of the specified bit
**         field to the inactive level.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Field           - Bit field to write. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**         Mask            - Aligned mask of bits to setting the
**                           inactive level. Each field pin has
**                           corresponding bit in the mask. Bit value 0
**                           means not selected bit, bit value 1 means
**                           selected bit. The bit 0 corresponds with
**                           the pin which has index 0 within the given
**                           bit field, the bit 1 corresponds with the
**                           pin which has index 1 within the given bit
**                           field, etc.
**     Returns     : Nothing
** ===================================================================
*/
void OdometryGPIO_ClearFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, OdometryGPIO_TFieldValue Mask)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case OdometryRightPin: {           /* bit field #0 */
      GPIO_PDD_ClearPortDataOutputMask(OdometryGPIO_MODULE_BASE_ADDRESS,
        ((OdometryGPIO_TPortValue)OdometryGPIO_OdometryRightPin_MASK)
        & ((OdometryGPIO_TPortValue)(Mask << OdometryGPIO_OdometryRightPin_START_BIT))
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  OdometryGPIO_SetFieldBits (component GPIO_LDD)
**
**     Description :
**         This method drives the specified bits of the specified bit
**         field to the active level.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Field           - Bit field to write. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**         Mask            - Aligned mask of bits to setting the
**                           active level. Each field pin has
**                           corresponding bit in the mask. Bit value 0
**                           means not selected bit, bit value 1 means
**                           selected bit. The bit 0 corresponds with
**                           the pin which has index 0 within the given
**                           bit field, the bit 1 corresponds with the
**                           pin which has index 1 within the given bit
**                           field, etc.
**     Returns     : Nothing
** ===================================================================
*/
void OdometryGPIO_SetFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, OdometryGPIO_TFieldValue Mask)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case OdometryRightPin: {           /* bit field #0 */
      GPIO_PDD_SetPortDataOutputMask(OdometryGPIO_MODULE_BASE_ADDRESS,
        ((OdometryGPIO_TPortValue)OdometryGPIO_OdometryRightPin_MASK)
        & ((OdometryGPIO_TPortValue)(Mask << OdometryGPIO_OdometryRightPin_START_BIT))
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  OdometryGPIO_ToggleFieldBits (component GPIO_LDD)
**
**     Description :
**         This method inverts the specified bits of the specified bit
**         field to other level.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Field           - Bit field to write. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**         Mask            - Aligned mask of bits to inverting the
**                           current level. Each field pin has
**                           corresponding bit in the mask. Bit value 0
**                           means not selected bit, bit value 1 means
**                           selected bit. The bit 0 corresponds with
**                           the pin which has index 0 within the given
**                           bit field, the bit 1 corresponds with the
**                           pin which has index 1 within the given bit
**                           field, etc.
**     Returns     : Nothing
** ===================================================================
*/
void OdometryGPIO_ToggleFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, OdometryGPIO_TFieldValue Mask)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case OdometryRightPin: {           /* bit field #0 */
      GPIO_PDD_TogglePortDataOutputMask(OdometryGPIO_MODULE_BASE_ADDRESS,
        ((OdometryGPIO_TPortValue)OdometryGPIO_OdometryRightPin_MASK)
        & ((OdometryGPIO_TPortValue)(Mask << OdometryGPIO_OdometryRightPin_START_BIT))
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  OdometryGPIO_SetFieldInputDirection (component GPIO_LDD)
**
**     Description :
**         This method sets all pins of the field to the input
**         direction.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Field           - Bit field to write. Bit fields are
**                           defined during design time and for each bit
**                           field there is a generated constant.
**     Returns     : Nothing
** ===================================================================
*/
void OdometryGPIO_SetFieldInputDirection(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case OdometryRightPin: {           /* bit field #0 */
      GPIO_PDD_SetPortInputDirectionMask(OdometryGPIO_MODULE_BASE_ADDRESS,
        OdometryGPIO_OdometryRightPin_MASK
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  OdometryGPIO_SetFieldOutputDirection (component GPIO_LDD)
**
**     Description :
**         This method sets all pins of the field to the output
**         direction.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         Field           - Bit field to set to the output
**                           direction. Bit fields are defined during
**                           design time and for each bit field there is
**                           a generated constant.
**         Value           - Aligned data value to appear on the
**                           bit field pins after they have been
**                           switched to the output direction.
**     Returns     : Nothing
** ===================================================================
*/
void OdometryGPIO_SetFieldOutputDirection(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, OdometryGPIO_TFieldValue Value)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  switch (Field) {                     /* no break */
    case OdometryRightPin: {           /* bit field #0 */
      GPIO_PDD_SetPortDataOutput(OdometryGPIO_MODULE_BASE_ADDRESS,
        ((OdometryGPIO_TPortValue)(
          GPIO_PDD_GetPortDataOutput(OdometryGPIO_MODULE_BASE_ADDRESS)
          & ((OdometryGPIO_TPortValue)(
            ~((OdometryGPIO_TPortValue)OdometryGPIO_OdometryRightPin_MASK)
          ))
        ))
        | (
          ((OdometryGPIO_TPortValue)(Value << OdometryGPIO_OdometryRightPin_START_BIT))
          & ((OdometryGPIO_TPortValue)OdometryGPIO_OdometryRightPin_MASK)
        )
      );
      GPIO_PDD_SetPortOutputDirectionMask(OdometryGPIO_MODULE_BASE_ADDRESS,
        OdometryGPIO_OdometryRightPin_MASK
      );
      break;
    }
    default:
      break;                           /* Invalid Field is not treated, result is undefined */
  } /* switch (Field) */
}

/*
** ===================================================================
**     Method      :  OdometryGPIO_ConnectPin (component GPIO_LDD)
**
**     Description :
**         This method reconnects the requested pin associated with the
**         selected peripheral in this component. This method is only
**         available for CPU derivatives and peripherals that support
**         the runtime pin sharing with other internal on-chip
**         peripherals.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * DeviceDataPtr   - Device data structure
**                           pointer returned by <Init> method.
**         PinMask         - Mask for the requested pins. The
**                           peripheral pins are reconnected according
**                           to this mask.
**     Returns     :
**         ---             - Error code, possible values:
**                           ERR_OK - OK
**                           ERR_PARAM_MASK - Invalid pin mask
** ===================================================================
*/
LDD_TError OdometryGPIO_ConnectPin(LDD_TDeviceData *DeviceDataPtr, LDD_TPinMask PinMask)
{
  (void)DeviceDataPtr;                 /* Parameter is not used, suppress unused argument warning */
  /* Pin mask test - this test can be disabled by setting the "Ignore range checking"
     property to the "yes" value in the "Configuration inspector" */
  if ((PinMask & ((LDD_TPinMask)~((LDD_TPinMask)OdometryGPIO_ALLOCATED_PINS_MASK))) != 0U) {
    return ERR_PARAM_MASK;
  }
  if ((PinMask & LDD_GPIO_PIN_6) != 0U) {
    clrSetReg32Bits(PORTD_PCR6, 0x01000600U, 0x0100U); /* MUX=0x01U */
  }
  return ERR_OK;
}

/*
** ===================================================================
**     Method      :  OdometryGPIO_Interrupt (component GPIO_LDD)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes event(s) of the component.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
PE_ISR(OdometryGPIO_Interrupt)
{
  /* {Default RTOS Adapter} ISR parameter is passed through the global variable */
  OdometryGPIO_TDeviceDataPtr DeviceDataPrv = INT_PORTD__DEFAULT_RTOS_ISRPARAM;
  OdometryGPIO_TPortValue State;

  State = (OdometryGPIO_TPortValue)(PORT_PDD_GetInterruptFlags(OdometryGPIO_PORTCONTROL_BASE_ADDRESS)
          & ((OdometryGPIO_TPortValue)OdometryGPIO_ALLOCATED_PINS_MASK)); /* Retrieve flags */
  DeviceDataPrv->EventFlags |= State;
  PORT_PDD_ClearInterruptFlags(OdometryGPIO_PORTCONTROL_BASE_ADDRESS, State); /* Clears flags */
  OdometryGPIO_OnPortEvent(DeviceDataPrv->UserData); /* Call OnPortEvent event */
}

/* END OdometryGPIO. */

/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
