// inclui as definicoes
#include "tela.h"
#include "game.h"

struct ESTADO {
    int chances;
    int chutes[4][8];
    int acertos[2][8];
    int cores[4];
    bool acertou;
    bool desistiu;
    bool nao;
} estado;

int contador = 0, chuteAtual[4];
circulo circulos[10];
ponto click;

void cria_array_circulos(circulo circulos[]) {
    for (int i=0; i<10; i++) {
        circulos[i].centro.x = LARGURA - i*50 - 50;
        circulos[i].centro.y = ALTURA - 50;
        circulos[i].raio = 20;
        circulos[i].cor = (i <= 6) ? i : preto;
    }
}

void cria_circulos_iniciais() {
	for (int i = 0; i < 10; i++) {
		tela_circulo(circulos[i].centro.x, circulos[i].centro.y, circulos[i].raio, 2, branco, circulos[i].cor);
	}

    tela_texto(circulos[9].centro.x, circulos[9].centro.y, 20, branco, "⟵");
    tela_texto(circulos[8].centro.x, circulos[8].centro.y, 20, branco, "✓");
    tela_texto(circulos[7].centro.x, circulos[7].centro.y, 20, branco, "✕");
}

void sorteia(int *resultado) {
    int vet[4], i = 0, igual;
    srand(time(NULL));

    do { 
        vet[i] = rand() % 7; 
        igual = 0;
        for (int j = 0; j < i; j++) { 
            if(vet[j] == vet[i]) igual = 1; 
        }

        if(igual == 0) i++;
    } while(i < 4);

    for (i = 0; i < 4; i++) {
        resultado[i] = vet[i];
    }
}

void desenha_matriz() {
    int x = 50, y = 50;
    for (int i = 0; i < estado.chances; i++) {
        for (int j = 0; j < 4; j++) {
            tela_circulo(x, y, 20, 2, branco, estado.chutes[i][j]);
            x += 50;
        }
        for (int j = 0; j < estado.acertos[0][i]; j++) {
            tela_circulo(x, y, 20, 2, branco, preto);
            x += 50;
        }
        for (int j = 0; j < estado.acertos[1][i]; j++) {
            tela_circulo(x, y, 20, 2, branco, branco);
            x += 50;
        }
        
        x = 50;
        y += 50;
    }
}

void desenha_chute() {
    for (int i = 0; i < contador; i++)
        tela_circulo((i + 1) * 50, ALTURA - 50, 20, 2, branco, chuteAtual[i]);
}

void ganhou() {
    tela_final();
    tela_texto(LARGURA/2, ALTURA/2, 50, branco, "Você ganhou!");
}

void desistiu() {
    tela_final();
    tela_texto(LARGURA/2, ALTURA/2, 50, branco, "Você desistiu!");
}

void conta_pretos_brancos() {
    int pretos = 0, brancos = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (chuteAtual[i] == estado.cores[j] && i == j) pretos++;
            if (chuteAtual[i] == estado.cores[j] && i != j) brancos++;
        }
    }

    if (pretos == 4) {
        estado.acertou = true;
        printf("Acertou\n");
    }

    estado.acertos[0][estado.chances] = pretos;
    estado.acertos[1][estado.chances] = brancos;
}


bool valida(int chute) {
    for (int i = 0; i < 4; i++) {
        if (chuteAtual[i] == chute) return false;
    }

    return true;
}

void confirma_chute() {
    printf("chute atual: %d %d %d %d\n", chuteAtual[0], chuteAtual[1], chuteAtual[2], chuteAtual[3]);

    conta_pretos_brancos();
    for (int i = 0; i < 4; i++) {
        estado.chutes[estado.chances][i] = chuteAtual[i];
        chuteAtual[i] = preto;
    }

    contador = 0;
    estado.chances++;
    desenha_matriz();
}

void remove_ultimo() {
    contador--;

    if (contador < 0) return;

    chuteAtual[contador] = preto;
}

void adiciona_chute(int chute) {
    if (contador >= 4) return;
    if (!valida(chute)) return;
    
    chuteAtual[contador] = chute;
    contador++;

    desenha_chute();
}

void processa_click() {
    click.x = tela_rato_x();
    click.y = tela_rato_y();

    int tmp = circulo_no_ponto(10, circulos, click);

    if (tmp == 7) {
        estado.desistiu = true;
        printf("Desistiu\n");
    } else if (tmp == 8) {
        printf("Confirmou\n");
        confirma_chute();
            // confirmar chute
    } else if (tmp == 9) {
        printf("Apagou\n");
        remove_ultimo();
    } else if (tmp >= 0 && tmp < 7) {
        printf("Chute: %d\n", tmp);
        adiciona_chute(tmp);
    }
}

void partida() {
    estado.chances = 0;
    estado.acertou = false;
    estado.desistiu = false;
    estado.nao = false; 
    sorteia(estado.cores);
    cria_array_circulos(circulos);

    printf("Cores: %d %d %d %d\n", estado.cores[0], estado.cores[1], estado.cores[2], estado.cores[3]);
    do {
        if (tela_rato_clicado()) {
            processa_click();
        }

        if (estado.desistiu) {
            desistiu();
            break;
        } else if (estado.acertou) {
            ganhou();
            break;
        }

        tela_jogo();
    } while (estado.chances < 9);

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
