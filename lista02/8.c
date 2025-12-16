#include <stdio.h> 

void concatenacao(char string1[100], char string2[100], int n);

int main() {
    char string1[100], string2[100];
    int n;

    printf("Insira a string1 e string2 para a concatenacao:\n");
    scanf("%s%s%*c", string1, string2);

    printf("Insira a qte de caracteres da string2 que deseja concatenar a string1:\n");
    scanf("%d", &n);

    concatenacao(string1, string2, n);

    printf("A concatenacao eh %s\n", string1);

    return 0;
}

void concatenacao(char string1[100], char string2[100], int n) {
    int i = 0, j;
    while (1) {
        if (string1[i] == '\0') {
            break;
        }
        i++;
    }
    for (j = 0; j < n; j++) {
        string1[i + j] = string2[j];
    }
    string1[i + n] = '\0';
}