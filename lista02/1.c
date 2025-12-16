#include <stdio.h>

int main() {
    int 
    u[100] = {1, 2, 3, 4, 5}, 
    v[100] = {6, 7, 8, 9, 10}, 
    n, i, 
    soma = 0;


    printf("Insira o tamanho dos vetores u e v: \n");
    scanf("%d%*c", &n);

    for (i = 0; i < n; i++) {
        soma = soma + (u[i] * v[i]);
    }

    printf("O produto escalar dos vetores u e v eh %d\n", soma);

    return 0;
}
