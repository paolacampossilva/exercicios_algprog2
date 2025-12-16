#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *odd;
    odd = fopen("lotr_cap1_odd.txt", "r");

    FILE *even;
    even = fopen("lotr_cap1_even.txt", "r");

    FILE *arq;
    arq = fopen("lotr_cap1_recovered.txt", "w");

    if (odd == NULL || even == NULL || arq == NULL) {
        perror("Erro ao abrir o arquivo!");
        exit(1);
    }

    int i = 1;
    char linha[200];

    while (1) {
        if (i % 2 == 0) {
            if (fgets(linha, 200, even) == NULL) {
                if (fgets(linha, 200, odd) == NULL) {
                    break;
                }
            }
        }
        else {
            if (fgets(linha, 200, odd) == NULL) {
                if (fgets(linha, 200, even) == NULL) {
                    break;
                }
            }
        }
        fprintf(arq, "%s", linha);
        i++;
    }

    fclose(odd);
    fclose(even);
    fclose(arq);

    return 0;
}
