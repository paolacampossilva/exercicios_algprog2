/*

A definição recursiva de palíndromos:

      pali(v[], inicio, fim) 

{ 1, v[inicio] == v[fim]         }
{ 0, inicio > fim                }
{ pali(v[], inicio + 1, fim - 1) }

*/

#include <stdio.h>

int pali(char *v, int inicio, int fim);

int main() {
    char v[50];
    int n, i, palindromo;

    printf("Insira a string:\n");
    scanf("%49s", v);

    for (i = 0; i < 50; i++) {
        if (v[i] == '\0') {
            break;
        }
    }

    palindromo = pali(v, 0, i - 1);

    printf("%s %s um palindromo!\n", v, palindromo ? "eh":"nao eh");

    return 0;
}

int pali(char *v, int inicio, int fim) {
    if (inicio > fim) {
        return 0;
    }
    else if (v[inicio] == v[fim]) {
        return 1;
    }
    else {
        return pali(v, inicio + 1, fim - 1);
    }
}
