/*
Crie uma função chamada print_addr(int x) cujo propósito 
seja apenas imprimir o conteúdo da variável x e seu endereço. 
Declare uma variável x do tipo int na main e inicialize-a com 
o valor 3. Imprima seu conteúdo e endereço dentro da main. 
Então, chame a função print_addr passando a variável x como 
argumento. Compare os resultados. Este comportamento é o esperado?

    R: Sim, pois a variável presente dentro da função print_addr() 
    é uma variável local, ou seja, por conta do seu escopo ela é 
    apenas uma cópia da variável x "original" (aquela presente na main), 
    fazendo com que os endereço da variável x na main() seja diferente 
    da mesma variável x na print_addr(), mesmo que ambas possuam o mesmo 
    conteúdo e estejam "conectadas" pela passagem por valor.
*/

#include <stdio.h>

void print_addr(int x);

int main() {
    int x = 3;
    
    printf("x = %d\n", x);
    printf("&x = %p\n", &x);

    print_addr(x);

    return 0;
}

void print_addr(int x) {
    printf("x = %d\n", x);
    printf("&x = %p\n", &x);
}
