#include "pci.hpp"

// Essas funções devem estar no seu io.asm / io.o
extern "C" void outl(uint16_t port, uint32_t data);
extern "C" uint32_t inl(uint16_t port);

uint32_t pci_read_config_32(uint8_t bus, uint8_t slot, uint8_t func, uint8_t offset) {
    uint32_t address = (uint32_t)((bus << 16) | (slot << 11) | (func << 8) | (offset & 0xFC) | ((uint32_t)0x80000000));
    outl(0xCF8, address);
    return inl(0xCFC);
}

void pci_write_config_32(uint8_t bus, uint8_t slot, uint8_t func, uint8_t offset, uint32_t value) {
    uint32_t address = (uint32_t)((bus << 16) | (slot << 11) | (func << 8) | (offset & 0xFC) | ((uint32_t)0x80000000));
    outl(0xCF8, address);
    outl(0xCFC, value);
}
