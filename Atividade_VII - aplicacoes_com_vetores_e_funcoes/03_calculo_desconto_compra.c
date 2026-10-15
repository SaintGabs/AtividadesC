/*3) Sistema de cálculo de desconto em compras

Uma loja deseja automatizar o cálculo de descontos concedidos aos clientes. Desenvolva um programa que solicite o valor de uma compra e utilize uma função chamada calcularDesconto() para calcular o desconto.

Regras:

- Compras abaixo de R$ 100,00: sem desconto.

- Compras de R$ 100,00 até R$ 499,99: desconto de 5%.

- Compras a partir de R$ 500,00: desconto de 10%.

Crie também uma função calcularValorFinal() para retornar o valor da compra após o desconto. Ao final, apresente o valor original, o desconto e o valor final.*/

#include<stdio.h>
float calculardesconto(float valor){
    if (valor>=100&&valor<499,99)
    {
        return valor * 0.05;
    }

    else if (valor>500)
    {
        return valor * 0.1;
    }
}

float calcularvalorfinal(float valor,float desconto){
    return valor-desconto;
}

int main(){
    float valor;
    printf("Digite o valor da compra: ");
    scanf("%f",&valor);
    printf("Valor original: %.2f", valor);
    printf("\nDesconto: %.2f", calculardesconto(valor));
    printf("\nValor Final: %.2f",calcularvalorfinal(valor,calculardesconto(valor)));
}