#include <stdio.h>
#include <stdlib.h>

struct cell {
    int conteudo;
    struct cell *seg;
};

typedef struct cell celula;

void insira(int y, celula *lst);
celula * concatene_listas(celula *lst1, celula *lst2);
void imprima(celula *lst);

int main() {
    celula cabeca1, *lst1, cabeca2, *lst2, *lst;

    lst1 = &cabeca1;
    cabeca1.seg = NULL;

    lst2 = &cabeca2;
    cabeca2.seg = NULL;

    insira(10, lst1);
    insira(7, lst1);
    insira(20, lst1);
    insira(5, lst1);

    imprima(lst1);

    insira(22, lst2);
    insira(33, lst2);
    insira(24, lst2);
    insira(55, lst2);

    imprima(lst2);

    lst = concatene_listas(lst1, lst2);

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

celula * concatene_listas(celula *lst1, celula *lst2) {
    celula *p;
    p = lst1->seg;

    while(p->seg != NULL) {
        p = p->seg;
    }

    p->seg = lst2->seg;
    lst2 = NULL;

    return lst1;
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
