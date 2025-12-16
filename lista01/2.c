#include <stdio.h>

int main() {
    float velocidade, multa;
    printf("Insira a velocidade do seu veiculo:\n");
    scanf("%f", &velocidade);
    if (velocidade > 80) {
        multa = 5 * (velocidade - 80);
        printf("A sua velocidade ultrapassou o limite de 80 km/h, entao voce recebeu uma multa de R$%.2f \n", multa);
    }
    return 0;
}
