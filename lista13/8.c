#include <stdio.h>
#include <stdlib.h>

struct cell {
    int conteudo;
    struct cell *seg;
};

typedef struct cell celula;

void empilhe(celula *lst, int y);
int desempilhe(celula *lst);

int main() {
    celula c, *lst;
    lst = &c;

    lst->seg = NULL;

    int y;

    empilhe(lst, 33);
    empilhe(lst, 7);
    empilhe(lst, 11);
    y = desempilhe(lst);
    y = desempilhe(lst);
    empilhe(lst, 2);
    y = desempilhe(lst);

    return 0;
}

void empilhe(celula *lst, int y) {
    celula *nova;

    nova = (celula *) malloc(sizeof(celula));
    nova->conteudo = y;

    nova->seg = lst->seg;
    lst->seg = nova;
}

int desempilhe(celula *lst) {
    // Pilha esta vazia (Stack Undeflow)
    if (lst->seg == NULL) {
        printf("Underflow!\n");
        return -1;
    }

    celula *p;
    p = lst->seg;

    int y;
    y = p->conteudo;

    lst->seg = p->seg;

    free(p);

    return y;
}
