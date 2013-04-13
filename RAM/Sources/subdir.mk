################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Accelerometer.c" \
"../Sources/Camera.c" \
"../Sources/Communication.c" \
"../Sources/Events.c" \
"../Sources/Map.c" \
"../Sources/Odometry.c" \
"../Sources/ProcessorExpert.c" \
"../Sources/Steering.c" \

C_SRCS += \
../Sources/Accelerometer.c \
../Sources/Camera.c \
../Sources/Communication.c \
../Sources/Events.c \
../Sources/Map.c \
../Sources/Odometry.c \
../Sources/ProcessorExpert.c \
../Sources/Steering.c \

OBJS += \
./Sources/Accelerometer_c.obj \
./Sources/Camera_c.obj \
./Sources/Communication_c.obj \
./Sources/Events_c.obj \
./Sources/Map_c.obj \
./Sources/Odometry_c.obj \
./Sources/ProcessorExpert_c.obj \
./Sources/Steering_c.obj \

C_DEPS += \
./Sources/Accelerometer.d \
./Sources/Camera.d \
./Sources/Communication.d \
./Sources/Events.d \
./Sources/Map.d \
./Sources/Odometry.d \
./Sources/ProcessorExpert.d \
./Sources/Steering.d \

OBJS_QUOTED += \
"./Sources/Accelerometer_c.obj" \
"./Sources/Camera_c.obj" \
"./Sources/Communication_c.obj" \
"./Sources/Events_c.obj" \
"./Sources/Map_c.obj" \
"./Sources/Odometry_c.obj" \
"./Sources/ProcessorExpert_c.obj" \
"./Sources/Steering_c.obj" \

C_DEPS_QUOTED += \
"./Sources/Accelerometer.d" \
"./Sources/Camera.d" \
"./Sources/Communication.d" \
"./Sources/Events.d" \
"./Sources/Map.d" \
"./Sources/Odometry.d" \
"./Sources/ProcessorExpert.d" \
"./Sources/Steering.d" \

OBJS_OS_FORMAT += \
./Sources/Accelerometer_c.obj \
./Sources/Camera_c.obj \
./Sources/Communication_c.obj \
./Sources/Events_c.obj \
./Sources/Map_c.obj \
./Sources/Odometry_c.obj \
./Sources/ProcessorExpert_c.obj \
./Sources/Steering_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/Accelerometer_c.obj: ../Sources/Accelerometer.c
	@echo 'Building file: $<'
	@echo 'Executing target #1 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Accelerometer.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/Accelerometer_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Camera_c.obj: ../Sources/Camera.c
	@echo 'Building file: $<'
	@echo 'Executing target #2 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Camera.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/Camera_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Communication_c.obj: ../Sources/Communication.c
	@echo 'Building file: $<'
	@echo 'Executing target #3 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Communication.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/Communication_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Events_c.obj: ../Sources/Events.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Events.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/Events_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Map_c.obj: ../Sources/Map.c
	@echo 'Building file: $<'
	@echo 'Executing target #5 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Map.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/Map_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Odometry_c.obj: ../Sources/Odometry.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Odometry.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/Odometry_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/ProcessorExpert_c.obj: ../Sources/ProcessorExpert.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/ProcessorExpert.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/ProcessorExpert_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Sources/Steering_c.obj: ../Sources/Steering.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/Steering.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Sources/Steering_c.obj"
	@echo 'Finished building: $<'
	@echo ' '


