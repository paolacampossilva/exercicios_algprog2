#include <stdio.h>
#include <stdlib.h>

struct cel {
    int conteudo;
    struct cel *seg;
};

typedef struct cel celula;

void insira(int y, celula *p);
void imprima(celula *lst);
void insira_em_ordem(int y, celula *p);
celula *busque(int x, celula *lst);
void remova_seguinte(celula *p);
void busque_e_remova(int x, celula *lst);

int main() {
    celula c, *lst, *cel1, *cel2;

    c.seg = NULL;

    lst = &c;

    insira_em_ordem(5, lst);
    insira_em_ordem(1, lst);
    insira_em_ordem(3, lst);
    insira_em_ordem(7, lst);

    imprima(lst);

    busque_e_remova(3, lst);
    busque_e_remova(8, lst);

    imprima(lst);

    return 0;
}

void insira(int y, celula *p) {
    celula *nova;

    nova = (celula *) malloc(sizeof(celula));

    nova->conteudo = y;
    nova->seg = p->seg;
    p->seg = nova;
}

void imprima(celula *lst) {
    celula *p;

    printf("cabeca -> ");

    for (p = lst->seg; p != NULL; p = p->seg) {
        printf("%d -> ", p->conteudo);
    }
    printf("NULL\n");
}

void insira_em_ordem(int y, celula *p) {
  celula *q;
  
  q = p->seg;
    while (p != NULL && q != NULL) {
        if (q->conteudo > y) {
            break;
        }
        
        p = p->seg;
        q = q->seg;
    }
    
    insira(y, p);
}

celula *busque(int x, celula *lst) {
    celula *p;
    p = lst->seg;
    while (p != NULL) {
        if (p->conteudo == x) {
            break;
        }

        p = p->seg;
    }

    return p;
}

void remova_seguinte(celula *p) {
    celula *q;
    q = p->seg;

    p->seg = q->seg;
    
    free(q);
}

void busque_e_remova(int x, celula *lst) {
    celula *p;
    p = lst;

    while (p->seg != NULL) {
        if (p->seg->conteudo == x) {
            remova_seguinte(p);
            return;
        }

        p = p->seg;
    }

    printf("O elemento %d NAO esta na lista\n", x);
}
