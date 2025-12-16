// ITERATIVAMENTE

#include <stdio.h>

int main() {
    int n, i, f0 = 0, f1 = 1, fib = -1;

    printf("Insira um numero:\n");
    scanf("%d%*c", &n);

    if (n == 0) {
        fib = f0;
    }
    else if (n == 1) {
        fib = f1;
    }

    for (i = 1; i < n; i++) {
        fib = f1 + f0;
        f0 = f1;
        f1 = fib;
    }

    if (fib == -1) {
        printf("Numero invalido!\n");
    }
    else {
        printf("O fibonacci de %d eh %d\n", n, fib);
    }
    
    return 0;
}
