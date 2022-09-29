#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Faça um programa C que calcula e imprime a área de um triângulo retângulo. 
O programa deve pedir para o usuário digitar as medidas dos dois catetos do triângulo. 
Use números float. */

int main(){
    setlocale(LC_ALL, "portuguese");
    float cateto1, cateto2, area;

    printf("Insira o valor do primeiro cateto: ");
    scanf("%f", &cateto1);
    printf("Insira o valor do segundo cateto: ");
    scanf("%f", &cateto2);

    area = (cateto1 * cateto2) / 2;

    printf("A área do triângulo é %.2f\n", area);

    return 0;
}