
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

/* Faça uma função que recebe uma string e remove as vogais que ela contém. 
Se receber a string "vista curta", deve alterá-la par que fique "vst crt". */

bool vogal(char c){
    int i = 0;
    char vogais[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    for (int j = 0; j < 10; j++)
        if (c == vogais[j]) return true;
        
    return false;
}

char semVogais(char* string)
{
    int i = 0, j = 0, k = strlen(string) - 1;

    while(string[i] != '\0')
    {
        if (!vogal(string[i]))
        {
            printf("%c - %c - %d - %d\n", string[i], string[j], i, j);
            string[j] = string[i];
            string[k] = '\0';
            k--;
            j++;                
        } 
        i++;
    }
    puts(string);
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    char vetor[] = "Bruna";
    char tmp[] = "arara";

    printf("- %s \n- %s\n\n", semVogais(vetor), semVogais(tmp));

    return 0;
}