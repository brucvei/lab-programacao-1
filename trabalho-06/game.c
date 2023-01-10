// inclui as definicoes
#include "tela.h"
#include "game.h"
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

// Os includes do allegro
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

struct ESTADO
{
    int chances;
    char chutes[5][8];
    char cores[5];
    bool acertou;
    bool desistiu;
    bool nao;
} estado;

void sorteia(char *letras[], char *resultado) {
    int vet[4], i = 0, igual;
    srand(time(NULL));

    do { 
        vet[i] = rand() % 6; 
        igual = 0;
        for(int j = 0; j < i; j++){ 
            if(vet[j] == vet[i]) igual = 1; 
        }

        if(igual == 0) i++;
    } 
    while(i < 4);

    for (i = 0; i < 4; i++) {
        strcat(resultado, letras[vet[i]]);
    }
}

void partida(){
    printf("Partida\n");

    estado.chances = 9;
    estado.acertou = false;
    estado.desistiu = false;
    estado.nao = false; 
    sorteia((char*[]){"v", "l", "a", "e", "z", "n", "i"}, estado.cores);

    printf("Jogo\n");
    tela_jogo();
    tela_atualiza();
}

void tela_jogo(){
    printf("telajogo\n");

    // desenha as cores nos retangulos
    tela_retangulo(LARGURA-10, ALTURA-60, LARGURA-60, ALTURA-10, 0, azul, azul);
    tela_retangulo(LARGURA-70, ALTURA-60, LARGURA-120, ALTURA-10, 0, vermelho, vermelho);
    tela_retangulo(LARGURA-130, ALTURA-60, LARGURA-180, ALTURA-10, 0, verde, verde);
    tela_retangulo(LARGURA-190, ALTURA-60, LARGURA-240, ALTURA-10, 0, amarelo, amarelo);
    tela_retangulo(LARGURA-250, ALTURA-60, LARGURA-300, ALTURA-10, 0, laranja, laranja);
    tela_retangulo(LARGURA-310, ALTURA-60, LARGURA-360, ALTURA-10, 0, rosa, rosa);
    tela_retangulo(LARGURA-370, ALTURA-60, LARGURA-420, ALTURA-10, 0, marrom, marrom);

    tela_atualiza();

}

void jogo(){
    tela_inicio(LARGURA, ALTURA, "Jogo Mastermind");

    do{
        tela_inicial();

        if (tela_rato_apertado()) {
            if(tela_rato_x() >= 450 && tela_rato_x() <= 490 && tela_rato_y() >= 230 && tela_rato_y() <= 250){
                partida();
            } else if(tela_rato_x() >= 500 && tela_rato_x() <= 540 && tela_rato_y() >= 230 && tela_rato_y() <= 250){
                estado.nao = true;
            }
        }
    } while (estado.nao == false);

    tela_fim();
}

void tela_inicial(){
    printf("Tela inicial\n");
    // desenha a tela inicial
    tela_texto(500, 200, 20, branco, "Deseja iniciar uma partida?");
    
    tela_retangulo(450, 230, 490, 250, 5, azul, azul);
    tela_texto(470, 240, 18, branco, "Sim");

    tela_retangulo(500, 230, 540, 250, 5, vermelho, vermelho);
    tela_texto(520, 240, 18, branco, "Nao");
    // desenha um círculo na posição do mouse
    tela_circulo(tela_rato_x(), tela_rato_y(), 10, 2, vermelho, branco);

    // faz uma linha se o botão do mouse tiver apertado
    if (tela_rato_apertado()) {
        tela_circulo(tela_rato_x(), tela_rato_y(), 10, 2, branco, azul);
    }
    tela_atualiza();

}