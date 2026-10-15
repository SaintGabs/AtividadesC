/*
4) Controle de aprovação de alunos

Uma instituição de ensino deseja automatizar a classificação dos estudantes. Elabore um programa que leia três notas de um aluno e utilize uma função chamada calcularMedia() para calcular a média aritmética.

Crie uma função verificarSituacao() que receba a média e retorne:

- 1 para aprovado, se a média for maior ou igual a 7;

- 2 para recuperação, se a média for maior ou igual a 5 e menor que 7;

- 3 para reprovado, se a média for menor que 5.

O programa principal deverá exibir a média e a situação final do aluno.*/

#include <stdio.h>

float calcularMedia(float array[], int tamanho){
    float soma = 0;
    for(int i = 0; i < tamanho; i++){
        soma += array[i];
    }
    return soma/tamanho;
}

int verificarSituacao(float media){
    if(media >= 7)
        return 1;
    if(media >= 5)
        return 2;
    return 3;
}

int main(){
    float notas[3];
    for(int i = 0; i < 3; i++){
        printf("Digite a %d nota: ", i + 1);
        scanf("%f",&notas[i]);
    }
    int situacao = verificarSituacao(calcularMedia(notas, sizeof(notas)/sizeof(notas[0])));

    printf("A media das notas: %.2f\n", calcularMedia(notas, sizeof(notas)/sizeof(notas[0])));
    switch(situacao){
        case 1:
            printf("Aprovado\n");
            break;
        case 2:
            printf("Recuperacao\n");
            break;
        case 3:
            printf("Reprovado\n");
            break;
    }

    return 0;
}