#include <stdio.h>

int main() {
    int n, v[100], num, i, j = 0;

    printf("Insira um numero:\n");
    scanf("%d%*c", &num);

    n = num;

    while (1) {
        if (n == 1 || n == 0) {
            v[j] = n;
            j++;
            break;
        }
        else {
            v[j] = n % 2;
            j++;

            n = n / 2;
        }
    }

    printf("O numero %d em binario eh ", num);
    for (i = j - 1; i >= 0; i--) {
        printf("%d", v[i]);
    }
    printf("\n");

    return 0;
}
