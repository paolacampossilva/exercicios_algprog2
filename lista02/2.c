#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int v[6], n, i, s;

    //deve ser chamada para "semear" o gerador
    srand(time(NULL));
    
    for (i = 0; i < 6; i++) {
        //intervalo [M, N]
        //rand() % (N - M + 1) + M

        //intervalo [1, 60]
        v[i] = rand() % (60 - 1 + 1) + 1;
    }
    i = 0;

    while (1) {
        printf("Insira o seu chute (1 <= n <= 60): \n");
        scanf("%d%*c", &n);

        if (n == 0) {
            break;
        }

        for (i = 0; i < 6; i++) {
            if (n == v[i]) {
                s = 1;
                break;
            }
            else {
                s = 0;
            }
        }

        if (s == 1) {
            printf("O numero %d esta presente no vetor!  :DD\n", n);
            printf("A sua posicao (0 a 5) eh %d \n", i);
        }
        else if (s == 0) {
            printf("O numero %d NAO esta presente no vetor!  DD:\n", n);
        }
    }

    printf("O vetor sorteado era: %d %d %d %d %d %d\n", v[0], v[1], v[2], v[3], v[4], v[5]);
    
    return 0;
}
