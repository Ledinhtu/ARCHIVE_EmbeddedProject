################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/Source/portable/GCC/ARM_CM3/port.c 

OBJS += \
./FreeRTOS/Source/portable/GCC/ARM_CM3/port.o 

C_DEPS += \
./FreeRTOS/Source/portable/GCC/ARM_CM3/port.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/Source/portable/GCC/ARM_CM3/%.o FreeRTOS/Source/portable/GCC/ARM_CM3/%.su FreeRTOS/Source/portable/GCC/ARM_CM3/%.cyclo: ../FreeRTOS/Source/portable/GCC/ARM_CM3/%.c FreeRTOS/Source/portable/GCC/ARM_CM3/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/STM32/CubeIDE/FreeRTOS_BD/FreeRTOS/Source/include" -I"D:/STM32/CubeIDE/FreeRTOS_BD/FreeRTOS/Source/portable/GCC/ARM_CM3" -I"D:/STM32/CubeIDE/FreeRTOS_BD/FreeRTOS/Source/portable/MemMang" -I"D:/STM32/CubeIDE/FreeRTOS_BD/FreeRTOS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-FreeRTOS-2f-Source-2f-portable-2f-GCC-2f-ARM_CM3

clean-FreeRTOS-2f-Source-2f-portable-2f-GCC-2f-ARM_CM3:
	-$(RM) ./FreeRTOS/Source/portable/GCC/ARM_CM3/port.cyclo ./FreeRTOS/Source/portable/GCC/ARM_CM3/port.d ./FreeRTOS/Source/portable/GCC/ARM_CM3/port.o ./FreeRTOS/Source/portable/GCC/ARM_CM3/port.su

.PHONY: clean-FreeRTOS-2f-Source-2f-portable-2f-GCC-2f-ARM_CM3

