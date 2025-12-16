#include <stdio.h>
#include <stdlib.h>

struct pessoa {
    char nome[50];
    int idade;
    float altura;
};

typedef struct pessoa pessoa;

int main() {
    FILE *arq;
    arq = fopen("dados.dat", "wb+");

    if (arq == NULL) {
        perror("Erro na abertura no arquivo!");
        exit(1);
    }

    int i;
    pessoa p;

    printf("Cadastramento das pessoas:\n");

    for (i = 0; i < 6; i++) {
        printf("\nInsira os dados da pessoa %d:\n", i + 1);
        printf("\nInsira o seu nome:\n");
        scanf("%49[^\n]%*c", p.nome);

        printf("Insira a sua idade:\n");
        scanf("%d%*c", &p.idade);

        printf("Insira a sua altura:\n");
        scanf("%f%*c", &p.altura);

        fwrite(&p, sizeof(pessoa), 1, arq);
    }

    pessoa pessoas[6];

    rewind(arq);

    fread(pessoas, 6 * sizeof(pessoa), 6, arq);

    printf("\nCadastros retirados do sistema:\n");
    
    for (i = 0; i < 6; i++) {
        printf("\nDados da pessoa %d:\n", i + 1);
        printf("\nNome: %s\n", pessoas[i].nome);
        printf("Idade: %d\n", pessoas[i].idade);
        printf("Altura: %.2f\n", pessoas[i].altura);
    }

    fclose(arq);
    return 0;
}
