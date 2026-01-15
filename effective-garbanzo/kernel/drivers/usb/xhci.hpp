#pragma once
#include <stdint.h>

namespace USB {
    // TRB: Transfer Request Block
    struct TRB {
        uint64_t parameter;
        uint32_t status;
        uint32_t control;
    } __attribute__((packed));

    struct XHCI_Regs {
        volatile uint32_t usb_cmd;
        volatile uint32_t usb_sts;
        volatile uint32_t page_size;
        uint32_t res1[2];
        volatile uint32_t dn_ctrl;
        volatile uint64_t crcr;   // Command Ring Control Register
        uint32_t res2[4];
        volatile uint64_t dcbaap; // Device Context Base Address Array
        volatile uint32_t config;
    } __attribute__((packed));

    class XHCI {
    public:
        XHCI(uintptr_t bar);
        void init();
        void ring_doorbell(uint32_t slot);
    private:
        XHCI_Regs* regs;
        TRB* cmd_ring;
        uint64_t* dcbaa;
    };
}
