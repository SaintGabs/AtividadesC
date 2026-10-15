/*

4) Você foi designado para desenvolver o protótipo de uma calculadora básica em Linguagem C. Para garantir a organização e modularidade do código, a lógica de cada operação matemática deve ser isolada em funções específicas.

Escreva um programa que exiba um menu de opções, solicite ao usuário a operação desejada e os dois números operandos. Em seguida, utilize a estrutura switch/case para chamar a função correspondente e exibir o resultado na tela.



Requisitos do Programa:

Criação das Funções:
float somar(float a, float b) — retorna a soma dos dois números.
float subtrair(float a, float b) — retorna a diferença.
float multiplicar(float a, float b) — retorna o produto.
float dividir(float a, float b) — retorna a divisão (tratar divisão por zero).
Estrutura do Menu e Seleção:
Apresentar o seguinte menu no terminal:
1. Somar
2. Subtrair
3. Multiplicar
4. Dividir
 
Utilizar a estrutura switch/case para direcionar a execução com base na opção escolhida pelo usuário.
Tratar opções inválidas utilizando a cláusula default.


Exemplo de Execução Esperada no Terminal

======================================
        CALCULADORA EM C - UDF        
======================================
 
1. Somar
2. Subtrair
3. Multiplicar
4. Dividir
 
Escolha a operacao desejada (1-4): 4
Digite o primeiro numero: 15.0
Digite o segundo numero: 3.0
 
--------------------------------------
Resultado da divisao: 5.00
======================================
*/
#include <stdio.h>

float somar(float a, float b){
    return a + b;
}

float subtrair(float a, float b){
    return a - b;
}
float multiplicar(float a, float b){
    return a*b;
}
float dividir(float a, float b){
    return a / b;
}

int main(){
    float num1,num2;
    int escolha;
    printf("======================================");
    printf("\n        CALCULADORA EM C - UDF        ");
    printf("\n======================================\n");
    printf("\n1. Somar");
    printf("\n2. Subtrair");
    printf("\n3. Multiplicar");
    printf("\n4. Dividir\n");

    printf("\nescolha a operacao desejada (1-4): ");
    scanf("%d",&escolha);

    printf("Digite o primeiro numero: ");
    scanf("%f",&num1);
    printf("Digite o segundo numero: ");
    scanf("%f",&num2);
    printf("--------------------------------------\n");

    switch (escolha)
    {
    case 1:
        printf("A soma dos numeros: %.2f",somar(num1,num2));
        break;
    case 2:
        printf("A diferenca dos numeros: %.2f",subtrair(num1,num2));
        break;
    case 3:
        printf("A multiplicacao dos numeros: %.2f",multiplicar(num1,num2));
        break;
    case 4:
        printf("A divisao dos numeros: %.2f",dividir(num1,num2));
        break;

    default:
     printf("Funcao escolhida nao valida");
        break;
    }
    printf("\n======================================");

    return 0;
}