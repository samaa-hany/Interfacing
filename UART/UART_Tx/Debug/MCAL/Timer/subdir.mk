################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Timer/Timer.c 

OBJS += \
./MCAL/Timer/Timer.o 

C_DEPS += \
./MCAL/Timer/Timer.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Timer/%.o: ../MCAL/Timer/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\UART_Tx\MCAL\DIO" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\UART_Tx\MCAL\Interrupt" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\UART_Tx\STD" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\UART_Tx\UART" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


