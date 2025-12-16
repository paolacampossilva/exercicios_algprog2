#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *in;
    in = fopen("entrada.txt", "r");

    FILE *out;
    out = fopen("saida.txt", "w");

    if (in == NULL || out == NULL) {
        perror("Erro na abertura do arquivo!");
        exit(1);
    }

    int s;
    char c, anterior = '\0';

    while (1) {
        s = fscanf(in, "%c", &c);

        if (s == EOF || s == 0) {
            break;
        }

        if (anterior == ' ' && c == ' ') {
            continue;
        }

        fprintf(out, "%c", c);
        anterior = c;
    }

    fclose(in);
    fclose(out);

    return 0;
}
