#include <stdint.h>
#include "../../../cpu/paging.hpp"

// Declaramos como extern "C" para linkar corretamente com o pci.o
extern "C" {
    void pci_write_config_32(uint8_t bus, uint8_t slot, uint8_t func, uint8_t offset, uint32_t value);
    uint32_t pci_read_config_32(uint8_t bus, uint8_t slot, uint8_t func, uint8_t offset);
}

using namespace paging;

void nv_init(uint8_t bus, uint8_t slot, uint8_t func) {
    // 1. Habilitar a placa no barramento PCI
    // Bus Master (bit 2) e Memory Space (bit 1)
    uint32_t cmd = pci_read_config_32(bus, slot, func, 0x04);
    pci_write_config_32(bus, slot, func, 0x04, cmd | 0x07);

    // 2. Mapear BAR0 (Registradores MMIO)
    uint32_t bar0_raw = pci_read_config_32(bus, slot, func, 0x10);
    uintptr_t bar0_phys = (uintptr_t)(bar0_raw & ~0xF);

    // Mapeamos 16MB para os registros de controle (PMC, PTIMER, etc)
    volatile uint32_t* regs = (volatile uint32_t*)paging::map_device(bar0_phys, 0x1000000);

    if (regs) {
        // Registro 0x000000 é o ID do hardware (PMC_BOOT_0)
        uint32_t gpu_id = regs[0];
        (void)gpu_id;
    }

    // 3. Mapear BAR1 (VRAM / Framebuffer)
    uint32_t bar1_raw = pci_read_config_32(bus, slot, func, 0x14);
    uintptr_t bar1_phys = (uintptr_t)(bar1_raw & ~0xF);

    // Mapeamos os primeiros 16MB da VRAM para teste de desenho
    uint32_t* fb = (uint32_t*)paging::map_device(bar1_phys, 0x1000000);

    if (fb) {
        // Pinta um bloco de 100.000 pixels de branco (ARGB: 0xFFFFFFFF)
        for (int i = 0; i < 100000; i++) {
            fb[i] = 0xFFFFFFFF;
        }
    }
}
