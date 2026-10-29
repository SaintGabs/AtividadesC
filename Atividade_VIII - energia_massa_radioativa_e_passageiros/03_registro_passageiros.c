#include <stdio.h>

long long calcularTotal(const int passageiros[], int tamanho) {
    long long total = 0;
    for (int i = 0; i < tamanho; i++) total += passageiros[i];
    return total;
}

int contarViagens(const int passageiros[], int tamanho) {
    int quantidade = 0;
    for (int i = 0; i < tamanho; i++)
        if (passageiros[i] > 30) quantidade++;
    return quantidade;
}

int lerQuantidade(int *valor) {
    char linha[128];
    int c, i = 0, longa = 0;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (i < 127) linha[i++] = (char)c;
        else longa = 1;
    }
    linha[i] = '\0';
    if (c == EOF && i == 0 && !longa) return -1;
    if (longa) return 0;

    int numero = 0, limite = (int)(~0u >> 1);
    i = 0;
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
    int passageiros[6];
    int viagemMaior = 0;

    for (int i = 0; i < 6; i++) {
        int estado;
        do {
            printf("Passageiros da viagem %d: ", i + 1);
            estado = lerQuantidade(&passageiros[i]);
            if (estado == -1) return 0;
            if (estado == 0) puts("Quantidade invalida.");
        } while (estado != 1);

        if (passageiros[i] > passageiros[viagemMaior]) viagemMaior = i;
    }

    printf("Total de passageiros: %lld\n", calcularTotal(passageiros, 6));
    printf("Maior quantidade: viagem %d - %d passageiros\n", viagemMaior + 1, passageiros[viagemMaior]);
    printf("Viagens com mais de 30 passageiros: %d\n", contarViagens(passageiros, 6));
    return 0;
}
