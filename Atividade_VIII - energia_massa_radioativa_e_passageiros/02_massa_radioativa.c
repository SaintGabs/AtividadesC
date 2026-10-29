#include <stdio.h>

int lerMassa(double *valor) {
    char linha[128], extra;
    int c, i = 0, longa = 0;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (i < 127) linha[i++] = (char)c;
        else longa = 1;
    }
    linha[i] = '\0';
    if (c == EOF && i == 0 && !longa) return -1;
    if (longa || sscanf(linha, "%lf %c", valor, &extra) != 1) return 0;
    if (!(*valor > 0.0 && *valor <= 1.7976931348623157e308)) return 0;
    return 1;
}

int main(void) {
    double massaInicial, massaFinal;
    int tempo = 0, horas, minutos, segundos, estado;

    do {
        printf("Massa inicial em gramas (use ponto decimal): ");
        estado = lerMassa(&massaInicial);
        if (estado == -1) return 0;
        if (estado == 0) puts("Massa invalida.");
    } while (estado != 1);

    massaFinal = massaInicial;
    while (massaFinal >= 0.5) {
        massaFinal /= 2.0;
        tempo += 50;
    }

    horas = tempo / 3600;
    minutos = (tempo % 3600) / 60;
    segundos = tempo % 60;

    printf("Massa inicial: %.6f g\n", massaInicial);
    printf("Massa final: %.6f g\n", massaFinal);
    printf("Tempo: %d horas, %d minutos e %d segundos\n", horas, minutos, segundos);
    return 0;
}
