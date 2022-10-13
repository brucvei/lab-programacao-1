#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>


int main () {
    setlocale(LC_ALL, "portuguese");
    float a, b, c;
    float delta, x1, x2;

    printf("Insira o valor de a: ");
    scanf("%f", &a);
    printf("Insira o valor de b: ");
    scanf("%f", &b);
    printf("Insira o valor de c: ");
    scanf("%f", &c);

    delta = (b * b) - (4 * a * c);

    if (delta < 0)
    {
        printf("A equação não há raízes reais\n");
        return 0;
    }
    
    x1 = (-b + sqrt(delta)) / 2 * a;
    x2 = (-b - sqrt(delta)) / 2 * a;

    if (x1 == x2)
    {
        printf("A raíz é %.2f\n", x2);
    } else {
        printf("As raízes são %.2f e %.2f\n", x1, x2);
    }

    return 0;
}