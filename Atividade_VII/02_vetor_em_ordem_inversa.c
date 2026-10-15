/*2) Exibição em ordem inversa. 

Leia 6 números inteiros, armazene-os em um vetor e exiba os valores na ordem inversa àquela em que foram digitados.*/

#include <stdio.h>
int main(){
    int nums[6];
    for(int i = 0; i < 6 ; i++){
        printf("Digite o %d valor: ",i+1);
        scanf("%d",&nums[i]);
    }

    for (int i = 5; i >= 0; i--)
    {
        printf("%d",nums[i]);
    }
    
}