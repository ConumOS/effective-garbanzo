ARCH=i686
CC=$(ARCH)-elf-g++
AS=nasm
LD=$(ARCH)-elf-ld

CFLAGS=-ffreestanding -O2 -Wall -Wextra -fno-exceptions -fno-rtti
LDFLAGS=-T linker.ld -nostdlib

SRC_CPP=$(shell find kernel -name "*.cpp")
SRC_ASM=$(shell find boot -name "*.asm")

OBJ_CPP=$(SRC_CPP:.cpp=.o)
OBJ_ASM=$(SRC_ASM:.asm=.o)

KERNEL=kernel.bin
ISO=kernel.iso

all: $(ISO)

boot/boot.o: boot/boot.asm
	$(AS) -f elf32 $< -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(KERNEL): $(OBJ_CPP) $(OBJ_ASM)
	$(LD) $(LDFLAGS) $^ -o $@

$(ISO): $(KERNEL)
	mkdir -p iso/boot/grub
	cp $(KERNEL) iso/boot/kernel.bin
	echo 'set timeout=0' > iso/boot/grub/grub.cfg
	echo 'menuentry "PCD" { multiboot /boot/kernel.bin }' >> iso/boot/grub/grub.cfg
	grub-mkrescue -o $(ISO) iso

run: $(ISO)
	qemu-system-i386 -cdrom $(ISO)

clean:
	rm -f $(OBJ_CPP) $(OBJ_ASM) $(KERNEL) $(ISO)
