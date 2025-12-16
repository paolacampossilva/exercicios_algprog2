#include <stdio.h>

int soma(int a, int b);

int main() {
    int a, b, s;

    printf("Insira dois numeros a e b:\n");
    scanf("%d%d%*c", &a, &b);

    s = soma(a, b);

    printf("A soma de %d e %d eh %d\n", a, b, s);

    return 0;
}

int soma(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return soma(a, b - 1) + 1;
    }
}
