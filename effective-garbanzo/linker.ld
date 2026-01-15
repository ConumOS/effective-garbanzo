/* O ponto de entrada é o _start do boot.asm */
ENTRY(_start)

SECTIONS
{
    /* O kernel será carregado em 1MB, padrão para Multiboot */
    . = 1M;

    .text ALIGN(4K) :
    {
        /* Garante que o cabeçalho Multiboot esteja no início do arquivo */
        KEEP(*(.multiboot))
        *(.text*)
    }

    .rodata ALIGN(4K) :
    {
        *(.rodata*)
    }

    .data ALIGN(4K) :
    {
        *(.data*)
    }

    .bss ALIGN(4K) :
    {
        *(COMMON)
        *(.bss*)
    }
}
