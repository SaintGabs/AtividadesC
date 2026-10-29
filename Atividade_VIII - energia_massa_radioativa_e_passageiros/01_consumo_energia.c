#include <stdio.h>

int lerConsumo(double *valor) {
    char linha[128], extra;
    int c, i = 0, longa = 0;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (i < 127) linha[i++] = (char)c;
        else longa = 1;
    }
    linha[i] = '\0';
    if (c == EOF && i == 0 && !longa) return -1;
    if (longa || sscanf(linha, "%lf %c", valor, &extra) != 1) return 0;
    if (!(*valor >= 0.0 && *valor <= 1.7976931348623157e308)) return 0;
    return 1;
}

int main(void) {
    double consumo[7];
    double total = 0.0, media;
    int diaMaior = 0, diasAcima = 0;

    for (int i = 0; i < 7; i++) {
        int estado;
        do {
            printf("Consumo do dia %d em kWh (use ponto decimal): ", i + 1);
            estado = lerConsumo(&consumo[i]);
            if (estado == -1) return 0;
            if (estado == 0) puts("Consumo invalido.");
        } while (estado != 1);

        total += consumo[i];
        if (consumo[i] > consumo[diaMaior]) diaMaior = i;
        if (consumo[i] > 250.0) diasAcima++;
    }

    media = total / 7;
    printf("Total da semana: %.2f kWh\n", total);
    printf("Media diaria: %.2f kWh\n", media);
    printf("Maior consumo: dia %d - %.2f kWh\n", diaMaior + 1, consumo[diaMaior]);
    printf("Dias acima de 250 kWh: %d\n", diasAcima);
    return 0;
}
