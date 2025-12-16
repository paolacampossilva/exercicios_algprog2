#include <stdio.h>

int main() {
    int num1, num2, resultado;
    resultado = 0;
    printf("Insira o dividendo e o divisor, respectivamente:\n");
    scanf("%d %d", &num1, &num2);
    while (num1 - num2 >= 0) {
        num1 = num1 - num2;
        resultado++;
    }
    printf("O resultado dessa divisao eh %d e o resto eh %d \n", resultado, num1);
    return 0;
}
