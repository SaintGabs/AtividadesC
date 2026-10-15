
#include <stdio.h>

int main()
{
    float fixo, horas, salario;
    fixo = 10.25;
    printf("horas trabalhadas: ");
    scanf_s("%f", &horas);

    salario = horas * fixo;
    printf("Seu Salario: R$%.3f", salario);
}
