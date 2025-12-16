// RECURSIVAMENTE

#include <stdio.h>

int gfib(int f0, int f1, int n);

int main() {
    int n, fib;

    printf("Insira um numero:\n");
    scanf("%d%*c", &n);

    fib = gfib(0, 1, n);

    if (fib == -1) {
        printf("Numero invalido!\n");
    }
    else {
        printf("O fibonacci de %d eh %d\n", n, fib);
    }

    return 0;
}

int gfib(int f0, int f1, int n) {
    if (n == 0) {
        return f0;
    }
    else if (n == 1) {
        return f1;
    }
    else if (n > 1) {
        return gfib(f0, f1, n - 1) + gfib(f0, f1, n - 2);
    }
    else {
        return -1;
    }
}
