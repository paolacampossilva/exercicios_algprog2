#include <stdio.h> 
#include <stdlib.h>

int main() {
    FILE *arq;
    arq = fopen("seq30_fib.dat", "wb");

    if (arq == NULL) {
        perror("Erro na abertura do arquivo!");
        exit(1);
    }
    int i, fib[30] = {1, 1};
    for (i = 2; i < 30; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    fwrite(fib, 30 * sizeof(int), sizeof(int), arq);

    fclose(arq);
    return 0;
}
