//RECURSIVAMENTE

#include <stdio.h>

int multiplicacao(int a, int b);

int main() {
    int a, b, m;

    printf("Insira dois numeros para a e b:\n");
    scanf("%d%d%*c", &a, &b);

    m = multiplicacao(a, b);

    printf("O produto de %d e %d eh %d\n", a, b, m);
    
    return 0;
}

int multiplicacao(int a, int b) {
    if (b == 1) {
        return a;
    }
    else {
        return a + multiplicacao(a, b - 1);
    }
}
