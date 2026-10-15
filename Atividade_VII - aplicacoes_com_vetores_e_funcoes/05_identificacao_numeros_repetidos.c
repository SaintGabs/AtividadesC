/*5) Identificação de números repetidos

Uma empresa precisa identificar valores duplicados em uma lista de registros numéricos. Leia 10 números inteiros e armazene-os em um vetor.

O programa deverá identificar e exibir os números que aparecem mais de uma vez, evitando mostrar o mesmo número repetido várias vezes na saída.

Desafio: comparar os elementos do vetor utilizando dois laços de repetição.*/

#include <stdio.h>

int main(){
    int nums[10], tamanho = sizeof(nums) / sizeof(nums[0]), repetidos[10];
    for(int i = 0 ; i < tamanho ; i ++){
        printf("Digite o %d numero: ",i + 1);
        scanf("%d",&nums[i]);
    }
    printf("Numeros Repetidos\n");
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = i+1; j < tamanho; j++)
        {
            if (nums[j] == nums[i]){
                printf("%d\n",nums[j]);
            }
        }
        
    }
    
}