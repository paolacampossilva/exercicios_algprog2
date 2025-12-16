// RECURSIVAMENTE

#include <stdio.h>
#include <stdlib.h>

struct cell {
    int conteudo;
    struct cell *seg;
};

typedef struct cell celula;

void insira(int y, celula *lst);
void remova_tudoR(celula *lst);
void imprima(celula *lst);

int main() {
    celula cabeca, *lst;

    lst = &cabeca;
    cabeca.seg = NULL;

    insira(10, lst);
    insira(7, lst);
    insira(20, lst);
    insira(5, lst);

    imprima(lst);

    remova_tudoR(lst);

    imprima(lst);

    return 0;
}

void insira(int y, celula *lst) {
    celula *nova;

    nova = (celula *) malloc(sizeof(celula));

    nova->conteudo = y;

    nova->seg = lst->seg;
    lst->seg = nova;
}

void remova_tudoR(celula *lst) {
    if (lst->seg == NULL) {
        return;
    }

    remova_tudoR(lst->seg);
    free(lst->seg);
    lst->seg = NULL;
}

void imprima(celula *lst) {
    celula *p;
    printf("cabeca -> ");
    for(p = lst->seg; p != NULL; p = p->seg) {
        printf("%d -> ", p->conteudo);
    }
    printf("NULL");
    printf("\n");
}
