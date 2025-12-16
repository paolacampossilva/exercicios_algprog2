#include <stdio.h>

int imprime_10_1(int n);

int main() {
    imprime_10_1(10);
    printf("\n");
    return 0;
}

int imprime_10_1(int n) {
    if (n == 0) {
        return n;
    }
    printf("%d ", n);
    imprime_10_1(n - 1);    
}
