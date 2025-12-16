//ITERATIVAMENTE

#include <stdio.h>

int main() {
    int a, b, m, i;

    printf("Insira dois numeros para a e b:\n");
    scanf("%d%d%*c", &a, &b);

    m = a;

    for (i = 1; i < b; i++) {
        m = m + a;
    } 

    printf("O produto de %d e %d eh %d\n", a, b, m);

    return 0;
}
