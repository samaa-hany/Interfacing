################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../UART/UART.c 

OBJS += \
./UART/UART.o 

C_DEPS += \
./UART/UART.d 


# Each subdirectory must supply rules for building sources it contributes
UART/%.o: ../UART/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\UART_Rx\MCAL\Interrupt" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\UART_Rx\LCD" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\UART_Rx\MCAL" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\UART_Rx\MCAL\DIO" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\UART_Rx\STD" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\UART_Rx\UART" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


