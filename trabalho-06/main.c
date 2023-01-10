// T6 - Bruna Caetano

// gcc -Wall -o main main.c tela.c -lallegro_font -lallegro_color -lallegro_ttf -lallegro_primitives -lallegro
#include "tela.h"

#include <stdlib.h>
#include <stdio.h>

void jogo(){

}

void visual(){
    tela_retangulo(30, 30, 470, 470, 5, preto, transparente);

    // faz uma linha se o botão do mouse tiver apertado
    if (tela_rato_apertado()) {
        tela_circulo(tela_rato_x(), tela_rato_y(), 10, 2, azul, branco);
    }

    // desenha um círculo na posição do mouse
    tela_circulo(tela_rato_x(), tela_rato_y(), 10, 2, vermelho, branco);

    // escreve o valor do relógio no canto da tela
    char txt[10];
    sprintf(txt, "%.1f", relogio());
    tela_texto_esq(950, 445, 20, azul, txt);

    tela_atualiza();
}

int main(){
    tela_inicio(1000, 500, "Jogo Mastermind");

    do{
        visual();
        jogo();
    } while (tela_tecla() == '\0');

    tela_fim();

    return 0;
}