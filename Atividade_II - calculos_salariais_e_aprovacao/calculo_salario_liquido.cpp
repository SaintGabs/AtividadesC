#include <stdio.h>

int main() {
	char nome[100], endereco[100], sexo[100], cidade[100], estado[100];
	int idade;
	float salariob, salariol, vt, vr, planosaude, descontos;
	vt = 0.02;
	vr = 0.05;
	planosaude = 0.10;
	printf("nome: ");
	scanf("%s", nome);

	printf("idade: ");
	scanf("%d", &idade);

	printf("endereço: ");
	scanf("%s", endereco);

	printf("sexo: ");
	scanf("%s", sexo);

	printf("cidade: ");
	scanf("%s", cidade);

	printf("estado: ");
	scanf("%s", estado);

	printf("Salario Bruto: ");
	scanf("%f", &salariob);
	descontos = salariob * (vr + vt + planosaude);
	salariol = salariob - descontos;
	printf("Seu Salario Liquido é %.3f", salariol);

}