#include <stdio.h>

int potencia(double base, int expoente);

int main() {
    int base, expoente, pot;

    printf("Insira a base e o expoente:\n");
    scanf("%d%d%*c", &base, &expoente);

    if (expoente < 0) {
        printf("Expoente invalido!");
    }
    else {
        pot = potencia(base, expoente);

        printf("A potencia de %d elevado a %d eh %d\n", base, expoente, pot);
    }

    return 0;
}

int potencia(double base, int expoente) {
    if (expoente == 0) {
        return 1;
    }
    else if (expoente == 1) {
        return base;
    }
    else {
        return base * potencia(base, expoente - 1);
    }
}
