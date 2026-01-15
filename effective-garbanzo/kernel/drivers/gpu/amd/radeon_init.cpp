// kernel/drivers/gpu/amd/radeon_init.cpp
#include <stdint.h>

void radeon_init(uint8_t bus, uint8_t slot, uint8_t func) {
    // AMD costuma usar o BAR0 para VRAM e BAR2 para MMIO (ao contrário da NVIDIA)
    // É aqui que a engenharia reversa muda de direção.
}
