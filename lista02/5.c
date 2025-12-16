#include <stdio.h> 
#define PI 3.14

double area_circulo(double raio);

int main() {
    double raio, area;
    printf("Insira o raio do circulo para calcular a sua area:\n");
    scanf("%lf%*c", &raio);

    area = area_circulo(raio);

    printf("A area do circulo eh %.2lf\n", area);
    return 0;
}

double area_circulo(double raio) {
    return PI * (raio * raio);
}
