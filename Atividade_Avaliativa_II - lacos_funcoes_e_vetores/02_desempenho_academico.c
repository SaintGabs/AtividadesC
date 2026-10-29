#include <stdio.h>

#define ALUNOS 12

float calcularMedia(const int notas[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) soma += notas[i];
    return (float)soma / tamanho;
}

int contarAprovados(const int notas[], int tamanho) {
    int quantidade = 0;
    for (int i = 0; i < tamanho; i++)
        if (notas[i] >= 7) quantidade++;
    return quantidade;
}

int encontrarMaiorNota(const int notas[], int tamanho) {
    int maior = notas[0];
    for (int i = 1; i < tamanho; i++)
        if (notas[i] > maior) maior = notas[i];
    return maior;
}

int contarAcimaMedia(const int notas[], int tamanho, float media) {
    int quantidade = 0;
    for (int i = 0; i < tamanho; i++)
        if (notas[i] > media) quantidade++;
    return quantidade;
}
int lerLinha(char linha[], int tamanho) {
    int c, i = 0, longa = 0;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (i < tamanho - 1) linha[i++] = (char)c;
        else longa = 1;
    }
    linha[i] = '\0';
    if (c == EOF && i == 0 && !longa) return -1;
    return !longa;
}
int lerInteiro(int *valor) {
    char linha[128];
    int estado = lerLinha(linha, sizeof linha);
    if (estado != 1) return estado;
    int i = 0, numero = 0;
    int limite = (int)(~0u >> 1);
    while (linha[i] == ' ' || linha[i] == '\t' || linha[i] == '\r') i++;
    if (linha[i] == '+') i++;
    if (linha[i] < '0' || linha[i] > '9') return 0;
    while (linha[i] >= '0' && linha[i] <= '9') {
        int digito = linha[i++] - '0';
        if (numero > (limite - digito) / 10) return 0;
        numero = numero * 10 + digito;
    }
    while (linha[i] == ' ' || linha[i] == '\t' || linha[i] == '\r') i++;
    if (linha[i] != '\0') return 0;
    *valor = numero;
    return 1;
}

int main(void) {
    int notas[12];
    for (int i = 0; i < ALUNOS; i++) {
        do {
            printf("Nota do aluno %d (0 a 10): ", i + 1);
            int estado = lerInteiro(&notas[i]);
            if (estado == -1) return 0;
            if (estado == 1 && notas[i] >= 0 && notas[i] <= 10) break;
            puts("Nota invalida.");
        } while (1);
    }
    float media = calcularMedia(notas, ALUNOS);
    int menor = notas[0];
    for (int i = 1; i < ALUNOS; i++)
        if (notas[i] < menor) menor = notas[i];
    printf("Media: %.2f\n", media);
    printf("Aprovados: %d\n", contarAprovados(notas, ALUNOS));
    printf("Maior nota: %d\n", encontrarMaiorNota(notas, ALUNOS));
    printf("Menor nota: %d\n", menor);
    printf("Acima da media: %d\n", contarAcimaMedia(notas, ALUNOS, media));
    puts("Notas na ordem cadastrada:");
    for (int i = 0; i < ALUNOS; i++)
        printf("%d%s", notas[i], i == ALUNOS - 1 ? "\n" : " ");
    return 0;
}
