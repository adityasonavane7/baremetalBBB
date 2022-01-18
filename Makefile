PATH_TO_CROSS_COMPILE = /home/aditya/beaglebone/gcc-arm-none-eabi-10.3-2021.10-x86_64-linux/gcc-arm-none-eabi-10.3-2021.10/bin/

CROSS_COMPILE = $(PATH_TO_CROSS_COMPILE)arm-none-eabi-

CC = $(CROSS_COMPILE)gcc
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJDUMP = $(CROSS_COMPILE)objdump
LINK = $(CROSS_COMPILE)ld
target_flags  = -mcpu=cortex-a8
# Compile for ARM CORTEX A8

# CORTEX A8 has a neon floating point implementation
target_flags += -mfpu=neon -mfloat-abi=hard -I include -nostdlib

#Common Flags
target_flags += -Wall -Wextra -O -g -static -ffreestanding -v
target_flags += -fbuiltin -marm -Xlinker -Map=output/logs/linkedElf.map

all: init.elf create-binary create-MLO

init.elf:src/initCode/init.S src/gpioSetup/main.c
	@$(CC) $(target_flags) -T Linker/linker.ld src/gpioSetup/main.c src/initCode/init.S -o output/main.elf

dump:
	$(OBJDUMP) -d output/main.elf

dump-all: 
	$(OBJDUMP) -D output/main.out

create-binary:
	$(OBJCOPY) -O binary output/main.elf output/main.bin

create-MLO:
	python3 Linker/MLOCreator.py

clean: 
	@rm output/*.*
	