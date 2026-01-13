// kernel/kernel.cpp
#include "drivers/vga.hpp"
#include "drivers/keyboard.hpp"

extern "C" void kernel_main() {
 vga_print("LOAD KERNEL.... OK")};
 keyboard_init();



   while (1) {
	asm volatile ("htl");
 }

}

