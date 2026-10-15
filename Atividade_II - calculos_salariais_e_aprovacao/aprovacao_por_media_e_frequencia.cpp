
#include <stdio.h>

int main()
{
	float media, cargaH;
	int faltas;

	printf("Sua media: ");
	scanf_s("%f", &media);
	printf("Faltas: ");
	scanf_s("%d", &faltas);
	printf("Carga Horaria: ");
	scanf_s("%f", &cargaH);

	if (media >= 7 && faltas < cargaH * 0.15);
	printf("Passou");
	else printf("Reprovou");
}
