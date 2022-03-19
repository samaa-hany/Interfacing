################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/DIO.c \
../MCAL/DIO_Confg.c 

OBJS += \
./MCAL/DIO.o \
./MCAL/DIO_Confg.o 

C_DEPS += \
./MCAL/DIO.d \
./MCAL/DIO_Confg.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o: ../MCAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\LCD\LCD" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\LCD" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\LCD\MCAL" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\LCD\STD" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


