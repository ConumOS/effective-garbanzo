// kernel/drivers/gpu/intel/i915_gem.cpp
#include <stdint.h>
#include "../../pci.hpp"

void intel_init(uint8_t bus, uint8_t slot, uint8_t func) {
    // BAR0 na Intel também são os registradores MMIO
    uint32_t bar0 = pci_read_config_32(bus, slot, func, 0x10);
    // Próximo passo seria configurar o GTT para acessar a VRAM roubada da RAM
}
