#include "xhci.hpp"

namespace USB {
    class USBManager {
    public:
        void probe_ports(XHCI* controller) {
            (void) controller; // Varre as portas físicas do controlador
            // Se detectar conexão:
            // 1. Reset Port
            // 2. Enable Slot
            // 3. Address Device
            // 4. Get Descriptor
        }
    };
}
