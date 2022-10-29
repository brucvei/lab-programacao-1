#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int fat(int n)
{
    int numb = n;

    for (int i = 1; i < n; i++)
        numb *= (n - i);

    return numb;
}

double xnan(double x, int n)
{
    double numb = x;

    for (int i = 1; i <= n; i++)
        numb *= x;

    return numb;
}

double seno(double ang)
{
    double parcela = 0, erro, seno = 0;
    int i = 1, j = 1;

    ang = ang / 180 * 3.14159;
    printf("ang: %lf\n", ang);

    do
    {
        parcela = (xnan(ang, i) / fat(i));
        erro = parcela;
        seno += (parcela * j);

        i += 2;
        j *= -1;
    } while (erro > 0.000001);

    return seno;
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int numero1;
    double numero2;

    // printf("Digite um número: ");
    // scanf("%d", &numero1);

    printf(" - seno: %lf\n", seno(30));

    return 0;
}