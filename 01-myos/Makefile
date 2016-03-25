
ARMGNU ?= /opt/arm-2011.09-none-eabi/bin/arm-none-eabi-

COPS ?= -g3 -Wextra -fpic -Wall -O2 -ffreestanding -std=gnu99
COPS += -mcpu=arm1176jzf-s

LIB ?= -L/opt/arm-2011.09-none-eabi/arm-none-eabi/lib/ -L/opt/arm-2011.09-none-eabi/lib/gcc/arm-none-eabi/4.6.1/

gcc : myos.img

OBJS = boot.o 
OBJS += kernel.o 

clean :
	rm -f *.o
	rm -f *.bin
	rm -f *.hex
	rm -f *.elf
	rm -f *.list
	rm -f *.img


%.o : %.s
	$(ARMGNU)gcc $(COPS) -D__ASSEMBLY__ -c -o $@ $<
	
%.o : %.c
	$(ARMGNU)gcc $(COPS) $(LIB) -c -o $@ $<

myos.img : linker.ld $(OBJS)
	$(ARMGNU)ld $(OBJS) -T linker.ld -o myos.elf $(LIB) -lc -lgcc
	$(ARMGNU)objdump -D myos.elf > myos.list
	$(ARMGNU)objcopy myos.elf -O ihex myos.hex
	$(ARMGNU)objcopy myos.elf -O binary myos.bin
	$(ARMGNU)objcopy myos.elf -O binary myos.img
