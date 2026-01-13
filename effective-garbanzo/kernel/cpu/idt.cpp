#include "idt.hpp"

struct IDTEntry {
    uint16_t base_low;
    uint16_t selector;
    uint8_t zero;
    uint8_t flags;
    uint16_t base_high;
} ___atrtibute__((packed));


struct IDTPoniter {
    uint16_t limit;
    uint32_t base;
} ___atrtibute__((packed));


static IDTEntry idt[256];
static IDTPoniter idt_ptr;

extern "C" void isr_stub_table();

static void set_gate(int n, uint32_t handler) {

idt[n].base_low = handler & 0xFFFF;
idt[n].base_high = (handler >> 16) & 0xFFFF;
idt[n].selector = 0x08;
idt[n].zero     = 0;
idt[n].flags    = 0x8E;
}

extern "C" load_idt(uint32_t);


void idt_init() {
    idt_ptr.limit = sizeof(idt) - 1;
    idt_ptr.base  = (uint32_t)&idt;


    for (int i = 0; i < 256; i++)
        set_gate(i, (uint32_t)isr_stub_table);


    load_idt((uint32_t)&idt_ptr);
}