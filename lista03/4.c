#include <stdio.h>

typedef struct {
    int num;
    char nome[100];
    double saldo;
} conta;

int menu();

void cadastrar_conta(conta banco[15], int cadastro[15]);

int iguais(char s1[], char s2[]);

void visualizar_contas(conta banco[15], int cadastro[15]);

void excluir_conta(conta banco[15], int cadastro[15]);

int main() {
    conta banco[15];
    int i, cadastro[15];

    for (i = 0; i < 15; i++) {
        banco[i].num = i + 1;
        cadastro[i] = 0;
    }

    printf("Bem-vindo(a) ao sistema do banco Bluebublu!\n");
    while (1) {
        switch (menu()) {
            case 1:
                cadastrar_conta(banco, cadastro);
                break;

            case 2:
                visualizar_contas(banco, cadastro);
                break;

            case 3:
                excluir_conta(banco, cadastro);
                break;

            case 4:
                printf("\nPrograma finalizado!\n");
                return 0;

            default:
                printf("\nOpcao Invalida!\n");
                break;
        }
    }
}

int menu() {
    int op;
    printf("\nMenu de opcoes:\n");
    printf("1. Cadastrar contas\n");
    printf("2. Visualizar todas as contas de determinado cliente\n");
    printf("3. Excluir a conta com menor saldo\n");
    printf("4. Sair\n");
    scanf("%d%*c", &op);
    return op;
}

void cadastrar_conta(conta banco[15], int cadastro[15]) {
    int i, s;
    char op;

    while (1) {
        s = 0;
        for (i = 0; i < 15; i++) {
            if (cadastro[i] == 0) {
                s = 1;
                
                //cadastro da conta
                cadastro[i] = 1;
                printf("\nConta disponivel encontrada! Seu cadastro sera realizado na conta %d\n", banco[i].num);
                printf("Insira o seu nome:\n");
                scanf("%99[^\n]%*c", banco[i].nome);
                printf("Insira o saldo atual da sua conta:\n");
                scanf("%lf%*c", &banco[i].saldo);
                printf("Conta cadastrada com sucesso!\n");
                
                break;
            }
        }
        if (s == 0) {
            printf("\nNao existe nenhuma conta disponivel para o cadastramento!\n");
            printf("Voce sera redirecionado(a) para o menu\n");
            return;
        }
        printf("\nVoce deseja cadastrar mais uma conta? (S/N)\n");
        scanf("%c%*c", &op);
        
        if (op == 'N') {
            break;
        }
    }
}

int iguais(char s1[], char s2[]) {
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return 0; // strings diferentes
        }
        i++;
    }

    return (s1[i] == '\0' && s2[i] == '\0');
}

void visualizar_contas(conta banco[15], int cadastro[15]) {
    int i, s;
    char nome[100], op;

    while (1) {
        s = 0;

        printf("\nInsira o nome do cliente para visualizar as suas contas:\n");
        scanf("%99[^\n]%*c", nome);

        for (i = 0; i < 15 && cadastro[i] == 1; i++) {
            if (iguais(banco[i].nome, nome)) {
                s = 1;
                //visualização das contas
                printf("\nConta encontrada!\n");
                printf("Número da conta: %d\n", banco[i].num);
                printf("Nome do cliente: %s\n", banco[i].nome);
                printf("Saldo da conta: R$%.2lf\n", banco[i].saldo);
            }
        }

        if (s == 0) {
            printf("\nNao existe nenhuma conta com esse cliente!\n");
            printf("Voce sera redirecionado(a) para o menu\n");
            return;
        }

        printf("\nVoce deseja visualizar mais contas? (S/N)\n");
        scanf("%c%*c", &op);

        if (op == 'N') {
            break;
        }
    }
}

void excluir_conta(conta banco[15], int cadastro[15]) {
    int i, index, s;
    double menor;
    char op;

    while (1) {
        s = 0;
        for (i = 0; i < 15 && cadastro[i] == 1; i++) {
            s = 1;
            index = i;
            menor = banco[i].saldo;
        }

        if (s == 0) {
            printf("\nNao existem mais contas para deletar!\n");
            printf("Voce sera redirecionado(a) para o menu\n");
            return;
        }

        for (i = 0; i < 15 && cadastro[i] == 1; i++) {
            if (banco[i].saldo < menor) {
                menor = banco[i].saldo;
                index = banco[i].num - 1;
            }
        }

        printf("\nA conta numero %d possui o menor saldo, tem certeza de que deseja exclui-la? (S/N)\n", index + 1);
        scanf("%c%*c", &op);

        if (op == 'S') {
            cadastro[index] = 0;
            banco[index].nome[0] = '\0';
            banco[index].saldo = 0;
            printf("\nConta excluida com sucesso!\n");
        }
        else {
            printf("\nVoce sera redirecionado(a) para o menu\n");
            return;
        }

        printf("\nVoce deseja excluir mais contas? (S/N)\n");
        scanf("%c%*c", &op);

        if (op == 'N') {
            break;
        }
    }
}
