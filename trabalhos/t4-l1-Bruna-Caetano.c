// T4 - Bruna Caetano

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void cor_texto(int vermelho, int verde, int azul)
{
    printf("\e[38;2;%d;%d;%dm", vermelho, verde, azul);
}

void cor_normal(void)
{
    printf("\e[m");
}

void espaco_vazio(int quantidade)
{
    for (int i = 0; i < quantidade; i++)
        printf(" ");
}

void espaco_x(int quantidade)
{
    for (int i = 0; i < quantidade; i++)
        printf("X");
}

void coluna_idade(int idade)
{
    if (idade == 20)
        printf(" ++ ");
    else if (idade == 0 || idade == 1)
        printf("  %d ", idade * 5);
    else
        printf(" %d ", idade * 5);
}

void linha(int homem, int mulher, int idade)
{
    int espH = 35 - homem, espM = 35 - mulher;

    /* HOMEM */
    cor_texto(0, 191, 255);
    espaco_vazio(espH);
    espaco_x(homem);

    /* MEIO */
    cor_normal();
    coluna_idade(idade);

    /* MULHER */
    cor_texto(255, 105, 180);
    espaco_x(mulher);
    espaco_vazio(espM);

    cor_normal();
    printf("\n");
}

float maior(float *vet1, float *vet2)
{
    float num = vet1[0];

    for (int i = 0; i < 21; i++)
    {
        if (num < vet1[i])
            num = vet1[i];

        if (num < vet2[i])
            num = vet2[i];
    }

    return num;
}

void desenha_piramide(float *masc, float *fem)
{
    int num = maior(masc, fem) / 35;

    for (int i = 20; i >= 0; i--)
    {
        int homem, mulher;

        homem = masc[i] / num;
        mulher = fem[i] / num;

        linha(homem, mulher, i);
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    float ph[21] = {200, 190, 180, 170, 160, 150, 140, 129, 120, 110, 100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 0};
    float pf[21] = {200, 190, 220, 170, 160, 150, 140, 129, 120, 40, 100, 90, 80, 70, 70, 50, 40, 30, 20, 10, 0};
    desenha_piramide(ph, pf);

    return 0;
}