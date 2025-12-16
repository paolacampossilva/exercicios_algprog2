#include <stdio.h>
#include <stdlib.h>

int main() {
    int v[2], i;

    FILE *arq;
    arq = fopen("entrada.dat", "wb");

    if (arq == NULL) {
        perror("Erro na abertura do arquivo!");
        exit(1);
    }

    printf("Insira dois numeros:\n");
    scanf("%d%d%*c", &v[0], &v[1]);

    for (i = 0; i < 2; i++) {
        fwrite(&v[i], sizeof(int), 1, arq);
    }

    fclose(arq);
    return 0;
}
