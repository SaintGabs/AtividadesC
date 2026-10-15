/*
3) Escreva um programa em Linguagem C que contenha uma função chamada calcularDobro.

A função deve receber um número inteiro como parâmetro, calcular e retornar o dobro desse valor. Na função principal (main), solicite um número ao usuário, chame a função calcularDobro e exiba o resultado retornado na tela.

*/


#include <stdio.h>

int dobro(int a){
    return a*2;
}

int main()
{
    int numero;
    printf("Digite um numero: ");
    scanf("%d",&numero);
    int valor = dobro(numero);
    printf("O dobro do valor: %d",valor);

    return 0;
}