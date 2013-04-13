################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Generated_Code/AD1.c" \
"../Generated_Code/AD2.c" \
"../Generated_Code/AS1.c" \
"../Generated_Code/CameraTimer.c" \
"../Generated_Code/Cpu.c" \
"../Generated_Code/CsIO1.c" \
"../Generated_Code/GPIO1.c" \
"../Generated_Code/GPIO2.c" \
"../Generated_Code/GPIO3.c" \
"../Generated_Code/I2C2.c" \
"../Generated_Code/IO1.c" \
"../Generated_Code/OdometryGPIO.c" \
"../Generated_Code/OdometryTimer.c" \
"../Generated_Code/PE_LDD.c" \
"../Generated_Code/PWMMotor.c" \
"../Generated_Code/Period.c" \
"../Generated_Code/ServoTimer.c" \
"../Generated_Code/SiPin.c" \
"../Generated_Code/Vectors.c" \

C_SRCS += \
../Generated_Code/AD1.c \
../Generated_Code/AD2.c \
../Generated_Code/AS1.c \
../Generated_Code/CameraTimer.c \
../Generated_Code/Cpu.c \
../Generated_Code/CsIO1.c \
../Generated_Code/GPIO1.c \
../Generated_Code/GPIO2.c \
../Generated_Code/GPIO3.c \
../Generated_Code/I2C2.c \
../Generated_Code/IO1.c \
../Generated_Code/OdometryGPIO.c \
../Generated_Code/OdometryTimer.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/PWMMotor.c \
../Generated_Code/Period.c \
../Generated_Code/ServoTimer.c \
../Generated_Code/SiPin.c \
../Generated_Code/Vectors.c \

OBJS += \
./Generated_Code/AD1_c.obj \
./Generated_Code/AD2_c.obj \
./Generated_Code/AS1_c.obj \
./Generated_Code/CameraTimer_c.obj \
./Generated_Code/Cpu_c.obj \
./Generated_Code/CsIO1_c.obj \
./Generated_Code/GPIO1_c.obj \
./Generated_Code/GPIO2_c.obj \
./Generated_Code/GPIO3_c.obj \
./Generated_Code/I2C2_c.obj \
./Generated_Code/IO1_c.obj \
./Generated_Code/OdometryGPIO_c.obj \
./Generated_Code/OdometryTimer_c.obj \
./Generated_Code/PE_LDD_c.obj \
./Generated_Code/PWMMotor_c.obj \
./Generated_Code/Period_c.obj \
./Generated_Code/ServoTimer_c.obj \
./Generated_Code/SiPin_c.obj \
./Generated_Code/Vectors_c.obj \

C_DEPS += \
./Generated_Code/AD1.d \
./Generated_Code/AD2.d \
./Generated_Code/AS1.d \
./Generated_Code/CameraTimer.d \
./Generated_Code/Cpu.d \
./Generated_Code/CsIO1.d \
./Generated_Code/GPIO1.d \
./Generated_Code/GPIO2.d \
./Generated_Code/GPIO3.d \
./Generated_Code/I2C2.d \
./Generated_Code/IO1.d \
./Generated_Code/OdometryGPIO.d \
./Generated_Code/OdometryTimer.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/PWMMotor.d \
./Generated_Code/Period.d \
./Generated_Code/ServoTimer.d \
./Generated_Code/SiPin.d \
./Generated_Code/Vectors.d \

OBJS_QUOTED += \
"./Generated_Code/AD1_c.obj" \
"./Generated_Code/AD2_c.obj" \
"./Generated_Code/AS1_c.obj" \
"./Generated_Code/CameraTimer_c.obj" \
"./Generated_Code/Cpu_c.obj" \
"./Generated_Code/CsIO1_c.obj" \
"./Generated_Code/GPIO1_c.obj" \
"./Generated_Code/GPIO2_c.obj" \
"./Generated_Code/GPIO3_c.obj" \
"./Generated_Code/I2C2_c.obj" \
"./Generated_Code/IO1_c.obj" \
"./Generated_Code/OdometryGPIO_c.obj" \
"./Generated_Code/OdometryTimer_c.obj" \
"./Generated_Code/PE_LDD_c.obj" \
"./Generated_Code/PWMMotor_c.obj" \
"./Generated_Code/Period_c.obj" \
"./Generated_Code/ServoTimer_c.obj" \
"./Generated_Code/SiPin_c.obj" \
"./Generated_Code/Vectors_c.obj" \

