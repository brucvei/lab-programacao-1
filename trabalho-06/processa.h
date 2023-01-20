#ifndef _game_h_  // para evitar problemas coma inclusão múltipla deste arquivo
#define _game_h_


typedef struct {
    float x, y;
} ponto;

typedef struct {
    ponto centro;
    float raio;
    int cor;
} circulo;

// ENTRADA DE DADOS
// retorna a posição x do mouse
float tela_rato_x(void);

// retorna a posição y do mouse
float tela_rato_y(void);

// retorna se o botão do mouse está apertado
bool tela_rato_apertado(void);

// retorna se o botão do mouse foi clicado (apertado e solto) desde a última
// chamada a esta função
bool tela_rato_clicado(void);

// retorna a posição x do mouse na última vez que ele foi clicado
float tela_rato_x_clique(void);

// retorna a posição y do mouse na última vez que ele foi clicado
float tela_rato_y_clique(void);

// retorna uma tecla digitada
// pode retornar um caractere imprimível ou '\b' para backspace ou '\n' para
// enter ou '\0' para qualquer outra coisa ou se não tiver sido digitado nada.
// char tela_tecla(void);

// cria o array dos circulos
void cria_array_circulos(int n, circulo circulos[n]);

// retorna se o ponto está dentro do círculo
bool ponto_no_circulo(ponto p, circulo c);

// retorna o índice do circulo do vetor no qual está o ponto, ou -1 se não tiver em nenhum deles
int circulo_no_ponto(int n, circulo circulos[n], ponto p);

#endif