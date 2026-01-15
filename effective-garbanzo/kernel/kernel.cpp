#include "drivers/vga.hpp"
#include "drivers/keyboard.hpp"
#include "cpu/idt.hpp"
#include "cpu/paging.hpp"
#include "cpu/pic.hpp"
#include "scheduler/scheduler.hpp"
#include "fs/fs.hpp"
#include "net/ethernet.hpp"
#include "net/tcpip.hpp"
#include "drivers/usb/xhci.hpp"
#include "drivers/pci.hpp"
#include <stdint.h>

// Protótipos das funções de inicialização (definidas em drivers/gpu/...)
// Usamos extern para o linker encontrar os símbolos nos outros arquivos .o
extern void nv_init(uint8_t bus, uint8_t slot, uint8_t func);
extern void intel_init(uint8_t bus, uint8_t slot, uint8_t func);
extern void radeon_init(uint8_t bus, uint8_t slot, uint8_t func);

/**
 * Varre o barramento PCI em busca de controladores gráficos (Class Code 0x03)
 * ou por Vendor IDs específicos.
 */
void pci_scan_graphics() {
    for (uint16_t bus = 0; bus < 256; bus++) {
        for (uint8_t slot = 0; slot < 32; slot++) {
            // Lê o primeiro registro do dispositivo (Vendor ID e Device ID)
            uint32_t pci_data = pci_read_config_32(bus, slot, 0, 0);
            uint16_t vendor = pci_data & 0xFFFF;

            if (vendor == 0xFFFF) continue; // Nenhum dispositivo neste slot

            // Identifica o fabricante e chama o driver correspondente
            if (vendor == 0x10DE) {      // NVIDIA
                nv_init(bus, slot, 0);
            }
            else if (vendor == 0x8086) { // Intel
                intel_init(bus, slot, 0);
            }
            else if (vendor == 0x1002) { // AMD / ATI
                radeon_init(bus, slot, 0);
            }
        }
    }
}

extern "C" void kernel_main() {
    // 1. Aqui você deve inicializar GDT, IDT e Paging primeiro.
    // O sistema de paginação é obrigatório para o nv_init funcionar (map_device).

    // 2. Busca e inicializa a GPU
    pci_scan_graphics();

    // 3. O Kernel terminou a carga básica.
    // Se o nv_init funcionou, você verá a alteração na tela (VRAM pintada).
    while (1) {
        // Halt ou loop de eventos
        __asm__ volatile("hlt");
    }
}
