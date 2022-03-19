################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LCD/LCD.c \
../HAL/LCD/LCD_Confg.c 

OBJS += \
./HAL/LCD/LCD.o \
./HAL/LCD/LCD_Confg.o 

C_DEPS += \
./HAL/LCD/LCD.d \
./HAL/LCD/LCD_Confg.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/LCD/%.o: ../HAL/LCD/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\SPI_Rx\HAL\LCD" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\SPI_Rx\MCAL\DIO" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\SPI_Rx\MCAL\Interrupt" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\SPI_Rx\SPI" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\SPI_Rx\STD" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


