#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

/* Juntar dois vetores que já estão em ordem e manter em ordem crescente */

void merge(int n, int v1[n], int m, int v2[m], int v3[])
{
    for (int i = 0; i < count; i++)
    {
        /* code */
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int v1[10] = {1, 3, 5, 6, 7, 9, 10, 14, 17, 20};
    int v2[7] = {2, 4, 8, 11, 12, 13, 15};
    int v3[17];

    printf("A moda é:  %d\n", merge(10, v1, 7, v2, v3));

    return 0;
}