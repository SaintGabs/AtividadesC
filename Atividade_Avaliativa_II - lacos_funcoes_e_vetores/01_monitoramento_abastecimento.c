#include <stdio.h>

#define VIAGENS 10

float calcularTotal(const float consumo[], int tamanho) {
    float total = 0.0f;
    for (int i = 0; i < tamanho; i++) total += consumo[i];
    return total;
}

float calcularMedia(const float consumo[], int tamanho) {
    return calcularTotal(consumo, tamanho) / tamanho;
}

int contarViagens(const float consumo[], int tamanho) {
    int quantidade = 0;
    for (int i = 0; i < tamanho; i++)
        if (consumo[i] > 50.0f) quantidade++;
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

int lerConsumo(float *valor) {
    char linha[128], extra;
    double numero;
    int estado = lerLinha(linha, sizeof linha);
    if (estado != 1) return estado;
    if (sscanf(linha, "%lf %c", &numero, &extra) != 1) return 0;
    if (!(numero >= 0.0 && numero <= 3.4028234663852886e38)) return 0;
    *valor = (float)numero;
    return 1;
}

int main(void) {
    float consumo[10];
    int indiceMaior = 0;
    for (int i = 0; i < VIAGENS; i++) {
        do {
            printf("Consumo da viagem %d (litros, use ponto decimal): ", i + 1);
            int estado = lerConsumo(&consumo[i]);
            if (estado == -1) return 0;
            if (estado == 1) break;
            puts("Consumo invalido.");
        } while (1);
    }
    for (int i = 1; i < VIAGENS; i++)
        if (consumo[i] > consumo[indiceMaior]) indiceMaior = i;
    printf("Total: %.2f litros\n", calcularTotal(consumo, VIAGENS));
    printf("Media: %.2f litros\n", calcularMedia(consumo, VIAGENS));
    printf("Maior consumo: viagem %d - %.2f litros\n", indiceMaior + 1, consumo[indiceMaior]);
    printf("Acima de 50 litros: %d\n", contarViagens(consumo, VIAGENS));
    puts("Consumos em ordem inversa:");
    for (int i = VIAGENS - 1; i >= 0; i--)
        printf("%.2f%s", consumo[i], i == 0 ? "\n" : " ");
    return 0;
}
