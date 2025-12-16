#include <stdio.h>

int sufixo(int a, int b);

int main() {
    int a, b, c;

    printf("Insira dois numeros a e b:\n");
    scanf("%d%d%*c", &a, &b);

    if (sufixo(a, b)) {
        printf("%d eh um sufixo de %d\n", b, a);
    }
    else {
        printf("%d NAO eh um sufixo de %d\n", b, a);
    }

    return 0;
}

int sufixo(int a, int b) {
    int c, cont = 0, i, m = 1;
    if (a == b) {
        return 1; //true
    }
    else if (b > a) {
        return 0; //false
    }
    else {
        c = b;
        if (c == 0) {
            cont = 1;
            m = m * 10;
        }
        else {
            while (c != 0) {
                c = c / 10;
                cont++;
                m = m * 10;
            }
        }

        c = a / m;
        c = c * m;

        if (a == c + b) {
            return 1; //true
        }
        else {
            return 0; //false
        }
    }
}
