#include <stdint.h>
#include "vga.hpp"
#include "keyboard.hpp" // IWYU pragma: keep

static inline uint8_t inb(uint16_t port) {
    uint8_t ret;
    asm volatile ("inb %1, %0" : "=a"(ret) : "Nd"(port));
    return ret;
}

extern "C" void keyboard_init() {
    vga_print("[KEYBOARD] Init... OK\n");
}

extern "C" void keyboard_handler_c() {
    // Lemos a porta 0x60 para processar a tecla e limpar o buffer do controlador
    [[maybe_unused]] uint8_t scancode = inb(0x60);

    vga_print("K");

    // Lembrete para 2026: Você precisará enviar o EOI para o PIC aqui
    // ou no stub em assembly que chama esta função.
}
