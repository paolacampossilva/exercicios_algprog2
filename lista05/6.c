#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *arq;
    arq = fopen("entrada.txt", "r");

    if (arq == NULL) {
        perror("Erro na abertura do arquivo!");
        exit(1);
    }

    int i = 1, s, e = 0;
    char linha[500], string[100];

    printf("Insira uma palavra:\n");
    scanf("%99s", string);

    while (fgets(linha, sizeof(linha), arq) != NULL) {
        if(strstr(linha, string) != NULL) {
            e = 1;
            printf("Palavra encontrada na linha %d!\n", i);
        }
        i++;
    }

    if (e == 0) {
        printf("Palavra nao encontrada no arquivo!\n");
    }

    fclose(arq);
    return 0;
}