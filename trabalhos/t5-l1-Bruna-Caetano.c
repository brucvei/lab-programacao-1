// T5 - Bruna Caetano

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#pragma region 
void cor_fundo(int vermelho, int verde, int azul) {
    printf("\e[48;2;%d;%d;%dm", vermelho, verde, azul);
}
// escolhe a cor normal para os próximos caracteres que serão escritos
void cor_normal(void) {
    printf("\e[m");
}

void espaco_vazio(int quantidade) {
    for (int i = 0; i < quantidade; i++)
        printf(" ");
}
#pragma endregion

int verifica(char chute[]){
    char* letras[] = {"v", "l", "a", "e", "z", "n", "i"};
    bool fora = false;

    if (strlen(chute) != 4) return false;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 7; j++)
            printf("%c - %c ", chute[i], letras[j]);
           /*  if (chute[i] == letras[j])
                fora = true; */

    if (fora == false) return false;

    return true;
}

void processa(char chute[], char cores[4], char *anteriores[], char *letras[], bool *acertou){
    if(verifica(chute)){
        strcpy(*anteriores, chute);
        /* verificar cada letra,
        verificar se esta na ordem certa */
        for (int i = 0; i < 4; i++) {
            printf("%c - %c ", chute[i], cores[i]);
        }
    } else {
        puts("Seu chute foi inválido, tente novamente.");
    }
    
}
#pragma region
void desistir() {
    puts("desistiu");
}

void historico() {
    puts("historico");
}

void tabela() {
    char* letras[] = {"v", "l", "a", "e", "z", "n", "i"};
    int cores[7][3] = {{255, 0, 0},{255, 127, 0},{255, 255, 0},{0, 255, 0},{0, 0, 255},{75, 0, 130},{143, 0, 255}};

    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 7; i++) {
            cor_fundo(cores[i][0], cores[i][1], cores[i][2]);
            if (j == 1) {
                espaco_vazio(2);
                printf("%s", letras[i]);
                espaco_vazio(2);
            } 
            else {
                espaco_vazio(5);
            }
            cor_normal();
            espaco_vazio(1);
        }
        printf("\n"); 
    }
}
 
int especial(char chute[]) {
    if (strcmp(chute, "?") == 0) return 1;
    else if (strcmp(chute, "!") == 0) return 2;
    else if (strcmp(chute, "#") == 0) return 3;

    return 0;
}

void sorteia(char *letras[], char *resultado) {
    int vet[4], i = 0, igual;
    char tmp[4];
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
#pragma endregion
void partida() { // cores = {"vermelho", "laranja", "amarelo", "verde", "azul", "anil", "violeta"}
    char chute[4], cores[4] = {};
    char* letras[] = {"v", "l", "a", "e", "z", "n", "i"}, *anteriores[] = {};
    int chances = 9;
    bool desistiu = false, acertou = false;

    sorteia(letras, cores);
    puts(cores);

    do {
        printf("Digite seu chute: \n? - tabela de cores\n! - historico de jogadas\n# - desistir de jogar\n- ");
        gets(chute);
        int tipo = especial(chute);
        if (tipo == 1) tabela();
        else if (tipo == 2) historico();
        else if (tipo == 3) desistir(&desistiu);
        else {
            processa(chute, cores, anteriores, letras, &acertou);
            chances--;
        }
    } while (!acertou || !desistiu || chances != 0);
}

void jogo() { // inicia o jogo
    char resposta[1];
    puts("---- Mastermind ----");

    while (strcmp(resposta, "N") != 0) {
        partida();
        puts("Deseja jogar outra vez?");
        puts("Digite qualquer coisa para sim e 'N' para não.");
        gets(resposta);
    }

    puts("Até logo!");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    jogo();

    return 0;
}