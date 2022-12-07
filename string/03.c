
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/* Faça uma função que recebe uma string (o vetor que a contém) e retorna o número de vogais 
existentes na string. Considere vogais os caracteres "aeiouAEIOU". */

int vogais(char string[]){
    int i = 0, numero = 0;
    char vogais[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    while (string[i] != '\0'){
        for (int j = 0; j < 10; j++)
            if (string[i] == vogais[j]) numero++;
        
        i++;
    } 
    return numero;
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    char vetor[] = "Bruna";
    char tmp[] = "arara";

    printf("- %d \n- %d\n\n", vogais(vetor), vogais(tmp));

    return 0;
}