#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arq;
    arq = fopen("entrada.txt", "r");

    if (arq == NULL) {
        perror("Erro na abertura do arquivo!");
        exit(1);
    }

    int s, cont = 0;

    while (1) {
        s = fscanf(arq, "%*s");

        if (s == EOF) {
            break;
        }

        cont++;
    }

    printf("%s %d %s nesse arquivo\n", cont == 1? "Existe":"Existem", cont, cont == 1? "palavra":"palavras");

    fclose(arq);
    return 0;
}
