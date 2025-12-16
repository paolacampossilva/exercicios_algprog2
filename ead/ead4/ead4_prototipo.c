#include <stdio.h>

#define N 2001

int main() {
    int i = 0, j, op, tamanho, cont, e, d, index;
    char string[N];

    while (1) {
        scanf("%s", string); // Entrada

        // Verificacao do final da entrada
        if (string[0] == '-') {
            break;
        }

        op = 0;
        e = 0;
        d = 0;
        if (string[0] != '\0' && string[0] != ' ') {
            tamanho = 0;
            while (string[tamanho] != '\0') {
                if (string[tamanho] == '{') {
                    e++;
                }
                else {
                    d++;
                }

                tamanho++;
            }

            if (string[0] == '}') {
                string[0] = '{';
                e++;
                d--;
                op++;
            }
            if (string[tamanho - 1] == '{') {
                string[tamanho - 1] = '}';
                e--;
                d++;
                op++;
            }

            cont = 0;
            if (e > d) {
                for (j = 0; j < tamanho; j++) {
                    if (cont == tamanho / 2) {
                        index = j;
                        break;
                    }
                    if (string[j] == '{') {
                        cont++;
                    }
                }
                for (j = index; j < tamanho; j++) {
                    if (string[j] != '}') {
                        string[j] = '}';
                        op++;
                    }
                }
            }
            else {
                for (j = tamanho - 1; j >= 0; j--) {
                    if (cont == tamanho / 2) {
                        index = j;
                        break;
                    }
                    if (string[j] == '}') {
                        cont++;
                    }
                }
                for (j = index; j >= 0; j--) {
                    if (string[j] != '{') {
                        string[j] = '{';
                        op++;
                    }
                }
            }
        }

        printf("%d. %d\n", i + 1, op); // Saida
        printf("%s\n", string); // so pra ver se ta certinho a alteracao
        i++;
    }

    return 0;
}
