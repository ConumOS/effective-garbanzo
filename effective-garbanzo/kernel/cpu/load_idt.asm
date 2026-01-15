; kernel/cpu/load_idt.asm
; Função para carregar a IDT
; Recebe o endereço de um IDTPointer em EAX (convenção cdecl)
; Compilar com: nasm -f elf32 load_idt.asm -o load_idt.o

global load_idt
section .text

load_idt:
    ; a função recebe o ponteiro da IDT como argumento na pilha
    ; conv cdecl: [esp + 4] = endereço do IDTPointer
    mov eax, [esp + 4]  ; pegar endereço do IDTPointer
    lidt [eax]          ; carregar IDT
    ret                 ; retornar para a função chamadora
