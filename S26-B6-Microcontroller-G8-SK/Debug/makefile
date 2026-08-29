################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include SOURCE/subdir.mk
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
S26-B6-Microcontroller-G8-SK.lss \

FLASH_IMAGE += \
S26-B6-Microcontroller-G8-SK.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: S26-B6-Microcontroller-G8-SK.elf secondary-outputs

# Tool invocations
S26-B6-Microcontroller-G8-SK.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,S26-B6-Microcontroller-G8-SK.map -mmcu=atmega32 -o "S26-B6-Microcontroller-G8-SK.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

S26-B6-Microcontroller-G8-SK.lss: S26-B6-Microcontroller-G8-SK.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S S26-B6-Microcontroller-G8-SK.elf  >"S26-B6-Microcontroller-G8-SK.lss"
	@echo 'Finished building: $@'
	@echo ' '

S26-B6-Microcontroller-G8-SK.hex: S26-B6-Microcontroller-G8-SK.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex S26-B6-Microcontroller-G8-SK.elf  "S26-B6-Microcontroller-G8-SK.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: S26-B6-Microcontroller-G8-SK.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 S26-B6-Microcontroller-G8-SK.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) S26-B6-Microcontroller-G8-SK.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
