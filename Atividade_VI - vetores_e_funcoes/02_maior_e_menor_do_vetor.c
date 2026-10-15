/*
2) Escreva um programa em Linguagem C que solicite ao usuário 5 números inteiros e os armazene em um vetor (array).

Em seguida, utilizando um laço de repetição (for) e estruturas condicionais (if), o programa deve percorrer o vetor e identificar:

O maior número digitado.
O menor número digitado.
*/
#include <stdio.h>

int main(void)
{
    int numeros[5];
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);

    for (int i = 0; i < tamanho; i++)
    {
        printf("digite o %d numero: ", i+1);
        scanf("%d",&numeros[i]);
    }

    int maior = numeros[0], menor = numeros[0];

    for (int i = 0; i < 5; i++)
    {
        if (numeros[i] < menor)
        {
            menor = numeros[i];
        }
        if (numeros[i] > maior)
        {
            maior = numeros[i];
        }
    }
    
    printf("O maior numero: %d", maior);
    printf("\nO menor numero: %d", menor);


    return 0;
}
