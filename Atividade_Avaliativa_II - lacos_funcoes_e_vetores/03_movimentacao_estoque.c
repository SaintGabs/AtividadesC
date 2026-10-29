#include <stdio.h>

#define PRODUTOS 10

void exibirMenu(void) {
    puts("\n1 - Consultar estoque\n2 - Registrar entrada\n3 - Registrar saida\n4 - Encerrar");
    printf("Opcao: ");
}

int registrarEntrada(int estoque[], int produto, int quantidade) {
    if (produto < 1 || produto > PRODUTOS) {
        puts("Produto invalido.");
        return 0;
    }
    if (quantidade <= 0) {
        puts("Quantidade invalida.");
        return 0;
    }
    int indice = produto - 1;
    if (quantidade > ((int)(~0u >> 1)) - estoque[indice]) {
        puts("Limite de estoque excedido.");
        return 0;
    }
    estoque[indice] += quantidade;
    puts("Entrada registrada.");
    return 1;
}

int registrarSaida(int estoque[], int produto, int quantidade) {
    if (produto < 1 || produto > PRODUTOS) {
        puts("Produto invalido.");
        return 0;
    }
    if (quantidade <= 0) {
        puts("Quantidade invalida.");
        return 0;
    }
    int indice = produto - 1;
    if (quantidade > estoque[indice]) {
        puts("Estoque insuficiente.");
        return 0;
    }
    estoque[indice] -= quantidade;
    puts("Saida registrada.");
    return 1;
}
long long calcularTotalEstoque(const int estoque[], int tamanho) {
    long long total = 0;
    for (int i = 0; i < tamanho; i++) total += estoque[i];
    return total;
}

int contarProdutosZerados(const int estoque[], int tamanho) {
    int quantidade = 0;
    for (int i = 0; i < tamanho; i++)
        if (estoque[i] == 0) quantidade++;
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
    int estoque[10];
    int opcao, produto, quantidade, estado;
    for (int i = 0; i < PRODUTOS; i++) {
        do {
            printf("Quantidade inicial do produto %d: ", i + 1);
            int estado = lerInteiro(&estoque[i]);
            if (estado == -1) return 0;
            if (estado == 1 && estoque[i] >= 0) break;
            puts("Quantidade inicial invalida.");
        } while (1);
    }
    do {
        exibirMenu();
        estado = lerInteiro(&opcao);
        if (estado == -1) return 0;
        if (estado == 0) opcao = 0;
        switch (opcao) {
            case 1:
                for (int i = 0; i < PRODUTOS; i++)
                    printf("Produto %d: %d\n", i + 1, estoque[i]);
                printf("Total de unidades: %lld\n", calcularTotalEstoque(estoque, PRODUTOS));
                printf("Produtos sem estoque: %d\n", contarProdutosZerados(estoque, PRODUTOS));
                break;
            case 2:
            case 3:
                printf("Numero do produto (1 a 10): ");
                estado = lerInteiro(&produto);
                if (estado == -1) return 0;
                if (estado == 0 || produto < 1 || produto > PRODUTOS) {
                    puts("Produto invalido.");
                    break;
                }
                printf("Quantidade movimentada: ");
                estado = lerInteiro(&quantidade);
                if (estado == -1) return 0;
                if (estado == 0 || quantidade <= 0) {
                    puts("Quantidade invalida.");
                    break;
                }
                if (opcao == 2) registrarEntrada(estoque, produto, quantidade);
                else registrarSaida(estoque, produto, quantidade);
                break;
            case 4:
                puts("Programa encerrado.");
                break;
            default:
                puts("Opcao invalida.");
        }
    } while (opcao != 4);
    return 0;
}
