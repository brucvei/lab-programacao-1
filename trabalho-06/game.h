#ifndef _game_h_  // para evitar problemas coma inclusão múltipla deste arquivo
#define _game_h_

struct ESTADO {
    int chances;
    int chutes[4][8];
    int cores[4];
    bool acertou;
    bool desistiu;
    bool nao;
} estado;

// Sorteia as cores
void sorteia(int *vetor);

// Inicia a partida, seta as variáveis
void partida(void);

// Inicia o jogo
void jogo(void);
     

#endif