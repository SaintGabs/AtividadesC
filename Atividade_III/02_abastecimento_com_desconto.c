 //Escreva um programa C que leia o número de litros vendidos, o tipo de combustível (codificado da seguinte forma: A-álcool, G-gasolina), calcule e imprima o valor a ser pago pelo cliente sabendo-se que o preço do litro da gasolina é R$ 2,50 o preço do litro do álcool é R$ 1,90.

 #include<stdio.h>

int main(){
    char tipoCombustivel;
    float PrecoGasolina, PrecoAlcool, litrosVendidos, PrecoTotal, desconto;
    printf("Informe a Quantidade Abastecida: ");
    scanf("%f",&litrosVendidos);
    printf("Informe o tipo de combustivel: A-Alcool, G-Gasolina");
    scanf(" %c", &tipoCombustivel);
    PrecoAlcool = 1.9;
    PrecoGasolina = 2.5;
    if (litrosVendidos > 20 && tipoCombustivel == 'A'){
        PrecoTotal = (litrosVendidos * 1.9) * 0.95; 
        desconto = (litrosVendidos * 1.9) * 0.05;
    }
    else if (litrosVendidos<=20 && tipoCombustivel=='A'){
        PrecoTotal = (litrosVendidos * 1.9) * 0.97;
        desconto = (litrosVendidos * 1.9) * 0.03;
    }
    else if (litrosVendidos>20 && tipoCombustivel == 'G'){
        PrecoTotal = (litrosVendidos * 2.5) * 0.94;
        desconto = (litrosVendidos * 2.5) * 0.06;
    }
    else if (litrosVendidos<=20 && tipoCombustivel=='G'){
        PrecoTotal = (litrosVendidos * 2.5) * 0.96;
        desconto = (litrosVendidos * 2.5) * 0.04;
    }

    printf("Valor a ser pago: %.2f", PrecoTotal);
    printf("\nDesconto: %.2f", desconto);

    return 0;
}
