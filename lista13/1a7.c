/* exercicio 1

Considere uma pilha de inteiros. Execute a sequência de operações a seguir na pilha,
mostrando ao final de cada operação desempilhe o valor que será retornado. Responda
a questão sem nenhuma implementação.

empilhe(33)
empilhe(7)
empilhe(11)
desempilhe() - retorna 11
desempilhe() - retorna 7
empilhe(2)
desempilhe() - retorna 2

*/

// exercicios 2 a 7

#include <stdio.h>

#define N 30

void empilhe(int p[], int *t, int y);
int desempilhe(int p[], int *t);

int main() {
    int p[N], t = 0, y;

    empilhe(p, &t, 33);
    empilhe(p, &t, 7);
    empilhe(p, &t, 11);
    y = desempilhe(p, &t);
    y = desempilhe(p, &t);
    empilhe(p, &t, 2);
    y = desempilhe(p, &t);

    return 0;
}

void empilhe(int p[], int *t, int y) {
    // Pilha esta cheia (Stack Overflow)
    if (*t == N) {
        printf("Overflow!\n");
        return;
    }

    p[*t] = y;
    *t = *t + 1;
}

int desempilhe(int p[], int *t) {
    // Pilha esta vazia (Stack Underflow)
    if (*t == 0) {
        printf("Underflow!\n");
        return -1;
    }

    *t = *t - 1;
    return p[*t];
}
