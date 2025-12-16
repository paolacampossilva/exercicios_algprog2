/*
Escreva um programa que solicite ao usuário o número de notas a 
serem fornecidas e aloque dinamicamente um vetor com a dimensão 
especificada para armazenar as entradas. Solicite as notas e chame 
uma função que retorne a média aritmética das notas. Após imprimir 
a média o programa deve liberar a memória dinâmica que fora alocada.
Se você já viu o modificador const, o utilize no parâmetro que recebe 
as notas, a fim de garantir que o seu conteúdo não será alterado.
*/

#include <stdio.h>
#include <stdlib.h>

double media_aritmetica(int n, const double *p);

int main() {
    int n, i;
    double *p, media;

    printf("Insira a quantidade de notas: ");
    scanf("%d%*c", &n);

    p = (double *) malloc(n * sizeof(double));

    for (i = 0; i < n; i++) {
        printf("Insira a nota %d: ", i + 1);
        scanf("%lf%*c", p + i);
    }

    media = media_aritmetica(n, p);

    printf("A media aritmetica das notas eh %.2lf\n", media);

    free(p);
    
    return 0;
}

double media_aritmetica(int n, const double *p) {
    int i;
    double media;

    for (i = 0; i < n; i++) {
        media = media + *(p + i);
    }

    media = media / n;

    return media;
}
