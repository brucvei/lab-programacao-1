#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>

// Suponha que já existe uma função que recebe um número e retorna um bool que diz se esse número é primo.
// Faça uma função que recebe um número e retorna o menor número primo maior que o número recebido.

bool primo(int num)
{
    int i, resultado = 0;

    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            resultado++;
            break;
        }
    }

    return (resultado == 0) ? true : false;
}

int proximo(int numero)
{
    int tmp = 2, j;

    j = 1;
    do {
        if (primo(numero + j)) {
            tmp = numero + j;
        }
        j++;
    } while (tmp == 2);
    
    return tmp;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int numero1;

    printf("Digite um número: ");
    scanf("%d", &numero1);

    printf("O próximo número primo é: %d", proximo(numero1));

    return 0;
}