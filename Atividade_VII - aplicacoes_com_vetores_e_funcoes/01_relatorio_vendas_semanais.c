/*1) Controle de vendas de uma loja



Uma loja deseja acompanhar as vendas realizadas durante sete dias. Desenvolva um programa que armazene em um vetor o valor das vendas de cada dia.

Ao final, o programa deverá:

- Calcular o total vendido na semana;

- Calcular a média diária de vendas;

- Identificar o dia com maior valor de vendas;

- Contar quantos dias tiveram vendas superiores a R$ 1.000,00.*/

#include <stdio.h>

int main(){
    float dias[7],maior = dias[0];
    int tamanho = sizeof(dias)/sizeof(dias[0]), counter=0;

    for (int i = 0; i < tamanho; i++)
    {
        printf("Digite o valor em vendas do dia %d: ",i+1);
        scanf("%f",&dias[i]);
}
    float valortotal = 0;
    for (int i = 0; i < tamanho; i++)
    {   
        valortotal += dias[i];
        if (dias[i] > maior)
        {
            maior = dias[i];
        }
        if (dias[i]>=1000){
            counter ++;
        }
        
    }
    printf("Valor total é igual a %.2f",valortotal);
    printf("\nMedia de vendas é igual a: %.2f",valortotal/tamanho);
    printf("\nMaior venda: %.2f",maior);
    printf("\nDias com valor superior a mil: %d",counter);

}