################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/KEYPAD/KEYPAD.c 

OBJS += \
./HAL/KEYPAD/KEYPAD.o 

C_DEPS += \
./HAL/KEYPAD/KEYPAD.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/KEYPAD/%.o: ../HAL/KEYPAD/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\Safe_Project\HAL" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\Safe_Project\HAL\KEYPAD" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\Safe_Project\HAL\LCD" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\Safe_Project\MCAL" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\Safe_Project\Safe" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\Safe_Project\STD" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


