/* 
O seguinte trecho de código calcula a soma dos n primeiros números naturais.

#include <stdio.h>

int main() {
    int n, soma;

    soma = 0;

    scanf("%d", &n);

    while (n > 0) {
        soma = soma + n;
        n -= 1;
    }
    
    printf("A soma dos %d primeiros números e: %d", n, soma);

    return 0;
}

Reescreva o código utilizando duas funções. Uma função deve 
calcular a soma utilizando passagem por referência e a segunda 
função exibe o resultado utilizando passagem por valor.

    Obs: da forma como o código do enunciado foi feito o n vai diminuindo, 
    fazendo com a mensagem no final fique estranha ao parecer com isso: 
    "A soma dos 0 primeiros números eh: {soma}", não mostrando a quantidade 
    de números novamente como provavelmente era a intenção. Por via das dúvidas, 
    copiei esse padrão na hora de reescrever o código.
*/

#include <stdio.h>

void somar(int &n, int &soma);

void resultado(int n, int soma);

int main() {
    int n, soma;
    
    soma = 0;

    printf("Insira a quantidade de numeros para a soma: ");
    scanf("%d%*c", &n);

    somar(n, soma);

    resultado(n, soma);

    return 0;
}

void somar(int &n, int &soma) {
    while (n > 0) {
        soma = soma + n;
        n = n - 1;
    }
}

void resultado(int n, int soma) {
    printf("A soma dos %d primeiros numeros eh: %d", n, soma);
}
