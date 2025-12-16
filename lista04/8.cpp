/*
Implemente a função troque3() que faz uso da passagem por 
referência com argumentos de ponteiro. Esta função deve 
realizar a troca dos argumentos a e b passados por referência
(passa-se o endereço neste caso específico). Teste na main 
se a sua função está funcionando corretamente.
*/

#include <stdio.h>

void troque3(double *p, double *q);

int main() {
    double a, b, *p, *q;

    p = &a;
    q = &b;

    printf("Insira os argumentos a e b para a troca: ");
    scanf("%lf%lf%*c", &a, &b);

    troque3(p, q);

    printf("a = %.2lf\n", a);
    printf("b = %.2lf\n", b);

    return 0;
}

void troque3(double *p, double *q) {
    double m;
    m = *p;
    *p = *q;
    *q = m;
}
