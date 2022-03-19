################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include SPI/subdir.mk
-include MCAL/Timer/subdir.mk
-include MCAL/Interrupt/subdir.mk
-include MCAL/DIO/subdir.mk
-include HAL/LCD/subdir.mk
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
SPI_Rx.lss \

FLASH_IMAGE += \
SPI_Rx.hex \

SIZEDUMMY += \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: SPI_Rx.elf secondary-outputs

# Tool invocations
SPI_Rx.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SPI_Rx.map -mmcu=atmega32 -o "SPI_Rx.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SPI_Rx.lss: SPI_Rx.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SPI_Rx.elf  >"SPI_Rx.lss"
	@echo 'Finished building: $@'
	@echo ' '

SPI_Rx.hex: SPI_Rx.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SPI_Rx.elf  "SPI_Rx.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SPI_Rx.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 SPI_Rx.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: SPI_Rx.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -u -Uflash:w:SPI_Rx.hex:a -Ulfuse:w:0xff:m -Uhfuse:w:0xd9:m
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SPI_Rx.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
