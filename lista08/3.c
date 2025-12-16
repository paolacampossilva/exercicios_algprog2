#include <stdio.h>
#include <stdlib.h>

int main() {
    int inicio, fim, meio, *v, n, i, elemento;

    printf("Insira a quantidade do elementos para o vetor:\n");
    scanf("%d%*c", &n);

    v = (int *) malloc(n * sizeof(int));

    printf("Insira os elementos do vetor (ja ordenados):\n");
    for(i = 0; i < n; i++) {
        scanf("%d%*c", &v[i]);
    }

    printf("Insira o elemento que deseja encontrar:\n");
    scanf("%d%*c", &elemento);

    inicio = 0;
    fim = n - 1;
    
    while (1) {
        meio = (inicio + fim) / 2;
        if (inicio > fim) { //elemento nao encontrado
            i = -1;
            break;
        }
        else if (v[meio] == elemento) { //elemento encontrado
            i = meio;
            break;
        }
        else if (elemento < v[meio]) { //esquerda
            fim = meio - 1;
        }
        else if (elemento > v[meio]) { //direita
            inicio = meio + 1;
        }
    }
   
    
    if (i == -1) {
        printf("O elemento nao foi encontrado no vetor!\n");
    }
    else {
        printf("O elemento esta na posicao %d\n", i);
    }
    
    free(v);
    return 0;
}
