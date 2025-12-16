#include <stdio.h>
#include <stdlib.h>

#define N 30

// Fila
void enfileire(int *fila, int s, int *t, int y);
int desenfileire(int *fila, int *s, int t);
void imprime_fila(int *fila, int s, int t);

// Pilha
void empilhe(int *pilha, int *t, int y);
int desempilhe(int *pilha, int *t);
void imprime_pilha(int *pilha, int t);

int main() {
    int fila[N], s = 0, t = 0; // Fila original
    int pilha[N], t_aux = 0; // Pilha auxiliar para a troca
    int i, n;

    enfileire(fila, s, &t, 1);
    enfileire(fila, s, &t, 2);
    enfileire(fila, s, &t, 3);
    enfileire(fila, s, &t, 4);
    enfileire(fila, s, &t, 5);

    printf("Antes da troca:\n");
    imprime_fila(fila, s, t);
    imprime_pilha(pilha, t_aux);
    printf("\n");

    n = t;
    for (i = 0; i < n; i++) {
        empilhe(pilha, &t_aux, desenfileire(fila, &s, t));
    }

    printf("Durante a troca:\n");
    imprime_fila(fila, s, t);
    imprime_pilha(pilha, t_aux);
    printf("\n");

    // Fila vazia
    if (s == t) {
        s = 0;
        t = 0;
    }

    for (i = 0; i < n; i++) {
        enfileire(fila, s, &t, desempilhe(pilha, &t_aux));
    }

    printf("Depois da troca:\n");
    imprime_fila(fila, s, t);
    imprime_pilha(pilha, t_aux);
    printf("\n");

    return 0;
}

// Fila
void enfileire(int *fila, int s, int *t, int y) {
    // Fila cheia
    if (*t == N) {
        printf("Overflow!\n");
        return;
    }

    fila[*t] = y;
    *t = *t + 1;
}

int desenfileire(int *fila, int *s, int t) {
    // Fila vazia
    if (*s == t) {
        printf("Underflow!\n");
        return -1;
    }
    int n;

    n = fila[*s];
    *s = *s + 1;

    return n;
}

void imprime_fila(int *fila, int s, int t) {
    int i;

    printf("Fila:\n");

    // Fila vazia
    if (s == t) {
        printf("Empty!\n");
        return;
    }

    for (i = s; i < t; i++) {
        printf("%d ", fila[i]);
    }
    printf("\n");
}

// Pilha
void empilhe(int *pilha, int *t, int y) {
    // Pilha cheia
    if (*t == N) {
        printf("Overflow!\n");
        return;
    }

    pilha[*t] = y;
    *t = *t + 1;
}

int desempilhe(int *pilha, int *t) {
    // Pilha vazia
    if (*t == 0) {
        printf("Underflow!\n");
        return -1;
    }
    int n;

    *t = *t - 1;
    n = pilha[*t];

    return n;
}

void imprime_pilha(int *pilha, int t) {
    int i;

    printf("Pilha:\n");

    // Pilha vazia
    if (t == 0) {
        printf("Empty!\n");
        return;
    }

    for (i = 0; i < t; i++) {
        printf("%d ", pilha[i]);
    }
    printf("\n");
}
