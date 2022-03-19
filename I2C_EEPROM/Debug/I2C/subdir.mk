################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../I2C/I2C.c 

OBJS += \
./I2C/I2C.o 

C_DEPS += \
./I2C/I2C.d 


# Each subdirectory must supply rules for building sources it contributes
I2C/%.o: ../I2C/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\I2C_EEPROM\HAL\EEPROM" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\I2C_EEPROM\I2C" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\I2C_EEPROM\HAL\LCD" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\I2C_EEPROM\MCAL\DIO" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\I2C_EEPROM\MCAL\Interrupt" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\I2C_EEPROM\STD" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


