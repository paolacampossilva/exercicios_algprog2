// NAO TERMINADO

#include <stdio.h>
#include <stdlib.h>

struct cell {
    struct cell *ant;
    int conteudo;
    struct cell *seg;
};

typedef struct cell celula;

// Prototipos das funcoes
void insira(celula *lst, int y);
void remova_tudo(celula *lst);
void imprima(celula *lst);
int tamanho(celula *lst);
void troque(celula *p, celula *q);
void bubble_sort(celula *lst);
void selection_sort(celula *lst);


int main() {
    //Inicializacao das listas
    celula *lst1, c1;
    lst1 = &c1;
    lst1->ant = NULL;
    lst1->seg = NULL;

    celula *lst2, c2;
    lst2 = &c2;
    lst2->ant = NULL;
    lst2->seg = NULL;

    // Preenchimento das listas
    printf("Lista 1:\n");
    imprima(lst1);
    insira(lst1, 1);
    insira(lst1, 2);
    insira(lst1, 3);

    printf("Lista 2:\n");
    imprima(lst2);
    insira(lst2, 1);
    insira(lst2, 2);
    insira(lst2, 3);

    troque(lst1->seg, lst1->seg->seg);
    imprima(lst1);
    /*
    // Bubble Sort
    printf("Lista 1 antes do Bubble Sort:\n");
    imprima(lst1);
    printf("Lista 1 depois do Bubble Sort:\n");
    bubble_sort(lst1);
    imprima(lst1);

    // Selection Sort
    printf("Lista 2 antes do Selection Sort:\n");
    imprima(lst2);
    printf("Lista 2 depois do Selection Sort:\n");
    selection_sort(lst2);
    imprima(lst2);

    // Excluindo as listas
    remova_tudo(lst1);
    printf("Lista 1:\n");
    imprima(lst1);

    remova_tudo(lst2);
    printf("Lista 2:\n");
    imprima(lst2);
    */
    
    return 0;
}

void insira(celula *lst, int y) {
    celula *nova;
    nova = (celula *) malloc(sizeof(celula));

    nova->conteudo = y;

    nova->ant = lst;
    nova->seg = lst->seg;

    if (lst->seg != NULL) {
        lst->seg->ant = nova;
    }
    
    lst->seg = nova;
}

void remova_tudo(celula *lst) {
    if (lst->seg == NULL) {
        return;
    }

    remova_tudo(lst->seg);
    free(lst->seg);
    lst->seg = NULL;
}

void imprima(celula *lst) {
    celula *p;
    p = lst->seg;

    printf("Cabeca -> ");
    while (p != NULL) {
        printf("%d -> ", p->conteudo);
        p = p->seg;
    }
    printf("NULL\n");
}

int tamanho(celula *lst) {
    int cont = 0;

    while (lst->seg != NULL) {
        cont++;
        lst = lst->seg;
    }

    return cont;
}

void troque(celula *p, celula *q) {
    celula *aux;

    p->seg->ant = q;
    q->seg->ant = p;

    p->ant->seg = q;
    q->ant->seg = p;

    aux = p;
    p->ant = q->ant;
    q->ant = aux->ant;

    p->seg = q->seg;
    q->seg = aux->seg;
}

void bubble_sort(celula *lst) {
    int size, ordenado = 0, i;
    size = tamanho(lst);

    celula *p;
    p = lst->seg;

    while (!ordenado) {
        ordenado = 1;
        p = lst->seg;
        for (i = 0; i < size; i++) {
            if (p->conteudo > p->seg->conteudo) {
                troque(p, p->seg);
                ordenado = 0;
                break;
            }
        }
    }
}

void selection_sort(celula *lst) {

}
