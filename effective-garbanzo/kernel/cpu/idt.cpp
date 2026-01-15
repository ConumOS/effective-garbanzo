#include "idt.hpp"

// Referência ao array definido em assembly
extern "C" void* isr_stub_table[256]; // apenas extern, **não define**

static IDTEntry idt[256];
static IDTPointer idt_ptr;

static void set_gate(int n, uint32_t handler) {
    idt[n].base_low  = handler & 0xFFFF;
    idt[n].sel       = 0x08;
    idt[n].always0   = 0;
    idt[n].flags     = 0x8E;
    idt[n].base_high = (handler >> 16) & 0xFFFF;
}

extern "C" void idt_init() {
    idt_ptr.limit = sizeof(idt) - 1;
    idt_ptr.base  = (uint32_t)&idt;

    for (int i = 0; i < 256; i++) {
        set_gate(i, (uint32_t)isr_stub_table[i]);
    }

    load_idt((uint32_t)&idt_ptr);
}
