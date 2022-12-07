
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

/* Implemente uma função que recebe um vetor de char que contém uma string, e 
retorna um bool que diz se essa string é ou não um palíndromo (se a sequência de 
caracteres é a mesma, lida da esquerda para a direita ou da direita pra esquerda). 
"AS SATAS SA" é um palíndromo, "OS SOTOS SA" não é. Faça um programa para testar sua função. */

bool palindromo(char string[]){
    int i = 0, j = strlen(string) - 1;

    while (string[i] != '\0'){
        if (string[i] != string[j] && i != j) return false;
        
        i++;
        j--;
    } 
    return true;
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    char vetor[] = "Bruna";
    char tmp[] = "arara";

    printf("- %d \n- %d\n\n", palindromo(vetor), palindromo(tmp));

    return 0;
}