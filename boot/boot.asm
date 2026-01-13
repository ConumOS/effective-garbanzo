; boot/boot.asm
 BITS 32
 GLOBAL _start
 EXTERN kernel_main


 SECTION .multiboot
 ALIGN 4
 dd 0x1BADB002
 dd 0
 dd -(0x1BADB002)


SECTION .text
_start:
    call kernel_main
    cli
    hlt