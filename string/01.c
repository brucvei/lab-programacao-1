
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/* Implemente as funções acima. Faça um programa para testá-las, com as funções oficiais
e com as tuas versões. Como contribuição, segue uma possível implementação para a primeira
delas (com o nome alterado para não dar conflito com as oficiais): */

char meustrcat(char *primeira, char *segunda)
{
    char *start = primeira;

    while(*start != '\0')
    {
        start++;
    }

    while(*segunda != '\0')
    {
        *start++ = *segunda++;
    }

    *start = '\0';
    return primeira;
}

char meustrcpy(char* destn, char *src)
{
    int i = 0;

    while (src[i] != '\0'){
        destn[i] = src[i];
        i++;
    }
}

int meustrlen(char s[])
{
    int i = 0;

    while (s[i] != '\0') i++;

    return i;
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    char vetor[] = "Bruna";
    char aux[strlen(vetor)], aux1[strlen(vetor)];
    char tmp[] = " Caetano";

    printf("strlen:\n-%d \n-%d\n\n", meustrlen(vetor), strlen(vetor));

    meustrcpy(aux, vetor);
    strcpy(aux1, vetor);
    printf("strcpy:\n-%s \n-%s\n\n", aux, aux1);

    meustrcat(vetor, tmp);
    strcat(aux, tmp);
    printf("strcat:\n-%s \n-%s\n\n", vetor, aux);

    return 0;
}