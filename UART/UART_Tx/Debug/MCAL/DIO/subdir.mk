################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/DIO/DIO.c \
../MCAL/DIO/DIO_Confg.c 

OBJS += \
./MCAL/DIO/DIO.o \
./MCAL/DIO/DIO_Confg.o 

C_DEPS += \
./MCAL/DIO/DIO.d \
./MCAL/DIO/DIO_Confg.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/DIO/%.o: ../MCAL/DIO/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\UART_Tx\MCAL\DIO" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\UART_Tx\MCAL\Interrupt" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\UART_Tx\STD" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\UART_Tx\UART" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


