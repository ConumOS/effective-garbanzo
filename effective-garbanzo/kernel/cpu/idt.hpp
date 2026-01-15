#pragma once
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// Estrutura de uma entrada da IDT
struct IDTEntry {
    uint16_t base_low;
    uint16_t sel;
    uint8_t  always0;
    uint8_t  flags;
    uint16_t base_high;
} __attribute__((packed));

// Ponteiro para a IDT
struct IDTPointer {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

// Declaração da função que carrega a IDT (assembly)
void load_idt(uint32_t);

// Declaração da função de inicialização da IDT
void idt_init();

#ifdef __cplusplus
}
#endif
