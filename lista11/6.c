#include <stdio.h>
#include <stdlib.h>

struct cell {
    int conteudo;
    struct cell *seg;
};

typedef struct cell celula;

void insira_c_cabeca(celula *lst, int y);
void insira_s_cabeca(celula **lst, int y);
celula * busque_I(celula *p, int y);
celula * busque_R(celula *p, int y);

int main() {
    celula c, *lst_c, *lst_s, *p;
    lst_c = &c;
    lst_c->seg = NULL;

    lst_s = NULL;

    // Lista com cabeca
    insira_c_cabeca(lst_c, 4);
    insira_c_cabeca(lst_c, 3);
    insira_c_cabeca(lst_c, 2);
    insira_c_cabeca(lst_c, 1);

    // Lista sem cabeca
    insira_s_cabeca(&lst_s, 4);
    insira_s_cabeca(&lst_s, 3);
    insira_s_cabeca(&lst_s, 2);
    insira_s_cabeca(&lst_s, 1);

    printf("Buscando iterativamente:\n");

    p = busque_I(lst_c->seg, 4);
    
    if (p == NULL) {
        printf("Valor nao encontrado!\n");
    }
    else {
        printf("Valor da com cabeca: %d\n", p->conteudo);
    }

    p = busque_I(lst_s, 4);
    if (p == NULL) {
        printf("Valor nao encontrado!\n");
    }
    else {
        printf("Valor da sem cabeca: %d\n", p->conteudo);
    }

    printf("\nBuscando recursivamente:\n");

    p = busque_R(lst_c->seg, 4);
    if (p == NULL) {
        printf("Valor nao encontrado!\n");
    }
    else {
        printf("Valor da com cabeca: %d\n", p->conteudo);
    }

    p = busque_R(lst_s, 4);
    if (p == NULL) {
        printf("Valor nao encontrado!\n");
    }
    else {
        printf("Valor da sem cabeca: %d\n", p->conteudo);
    }

    return 0;
}

void insira_c_cabeca(celula *lst, int y) {
    celula *nova;
    nova = (celula *) malloc(sizeof(celula));
    nova->conteudo = y;

    nova->seg = lst->seg;
    lst->seg = nova;
}

void insira_s_cabeca(celula **lst, int y) {
    celula *nova;
    nova = (celula *) malloc(sizeof(celula));
    nova->conteudo = y;

    if (*lst == NULL) {
        *lst = nova;
        nova->seg = NULL;
        return;
    }

    nova->seg = *lst;
    *lst = nova;
}

celula * busque_I(celula *p, int y) {
    while (p != NULL && p->conteudo < y) {
        p = p->seg;
    }

    if (p != NULL && p->conteudo == y) {
        return p;
    }
    else {
        return NULL;
    }
}

celula * busque_R(celula *p, int y) {
    if (p == NULL || p->conteudo > y) {
        return NULL;
    }
    else if (p->conteudo == y) {
        return p;
    }
    else {
        return busque_R(p->seg, y);
    }
}
