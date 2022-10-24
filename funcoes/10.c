#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>

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

int total(int num1, int num2)
{
    int tmp = 0;

    do {
        if (primo(num1))
        {
            tmp++;
            // printf("- %d: %d\n", j, tmp);
        }
        num1++;
    } while (num1 < num2);

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