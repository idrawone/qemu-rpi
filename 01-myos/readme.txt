###################################################################################
###  http://wiki.osdev.org/Raspberry_Pi_Bare_Bones
###################################################################################

### to set the cross-compile 
$ export PATH=/opt/arm-2011.09-none-eabi/bin:$PATH

### to build
$ make

### to test, run command below first
$ ../tools/qemu-system-arm -cpu arm1176 -m 128 -M raspi -s -S -nographic -kernel myos.elf

### in the 2nd terminal
$ export PATH=/opt/arm-2011.09-none-eabi/bin:$PATH 
$ arm-none-eabi-gdb
(gdb) target remote localhost:1234
Remote debugging using localhost:1234
0x00008000 in ?? ()
(gdb) c
Continuing.

### in the 1st terminal
Hello, kernel World!

### to tear down
killall -9 qemu-system-arm

### use gdb to debug the soure code
(gdb) file myos.elf 
A program is being debugged already.
Are you sure you want to change the file? (y or n) y
Reading symbols from /home/utop/qemu-rpi/01-myos/myos.elf...done.
(gdb) c
Continuing.
^C
Program received signal SIGINT, Interrupt.
0x00008118 in mmio_read () at kernel.c:122
122 {
    (gdb) l
    117     while ( mmio_read(UART0_FR) & (1 << 5) ) { }
    118     mmio_write(UART0_DR, byte);
    119 }
    120  
    121 unsigned char uart_getc()
    122 {
        123     // Wait for UART to have recieved something.
        124     while ( mmio_read(UART0_FR) & (1 << 4) ) { }
        125     return mmio_read(UART0_DR);
        126 }
        (gdb) 

