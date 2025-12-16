#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum naipe {
    OUROS,
    ESPADAS,
    COPAS,
    PAUS
};

enum face {
    AS,
    DOIS,
    TRES,
    QUATRO,
    CINCO,
    SEIS,
    SETE,
    OITO,
    NOVE,
    DEZ,
    VALETE,
    DAMA, 
    REI
};

struct carta {
    enum face valores;
    enum naipe naipes;
};

typedef struct carta carta;

int main() {
    char *naipe[4] = {"Ouros", "Espadas", "Copas", "Paus"}, *face[13] = {"As", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove", "Dez", "Valete", "Dama", "Rei"};
    carta baralho[52];
    int f, n, b = 0, repetido, i, j, sorteadas[3] = {-1, -1, -1}, sorteio = -1;

    for (f = 0; f < 13; f++) {
        for (n = 0; n < 4; n++) {
            switch (f) {
                case 0:
                baralho[b].valores = AS;
                break;

                case 1:
                baralho[b].valores = DOIS;
                break;

                case 2:
                baralho[b].valores = TRES;
                break;

                case 3:
                baralho[b].valores = QUATRO;
                break;

                case 4:
                baralho[b].valores = CINCO;
                break;

                case 5:
                baralho[b].valores = SEIS;
                break;

                case 6:
                baralho[b].valores = SETE;
                break;

                case 7:
                baralho[b].valores = OITO;
                break;

                case 8:
                baralho[b].valores = NOVE;
                break;

                case 9:
                baralho[b].valores = DEZ;
                break;

                case 10:
                baralho[b].valores = VALETE;
                break;

                case 11:
                baralho[b].valores = DAMA;
                break;

                case 12:
                baralho[b].valores = REI;
                break;
            }
            
            switch (n) {
                case 0:
                baralho[b].naipes = OUROS;
                break;

                case 1:
                baralho[b].naipes = ESPADAS;
                break;

                case 2:
                baralho[b].naipes = COPAS;
                break;

                case 3:
                baralho[b].naipes = PAUS;
                break;
            }
            
            b++;
        }
    }

    //deve ser chamada para "semear" o gerador
    srand(time(NULL));

    for (i = 0; i < 3; i++) {
        repetido = 1;
        while (repetido) {
            //intervalo [M, N]
            //rand() % (N - M + 1) + M
            
            //intervalo [0, 51]
            sorteio = rand() % (52);
            repetido = 0;

            for (j = 0; j < i; j++) {
                if (sorteio == sorteadas[j]) {
                    repetido = 1;
                    break;
                }
            }
        }
        sorteadas[i] = sorteio;

        printf("%s de %s\n", face[baralho[sorteadas[i]].valores], naipe[baralho[sorteadas[i]].naipes]);
    }

    return 0;
}
