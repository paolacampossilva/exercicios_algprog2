#include <stdio.h>
#include <stdlib.h>

struct registro {
    int id;
    char nome[50];
    double salario;
};

typedef struct registro registro;

int main() {
    FILE *arq;
    arq = fopen("registro.dat", "wb+");

    if (arq == NULL) {
        perror("Erro na abertura do arquivo!");
        exit(1);
    }

    int i;
    registro r;

    for (i = 0; i < 6; i++) {
        printf("\nInsira os dados da pessoa %d:\n", i + 1);
        
        r.id = i + 1;

        printf("\nInsira o seu nome:\n");
        scanf("%49[^\n]%*c", r.nome);

        printf("Insira o seu salario:\n");
        scanf("%lf%*c", &r.salario);

        fwrite(&r, sizeof(registro), 1, arq);
    }

    int id;
    char s;

    while (1) {
        printf("\nVoce deseja buscar algum id? (S/N)\n");
        scanf("%c%*c", &s);

        if (s == 'N') {
            break;
        }

        printf("Insira o id desejado:\n");
        scanf("%d%*c", &id);

        rewind(arq);

        fseek(arq, (id - 1) * sizeof(registro), SEEK_SET);

        fread(&r, sizeof(registro), 1, arq);

        printf("\nDados:\n");
        printf("\nID: %d\n", r.id);
        printf("Nome: %s\n", r.nome);
        printf("Salario: %.2lf\n", r.salario);
    }

    fclose(arq);
    return 0;
}
