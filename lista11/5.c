#include <stdio.h>
#include <stdlib.h>

struct cell {
    int conteudo;
    struct cell *seg;
};

typedef struct cell celula;

void insira(int y, celula *lst);
celula * menor_elementoI(celula *lst);
celula * menor_elementoR(celula *p, celula *q);
void imprima(celula *lst);

int main() {
    celula cabeca, *lst;

    lst = &cabeca;
    cabeca.seg = NULL;

    insira(10, lst);
    insira(7, lst);
    insira(20, lst);
    insira(5, lst);

    if (lst->seg != NULL) {
        printf("Menor elemento iterativamente: %d\n", menor_elementoI(lst->seg)->conteudo);
        printf("Menor elemento recursivamente: %d\n", menor_elementoR(lst->seg, lst->seg)->conteudo);
    }

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

celula * menor_elementoI(celula *p) {
    int menor;

    celula *cel;

    menor = p->conteudo;
    cel = p;

    while (p->seg != NULL) {
        if (p->seg->conteudo < menor) {
            menor = p->seg->conteudo;
            cel = p->seg;
        }
        p = p->seg;
    }

    return cel;
} 

celula * menor_elementoR(celula *p, celula *q) {
    if (p->seg == NULL) {
        return q;
    }
    
    if (p->conteudo < q->conteudo) {
        q = p;
    }

    q = menor_elementoR(p->seg, q); 
    return q;
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
