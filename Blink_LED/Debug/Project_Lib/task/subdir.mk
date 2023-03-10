################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Project_Lib/task/task.c 

OBJS += \
./Project_Lib/task/task.o 

C_DEPS += \
./Project_Lib/task/task.d 


# Each subdirectory must supply rules for building sources it contributes
Project_Lib/task/%.o Project_Lib/task/%.su Project_Lib/task/%.cyclo: ../Project_Lib/task/%.c Project_Lib/task/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/STM32/CubeIDE/Blink_LED/Project_Lib/dht/Inc" -I"D:/STM32/CubeIDE/Blink_LED/Project_Lib/delay_timer/Inc" -I"D:/STM32/CubeIDE/Blink_LED/Project_Lib/n" -I"D:/STM32/CubeIDE/Blink_LED/Project_Lib/handle" -I"D:/STM32/CubeIDE/Blink_LED/Project_Lib/task" -I"D:/STM32/CubeIDE/Blink_LED/Project_Lib/dc_motor" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Project_Lib-2f-task

clean-Project_Lib-2f-task:
	-$(RM) ./Project_Lib/task/task.cyclo ./Project_Lib/task/task.d ./Project_Lib/task/task.o ./Project_Lib/task/task.su

.PHONY: clean-Project_Lib-2f-task

