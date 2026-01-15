#include <stdint.h>
#include "../drivers/vga.hpp"

extern "C" void isr_handler(uint32_t int_no, [[maybe_unused]] uint32_t err_code) {
    vga_print("CPU EXCEPTION: "); //

    char msg[4];
    msg[0] = '0' + (int_no / 10);
    msg[1] = '0' + (int_no % 10);
    msg[2] = '\n';
    msg[3] = 0;

    vga_print(msg);

    // Loop
    while (1) {
        asm volatile("hlt");
    }
}
