################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include UART/subdir.mk
-include MCAL/Timer/subdir.mk
-include MCAL/Interrupt/subdir.mk
-include MCAL/DIO/subdir.mk
-include LCD/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
UART_Rx.lss \

FLASH_IMAGE += \
UART_Rx.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: UART_Rx.elf secondary-outputs

# Tool invocations
UART_Rx.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,UART_Rx.map -mmcu=atmega16 -o "UART_Rx.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

UART_Rx.lss: UART_Rx.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S UART_Rx.elf  >"UART_Rx.lss"
	@echo 'Finished building: $@'
	@echo ' '

UART_Rx.hex: UART_Rx.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex UART_Rx.elf  "UART_Rx.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: UART_Rx.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 UART_Rx.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: UART_Rx.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm16 -cusbasp -u -Uflash:w:UART_Rx.hex:a -Ulfuse:w:0xff:m -Uhfuse:w:0xd9:m
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) UART_Rx.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
