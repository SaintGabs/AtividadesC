
#include <stdio.h>
#include <math.h>
int main(){
    float TamanhoaSerPintado;
    float PrecoTotal;
    int QuantidadeDeLatas;
    printf("informe a quantidade de metros quadrados a ser pintado: ");
    scanf("%f", &TamanhoaSerPintado);
    QuantidadeDeLatas = (TamanhoaSerPintado/54);
    if (QuantidadeDeLatas < 1)
        QuantidadeDeLatas = 1;
    PrecoTotal = (int)(ceil(QuantidadeDeLatas * 80));
    printf("Quatidade de latas: %d\n", QuantidadeDeLatas);
    printf("Preco Total: %.2f", PrecoTotal);


    return 0;
}