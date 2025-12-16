#include <stdio.h> 
#include <stdlib.h>

int * realocando_vetor(int *v, int *size);

int main() {
    int *v, size = 5, i = 0, num, j;
    v = (int *) malloc(5 * sizeof(int));

    printf("Insira os elementos do vetor:\n");

    while (1) {
        if (i == size) {
            v = realocando_vetor(v, &size);
        }

        scanf("%d%*c", &num);

        if(num == -1) {
            break;
        }

        v[i] = num;
        i++;
    }

    printf("\nElementos do vetor:\n");
    for (j = 0; j < i; j++) {
        printf("%d ", v[j]);
    }
    printf("\n");

    free(v);

    return 0;
}

int * realocando_vetor(int *v, int *size) {
    int *novo_v, antigo_size, i;

    antigo_size = *size;
    *size = *size * 2;

    novo_v = (int *) malloc(*size * sizeof(int));

    for (i = 0; i < antigo_size; i++) {
        novo_v[i] = v[i];
    }

    free(v);

    return novo_v;
}
