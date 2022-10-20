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

    if (num <= 2) {
        return false;
    }

    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            resultado++;
            break;
        }
    }

    return (resultado == 0) ? true : false;
}

int total(int j, int i)
{
    int tmp = 0;

    do {
        if (primo(j)) {
            tmp++;
            // printf("- %d: %d\n", j, tmp);
        }
        j++;
    } while (j < i);
    
    return tmp;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int numero1, numero2;

    printf("Digite um número: ");
    scanf("%d", &numero1);
    printf("Digite outro número: ");
    scanf("%d", &numero2);

    printf("O total de primos é: %d", total(numero1, numero2));

    return 0;
}