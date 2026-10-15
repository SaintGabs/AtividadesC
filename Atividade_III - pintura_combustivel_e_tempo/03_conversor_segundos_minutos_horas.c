 #include<stdio.h>

int main(){
    int segundos, minutos, horas, resto;
    printf("Infome a quantidade de segundos");
    scanf("%d", &segundos);
    minutos = segundos/60;
    horas = minutos/60;
    resto = minutos%60;
    printf("\n%d Segundos são:", segundos);
    printf("\n%d Minutos", minutos);
    printf("\n%d Horas e %d minutos", horas, resto);
}