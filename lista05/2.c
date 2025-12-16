#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, soma;

    FILE *in;
    in = fopen("entrada.txt", "r");

    FILE *out;
    out = fopen("saida.txt", "w");

    if (in == NULL || out == NULL) {
        perror("Erro ao abrir o arquivo!");
        exit(1);
    }

    fscanf(in, "%d%d", &a, &b);

    soma = a + b;

    fprintf(out, "%d", soma);

    return 0;
}
