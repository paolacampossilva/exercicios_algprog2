/*
Implemente a função troque() que faz uso da passagem por valor. 
Essa função deve realizar a troca dos argumentos a e b. 
Teste na main e veja que a função implementada não funciona. Explique.

    R: A função troque() não funciona pois com a passagem por valor são 
    criadas cópias das variáveis "originais" presentes na main(), fazendo 
    com que qualquer alteração feita no escopo dessa funcão não impacte em 
    seus valores na main().

    Obs: Também não seria possível se utilizar de vetores, já que com a função 
    troque() com a passagem por valor seria necessário retornar ambos os valores 
    trocados novamente, o que não acontece pois não é possível retornar mais de 
    um valor em uma função.
*/

#include <stdio.h>

void troque(double a, double b);

int main() {
    double a, b;

    printf("Insira os argumentos a e b: ");
    scanf("%lf%lf%*c", &a, &b);

    troque(a, b); 

    printf("a = %.2lf\n", a);
    printf("b = %.2lf\n", b);

    return 0;
}

void troque(double a, double b) {
    int c;
    c = a;
    a = b;
    b = c;
}
