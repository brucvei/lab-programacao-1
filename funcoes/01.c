#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int rand_entre(int inicio, int final){
    srand(time(NULL));
    return inicio + (rand() % (final + 1 - inicio));
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    int numero1, numero2, aleatorio;

    printf("Digite um número: ");
    scanf("%d", &numero1);
    printf("Digite outro número: ");
    scanf("%d", &numero2);

    aleatorio = rand_entre(numero1, numero2);
    printf("Número aleatório: %d", aleatorio);
    
    return 0;
}