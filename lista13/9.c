#include <stdio.h>
#include <stdlib.h>

struct cell {
    int conteudo;
    struct cell *seg;
};

typedef struct cell celula;

void empilhe(celula **lst, int y);
int desempilhe(celula **lst);

int main() {
    celula *lst; // Pilha

    lst = NULL;

    int y;

    empilhe(&lst, 33);
    empilhe(&lst, 7);
    empilhe(&lst, 11);
    y = desempilhe(&lst);
    y = desempilhe(&lst);
    empilhe(&lst, 2);
    y = desempilhe(&lst);

    return 0;
}

void empilhe(celula **lst, int y) {
    celula *nova;

    nova = (celula *) malloc(sizeof(celula));

    nova->conteudo = y;

    nova->seg = *lst;
    *lst = nova;
}

int desempilhe(celula **lst) {
    int y;
    celula *p;

    // Pilha esta vazia (Stack Underflow)
    if (*lst == NULL) {
        printf("Underflow!\n");
        return -1;
    }

    p = *lst;
    y = p->conteudo;

    *lst = (*lst)->seg;

    free(p);

    return y;
}
