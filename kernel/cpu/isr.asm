BITS 32
GLOBAL isr_stub_table
GLOBAL load_idt


isr_stub_table:
    iret


load_idt:
    mov eax, [exp + 4]
    lidt [eax]
    ret