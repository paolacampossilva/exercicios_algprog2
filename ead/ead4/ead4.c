#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 2001

char consulte(char pilha[], int t);
void empilhe(char pilha[], int *t, char c);
char desempilhe(char pilha[], int *t);

int main() {
    int i = 0, j, op, tamanho, t = 0;
    char string[N], *pilha, lixo;

    while (1) {
        scanf("%s", string); // Entrada

        // Parada
        if (string[0] == '-') {
            break;
        }

        t = 0;
        op = 0;

        tamanho = strlen(string);

        pilha = (char *) malloc(sizeof(char) * tamanho);

        for (j = 0; j < tamanho; j++) {
            if (string[j] == '{') {             // Quando eh igual a '{'
                empilhe(pilha, &t, string[j]);  // entao adiciona na pilha
            }
            else {                                 // Quando eh igual a '}'
                if (consulte(pilha, t) == '{') {   // se no topo da pilha estiver um '{'
                    lixo = desempilhe(pilha, &t);  // entao desempilha esse '{' no topo
                }                                  // assim fechando um par '{}'
                else {
                    op++;                     // Quando eh '}' e nao tem um '{' para fazer par com ele
                    empilhe(pilha, &t, '{');  // entao sera necessaria uma operacao para transformar esse '}' em um '{'
                }   
            }
        }

        // Transforma um '{' em '}' para cada par '{{' que sobrou na pilha
        // assim formando os pares '{}' necessarios
        op = op + (t / 2); 

        free(pilha);
        
        printf("%d. %d\n", i + 1, op); // Saida

        i++;
    }

    return 0;
}

char consulte(char pilha[], int t) {
    if (t == 0) {
        return 'e'; // 'e' de 'empty' pois a pilha esta vazia
    }

    return pilha[t - 1]; // retorna o elemento do topo da pilha
}

void empilhe(char pilha[], int *t, char c) {
    // Pilha esta cheia (Stack Overflow)
    if (*t == N) {
        printf("Overflow!\n");
        return;
    }

    pilha[*t] = c;
    *t = *t + 1;
}

char desempilhe(char pilha[], int *t) {
    // Pilha esta vazia (Stack Underflow)
    if (*t == 0) {
        printf("Underflow!\n");
        return 'e'; // 'e' de 'empty'
    }

    char c;

    *t = *t - 1;
    c = pilha[*t];

    return c;
}
