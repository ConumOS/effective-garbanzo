#include <stdint.h>

namespace USB {
    struct KeyboardReport {
        uint8_t modifiers;
        uint8_t reserved;
        uint8_t keys[6];
    } __attribute__((packed));

    void handle_keyboard(KeyboardReport* report) {
        // Exemplo: Se keys[0] == 0x04, o usuário pressionou 'A'
        for(int i = 0; i < 6; i++) {
            if(report->keys[i] != 0) {
                // Aqui você enviaria o caractere para o seu terminal VGA
            }
        }
    }
}
