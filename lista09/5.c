#include <stdio.h>

float serie(int n);

int main() {
    int n;
    float soma;

    printf("Insira o numero de termos que deseja somar:\n");
    scanf("%d%*c", &n);

    soma = serie(n);

    printf("A soma dos %d primeiros termos da serie eh %.2f\n", n, soma);

    return 0;
}

float serie(int n) {
    if (n == 1) {
        return 1;
    }
    else {
        if (n % 2 == 0) {
            return (1.0 / n) + serie(n - 1);
        }
        else {
            return (-1.0 / n) + serie(n - 1);
        }
    }
}
