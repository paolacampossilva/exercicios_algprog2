#include <stdio.h>

struct produto {
    int codigo;
    char descricao[50];
    float preco;
};

typedef struct produto produto;

int main() {
    int n, i;
    produto cardapio[10];
    
    printf("Insira a quantidade de produtos a serem lidos:\n");
    scanf("%d%*c", &n);

    for (i = 0; i < n; i++) {
        printf("\nCadastro do produto %d:\n", i + 1);

        printf("Insira o codigo do produto:\n");
        scanf("%d%*c", &cardapio[i].codigo);

        printf("Insira a descricao do produto:\n");
        scanf("%49s", cardapio[i].descricao);

        printf("Insira o preco do produto:\n");
        scanf("%f%*c", &cardapio[i].preco);
    }

    printf("\nCadastro dos produtos realizado com sucesso!\n");

    printf("\nInsercao dos pedidos:\n");

    int codigo, q, qte[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; 
    float total = 0;

    while (1) {
        printf("\nInsira o codigo do produto:\n");
        scanf("%d%*c", &codigo);

        if (codigo == 0) {
            printf("\nRegistro dos pedidos finalizado com sucesso!\n");
            break;
        }

        printf("Insira a quantidade:\n");
        scanf("%d%*c", &q);

        for (i = 0; i < n; i++) {
            if (codigo == cardapio[i].codigo) {
                qte[i] = qte[i] + q;
                break;
            }
        }
    }

    printf("\nPEDIDO FINALIZADO\n");

    for (i = 0; i < n; i++) {
        printf("%d x %s\n", qte[i], cardapio[i].descricao);
        total = total + (qte[i] * cardapio[i].preco);
    }

    printf("TOTAL R$ %.2f\n", total);

    return 0;
}
