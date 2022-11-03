#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

/* Faça uma função que recebe um vetor de inteiros e seu tamanho e retorna a moda (valor que mais se repete). Sabe-se que cada elemento do vetor tem valor entre 0 e 99 */

int moda(int n, int v[n])
{
    int aux[100] = {0}, maior = 0, moda;

    for (int i = 0; i < n; i++)
        aux[v[i]]++;

    for (int i = 0; i < 100; i++)
    {
        if (maior < aux[i])
        {
            maior = aux[i];
            moda = i;
        }
    }

    return moda;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int v[10] = {1, 3, 2, 5, 5, 5, 5, 2, 7, 8};

    printf("A moda é:  %d\n", moda(10, v));

    return 0;
}