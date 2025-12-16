#include <stdio.h>

int main() {
    float altura, raio, volume;
    printf("Insira o raio e a altura do cilindro, respectivamente:\n");
    scanf("%f %f", &raio, &altura);
    volume = 3.14 * (raio * raio) * altura;
    printf("O volume do cilindro eh igual a %.2f \n", volume);
    return 0;
}
