################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SOURCE/ADC_PROGRAM.c \
../SOURCE/DIO_PROGRAM.c \
../SOURCE/EXTI_PROGRAM.c \
../SOURCE/GI_PROGRAM.c \
../SOURCE/KEYPAD_PROGRAM.c \
../SOURCE/LCD_PROGRAM.c \
../SOURCE/TIMER1_PROGRAM.c \
../SOURCE/TIMER_PROGRAM.c \
../SOURCE/UART_PROGRAM.c \
../SOURCE/WDT_PROGRAM.c \
../SOURCE/main.c 

OBJS += \
./SOURCE/ADC_PROGRAM.o \
./SOURCE/DIO_PROGRAM.o \
./SOURCE/EXTI_PROGRAM.o \
./SOURCE/GI_PROGRAM.o \
./SOURCE/KEYPAD_PROGRAM.o \
./SOURCE/LCD_PROGRAM.o \
./SOURCE/TIMER1_PROGRAM.o \
./SOURCE/TIMER_PROGRAM.o \
./SOURCE/UART_PROGRAM.o \
./SOURCE/WDT_PROGRAM.o \
./SOURCE/main.o 

C_DEPS += \
./SOURCE/ADC_PROGRAM.d \
./SOURCE/DIO_PROGRAM.d \
./SOURCE/EXTI_PROGRAM.d \
./SOURCE/GI_PROGRAM.d \
./SOURCE/KEYPAD_PROGRAM.d \
./SOURCE/LCD_PROGRAM.d \
./SOURCE/TIMER1_PROGRAM.d \
./SOURCE/TIMER_PROGRAM.d \
./SOURCE/UART_PROGRAM.d \
./SOURCE/WDT_PROGRAM.d \
./SOURCE/main.d 


# Each subdirectory must supply rules for building sources it contributes
SOURCE/%.o: ../SOURCE/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


