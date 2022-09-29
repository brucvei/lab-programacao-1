#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Faça um programa para calcular o consumo de um carro. Para usar o programa, deve-se encher o tanque do carro, anotar o valor no odômetro, rodar com o carro, encher novamente o tanque, e anotar novamente o valor do odômetro e número de litros de combustível que couberam no tanque. O programa pede então os 3 valores anotados e calcula o consumo (dividindo o número de quilômetros percorridos pelo número de litros usados nesse percurso tem-se o consumo em km/l). Além de informar o consumo em km/l, o programa deve também informar em milhas por galão e em litros para 100km, como é usual nos EUA e na Europa. Um galão equivale a 3,79 litros; uma milha a 1,609 km. */

int main(){
    setlocale(LC_ALL, "portuguese");
    float km1, km2, litros, consumo, milhaGalao;

    printf("Insira o valor do odômetro: ");
    scanf("%f", &km1);
    printf("Insira o valor do odômetro de novo: ");
    scanf("%f", &km2);
    printf("Insira a quantidade de litros: ");
    scanf("%f", &litros);

    consumo = (km1 + km2) / litros;
    printf("\nO valor do consumo total foi de %.2f km/l.\n", consumo);

    milhaGalao = consumo * 2.35215;
    printf("O valor do consumo total foi de %.2f m/g.\n", milhaGalao);

    consumo = 100 / consumo;
    printf("O valor do consumo foi de %.2f l/100km.\n", consumo);

    return 0;
}