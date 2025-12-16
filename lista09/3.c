#include <stdio.h>

int contagem(int n);

int main() {
    int n, digitos;

    printf("Insira um numero:\n");
    scanf("%d%*c", &n);

    digitos = contagem(n);

    printf("A quantidade de digitos de %d eh %d\n", n, digitos);

    return 0;
}

int contagem(int n) {
    if (n < 10) {
        return 1;
    }
    else {
        return 1 + contagem(n / 10);
    }
}
