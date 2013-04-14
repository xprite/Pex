################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Project_Settings/Startup_Code/__arm_end.c" \
"../Project_Settings/Startup_Code/__arm_start.c" \

C_SRCS += \
../Project_Settings/Startup_Code/__arm_end.c \
../Project_Settings/Startup_Code/__arm_start.c \

OBJS += \
./Project_Settings/Startup_Code/__arm_end_c.obj \
./Project_Settings/Startup_Code/__arm_start_c.obj \

C_DEPS += \
./Project_Settings/Startup_Code/__arm_end.d \
./Project_Settings/Startup_Code/__arm_start.d \

OBJS_QUOTED += \
"./Project_Settings/Startup_Code/__arm_end_c.obj" \
"./Project_Settings/Startup_Code/__arm_start_c.obj" \

C_DEPS_QUOTED += \
"./Project_Settings/Startup_Code/__arm_end.d" \
"./Project_Settings/Startup_Code/__arm_start.d" \

OBJS_OS_FORMAT += \
./Project_Settings/Startup_Code/__arm_end_c.obj \
./Project_Settings/Startup_Code/__arm_start_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Project_Settings/Startup_Code/__arm_end_c.obj: ../Project_Settings/Startup_Code/__arm_end.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Project_Settings/Startup_Code/__arm_end.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Project_Settings/Startup_Code/__arm_end_c.obj"
	@echo 'Finished building: $<'
	@echo ' '

Project_Settings/Startup_Code/__arm_start_c.obj: ../Project_Settings/Startup_Code/__arm_start.c
	@echo 'Building file: $<'
	@echo 'Executing target #11 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Project_Settings/Startup_Code/__arm_start.args" -Wa,-adhlns="$@.lst" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -g3 -gdwarf-2 -gstrict-dwarf -o"Project_Settings/Startup_Code/__arm_start_c.obj"
	@echo 'Finished building: $<'
	@echo ' '


