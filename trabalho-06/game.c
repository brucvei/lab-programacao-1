// inclui as definicoes
#include "tela.h"
#include "processa.h"
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


void sorteia(int *resultado) {
    int vet[4], i = 0, igual;
    srand(time(NULL));

    do { 
        vet[i] = rand() % 7; 
        igual = 0;
        for(int j = 0; j < i; j++){ 
            if(vet[j] == vet[i]) igual = 1; 
        }

        if(igual == 0) i++;
    } 
    while(i < 4);

    for (i = 0; i < 4; i++) {
        resultado[i] = vet[i];
    }
    
}

void partida() {
    printf("Partida\n");

    estado.chances = 9;
    estado.acertou = false;
    estado.desistiu = false;
    estado.nao = false; 
    sorteia(estado.cores);

    printf("Jogo\n");
    tela_jogo();
    tela_atualiza();
}

void jogo() {
    tela_inicio(LARGURA, ALTURA, "Jogo Mastermind");

    do {
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
