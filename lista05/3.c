#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, soma, n;

    FILE *in;
    in = fopen("entrada.txt", "r");

    FILE *out;
    out = fopen("saida.txt", "w");

    if (in == NULL || out == NULL) {
        perror("Erro ao abrir o arquivo!");
        exit(1);
    }

    while (1) {
        n = fscanf(in, "%d%d", &a, &b);

        if (n == EOF) {
            break;
        }
        else if (n == 1){
            soma = a;
        }
        else {
            soma = a + b;
        }

        fprintf(out, "%d\n", soma);
    }
    
    fclose(in);
    fclose(out);
    
    return 0;
}
