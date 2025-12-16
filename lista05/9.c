#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *in;
    in = fopen("entrada.txt", "r");

    FILE *out;
    out = fopen("saida.txt", "w");

    if (in == NULL || out == NULL) {
        perror("Erro na abertura do arquivo!");
        exit(1);
    }

    int s, cont = 0, i, ordenado = 0;
    char c, **l, linha[500], *temp;

    while (fgets(linha, 500, in) != NULL) {
        cont++;
    }

    rewind(in);

    l = malloc(cont * sizeof(char *));

    for (i = 0; i < cont; i++) {
        fgets(linha, 500, in);
        linha[strcspn(linha, "\n")] = '\0';
        l[i] = malloc(strlen(linha) + 1);
        strcpy(l[i], linha);
    }

    while (!ordenado) {
        ordenado = 1;
        for (i = 0; i < cont - 1; i++) {
            if (strcmp(l[i], l[i + 1]) > 0) {
                temp = l[i];
                l[i] = l[i + 1];
                l[i + 1] = temp;
                ordenado = 0;
            }
        }
    }

    for (i = 0; i < cont; i++) {
        fprintf(out, "%s\n", l[i]);
        free(l[i]);
    }

    free(l);

    fclose(in);
    fclose(out);

    return 0;
}
