// T3 - Bruna Caetano

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>

int fat(int n) // !n
{
    int numb = n;

    for (int i = 1; i < n; i++)
        numb *= (n - i);

    return numb;
}

double xnan(double x, int n) // x^y
{
    double numb = x;

    for (int i = 1; i <= n; i++)
        numb *= x;

    return numb;
}

double enax(double x) // e^x
{
    double parcela = 0, erro, tmp = 1;
    int i = 1;

    do
    {
        parcela = xnan(x, i) / fat(i);
        tmp += parcela;

        i++;
    } while (parcela > 0.0000001);

    return tmp;
}

double ln_xmais1(double x) // ln(1+x)
{
    double parcela = 0, erro, tmp = 0;
    int i = 1, j = 1;

    do
    {
        parcela = xnan(x, i) / i;
        erro = parcela;
        tmp += (parcela * j);

        i++;
        j *= -1;
    } while (erro > 0.0000001);

    return tmp;
}

double ln(double x) // ln(x)
{
    int n = 0;
    double y = x;

    while (y > 1.35)
    {
        y /= 2;
        n++;
    }

    while (y < 0.65)
    {
        y *= 2;
        n--;
    }

    double ln2 = ln_xmais1(0.5) + ln_xmais1(1.0 / 3.0);
    return ln_xmais1(y - 1) + n * ln2;
}

double xnay(double x, double y) // x^y
{
    return enax(y * ln(x));
}

int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    double a = 19.42, rc = xnay(a, 1.0 / 3.0);
    double b = rc * rc * rc;
    printf("%lf deve ser parecido com %lf\n", a, b);

    return 0;
}