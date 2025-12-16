#include <stdio.h> 

struct fracao {
    int numerador;
    int denominador;
};

typedef struct fracao fracao;

int mdc(int a, int b);

fracao simplifique(fracao fracao);

double para_real(fracao fracao);

fracao some(fracao fracao1, fracao fracao2);

int main() {
    fracao frac1, frac2, frac;
    double real;
    int op;

    printf("Escolha uma das opcoes:\n");
    printf("1. Simplicacao de fracoes\n");
    printf("2. Divisao real de fracoes\n");
    printf("3. Soma de fracoes\n");
    scanf("%d%*c", &op);

    switch (op) {
        case 1:
            printf("Insira a fracao para simplificacao (a/b):\n");
            scanf("%d/%d", &frac1.numerador, &frac1.denominador);

            frac = simplifique(frac1);

            printf("A simplificacao da fracao %d/%d eh %d/%d\n", frac1.numerador, frac1.denominador, frac.numerador, frac.denominador);
            break;

        case 2:
            printf("Insira a fracao para a divisao real (a/b):\n");
            scanf("%d/%d", &frac1.numerador, &frac1.denominador);
            
            real = para_real(frac1);

            printf("A divisao real da fracao %d/%d eh %.2lf\n", frac1.numerador, frac1.denominador, real);
            break;

        case 3:
            printf("Insira as fracoes para a soma (a/b c/d):\n");
            scanf("%d/%d %d/%d", &frac1.numerador, &frac1.denominador, &frac2.numerador, &frac2.denominador);

            frac = some(frac1, frac2);

            printf("A soma das fracoes %d/%d e %d/%d eh %d/%d\n", frac1.numerador, frac1.denominador, frac2.numerador, frac2.denominador, frac.numerador, frac.denominador);
            break;

        default:
            printf("Opcao Invalida!\n");
            break;
    }

    return 0;
}

int mdc(int a, int b) {
    int resto;
    while (b != 0) {
        resto = a % b;
        a = b;
        b = resto;
    }
    return a;
}

fracao simplifique(fracao fracao) {

    /* Meu jeito de simplificar (nao funciona muito bem)

    int i, menor;

    if (fracao.numerador < fracao.denominador) {
        menor = fracao.numerador;
    }
    else {
        menor = fracao.denominador;
    }

    for (i = menor; i > 1; i++) {
        if (fracao.numerador == 1 || fracao.denominador == 1) {
            break;
        }

        if (fracao.numerador % i == 0 && fracao.denominador % i == 0) {
            fracao.numerador = fracao.numerador / i;
            fracao.denominador = fracao.denominador / i;
        }
    }
    */

    int divisor;

    divisor = mdc(fracao.numerador, fracao.denominador);
    fracao.numerador = fracao.numerador / divisor;
    fracao.denominador = fracao.denominador / divisor;

    return fracao;
}

double para_real(fracao fracao) {
    return (double) fracao.numerador / fracao.denominador;
}

fracao some(fracao fracao1, fracao fracao2) {
    fracao soma;

    if (fracao1.denominador == fracao2.denominador) {
        soma.denominador = fracao1.denominador;
        soma.numerador = fracao1.numerador + fracao2.numerador;
    }
    else {
        //com simplicacao - como se tivesse sido feito com MMC
        soma.denominador = fracao1.denominador * fracao2.denominador;
        soma.numerador = (fracao1.numerador * fracao2.denominador) + (fracao2.numerador * fracao1.denominador);
        soma = simplifique(soma);
    }

    return soma;
}
