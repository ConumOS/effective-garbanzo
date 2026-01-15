; boot/boot.asm
section .multiboot
align 4
    dd 0x1BADB002              ; Magic number
    dd 0x03                    ; Flags (ALIGN + MEMINFO)
    dd -(0x1BADB002 + 0x03)    ; Checksum

section .bss
align 16
stack_bottom:
    resb 16384 ; 16 KB
stack_top:

section .text
global _start
extern kernel_main

_start:
    mov esp, stack_top
    call kernel_main

    cli
.hang:
    hlt
    jmp .hang
