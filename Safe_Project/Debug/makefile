################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Safe/subdir.mk
-include MCAL/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KEYPAD/subdir.mk
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
Safe_Project.lss \
Safe_Project.lss \
Safe_Project.lss \

FLASH_IMAGE += \
Safe_Project.hex \

SIZEDUMMY += \
sizedummy \
sizedummy \
sizedummy \

AVRDUDEDUMMY += \
avrdudedummy \


# All Target
all: Safe_Project.elf secondary-outputs

# Tool invocations
Safe_Project.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Safe_Project.map -mmcu=atmega32 -o "Safe_Project.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Safe_Project.lss: Safe_Project.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Safe_Project.elf  >"Safe_Project.lss"
	@echo 'Finished building: $@'
	@echo ' '

Safe_Project.hex: Safe_Project.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Safe_Project.elf  "Safe_Project.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Safe_Project.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Safe_Project.elf
	@echo 'Finished building: $@'
	@echo ' '

avrdudedummy: Safe_Project.elf
	@echo 'Invoking: AVRDude'
	C:\WinAVR-20100110\bin\avrdude -pm32 -cusbasp -u -Uflash:w:Safe_Project.hex:a -Ulfuse:w:0xff:m -Uhfuse:w:0xd9:m
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(AVRDUDEDUMMY)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Safe_Project.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY) $(AVRDUDEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
