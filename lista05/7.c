#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arq;
    arq = fopen("entrada.txt", "r");

    if (arq == NULL) {
        perror("Erro na abertura do arquivo!");
        exit(1);
    }

    char alfabeto[27] = "abcdefghijklmnopqrstuvwxyz", letra;
    int qte[26], i, s;

    for (i = 0; i < 26; i++) {
        qte[i] = 0;
    }

    while (1) {
        s = fscanf(arq, "%c", &letra);

        if (s == EOF || s == 0) {
            break;
        }

        for (i = 0; i < 26; i++) {
            if (letra == alfabeto[i] || letra + 32 == alfabeto[i]) {
                qte[i]++;
                break;
            }
        }
    }

    printf("Quantidade de cada uma das letras:\n");
    for (i = 0; i < 26; i++) {
        printf("'%c' - %d\n", alfabeto[i], qte[i]);
    }

    fclose(arq);
    return 0;
}
