#include "multiboot.hpp"

extern "C" {
    // Standard Multiboot 1 values
    const uint32_t MAGIC = 0x1BADB002;
    const uint32_t FLAGS = 0x00000000;

    __attribute__((section(".multiboot"), used))
    const multiboot_header_t multiboot_header = {
        .magic    = MAGIC,
        .flags    = FLAGS,
        .checksum = -(MAGIC + FLAGS)
    };
}
