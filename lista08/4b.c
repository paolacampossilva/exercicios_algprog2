//RECURSIVAMENTE

#include <stdio.h>

int fibonacci(int n, int *cont);

int main() {
    int n, fib, cont = 0;

    printf("Insira um numero (1 <= n <= 10):\n");
    scanf("%d%*c", &n);

    if (n < 1 || n > 10) {
        printf("Valor invalido!\n");
    }
    else {
        fib = fibonacci(n, &cont);

        printf("O fibonacci de %d eh %d\n", n, fib);

        if (cont == 1) {
            printf("Foi feita %d soma\n", cont);
        }
        else {
            printf("Foram feitas %d somas\n", cont);
        }
    }
    
    return 0;
}

int fibonacci(int n, int *cont) {
    if (n == 0 || n == 1) {
        return n;
    }
    else {
        *cont = *cont + 1;
        return fibonacci(n - 1, cont) + fibonacci(n - 2, cont);
    }
}

/*

O padrão é que a quantidade de somas de um determinado número de Fibonacci é a 
quantidade de somas do anterior mais o número de Fibonacci do anterior, por exemplo:

Insira um numero (1 <= n <= 10):
8
O fibonacci de 8 eh 21
Foram feitas 33 somas

Insira um numero (1 <= n <= 10):
9
O fibonacci de 9 eh 34
Foram feitas 54 somas

Assim, a quantidade de somas de Fibonacci de 9 (54) é a quantidade de somas de 
Fibonacci de 8 (33) mais o Fibonacci de 8 (21).

Logo, como 33 + 21 = 54, então esse é um padrão aceitável.

*/
