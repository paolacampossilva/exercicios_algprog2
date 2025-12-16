/*
Escreva um programa que recebe três variáveis do tipo int (a, b, c) 
e rotacione os valores de forma que o valor de a vai para b, o valor 
de b para c e o valor de c para a. Utilize chamadas a função troque 
desenvolvida anteriormente (escolha uma das duas implementações da 
função que funciona: troque1 ou troque2).
*/

#include <stdio.h>

void troque2(double &x, double &y);

int main() {
    double a, b, c;

    printf("Insira os argumentos a, b e c para a troca: ");
    scanf("%lf%lf%lf%*c", &a, &b, &c);

    troque2(a, b);
    troque2(a, c);

    printf("a = %.2lf\n", a);
    printf("b = %.2lf\n", b);
    printf("c = %.2lf\n", c);
    
    return 0;
}

void troque2(double &x, double &y) {
    double z;
    z = x;
    x = y;
    y = z;
}
