#include <stdio.h>
#include <stdlib.h>

int produto(int *v, int n);

int main() {
    int *v, n, i, prod;

    printf("Insira o tamanho do vetor:\n");
    scanf("%d%*c", &n);

    v = (int *) malloc(n * sizeof(int));

    printf("Insira os elementos do vetor:\n");
    for (i = 0; i < n; i ++) {
        scanf("%d%*c", &v[i]);
    }

    prod = produto(v, n - 1);

    printf("O produto dos elementos do vetor eh %d\n", prod);

    return 0;
}

int produto(int *v, int n) {
    if (n == 0) {
        return v[n];
    }
    else {
        return v[n] * produto(v, n - 1);
    }
}
