//consulta_fib.cpp

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, fib, i;

    FILE *arq;
    arq = fopen("30_fib.txt", "r");

    if (arq == NULL) {
        perror("Erro ao abrir o arquivo!");
        exit(1);
    }

    printf("Insira um numero para obter o seu fibonacci:\n");
    scanf("%d%*c", &n);

    for (i = 1; i <= 30; i++) {
        fscanf(arq, "%d", &fib);
    }

    printf("Fibonacci de %d eh %d\n", n, fib);

    fclose(arq);

    return 0;
}
