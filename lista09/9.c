#include <stdio.h>
#include <math.h>

int fatorial(int n);

double e_exp(double x, int n);

int main() {
    int n;
    double x, soma;

    printf("Insira o expoente e o numero de termos a serem somados:\n");
    scanf("%lf%d%*c", &x, &n);

    soma = e_exp(x, n);

    printf("A soma eh %.2lf\n", soma);

    return 0;
}

int fatorial(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n * fatorial(n - 1);
    }
}

double e_exp(double x, int n) {
    if (n == 1) {
        return 1;
    }
    else {
        return (pow(x, n - 1) / fatorial(n - 1)) + e_exp(x, n - 1);
    }
}
