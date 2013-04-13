/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : SiPin.h
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
**          Component name                                 : SiPin
**          Port                                           : PTB
**          Port width                                     : 32 bits
**          Mask of allocated pins                         : 4
**          Interrupt service/event                        : Disabled
**          Bit fields                                     : 1
**            Bit field                                    : 
**              Field name                                 : Si
**              Pins                                       : 1
**                Pin                                      : 
**                  Pin                                    : PTB2/I2C0_SCL/UART0_RTS_b/FTM0_FLT3/LCD_P2/ADC0_SE12/TSI0_CH7
**                  Pin signal                             : 
**                  Initial pin direction                  : Output
**                    Initial output state                 : 0
**                  Initial pin event                      : Disabled
**                  Lock initialization function           : no
**          Initialization                                 : 
**            Auto initialization                          : yes
**            Event mask                                   : 
**              OnPortEvent                                : Disabled
**     Contents    :
**         Init                    - LDD_TDeviceData* SiPin_Init(LDD_TUserData *UserDataPtr);
**         Deinit                  - void SiPin_Deinit(LDD_TDeviceData *DeviceDataPtr);
**         SetFieldValue           - void SiPin_SetFieldValue(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField...
**         GetFieldValue           - SiPin_TFieldValue SiPin_GetFieldValue(LDD_TDeviceData *DeviceDataPtr,...
**         ClearFieldBits          - void SiPin_ClearFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField...
**         SetFieldBits            - void SiPin_SetFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField...
**         ToggleFieldBits         - void SiPin_ToggleFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField...
**         SetFieldInputDirection  - void SiPin_SetFieldInputDirection(LDD_TDeviceData *DeviceDataPtr,...
**         SetFieldOutputDirection - void SiPin_SetFieldOutputDirection(LDD_TDeviceData *DeviceDataPtr,...
**         ConnectPin              - LDD_TError SiPin_ConnectPin(LDD_TDeviceData *DeviceDataPtr, LDD_TPinMask...
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

#ifndef __SiPin_H
#define __SiPin_H

/* MODULE SiPin. */

/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* Include inherited beans */
#include "IO_Map.h"
#include "GPIO_PDD.h"
#include "PORT_PDD.h"
#include "PE_LDD.h"

#include "Cpu.h"


/* Peripheral base address of a device allocated by the component. This constant can be used directly in PDD macros. */
#define SiPin_PRPH_BASE_ADDRESS  0x400FF040U
  
/* Device data structure pointer used when auto initialization property is enabled. This constant can be passed as a first parameter to all component's methods. */
#define SiPin_DeviceData  ((LDD_TDeviceData *)PE_LDD_GetDeviceStructure(PE_LDD_COMPONENT_SiPin_ID))

/* Methods configuration constants - generated for all enabled component's methods */
#define SiPin_Init_METHOD_ENABLED
#define SiPin_Deinit_METHOD_ENABLED
#define SiPin_SetFieldValue_METHOD_ENABLED
#define SiPin_GetFieldValue_METHOD_ENABLED
#define SiPin_ClearFieldBits_METHOD_ENABLED
#define SiPin_SetFieldBits_METHOD_ENABLED
#define SiPin_ToggleFieldBits_METHOD_ENABLED
#define SiPin_SetFieldInputDirection_METHOD_ENABLED
#define SiPin_SetFieldOutputDirection_METHOD_ENABLED
#define SiPin_ConnectPin_METHOD_ENABLED

/* Events configuration constants - generated for all enabled component's events */

/* Definition of bit field constants */
#define Si ((LDD_GPIO_TBitField)0)

/* Definition of implementation constants */
#define SiPin_ALLOCATED_PINS_MASK 0x04U /* Mask of all allocated pins from the port */
#define SiPin_MODULE_BASE_ADDRESS PTB_BASE_PTR /* Name of macro used as the base address */
#define SiPin_PORTCONTROL_BASE_ADDRESS PORTB_BASE_PTR /* Name of macro used as the base address */
#define SiPin_AVAILABLE_EVENTS_MASK 0x00U /* Mask of all available events */
#define SiPin_FIELD_0_PIN_0 LDD_GPIO_PIN_2 /* Constant for the pin in the field used in the method ConnectPin */
#define SiPin_Si_START_BIT 2u          /* Index of the starting bit of the bit field (0 represents LSB) */
#define SiPin_Si_MASK 0x04u            /* Mask of the bits allocated by the bit field (within the port) */
/* Representation of unaligned data value of the port.
   Unsigned integer of proper width depending on the size of the GPIO port allocated.
   Typically the value of n-th bit represents the data for the n-th pin within the port.
   Such value is not abstracted from the physical position of the bits within the port. */
typedef uint32_t SiPin_TPortValue;

/* Representation of right-aligned data value of the bit field.
   Typically the value of n-th bit represents the data of the n-th bit within the bit field (not within the port).
   There are used only so many lowest bits, as it is denoted by the width of the bit field.
   Such value is abstracted from the physical position of the bit field pins within the port.
   Equals to the type <compId>_TPortValue. */
typedef SiPin_TPortValue SiPin_TFieldValue;



LDD_TDeviceData* SiPin_Init(LDD_TUserData *UserDataPtr);
/*
** ===================================================================
**     Method      :  SiPin_Init (component GPIO_LDD)
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

void SiPin_Deinit(LDD_TDeviceData *DeviceDataPtr);
/*
** ===================================================================
**     Method      :  SiPin_Deinit (component GPIO_LDD)
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

void SiPin_SetFieldValue(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, SiPin_TFieldValue Value);
/*
** ===================================================================
**     Method      :  SiPin_SetFieldValue (component GPIO_LDD)
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

SiPin_TFieldValue SiPin_GetFieldValue(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field);
/*
** ===================================================================
**     Method      :  SiPin_GetFieldValue (component GPIO_LDD)
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

void SiPin_ClearFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, SiPin_TFieldValue Mask);
/*
** ===================================================================
**     Method      :  SiPin_ClearFieldBits (component GPIO_LDD)
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

void SiPin_SetFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, SiPin_TFieldValue Mask);
/*
** ===================================================================
**     Method      :  SiPin_SetFieldBits (component GPIO_LDD)
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

void SiPin_ToggleFieldBits(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, SiPin_TFieldValue Mask);
/*
** ===================================================================
**     Method      :  SiPin_ToggleFieldBits (component GPIO_LDD)
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

void SiPin_SetFieldInputDirection(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field);
/*
** ===================================================================
**     Method      :  SiPin_SetFieldInputDirection (component GPIO_LDD)
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

void SiPin_SetFieldOutputDirection(LDD_TDeviceData *DeviceDataPtr, LDD_GPIO_TBitField Field, SiPin_TFieldValue Value);
/*
** ===================================================================
**     Method      :  SiPin_SetFieldOutputDirection (component GPIO_LDD)
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

LDD_TError SiPin_ConnectPin(LDD_TDeviceData *DeviceDataPtr, LDD_TPinMask PinMask);
/*
** ===================================================================
**     Method      :  SiPin_ConnectPin (component GPIO_LDD)
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

/* END SiPin. */

#endif
/* ifndef __SiPin_H */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/