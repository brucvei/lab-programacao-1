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

float tela_rato_x(void) {
	ALLEGRO_MOUSE_STATE rato;
	al_get_mouse_state(&rato);
	return al_get_mouse_state_axis(&rato, 0);
}

float tela_rato_y(void) {
	ALLEGRO_MOUSE_STATE rato;
	al_get_mouse_state(&rato);
	return al_get_mouse_state_axis(&rato, 1);
}

bool tela_rato_apertado(void) {
	ALLEGRO_MOUSE_STATE rato;
	al_get_mouse_state(&rato);
	// só nos interessa o botão da esquerda
	return al_mouse_button_down(&rato, 1);
}

bool tava_apertado = false;
float x_clicado = 0;
float y_clicado = 0;
bool tela_rato_clicado(void) {
	bool ta_apertado = tela_rato_apertado();
	bool foi_clicado = (tava_apertado && !ta_apertado);
	if (foi_clicado)
	{
	x_clicado = tela_rato_x();
	y_clicado = tela_rato_y();
	}
	tava_apertado = ta_apertado;
	return foi_clicado;
}

float tela_rato_x_clique(void) {
	return x_clicado;
}

float tela_rato_y_clique(void) {
	return y_clicado;
}

char tela_tecla(void) {
	ALLEGRO_EVENT ev;

	while (al_get_next_event(tela_eventos_teclado, &ev)) {
		if (ev.type == ALLEGRO_EVENT_KEY_CHAR) {
			int c = ev.keyboard.unichar;
	
			if (c == '\r')
				c = '\n'; // corrige windowscentrismo
			
			// só retorna caracteres imprimíveis, backspace e enter
			if ((c >= ' ' && c <= '~') || c == '\b' || c == '\n')
				return (char)c;
		}
	}
	// nada foi pressionado (ou foi pressionado algo não imprimível)
	return '\0';
}

circulo circulos[7];
void cria_array_circulos(int n, circulo circulos[n]) {
    for (int i=0; i<n; i++) {
        circulos[i].x = LARGURA - i*100;
        circulos[i].y = ALTURA - 60;
        circulos[i].raio = 50;
        circulos[i].cor = cores[i];
    }
}

bool ponto_no_circulo(ponto p, circulo c) {
    float dx = p.x - c.x;
    float dy = p.y - c.y;
    float dist = sqrt(dx*dx + dy*dy);
    return dist <= c.raio;
}

int circulo_no_ponto(int n, circulo circulos[n], ponto p) {
    for (int i=0; i<n; i++) {
        if (ponto_no_circulo(p, circulos[i])) {
            return i;
        }
    }
    return -1;
}