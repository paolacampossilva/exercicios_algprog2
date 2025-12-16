#include <stdio.h>
#include <stdlib.h>

struct cell {
    struct cell *ant;
    int conteudo;
    struct cell *seg;
};

typedef struct cell celula;

void enfileire(celula *lst, int y);
int desenfileire(celula *lst);

int main() {
    celula c, *lst;
    lst = &c;

    lst->ant = lst;
    lst->seg = lst;

    int y;

    enfileire(lst, 33);
    enfileire(lst, 7);
    enfileire(lst, 11);
    y = desenfileire(lst);
    y = desenfileire(lst);
    enfileire(lst, 2);
    y = desenfileire(lst);

    return 0;
}

void enfileire(celula *lst, int y) {
    celula *nova;
    nova = (celula *) malloc(sizeof(celula));

    nova->conteudo = y;

    nova->seg = lst->seg;
    nova->ant = lst;
    lst->seg->ant = nova;
    lst->seg = nova;
}

int desenfileire(celula *lst) {
    // Fila vazia (Queue Underflow)
    if (lst->seg == lst) {
        printf("Underflow!\n");
        return -1;
    }

    celula *p;
    p = lst->ant;

    int y;
    y = p->conteudo;

    p->ant->seg = lst;
    lst->ant = p->ant;

    free(p);

    return y;
}
