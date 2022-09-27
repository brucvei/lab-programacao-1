#include <stdio.h>
#include <stdlib.h>

/* Suponha que o valor de um litro de diesel seja 666 centavos de real, e que um caminhão tem um tanque onde cabem 333 litros. Faça um programa para calcular o valor necessário para encher o tanque inicialmente vazio. O programa deve imprimir o valor separando reais e centavos (por exemplo, "234 reais e 27 centavos"). Dica: pra que serve o resto da divisão mesmo? */

int main () {
    int valor = 666, tanque = 333, reais, centavos;

    reais = valor * tanque;
    centavos = reais % 100;

    printf("%d reais e %d centavos\n", reais / 1000, centavos);

    return 0;
}