#pragma once
// kernel/multiboot.hpp
#include <stdint.h>  // Use the C header instead of <cstdint>

extern "C" {
    struct multiboot_header_t {
        uint32_t magic;
        uint32_t flags;
        uint32_t checksum;
    };

    // Reference the header defined in the .cpp file
    extern const multiboot_header_t multiboot_header;
}
