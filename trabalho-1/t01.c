/* Bruna Caetano - Laboratório de programação - SI 2022.2 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    int opcao, numero, param1, param2, p1Anterior, p2Anterior;

    param1 = 0;
    param2 = 100;
    printf("Pense em algum número entre 0 e 100. \n\n");

    do
    {
        srand(time(NULL));
        
        p1Anterior = param1;
        p2Anterior = param2;

        // primeiro número do intervalo + (numero aleatorio entre o maior e menor numero + 1);
        numero = param1 + (rand() % (param2 + 1 - param1));

        printf("Seu número é o %d? \n", numero);
        printf("Digite: \n\t 0 se correto; \n\t 1 se a cima de %d; \n\t 2 se abaixo de %d; \n-> ", numero, numero);
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            param1 = numero;
            param2 = p2Anterior;
        }
        else if (opcao == 2)
        {
            param1 = p1Anterior;
            param2 = numero;
        }
    } while (opcao != 0);

    return 0;
}