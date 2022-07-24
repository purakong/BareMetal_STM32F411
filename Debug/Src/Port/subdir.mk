################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/Port/port.c 

OBJS += \
./Src/Port/port.o 

C_DEPS += \
./Src/Port/port.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Port/%.o: ../Src/Port/%.c Src/Port/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Port

clean-Src-2f-Port:
	-$(RM) ./Src/Port/port.d ./Src/Port/port.o

.PHONY: clean-Src-2f-Port

