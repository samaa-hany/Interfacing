################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/SWITCH/SWITCH.c 

OBJS += \
./MCAL/SWITCH/SWITCH.o 

C_DEPS += \
./MCAL/SWITCH/SWITCH.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/SWITCH/%.o: ../MCAL/SWITCH/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\DIO\MCAL" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\DIO\MCAL\DIO" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\DIO\STD" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


