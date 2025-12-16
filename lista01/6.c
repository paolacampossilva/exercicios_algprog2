#include <stdio.h>

int main() {
    float num, soma, media;
    int qte;
    num = 1;
    qte = -1;
    printf("Insira os numeros:\n");
    while (num != 0) {
        scanf("%f", &num);
        soma = soma + num;
        qte++;
    }
    media = soma / qte;
    printf("A quantidade de numeros eh %d, a sua soma eh %.2f e a sua media eh %.2f \n", qte, soma, media);
    return 0;
}
