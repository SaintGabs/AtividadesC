/*1) Escreva um programa em C que solicite ao usuário 5 números inteiros, armazene-os em um vetor(array) e, utilizando um laço de repetição (for), calcule e exiba a soma dos números pares. 

Exemplo: 

Digite o 1o número: 5

Digite o 2o número: 4

Digite o 3o número: 8

Digite o 4o número: 3

Digite o 5o número: 1



Saída: A soma dos números pares = 12.
*/
#include <stdio.h>
int main(){
    int soma = 0, numeros[5], tamanho = sizeof(numeros) / sizeof(numeros[0]);

    for (int i = 0; i < tamanho; i++) {
        printf("Digite o %d numero: ", i+1);
        scanf("%d", &numeros[i]);
    }


    for (int i = 0 ; i < 5 ; i++)
    {   
        if (numeros[i]%2==0)
        {
            soma+=numeros[i];
        }
    }
    
    printf("A soma dos numeros pares dos numeros digitados: %d",soma);

    return 0;
}