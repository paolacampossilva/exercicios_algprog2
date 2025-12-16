#include <stdio.h>
#include <stdlib.h>

struct cell {
    int conteudo;
    struct cell *seg;
};

typedef struct cell celula;

void insira(int y, celula *lst);
int conte_celulas(celula *lst);
void imprima(celula *lst);

int main() {
    celula cabeca, *lst;

    lst = &cabeca;
    cabeca.seg = NULL;

    insira(10, lst);
    insira(7, lst);
    insira(20, lst);
    insira(5, lst);

    printf("Existem %d celulas na lista\n", conte_celulas(lst));

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

int conte_celulas(celula *lst) {
    int cont = 0;

    celula *p;
    p = lst->seg;

    while(p != NULL) {
        cont++;
        p = p->seg;
    }

    return cont;
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
