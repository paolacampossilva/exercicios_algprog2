#include <stdio.h>

#define N 30

void enfileire(int *fila, int s, int *t, int y);
int desenfileire(int *fila, int *s, int t);

int main() {
    int fila[N], s = 0, t = 0, y;

    enfileire(fila, s, &t, 33);
    enfileire(fila, s, &t, 7);
    enfileire(fila, s, &t, 11);
    y = desenfileire(fila, &s, t);
    y = desenfileire(fila, &s, t);
    enfileire(fila, s, &t, 2);
    y = desenfileire(fila, &s, t);

    return 0;
}

void enfileire(int *fila, int s, int *t, int y) {
    // Fila cheia (Queue Overflow)
    if (s == *t + 1 || s == 0 && *t == N - 1) {
        printf("Overflow!\n");
        return;
    }

    fila[*t] = y;

    if (*t == N - 1) {
        *t = 0;
    }
    else {
        *t = *t + 1;
    }
}

int desenfileire(int *fila, int *s, int t) {
    // Fila vazia (Queue Underflow)
    if (*s == t) {
        printf("Underflow!\n");
        return -1;
    }

    int y;

    y = fila[*s];

    if (*s == N - 1) {
        *s = 0;
    }
    else {
        *s = *s + 1;
    }

    return y;
}
