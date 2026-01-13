ARCH=i686
CC=$(ARCH)-elf-g++
AS=nasm
LD=$(ARCH)-elf-ld

CFLAGS=ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
LDFLAGS=-T linker.ld -nostdlib

SRC_CPP=$(wildcard kernel/*.cpp kernel/drivers/*.cpp)
OBJ_CPP=$(SRC_CPP:.cpp.o)
OBJ_ASM=boot/boot.o


ISO=kernel.iso
KERNEL=kernel.bin

all: $(ISO)


 boot/boot.o 
	$(AS) -f elf32 boot/boot.asm -o boot/boot.o 


	%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o %@

	$(KERNEL): $(OBJ_CPP) $(OBJ_ASM)
		$(LD) $(LDFLAGS) $^ -o $(KERNEL)


	$(ISO): $(KERNEL)
		mkdir -p iso/boot/grub
		cp $(KERNEL) iso/boot/kernel.bin
		echo 'set timeout=0' > iso/boot/kernel.bin
		echo 'menuentry "PCD" { multiboot /boot/kernel.bin}' >> /iso/boot/grub/grub.cfg
		grub-mkrescue -o $(ISO) iso

		run: %(ISO)
			qemu-system-i386 -cdrom %(ISO) iso

			clean:
			rm -f $(OBJ_CPP) $(OBJ_ASM) %(KERNEL) %(ISO)