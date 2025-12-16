#include <stdio.h>
#include <stdlib.h>

struct cell {
    struct cell *ant;
    int conteudo;
    struct cell *seg;
};

typedef struct cell celula;

void enfileirar(celula *lst, int n);
int desenfileirar(celula *lst);
void imprimir(celula *lst);

int main() {
    celula c, *lst;
    int ins, i, op, n;

    lst = &c;
    lst->ant = lst;
    lst->seg = lst;

    // a frente da cabeca eh o comeco da fila
    // atras da cabeca eh o final da fila

    printf("Insira a quantidade de instrucoes a serem executadas:\n");
    scanf("%d", &ins);

    for(i = 0; i < ins; i++) {
        scanf("%d", &op);

        switch(op) {
            case 1: // Enfileirar
                scanf("%d", &n);
                enfileirar(lst, n);

                break;
            
            case 2: // Desenfileirar
                n = desenfileirar(lst);

                break;
            
            case 3: // Imprimir
                imprimir(lst);
                break;
            
            default:
                printf("Operacao Invalida!\n");
                break;
        }
    }

    return 0;
}

void enfileirar(celula *lst, int n) {
    celula *nova;

    nova = (celula *) malloc(sizeof(celula));

    nova->conteudo = n;

    nova->seg = lst;
    nova->ant = lst->ant;
    lst->ant->seg = nova;
    lst->ant = nova;

    printf("Elemento enfileirado com sucesso!\n");
}

int desenfileirar(celula *lst) {
    int n;

    // Fila esta vazia, entao nao eh possivel remover um elemento
    if (lst->seg == lst) {
        printf("Underflow!\n");
        return -1;
    }

    celula *p;
    p = lst->seg;

    n = p->conteudo;

    lst->seg = p->seg;
    p->seg->ant = lst;

    free(p);

    printf("Elemento desenfileirado com sucesso!\n");

    return n;
}

void imprimir(celula *lst) {
    // Fila esta vazia
    if (lst->seg == lst) {
        printf("Empty!\n");
    }
    else {
        printf("Primeiro elemento da fila: %d\n", lst->seg->conteudo);
    }
}
