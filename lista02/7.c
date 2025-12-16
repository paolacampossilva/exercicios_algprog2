#include <stdio.h> 

int main() {
    char nome[50], i;

    printf("Insira o seu nome:\n");
    scanf("%s", nome);

    printf("As 4 primeiras letras do seu nome sao ");
    for (i = 0; i < 4 && nome[i] != '\0'; i++) {
        if (i == 3) {
            printf("'%c'", nome[i]);
        }
        else {
            printf("'%c'%s", nome[i], i == 2? " e ":", ");
        }
        
    }

    return 0;
}
