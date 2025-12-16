#include <stdio.h>
#include <stdlib.h>

int main() {
    int v[2], i, soma = 0;

    FILE *in;
    in = fopen("entrada.dat", "rb");

    FILE *out;
    out = fopen("saida.dat", "wb");

    if (in == NULL || out == NULL) {
        perror("Erro na abertura do arquivo!");
        exit(1);
    }

    for (i = 0; i < 2; i++) {
        fread(&v[i], sizeof(int), 1, in);
        soma = soma + v[i];
    }

    fwrite(&soma, sizeof(int), 1, out);

    fclose(in);
    fclose(out);
    return 0;
}
