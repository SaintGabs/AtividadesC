#include <stdio.h>
#define taxa 0.1
int main(){
    float consumo, total, valorpessoa;
    int quantidade;
    printf("Valor do consumo\n");
    scanf("%f",&consumo);
    printf("Quantidade de pessoas para dividir a conta\n");
    scanf("%d",&quantidade);

    total = consumo * 1.1;
    valorpessoa = total / quantidade;

    printf("----Conta----");
    printf("\n-------------");
    printf("\nValor consumido: %.2f",consumo);
    printf("\nNumero de pessoas na mesa: %d",quantidade);
    printf("\n-------------");
    printf("\nValor consumido: %.2f",consumo);
    printf("\nTaxa de servico:  %.2f", taxa*consumo);
    printf("\n-------------");
    printf("\nValor total da conta: %.2f",total);
    printf("\nValor por pessoa(%d): %.2f",quantidade, total/quantidade);

   
    
}