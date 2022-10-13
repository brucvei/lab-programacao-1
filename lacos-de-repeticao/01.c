#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int numero, i, total;

    printf("Insira algum valor: ");
    scanf("%d", &numero);

    i = 1;
    total = 1;
    while (i <= numero)
    {
        total *= i;
        i++;
    }

    printf("O número final é %d\n", total);

    return 0;
}