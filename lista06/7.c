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
    arq = fopen("registro.dat", "rb+");

    if (arq == NULL) {
        perror("Erro na abertura do arquivo!");
        exit(1);
    }

    char s;
    int id;
    registro r;
    double salario;

    while (1) {
        printf("\nVoce deseja atualizar algum salario? (S/N)\n");
        scanf("%c%*c", &s);

        if (s == 'N') {
            break;
        }

        printf("\nInsira o id da pessoa:\n");
        scanf("%d%*c", &id);

        fseek(arq, (id - 1) * sizeof(registro), SEEK_SET);

        fread(&r, sizeof(registro), 1, arq);

        printf("\nDados antigos:\n");
        printf("\nID: %d\n", r.id);
        printf("Nome: %s\n", r.nome);
        printf("Salario: %.2lf\n", r.salario);

        printf("\nInsira o novo salario:\n");
        scanf("%lf%*c", &salario);

        r.salario = salario;
        
        rewind(arq);

        fseek(arq, (id - 1) * sizeof(registro), SEEK_SET);
        
        fwrite(&r, sizeof(registro), 1, arq);

        printf("\nSalario Atualizado com sucesso!\n");

        printf("\nDados atualizados:\n");
        printf("\nID: %d\n", r.id);
        printf("Nome: %s\n", r.nome);
        printf("Salario: %.2lf\n", r.salario);

        rewind(arq);
    }

    fclose(arq);
    return 0;
}
