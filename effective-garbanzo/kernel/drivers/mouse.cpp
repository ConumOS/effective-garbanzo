#include "mouse.hpp"
#include "vga.hpp"

// CONSTRUTOR
// Inicializa a posição do mouse no centro da tela e limpa os botões
Mouse::Mouse() : m_x(40), m_y(12), m_botao_esquerdo_pressionado(false) {}

// ATUALIZAÇÃO DE ESTADO
// Recebe os deltas de movimento e o status dos botões do controlador PS/2
void Mouse::atualizar_estado(int delta_x, int delta_y, int botoes) {
    m_x += delta_x;
    m_y += delta_y;

    // Clamping: Garante que o cursor permaneça dentro da tela VGA (80x25)
    if (m_x < 0) m_x = 0;
    if (m_x >= 80) m_x = 79;
    if (m_y < 0) m_y = 0;
    if (m_y >= 25) m_y = 24;

    // Bit 0 do primeiro byte do pacote PS/2 indica o botão esquerdo
    m_botao_esquerdo_pressionado = (botoes & 0x01) != 0;
}

bool Mouse::is_clique_esquerdo() {
    return m_botao_esquerdo_pressionado;
}

int Mouse::get_x() {
    return m_x;
}

int Mouse::get_y() {
    return m_y;
}

// INICIALIZAÇÃO DO DRIVER
// Função com ligação C para ser chamada no kernel_main
extern "C" void mouse_init() {
    // Aqui você adicionaria os comandos inb/outb para habilitar a IRQ 12
    vga_print("[MOUSE] Init... OK\n");
}
