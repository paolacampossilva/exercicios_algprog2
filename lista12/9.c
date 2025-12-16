#include <stdio.h>
#include <stdlib.h>

struct cell {
    int conteudo;
    struct cell *seg;
};

typedef struct cell celula;

void enfileire(celula **t, int y); // final da lista
int desenfileire(celula *lst); // comeco da lista (depois da cabeca)

int main() {
    celula c, *lst, *t; // Fila

    lst = &c;
    t = lst;
    lst->seg = NULL;

    int y;

    enfileire(&t, 33);
    enfileire(&t, 7);
    enfileire(&t, 11);
    y = desenfileire(lst);
    y = desenfileire(lst);
    enfileire(&t, 2);
    y = desenfileire(lst);

    return 0;
}

void enfileire(celula **t, int y) {
    celula *nova;
    nova = (celula *) malloc(sizeof(celula));

    nova->conteudo = y;
    
    (*t)->seg = nova;
    nova->seg = NULL;
    (*t) = (*t)->seg;
}

int desenfileire(celula *lst) {
    celula *p;
    p = lst->seg;

    // Fila vazia (Queue Underflow)
    if (p == NULL) {
        printf("Underflow!\n");
        return -1;
    }

    int y;
    y = p->conteudo;

    lst->seg = p->seg;

    free(p);

    return y;
}
