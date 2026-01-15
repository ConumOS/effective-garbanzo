#include "paging.hpp"
#include <stdint.h>
#include <stddef.h>

namespace paging {

static uintptr_t next_device_vaddr = 0xD0000000;

// Lembre-se que map_page deve estar declarado no seu paging.hpp
extern void paging::map_page(uintptr_t phys, uintptr_t virt, uint32_t flags);

void* map_device(uintptr_t physical_addr, size_t size) {
    uintptr_t offset = physical_addr % 4096;
    uintptr_t aligned_phys = physical_addr - offset;

    // O erro do size_t acontecia aqui
    size_t num_pages = (size + offset + 4095) / 4096;

    uintptr_t start_vaddr = next_device_vaddr;

    for (size_t i = 0; i < num_pages; i++) {
        uintptr_t phys = aligned_phys + (i * 4096);
        uintptr_t virt = start_vaddr + (i * 4096);

        // Present | Writable | Write-Through | Cache Disable
        uint32_t mmio_flags = 0x1 | 0x2 | 0x08 | 0x10;

        map_page(phys, virt, mmio_flags);
    }

    next_device_vaddr += (num_pages * 4096);

    return (void*)(start_vaddr + offset);
}

} // namespace paging
