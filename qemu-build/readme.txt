### In 01-myos, I use a USB-232 cable connect to RPI B+ UART1 as the debug console 
# any c file which implements UARTx recv/send need to be changed correspondingly
# such as the kernel.c in 01-myos

### below is the qemu repository information used to rebuild the qemu-system-arm
$ cat .git/config
[core]
        repositoryformatversion = 0
        filemode = true
        bare = false
        logallrefupdates = true
[remote "origin"]
        fetch = +refs/heads/*:refs/remotes/origin/*
        url = https://github.com/Torlus/qemu.git
[branch "master"]
        remote = origin
        merge = refs/heads/master
[branch "rpi"]
        remote = origin
        merge = refs/heads/rpi
[submodule "dtc"]
        url = git://git.qemu-project.org/dtc.git

### replace UART0_BASE to UART1_BASE for raspi, then rebuild
$ vim hw/arm/raspi.c 
    /* UART */
    dev = sysbus_create_simple("pl011", UART1_BASE, pic[INTERRUPT_VC_UART]);
    s = SYS_BUS_DEVICE(dev);
    mr = sysbus_mmio_get_region(s, 0);
    memory_region_init_alias(per_uart_bus, NULL, NULL, mr,
        0, memory_region_size(mr));
    memory_region_add_subregion(sysmem, BUS_ADDR(UART1_BASE),
        per_uart_bus);

$./configure --target-list=arm-softmmu

make

make install #maybe needed
