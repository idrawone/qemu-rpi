
ARMGNU ?= /opt/arm-2011.09-none-eabi/bin/arm-none-eabi-

PWD=$(shell pwd)
INCLUDEPATH ?= "$(PWD)/include"

COPS = -g3 -Wextra -fpic -Wall -O2 -ffreestanding -std=gnu99 -I $(INCLUDEPATH)
COPS += -mcpu=arm1176jzf-s

LIB = -L/opt/arm-2011.09-none-eabi/arm-none-eabi/lib/ -L/opt/arm-2011.09-none-eabi/lib/gcc/arm-none-eabi/4.6.1/

gcc : kernel.img

OBJS = build/startup.o 

OBJS += build/syscalls.o
OBJS += build/uart.o
OBJS += build/timer.o
OBJS += build/interrupts.o

OBJS += build/OS_Cpu_a.o
OBJS += build/OS_Cpu_c.o

OBJS += build/ucos_ii.o

OBJS += build/main.o
OBJS += build/userApp.o


clean :
	rm -f build/*.o
	rm -f *.bin
	rm -f *.hex
	rm -f *.elf
	rm -f *.list
	rm -f *.img
	rm -f build/*.bc


build/%.o : port/%.s
	$(ARMGNU)gcc $(COPS) -D__ASSEMBLY__ -c -o $@ $<
	
build/%.o : init/%.s
	$(ARMGNU)gcc $(COPS) -D__ASSEMBLY__ -c -o $@ $<
	
build/%.o : port/%.c
	$(ARMGNU)gcc $(COPS) $(LIB) -c -o $@ $<

build/%.o : bsp/%.c
	$(ARMGNU)gcc $(COPS) $(LIB) -c -o $@ $<
	
build/%.o : usrApp/%.c
	$(ARMGNU)gcc $(COPS) $(LIB) -c -o $@ $<

build/ucos_ii.o : ucos/ucos_ii.c
	$(ARMGNU)gcc $(COPS) $(LIB) ucos/ucos_ii.c -c -o build/ucos_ii.o

kernel.img : linker.ld $(OBJS)
	$(ARMGNU)ld $(OBJS) -T linker.ld -o ucos_bcm2835.elf $(LIB) -lc -lgcc
	$(ARMGNU)objdump -D ucos_bcm2835.elf > ucos_bcm2835.list
	$(ARMGNU)objcopy ucos_bcm2835.elf -O ihex ucos_bcm2835.hex
	$(ARMGNU)objcopy ucos_bcm2835.elf -O binary ucos_bcm2835.bin
	$(ARMGNU)objcopy ucos_bcm2835.elf -O binary kernel.img