C_DEPS_QUOTED += \
"./Generated_Code/AD1.d" \
"./Generated_Code/AD2.d" \
"./Generated_Code/AS1.d" \
"./Generated_Code/CameraTimer.d" \
"./Generated_Code/Cpu.d" \
"./Generated_Code/CsIO1.d" \
"./Generated_Code/GPIO1.d" \
"./Generated_Code/GPIO2.d" \
"./Generated_Code/GPIO3.d" \
"./Generated_Code/I2C2.d" \
"./Generated_Code/IO1.d" \
"./Generated_Code/OdometryGPIO.d" \
"./Generated_Code/OdometryTimer.d" \
"./Generated_Code/PE_LDD.d" \
"./Generated_Code/PWMMotor.d" \
"./Generated_Code/Period.d" \
"./Generated_Code/ServoTimer.d" \
"./Generated_Code/SiPin.d" \
"./Generated_Code/Vectors.d" \

OBJS_OS_FORMAT += \
./Generated_Code/AD1_c.obj \
./Generated_Code/AD2_c.obj \
./Generated_Code/AS1_c.obj \
./Generated_Code/CameraTimer_c.obj \
./Generated_Code/Cpu_c.obj \
./Generated_Code/CsIO1_c.obj \
./Generated_Code/GPIO1_c.obj \
./Generated_Code/GPIO2_c.obj \
./Generated_Code/GPIO3_c.obj \
./Generated_Code/I2C2_c.obj \
./Generated_Code/IO1_c.obj \
./Generated_Code/OdometryGPIO_c.obj \
./Generated_Code/OdometryTimer_c.obj \
./Generated_Code/PE_LDD_c.obj \
./Generated_Code/PWMMotor_c.obj \
./Generated_Code/Period_c.obj \
./Generated_Code/ServoTimer_c.obj \
./Generated_Code/SiPin_c.obj \
./Generated_Code/Vectors_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/AD1_c.obj: ../Generated_Code/AD1.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/AD1.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/AD1_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/AD2_c.obj: ../Generated_Code/AD2.c
	@echo 'Building file: $<'
	@echo 'Executing target #12 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/AD2.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/AD2_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/AS1_c.obj: ../Generated_Code/AS1.c
	@echo 'Building file: $<'
	@echo 'Executing target #13 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/AS1.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/AS1_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/CameraTimer_c.obj: ../Generated_Code/CameraTimer.c
	@echo 'Building file: $<'
	@echo 'Executing target #14 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/CameraTimer.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/CameraTimer_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Cpu_c.obj: ../Generated_Code/Cpu.c
	@echo 'Building file: $<'
	@echo 'Executing target #15 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Cpu.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/Cpu_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/CsIO1_c.obj: ../Generated_Code/CsIO1.c
	@echo 'Building file: $<'
	@echo 'Executing target #16 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/CsIO1.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/CsIO1_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/GPIO1_c.obj: ../Generated_Code/GPIO1.c
	@echo 'Building file: $<'
	@echo 'Executing target #17 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/GPIO1.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/GPIO1_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/GPIO2_c.obj: ../Generated_Code/GPIO2.c
	@echo 'Building file: $<'
	@echo 'Executing target #18 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/GPIO2.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/GPIO2_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/GPIO3_c.obj: ../Generated_Code/GPIO3.c
	@echo 'Building file: $<'
	@echo 'Executing target #19 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/GPIO3.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/GPIO3_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/I2C2_c.obj: ../Generated_Code/I2C2.c
	@echo 'Building file: $<'
	@echo 'Executing target #20 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/I2C2.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/I2C2_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/IO1_c.obj: ../Generated_Code/IO1.c
	@echo 'Building file: $<'
	@echo 'Executing target #21 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/IO1.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/IO1_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/OdometryGPIO_c.obj: ../Generated_Code/OdometryGPIO.c
	@echo 'Building file: $<'
	@echo 'Executing target #22 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/OdometryGPIO.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/OdometryGPIO_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/OdometryTimer_c.obj: ../Generated_Code/OdometryTimer.c
	@echo 'Building file: $<'
	@echo 'Executing target #23 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/OdometryTimer.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/OdometryTimer_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PE_LDD_c.obj: ../Generated_Code/PE_LDD.c
	@echo 'Building file: $<'
	@echo 'Executing target #24 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/PE_LDD.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/PE_LDD_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/PWMMotor_c.obj: ../Generated_Code/PWMMotor.c
	@echo 'Building file: $<'
	@echo 'Executing target #25 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/PWMMotor.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/PWMMotor_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Period_c.obj: ../Generated_Code/Period.c
	@echo 'Building file: $<'
	@echo 'Executing target #26 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Period.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/Period_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/ServoTimer_c.obj: ../Generated_Code/ServoTimer.c
	@echo 'Building file: $<'
	@echo 'Executing target #27 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/ServoTimer.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/ServoTimer_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/SiPin_c.obj: ../Generated_Code/SiPin.c
	@echo 'Building file: $<'
	@echo 'Executing target #28 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/SiPin.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/SiPin_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Generated_Code/Vectors_c.obj: ../Generated_Code/Vectors.c
	@echo 'Building file: $<'
	@echo 'Executing target #29 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Generated_Code/Vectors.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Generated_Code/Vectors_c.obj"
	@echo 'Finished building: $<'
	@echo ' '


