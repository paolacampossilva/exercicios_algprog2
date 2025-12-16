#include <stdio.h>

int main() {
    int matriz[100][100], matriz_t[100][100], l, c, i, j;

    printf("Insira a qte de linhas e colunas da matriz: \n");
    scanf("%d%d%*c", &l, &c);
    
    /* Linha por linha
    
    for (i = 0; i < l; i++) {
        printf("Insira a linha %d:\n", i);
        for (j = 0; j < c; j++) {
            scanf("%d%*c", &matriz[i][j]);
            matriz_t[j][i] = matriz[i][j];
        }
    }
    */

    //Elemento por elemento
    
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            printf("Insira o elemento da linha %d e coluna %d:\n", i, j);
            scanf("%d%*c", &matriz[i][j]);
            matriz_t[j][i] = matriz[i][j];
        }
    }
    
    printf("Matriz Transposta:\n");
    for (i = 0; i < c; i++) {
        for (j = 0; j < l; j++) {
            if (j == l - 1) {
                printf("%d\n", matriz_t[i][j]);
            }
            else {
                printf("%d ", matriz_t[i][j]);
            }
        }
    }

    return 0;
}
