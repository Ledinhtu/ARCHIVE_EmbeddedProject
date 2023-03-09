################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Project_Lib/dc_motor/dc_motor.c 

OBJS += \
./Project_Lib/dc_motor/dc_motor.o 

C_DEPS += \
./Project_Lib/dc_motor/dc_motor.d 


# Each subdirectory must supply rules for building sources it contributes
Project_Lib/dc_motor/%.o Project_Lib/dc_motor/%.su: ../Project_Lib/dc_motor/%.c Project_Lib/dc_motor/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/STM32/CubeIDE/Blink_LED/Project_Lib/dht/Inc" -I"D:/STM32/CubeIDE/Blink_LED/Project_Lib/delay_timer/Inc" -I"D:/STM32/CubeIDE/Blink_LED/Project_Lib/lcd_i2c/Inc" -I"D:/STM32/CubeIDE/Blink_LED/Project_Lib/n" -I"D:/STM32/CubeIDE/Blink_LED/Project_Lib/handle" -I"D:/STM32/CubeIDE/Blink_LED/Project_Lib/task" -I"D:/STM32/CubeIDE/Blink_LED/Project_Lib/dc_motor" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Project_Lib-2f-dc_motor

clean-Project_Lib-2f-dc_motor:
	-$(RM) ./Project_Lib/dc_motor/dc_motor.d ./Project_Lib/dc_motor/dc_motor.o ./Project_Lib/dc_motor/dc_motor.su

.PHONY: clean-Project_Lib-2f-dc_motor

