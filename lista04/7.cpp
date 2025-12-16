/* 
Implemente a função troque2() que faz uso da passagem por 
referência com argumentos de referência (específico de C++, 
utilizando o operador de referência & a frente dos parâmetros). 
Essa função deve realizar a troca dos argumentos a e b passados 
por referência. Teste na main se a sua função está funcionando 
corretamente.
*/

#include <stdio.h>

void troque2(double &a, double &b);

int main() {
    double a, b;

    printf("Insira os argumentos a e b para a troca: ");
    scanf("%lf%lf%*c", &a, &b);

    troque2(a, b);

    printf("a = %.2lf\n", a);
    printf("b = %.2lf\n", b);

    return 0;
}

void troque2(double &a, double &b) {
    double c;
    c = a;
    a = b;
    b = c;
}
