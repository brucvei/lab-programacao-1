#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int numero;

    printf("Insira algum valor: ");
    scanf("%d", &numero);

    for (int i = 1; i <= numero; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            printf("papum\n");
        }
        else if (i % 3 == 0)
        {
            printf("pa\n");
        }
        else if (i % 5 == 0)
        {
            printf("pum\n");
        }
        else
        {
            printf("%d\n", i);
        }
    }

    return 0;
}