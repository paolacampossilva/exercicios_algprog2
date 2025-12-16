// RECURSIVAMENTE

#include <stdio.h>

int mdc(int x, int y);

int main() {
    int x, y, max_div;

    printf("Insira dois numeros x e y:\n");
    scanf("%d%d%*c", &x, &y);

    max_div = mdc(x, y);

    printf("O maximo divisor comum de %d e %d eh %d\n", x, y, max_div);

    return 0;
}

int mdc(int x, int y) {
    if (y <= x && x % y == 0) {
        return y;
    }
    else if (x < y) {
        return mdc(y, x);
    }
    else {
        return mdc(y, x % y);
    }
}
