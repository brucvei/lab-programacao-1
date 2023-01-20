#ifndef _game_h_  // para evitar problemas coma inclusão múltipla deste arquivo
#define _game_h_

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// Os includes do allegro
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

// cria o array dos circulos
void cria_array_circulos(int n, circulo circulos[n]);

// Sorteia as cores
void sorteia(int *vetor);

// Inicia a partida, seta as variáveis
void partida(void);

// Inicia o jogo
void jogo(void);
     

#endif