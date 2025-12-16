#include <stdio.h>

int main() {
    int matriz[100][100], l, c, i, j, linhas = 0, colunas = 0, cont;

    printf("Insira o numero de linhas e colunas da matriz:\n");
    scanf("%d%d%*c", &l, &c);

    for (i = 0; i < l; i++) {
        cont = 0;
        printf("Insira a linha %d:\n", i);
        for (j = 0; j < c; j++) {
            scanf("%d%*c", &matriz[i][j]);
            if (matriz[i][j] == 0) {
                cont = cont + 1;
            }
        }
        if (cont == c) {
            linhas = linhas + 1;
        }
    }

    for (j = 0; j < c; j++) {
        cont = 0;
        for (i = 0; i < l; i++) {
            if (matriz[i][j] == 0) {
                cont = cont + 1;
            }
        }
        if (cont == l) {
            colunas = colunas + 1;
        }
    }

    printf("A matriz tem %d %s e %d %s\n", linhas, linhas == 1? "linha nula":"linhas nulas", colunas, colunas == 1? "coluna nula":"colunas nulas");
    return 0;
}
