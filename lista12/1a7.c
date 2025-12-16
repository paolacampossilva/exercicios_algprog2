/* exercicio 1

Considere uma fila de inteiros. Execute a sequência de operações a seguir na fila, mostrando ao final de cada operação desenfileire() o valor que será retornado. Responda
a questão sem nenhuma implementação.

enfileire(33)
enfileire(7)
enfileire(11)
desenfileire() - retorna 33
desenfileire() - retorna 7
enfileire(2)
desenfileire() - retorna 11

*/

// exercicio 2 a 7

#include <stdio.h>

#define TAMANHO_FILA 30

void enfileire(int f[], int s, int *t, int x);
int desenfileire(int f[], int *s, int t);

int main() {
    int f[TAMANHO_FILA], s = 0, t = 0, x;

    enfileire(f, s, &t, 33);
    enfileire(f, s, &t, 7);
    enfileire(f, s, &t, 11);
    x = desenfileire(f, &s, t);
    x = desenfileire(f, &s, t);
    enfileire(f, s, &t, 2);
    x = desenfileire(f, &s, t);
    
    return 0;
}

void enfileire(int f[], int s, int *t, int x) {
    // Fila cheia (Queue Overflow)
    if (*t == TAMANHO_FILA) {
        printf("Overflow!\n");
        return;
    }

    f[*t] = x;
    *t = *t + 1;
}

int desenfileire(int f[], int *s, int t) {
    // Fila vazia (Queue Underflow)
    if (*s == t) {
        printf("Underflow!\n");
        return -1;
    }

    int x;
    x = f[*s];

    *s = *s + 1;

    return x;
}
