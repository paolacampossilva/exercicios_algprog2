/*
Crie um programa que use ponteiro para função a fim de executar 
diferentes operações aritméticas baseado na entrada do usuário.
Crie quatro funções simples: adicione, subtraia, multiplique e divida. 

Cada função deve receber dois argumentos int e retornar um int 
como resultado. A função divida deve tratar divisão por zero a 
fim de prevenir erros em tempo de execução.

Declare um ponteiro para função que possa apontar para qualquer 
uma dessas quatro funções. A assinatura do ponteiro deve casar 
com as assinaturas das funções (ou seja, int (*ptr) (int, int)).

Entrada:

• Solicite ao usuário entrar com dois inteiros;
• Solicite ao usuário escolher uma operação (por exemplo, ’a’ para 
adicionar, ’s’ para subtrair, ’m’ para multiplicar e ’d’ para dividir).

Atribuir e chamar:

• Baseado na escolha do usuario, atribua o endereço da função 
correspondente para o ponteiro para função;
• Chame a função escolhida usando ponteiro para função, passando 
os dois inteiros de entrada como argumentos;
• Imprima o resultado da operação.
*/

#include <stdio.h>
#include <stdlib.h>

int adicione(int a, int b);

int subtraia(int a, int b);

int multiplique(int a, int b);

int divida(int a, int b);

int main() {
    int a, b, resultado;
    char l;

    int (*op) (int, int);

    printf("Insira dois numeros para realizar a operacao: ");
    scanf("%d%d%*c", &a, &b);

    printf("Insira a operacao que deseja executar (a/s/m/d): ");
    scanf("%c%*c", &l);

    if (l == 'a') {
        op = adicione;
    }
    else if (l == 's') {
        op = subtraia;
    }
    else if (l == 'm') {
        op = multiplique;
    }
    else if (l == 'd') {
        op = divida;
    }

    resultado = (*op) (a, b);

    printf("O resultado da operacao '%c' eh %d\n", l, resultado);

    return 0;
}

int adicione(int a, int b) {
    return a + b;
}

int subtraia(int a, int b) {
    return a - b;
}

int multiplique(int a, int b) {
    return a * b;
}

int divida(int a, int b) {
    if (b == 0) {
        printf("Erro!! Divisao por zero!!");
        exit(1);
    }
    else {
        return (int) (a / b);
    }
}
