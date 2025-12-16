#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu();

int compare_char(const void *a, const void *b);

int compare_string(const void *a, const void *b);

int compare_int(const void *a, const void *b);

int compare_float(const void *a, const void *b);

int compare_double(const void *a, const void *b);

void bubble_sort(void *base, size_t nitems, size_t size, int (*compare)(const void *, const void*));

int main() {
    char *letras, **palavras;
    int n, i, *inteiros;
    float *flutuantes;
    double *duplos;

    while (1) {
        switch (menu()) {
            case 1:
            //Char
            printf("\nInsira a quantidade de caracteres presentes no vetor:\n");
            scanf("%d", &n);

            letras = malloc(n * sizeof(char));

            printf("Preencha o vetor:\n");
            for (i = 0; i < n; i++) {
                scanf(" %c", &letras[i]);
            }

            bubble_sort(letras, n, sizeof(char), compare_char);

            printf("\n");
            printf("Vetor ordenado:\n");
            for (i = 0; i < n; i++) {
                printf("%c ", letras[i]);
            }
            printf("\n");

            free(letras);
            break;

            case 2:
            //String
            printf("\nInsira a quantidade de strings presentes no vetor:\n");
            scanf("%d", &n);

            palavras = malloc(n * sizeof(char *));

            printf("Preencha o vetor:\n");
            for (i = 0; i < n; i++) {
                palavras[i] = malloc(50 * sizeof(char));
                scanf("%49s", palavras[i]);
            }

            bubble_sort(palavras, n, sizeof(char *), compare_string);

            printf("\n");
            printf("Vetor ordenado:\n");
            for (i = 0; i < n; i++) {
                printf("%s ", palavras[i]);
            }
            printf("\n");

            for (i = 0; i < n; i++) {
                free(palavras[i]);
            }
            free(palavras);
            break;

            case 3:
            //Int
            printf("\nInsira a quantidade de inteiros presentes no vetor:\n");
            scanf("%d", &n);

            inteiros = malloc(n * sizeof(int));

            printf("Preencha o vetor:\n");
            for (i = 0; i < n; i++) {
                scanf("%d", &inteiros[i]);
            }

            bubble_sort(inteiros, n, sizeof(int), compare_int);

            printf("\n");
            printf("Vetor ordenado:\n");
            for (i = 0; i < n; i++) {
                printf("%d ", inteiros[i]);
            }
            printf("\n");
            
            free(inteiros);
            break;

            case 4:
            //Float
            printf("\nInsira a quantidade de floats presentes no vetor:\n");
            scanf("%d", &n);

            flutuantes = malloc(n * sizeof(float));

            printf("Preencha o vetor:\n");
            for (i = 0; i < n; i++) {
                scanf("%f", &flutuantes[i]);
            }

            bubble_sort(flutuantes, n, sizeof(float), compare_float);

            printf("\n");
            printf("Vetor ordenado:\n");
            for (i = 0; i < n; i++) {
                printf("%f ", flutuantes[i]);
            }
            printf("\n");
            
            free(flutuantes);
            break;

            case 5:
            //Double
            printf("\nInsira a quantidade de doubles presentes no vetor:\n");
            scanf("%d", &n);

            duplos = malloc(n * sizeof(double));

            printf("Preencha o vetor:\n");
            for (i = 0; i < n; i++) {
                scanf("%lf", &duplos[i]);
            }

            bubble_sort(duplos, n, sizeof(double), compare_double);

            printf("\n");
            printf("Vetor ordenado:\n");
            for (i = 0; i < n; i++) {
                printf("%lf ", duplos[i]);
            }
            printf("\n");
            
            free(duplos);
            break;

            case 6:
            printf("\nFinalizando o programa!\n");
            return 0;
        }
    }
}

int menu() {
    int op;
    printf("\nEscolha qual ordenacao deseja realizar:\n");
    printf("1. Char\n");
    printf("2. String\n");
    printf("3. Int\n");
    printf("4. Float\n");
    printf("5. Double\n");
    printf("6. Sair do programa\n");
    scanf("%d%*c", &op);
    return op;
}

int compare_char(const void *a, const void *b) {
    return *(char *)a - *(char *)b;
}

int compare_string(const void *a, const void *b) {
    return strcmp(*(char**)a, *(char**)b);
}

int compare_int(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int compare_float(const void *a, const void *b) {
    float fa = *(const float *)a, fb = *(const float *)b;
    return (fa > fb) - (fa < fb);
}

int compare_double(const void *a, const void *b) {
    double da = *(const double *)a, db = *(const double *)b;
    return (da > db) - (da < db);
}

void bubble_sort(void *base, size_t nitems, size_t size, int (*compare)(const void *, const void *)) {
    int i, j;
    char *p = (char *) base;
    void *aux = malloc(size);

    for (i = 0; i < nitems - 1; i++) {
        for (j = 0; j < nitems - i - 1; j++) {
            if ((*compare)((p + j * size), (p + (j + 1) * size)) > 0) {
                memcpy(aux, (p + j * size), size);
                memcpy((p + j * size), (p + (j + 1) * size), size);
                memcpy((p + (j + 1) * size), aux, size);
            }
        }
    }
    free(aux);
}
