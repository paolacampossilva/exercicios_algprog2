//INTERATIVAMENTE

#include <stdio.h>

int main() {
    int a = 0, b = 1, c, i, soma = 0, n;

    printf("Insira um numero (1 <= n <= 10):\n");
    scanf("%d%*c", &n);

    if (n < 1 || n > 10) {
        printf("Valor invalido!\n");
    }
    else {
        for (i = 2; i <= n; i++) {
            c = a;
            a = b;
            b = c + b;
            soma = soma + 1;
        }

        printf("O fibonacci de %d eh %d\n", n, b);
        printf("O total de somas feitas eh %d\n", soma);
    }
    
    return 0;
}

/*

O padrão é que a quantidade de somas de um determinado número de Fibonacci 
é esse mesmo número menos um, por exemplo:

Insira um numero (1 <= n <= 10):
8
O fibonacci de 8 eh 21
O total de somas feitas eh 7

Insira um numero (1 <= n <= 10):
9
O fibonacci de 9 eh 34
O total de somas feitas eh 8

*/
