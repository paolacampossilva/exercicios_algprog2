/*
Considere o seguinte trecho de código:

#include <stdio.h>

int main() {
    float *q, b;
    
    b = 3.14;
    
    *q = *q + 1;
    
    printf("*q = %f\n", *q);
    
    return 0;
}

Onde está o erro neste código? O que acontecerá se você executá-lo desta maneira?

    R: O ponteiro q não recebeu a atribuição de nenhum endereço, ele mostrará 
    um erro com releção a falta do conteúdo do ponteiro q para que seja 
    possível realizar a operação de adição.
    
    Obs: Em alguns compiladores online esse erro não acontece, na saída ele 
    apenas mostra diferentes valores a cada vez que o código é executado.
*/
