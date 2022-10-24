/* Bruna Caetano - Laboratório de programação - SI 2022.2 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>

bool primo(int num)
{
    int i, resultado = 0;

    if (num < 2)
    {
        return false;
    }

    for (i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            resultado++;
            break;
        }
    }

    return (resultado == 0) ? true : false;
}

void intervalo(int num1, int num2)
{
    do
    {
        if (primo(num1))
        {
            printf("%d ", num1);
        }
        num1++;
    } while (num1 < num2);
}

int total(int num1, int num2)
{
    int tmp = 0;

    do
    {
        if (primo(num1))
        {
            tmp++;
            // printf("- %d: %d\n", num1, tmp);
        }
        num1++;
    } while (num1 < num2);

    return tmp;
}

void getIntervalo()
{
    int numero1, numero2, i, tmp1, tmp2;

    printf("Digite o tamanho do intervalo: ");
    scanf("%d", &numero1);
    printf("Digite a quantidade de intervalo: ");
    scanf("%d", &numero2);

    int totais[numero2], menor, posicao;

    i = 1;
    while (i <= numero2)
    {
        tmp1 = (numero1 * (i - 1)) + 1;
        tmp2 = numero1 * i;

        totais[i] = total(tmp1, tmp2);

        i++;
    }

    menor = totais[0];
    for (i = 1; i <= numero2; i++)
    {
        if (totais[i] < menor)
        {
            menor = totais[i];
            posicao = i;
        }
    }

    tmp1 = (numero1 * (posicao - 1)) + 1;
    tmp2 = numero1 * posicao;

    printf("O intervalo é o %d - %d\n", tmp1, tmp2);
    printf("O total de primos é %d\n", menor);

    intervalo(tmp1, tmp2);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    getIntervalo();

    return 0;
}