// inclui as definicoes
#include "tela.h"
#include "game.h"

struct ESTADO {
    int chances;
    int chutes[4][8];
    int cores[4];
    bool acertou;
    bool desistiu;
    bool nao;
} estado;

circulo circulos[7], funcoes[3];
ponto click;

void cria_circulos_funcoes(){

}

void cria_array_circulos(circulo circulos[]) {
    for (int i=0; i<7; i++) {
        circulos[i].centro.x = LARGURA - i*50 - 50;
        circulos[i].centro.y = ALTURA - 50;
        circulos[i].raio = 20;
        circulos[i].cor = i;
    }
}

void cria_circulos_iniciais(){
	for (int i = 0; i < 7; i++)
	{
		tela_circulo(circulos[i].centro.x, circulos[i].centro.y, circulos[i].raio, 2, circulos[i].cor, circulos[i].cor);
	}
}

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

void processa_click(){
    /* if(valida(chute)){
        push(chute);
        char temp[4];
        int result = verifica(chute, cores);
        int pretos = result / 10;
        int brancos = result - pretos * 10;

        desenha(chute, pretos, brancos);
        strncpy(temp, cores, 4);

        if (strcmp(chute, temp) == 0) {
            puts("Parabéns! Você acertou!");
            *acertou = true;
        }
    } else {
        puts("Seu chute foi inválido, tente novamente.\n");
    } */
    click.x = tela_rato_x();
    click.y = tela_rato_y();

    int tmp = circulo_no_ponto(7, circulos, click);
    if (tmp > 0) {
        printf("Chute: %d\n", tmp);
    }
}

void partida() {
    estado.chances = 9;
    estado.acertou = false;
    estado.desistiu = false;
    estado.nao = false; 
    sorteia(estado.cores);
    cria_array_circulos(circulos);

    do {
        printf("Cores: %d %d %d %d\n", estado.cores[0], estado.cores[1], estado.cores[2], estado.cores[3]);

        if (tela_rato_clicado()) {
            processa_click();
        }
        
        estado.chances--;

        tela_jogo();
    } while (true);

    // tela_atualiza();
    
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
