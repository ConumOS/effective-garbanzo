#include "xhci.hpp"

using namespace USB;

XHCI::XHCI(uintptr_t bar) {
    uint8_t cap_len = *(volatile uint8_t*)bar;
    regs = (XHCI_Regs*)(bar + cap_len);
}

void XHCI::init() {
    // 1. Reset do controlador
    regs->usb_cmd &= ~1; // Para o controlador
    while(!(regs->usb_sts & 1));
    regs->usb_cmd |= 2;  // Reset
    while(regs->usb_cmd & 2);

    // 2. Configura Device Context Base Address Array (DCBAA)
    // Nota: Em um kernel real, use seu PMM para alocar memória física!
    dcbaa = (uint64_t*)0x2000000;
    regs->dcbaap = (uintptr_t)dcbaa;

    // 3. Configura o Command Ring
    cmd_ring = (TRB*)0x2001000;
    regs->crcr = (uintptr_t)cmd_ring | 1;

    // 4. Inicia o controlador
    regs->usb_cmd |= 1;
    while(regs->usb_sts & 1);
}
