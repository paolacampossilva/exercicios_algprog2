#include <stdio.h>
#include <stdlib.h>

struct cell {
    struct cell *ant;
    int conteudo;
    struct cell *seg;
};

typedef struct cell celula;

int menu();
celula * buscar(int y, celula *lst);
void inserir(int y, celula *p);
void remover(int y, celula *lst);
void imprimir(celula *lst);

int main() {
    celula *lst, cabeca, *p;

    lst = &cabeca;
    lst->ant = lst;
    lst->seg = lst;

    int y;

    while (1) {
        switch (menu()) {
            case 1: // Inserir um elemento
                printf("\nInsira um numero para adicionar a lista:\n");
                scanf("%d", &y);

                inserir(y, lst);

                printf("\nElemento inserido com sucesso!\n");
                break;

            case 2: // Remover um elemento
                if (lst->seg == lst) {
                    printf("\nOperacao impossivel! Lista esta vazia!\n");
                }
                else {
                    printf("\nInsira um numero para remover da lista:\n");
                    scanf("%d", &y);

                    if (buscar(y, lst) == NULL) {
                        printf("\nEsse numero nao esta na lista!\n");
                        printf("Tente novamente!\n");
                    }
                    else {
                        remover(y, lst);
                        printf("\nElemento removido com sucesso!\n");
                    }
                }
                
                break;

            case 3: // Buscar por um elemento
                if (lst->seg == lst) {
                    printf("\nOperacao impossivel! Lista esta vazia!\n");
                }
                else {
                    printf("\nInsira um numero para buscar na lista:\n");
                    scanf("%d", &y);

                    p = buscar(y, lst);
                    if (p == NULL) {
                        printf("\nEsse numero nao esta na lista!\n");
                    }
                    else {
                        printf("\nEsse numero esta na lista!\n");
                        printf("Endereco da celula: %p\n", p);
                    }
                }

                break;

            case 4: // Imprimir a lista
                printf("\nLista: \n");
                imprimir(lst);
                break;

            case 5: // Encerrar a aplicacao (Sair)
                return 0;

            default:
                printf("\nOpcao Invalida!\n");
                printf("Tente novamente!\n");
                break;
        }
    }
}

int menu() {
    int op;
    printf("\nEscolha uma das opções abaixo:\n");
    printf("\n1. Inserir um elemento na lista\n");
    printf("2. Remover um elemento da lista\n");
    printf("3. Buscar por um elemento na lista\n");
    printf("4. Imprimir a lista\n");
    printf("5. Sair\n");
    scanf("%d", &op);

    return op;
}

celula * buscar(int y, celula *lst) {
    celula *p;
    p = lst->seg;

    while (p != lst) {
        if (p->conteudo == y) {
            break;
        }
        p = p->seg;
    }

    if (p == lst) {
        return NULL;
    }
    else {
        return p;
    }
}

void inserir(int y, celula *lst) {
    celula *nova;

    nova = (celula *) malloc(sizeof(celula));

    nova->conteudo = y;

    nova->ant = lst;
    nova->seg = lst->seg;
    
    lst->seg = nova;
    nova->seg->ant = nova;
}

void remover(int y, celula *lst) {
    celula *p;

    p = buscar(y, lst);
    p->ant->seg = p->seg;
    p->seg->ant = p->ant;

    free(p);
}

void imprimir(celula *lst) {
    celula *p;
    p = lst->seg;

    printf("cabeca -> ");
    while (p != lst) {
        printf("%d -> ", p->conteudo);
        p = p->seg;
    }
    printf("cabeca\n");
}
