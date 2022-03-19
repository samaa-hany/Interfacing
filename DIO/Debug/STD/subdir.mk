################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STD/main.c 

OBJS += \
./STD/main.o 

C_DEPS += \
./STD/main.d 


# Each subdirectory must supply rules for building sources it contributes
STD/%.o: ../STD/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\DIO\APP" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\DIO\HAL\KEYPAD" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\DIO\HAL\SEV_SEG" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\DIO\MCAL\DIO" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\DIO\MCAL\SWITCH" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\DIO\HAL" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\DIO\MCAL" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\DIO\STD" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


