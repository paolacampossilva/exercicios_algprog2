#include <stdio.h> 

struct data {
    int dia;
    int mes;
    int ano;
};

typedef struct data data;

int calcular_idade(data atual, data nascimento);

int main() {
    data atual, nascimento;
    int idade;

    printf("Insira a data atual (dd/mm/aaaa):\n");
    scanf("%d/%d/%d%*c", &atual.dia, &atual.mes, &atual.ano);

    printf("Insira a sua data de nascimento (dd/mm/aaaa):\n");
    scanf("%d/%d/%d%*c", &nascimento.dia, &nascimento.mes, &nascimento.ano);

    idade = calcular_idade(atual, nascimento);

    printf("Você tem %d %s de idade\n", idade, idade == 1? "ano":"anos");

    return 0;
}

int calcular_idade(data atual, data nascimento) {
    int idade;

    idade = atual.ano - nascimento.ano;

    if (atual.mes < nascimento.mes || atual.mes == nascimento.mes && atual.dia < nascimento.dia) {
        idade--;
    }

    return idade;
}
