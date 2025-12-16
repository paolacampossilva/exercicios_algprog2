#include <stdio.h> 

struct registro {
    char nome[100];
    char cpf[12];
    char tipo;
    char socio;
};

typedef struct registro registro;

double pagamento_evento(registro registro);

int main() {
    registro registro;
    double valor;

    printf("Insira o seu nome:\n");
    scanf("%99[^'\n']%*c", registro.nome);

    printf("Insira o seu CPF (somente os digitos):\n");
    scanf("%11[0-9]s%*c", registro.cpf);

    printf("Insira o seu tipo de participacao:\n");
    scanf("%c%*c", &registro.tipo);

    printf("Insira se voce eh socio (S/N):\n");
    scanf("%c%*c", &registro.socio);

    valor = pagamento_evento(registro);

    printf("O valor a ser pago para a participacao no evento eh R$%.2lf\n", valor);
    
    return 0;
}

double pagamento_evento(registro registro) {
    double valor;

    switch (registro.tipo){
        case 'A':
            valor = 30;
            break;

        case 'B':
            valor = 60;
            break;
        
        case 'C':
            valor = 90;
            break;
        
        case 'D':
            valor = 100;
            break;

        default:
            printf ("Valor invalido!\n");
            break;
    }

    if (registro.socio == 'S') {
        valor = valor - (valor * 0.20);
    }
    
    return valor;
}
