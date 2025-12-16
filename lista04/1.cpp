//Considere o seguinte trecho de código:

#include <stdio.h>

int main() {
    int *p, a;
    
    a = 10;
    p = &a;
    
    *p = *p * 2;
    
    printf("a = %d\n", a);
    
    return 0;
}

/*
Qual o valor da variável a ao final da execução? 
(Tente primeiro responder apenas analisando o código. 
Confirme a sua resposta compilando e executando o código.).

    R: A variável a está recebendo o valor inteiro 10 e o ponteiro p 
    está recebendo o endereço de a (p está apontando para a). 
    O conteúdo para o qual p está apontando (*p, ou seja, a) 
    será multiplicado por 2, fazendo com que a variável seja 
    atualizada para o valor de 20 (10 * 2). 
    No final, ele mostra na tela o novo valor de a (20).
*/
