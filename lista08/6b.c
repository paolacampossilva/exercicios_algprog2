// ITERATIVAMENTE

#include <stdio.h>

int main() {
    int x, y, a, b, mdc = 1, i;

    printf("Insira dois numeros x e y:\n");
    scanf("%d%d%*c", &x, &y);

    a = x;
    b = y;

    for (i = (x > y ? x : y); i > 0; i--) {
        if (x % i == 0 && y % i == 0) {
            mdc = i;
            break;
        }
    }

    printf("O maximo divisor comum de %d e %d eh %d\n", x, y, mdc);

    return 0;
}
