#ifndef MOUSE_HPP
#define MOUSE_HPP

class Mouse {
public:
    Mouse(); // <--- Adicione esta linha aqui
    void atualizar_estado(int x, int y, int botoes);
    bool is_clique_esquerdo();
    int get_x();
    int get_y();

private:
    int m_x;
    int m_y;
    bool m_botao_esquerdo_pressionado;
};

#endif // MOUSE_HPP
