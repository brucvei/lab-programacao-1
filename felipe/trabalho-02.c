#include <stdio.h>
#include <stdlib.h>

int exercicio1(){
    float altura[10], media = 0;
    int i, quantidade = 0;

    for (i = 0; i < 10; i++) {
        printf("\nDigite a altura do atleta %d: ", i+1);
        scanf("%f", &altura[i]);
        media += altura[i];
    }

    media /= 10;

    printf("\n");
    for (i = 0; i < 10; i++) {
        if (altura[i] > media) {
            printf("Atleta %d: %.2f\n", i+1, altura[i]);
            quantidade++;
        }
    }
    printf("\n");

    return quantidade;
}

void exercicio2(){
    int gabarito[13], respostas[13], i;

    for (i = 0; i < 13; i++)
    {
        do {
            printf("Digite o valor do gabarito %d: ", i+1);
            scanf("%d", &gabarito[i]);
        } while (gabarito[i] != 1 && gabarito[i] != 2 && gabarito[i] != 0);
    }

    int opcao;
    do {
        int acertos = 0, apostador;

        printf("\nDigite o numero do apostador: \n -");
        scanf("%d", &apostador);
        for (i = 0; i < 13; i++) {
            do {
            printf("Digite o valor da resposta %d: ", i+1);
            scanf("%d", &respostas[i]);
            } while (respostas[i] != 1 && respostas[i] != 2 && respostas[i] != 0);

            if (gabarito[i] == respostas[i]) acertos++;
        }
        printf("\n");

        printf("Numero do apostador: %d \nAcertos: %d\n", apostador, acertos);
        if (acertos == 13) printf("Ganhador"); 

        printf("Deseja cadastrar outro apostador? (1 - Sim / 0 - Nao) ");
        scanf("%d", &opcao);
    } while (opcao != 0);
}

float exercicio3(){
    float matriz[4][5], vetor[4],  soma = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            printf("Digite o valor da matriz %d %d: ", i+1, j+1);
            scanf("%f", &matriz[i][j]);
            vetor[i] += matriz[i][j];
        }
    }

    for (int i = 0; i < 4; i++) {
        soma += vetor[i];
    }

    return soma;
}

void exercicio4(){
    float pares = 0, impares = 0;
    int matriz[10][7];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 7; j++) {
            printf("Digite o valor da matriz %d %d: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
            if (matriz[i][j] % 2 == 0) pares++;
            else impares++;
        }
    }

    printf("Percentual de elementos pares: %.2f%%\n", (pares / (pares + impares) * 100));
    printf("Percentual de elementos impares: %.2f%%\n", (impares / (pares + impares) * 100));
}

void exercicio5(){
    int opcao;

    printf("\nEscolha uma opcao:\n 1. Opcao 1\n 2. Opcao 2\n 3. Opcao 3\n 4. Opcao 4\n 5. Opcao 5\n - ");
    scanf("%d", &opcao);

    switch (opcao)
    {
        case 1:
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    printf("* ");
                }
                printf("\n");
            }
            break;
        case 2:
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (i < j) printf("* ");
                    else printf("  ");
                }
                printf("\n");
            }
            break;
        case 3:
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (i > j) printf("* ");
                    else printf("  ");
                }
                printf("\n");
            }
            break;
        case 4:
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (i != j) printf("* ");
                    else printf("  ");
                }
                printf("\n");
            }
            break;
        case 5:
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (i == j) printf("* ");
                    else printf("  ");
                }
                printf("\n");
            }
            break;
    }
}

int main()
{
    int opcao;

    do
    {
        printf("\nEscolha uma opcao:\n 1. Exercicio 1\n 2. Exercicio 2\n 3. Exercicio 3\n 4. Exercicio 4\n 5. Exercicio 5\n 0. Sair\n - ");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1:
                printf("Exercicio 1:\n");
                printf("Quantidade de atletas acima da media: %d\n", exercicio1());
                break;
            case 2:
                printf("Exercicio 2:\n");
                exercicio2();
                break;  
            case 3:
                printf("Exercicio 3:\n");
                printf("Soma dos elementos da matriz: %f\n", exercicio3());
                break;
            case 4:
                printf("Exercicio 4:\n");
                exercicio4();
                break;
            case 5:
                printf("Exercicio 5:\n");
                exercicio5();
                break;
        }
    } while (opcao != 0);

    return 0;
}