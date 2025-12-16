#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arq;
    arq = fopen("seq30_fib.dat", "rb");

    if (arq == NULL) {
        perror("Erro na abertura do arquivo!");
        exit(1);
    }

    int n, fib;

    printf("Insira um numero (1 <= n <= 30):\n");
    scanf("%d%*c", &n);

    if (n < 1 || n > 30) {
        printf("Valor Invalido!\n");
    }
    else {
        fseek(arq, (n - 1) * sizeof(int), SEEK_SET);

        fread(&fib, sizeof(int), 1, arq);

        printf("Fibonacci de %d eh %d\n", n, fib);
    }

    fclose(arq);
    return 0;
}
