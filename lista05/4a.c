//fib_arq.cpp

#include <stdio.h>
#include <stdlib.h>

int main() {
    int fib[30], i;
    fib[0] = 1;
    fib[1] = 1;

    FILE *arq;
    arq = fopen("30_fib.txt","w+");
    
    if (arq == NULL) {
        perror("Erro ao abrir o arquivo!");
        exit(1);
    }

    fprintf(arq, "%d %d ", fib[0], fib[1]);

    for (i = 2; i < 30; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        fprintf(arq, "%d ", fib[i]);
    }

    fclose(arq);

    return 0;
}
