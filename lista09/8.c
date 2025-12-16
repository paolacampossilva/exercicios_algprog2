// RECURSIVAMENTE

#include <stdio.h>

void binario(int n);

int main() {
    int n;

    printf("Insira um numero:\n");
    scanf("%d%*c", &n);

    binario(n);
    printf("\n");

    return 0;
}

void binario(int n) {
    if (n == 0) {
        printf("0");
    }
    else if (n == 1) {
        printf("1");
    }
    else {
        binario(n / 2);
        printf("%d", (n % 2));
    }
}
