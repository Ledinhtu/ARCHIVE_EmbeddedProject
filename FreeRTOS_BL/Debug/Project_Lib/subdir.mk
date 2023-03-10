################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Project_Lib/LiquidCrystal_I2C.c \
../Project_Lib/dc_motor.c \
../Project_Lib/delay_timer.c \
../Project_Lib/dht.c \
../Project_Lib/handle_task.c \
../Project_Lib/uart_handle.c 

OBJS += \
./Project_Lib/LiquidCrystal_I2C.o \
./Project_Lib/dc_motor.o \
./Project_Lib/delay_timer.o \
./Project_Lib/dht.o \
./Project_Lib/handle_task.o \
./Project_Lib/uart_handle.o 

C_DEPS += \
./Project_Lib/LiquidCrystal_I2C.d \
./Project_Lib/dc_motor.d \
./Project_Lib/delay_timer.d \
./Project_Lib/dht.d \
./Project_Lib/handle_task.d \
./Project_Lib/uart_handle.d 


# Each subdirectory must supply rules for building sources it contributes
Project_Lib/%.o Project_Lib/%.su Project_Lib/%.cyclo: ../Project_Lib/%.c Project_Lib/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -I"D:/STM32/CubeIDE/FreeRTOS_BL/Project_Lib/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Project_Lib

clean-Project_Lib:
	-$(RM) ./Project_Lib/LiquidCrystal_I2C.cyclo ./Project_Lib/LiquidCrystal_I2C.d ./Project_Lib/LiquidCrystal_I2C.o ./Project_Lib/LiquidCrystal_I2C.su ./Project_Lib/dc_motor.cyclo ./Project_Lib/dc_motor.d ./Project_Lib/dc_motor.o ./Project_Lib/dc_motor.su ./Project_Lib/delay_timer.cyclo ./Project_Lib/delay_timer.d ./Project_Lib/delay_timer.o ./Project_Lib/delay_timer.su ./Project_Lib/dht.cyclo ./Project_Lib/dht.d ./Project_Lib/dht.o ./Project_Lib/dht.su ./Project_Lib/handle_task.cyclo ./Project_Lib/handle_task.d ./Project_Lib/handle_task.o ./Project_Lib/handle_task.su ./Project_Lib/uart_handle.cyclo ./Project_Lib/uart_handle.d ./Project_Lib/uart_handle.o ./Project_Lib/uart_handle.su

.PHONY: clean-Project_Lib

