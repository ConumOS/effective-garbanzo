[BITS 32]

section .text

global outl
global inl
global outb
global inb

; Envia 32 bits para uma porta
; void outl(uint16_t port, uint32_t data)
outl:
    mov edx, [esp + 4]    ; port
    mov eax, [esp + 8]    ; data
    out dx, eax
    ret

; Recebe 32 bits de uma porta
; uint32_t inl(uint16_t port)
inl:
    mov edx, [esp + 4]    ; port
    in eax, dx
    ret

; Envia 8 bits (útil para outros drivers como teclado)
; void outb(uint16_t port, uint8_t data)
outb:
    mov edx, [esp + 4]    ; port
    mov al, [esp + 8]     ; data
    out dx, al
    ret

; Recebe 8 bits
; uint8_t inb(uint16_t port)
inb:
    mov edx, [esp + 4]    ; port
    in al, dx
    ret
