################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SEV_SEG/SEV_SEG.c 

OBJS += \
./SEV_SEG/SEV_SEG.o 

C_DEPS += \
./SEV_SEG/SEV_SEG.d 


# Each subdirectory must supply rules for building sources it contributes
SEV_SEG/%.o: ../SEV_SEG/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\Traffic_Light\MCAL" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\Traffic_Light\Traffic" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\Traffic_Light\SEV_SEG" -I"D:\ITI_Programs\embedded_interfacing_emvironment\eclipse\workspace\Traffic_Light\STD" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


