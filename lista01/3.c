#include <stdio.h>

int main() {
    float num1, num2, num3, maior, menor;
    printf("Insira 3 numeros:\n");
    scanf("%f %f %f", &num1, &num2, &num3);
    if (num1 > num2 && num1 > num3) {
        maior = num1;
        if (num2 < num3) {
            menor = num2;
        }
        else {
            menor = num3;
        }
    } 
    else if (num2 > num1 && num2 > num3) {
        maior = num2;
        if (num1 < num3) {
            menor = num1;
        }
        else {
            menor = num3;
        }
    }
    else {
        maior = num3;
        if (num1 < num2) {
            menor = num1;
        }
        else {
            menor = num2;
        }
    }
    printf("O maior numero eh %.2f e o menor numero eh %.2f \n", maior, menor);
    return 0;
}
