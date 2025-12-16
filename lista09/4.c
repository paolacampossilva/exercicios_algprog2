#include <stdio.h> 

void impares_1_n(int n); // a) de 1 a n
void impares_n_1(int n); // b) de n a 1

int main() {
    int n, op;

    printf("Insira um numero:\n");
    scanf("%d%*c", &n);

    printf("Escolha uma opcao:\n");
    printf("1. de 1 a n\n");
    printf("2. de n a 1\n");
    scanf("%d%*c", &op);

    switch(op) {
        case 1:
        impares_1_n(n);
        break;

        case 2:
        impares_n_1(n);
        break;

        default:
        printf("Opcao Invalida!\n");
        break;
    }
 
    printf("\n");

    return 0;
}

void impares_1_n(int n) { // a) de 1 a n
    if (n == 0) {
        return;
    }
    else {
        impares_1_n(n - 1);
    }
    
    if (n % 2 != 0) {
        printf("%d ", n);
    }
}

void impares_n_1(int n) { // b) de n a 1
    if (n % 2 != 0) {
        printf("%d ", n);
    }
    
    if (n == 1) {
        return;
    }
    else {
        impares_n_1(n - 1);
    }
}
