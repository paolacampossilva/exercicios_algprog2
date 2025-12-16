#include <stdio.h>
#include <stdlib.h>

int main() {
    int soma;

    FILE *arq;
    arq = fopen("saida.dat", "rb");

    if (arq == NULL) {
        perror("Erro na abertura do arquivo!");
        exit(1);
    }

    fread(&soma, sizeof(int), 1, arq);

    printf("A soma eh %d\n", soma);

    fclose(arq);
    return 0;
}
