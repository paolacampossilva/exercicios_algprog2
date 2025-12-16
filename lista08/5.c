/*

Determine o que a seguinte função recursiva em C calcula. Escreva uma função iterativa
para atingir o mesmo objetivo.

int func (int n) {
    if (n == 0) {
        return 0 ;
    }
    return n + func (n - 1);
} 

R: É a soma dos n primeiros números naturais.

*/

#include <stdio.h>

int main() {
    int num, n, soma = 0, i;

    printf("Insira um numero:\n");
    scanf("%d%*c", &num);

    n = num;
    for (i = 0; i < n; i++, num--) {
        soma = soma + num;
    }

    printf("A soma eh %d\n", soma);

    return 0;
}
