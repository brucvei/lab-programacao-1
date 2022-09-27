#include <stdio.h>
#include <stdlib.h>

/* Faça um programa para calcular e imprimir o valor de um litro de suco de laranja. Esse programa deve inicializar uma variável com o custo de um quilo de laranja (20), outra com a quantidade de suco, em ml, extraível de um quilo (800), outra com o custo da mão de obra mais lucro para produzir um litro de suco (14). */

int main () {
    int quilo, fixo, litro;

    printf("Insira o valor do quilo: ");
    scanf("%d", &quilo);
    printf("Insira o valor fixo: ");
    scanf("%d", &fixo);

    litro = (quilo * 1000 / 800) + fixo;

    printf("O valor do litro é %d\n", litro);

    return 0;
}