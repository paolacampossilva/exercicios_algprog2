#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b;

    FILE *arq;
    arq = fopen("entrada.txt", "w");

    printf("Insira dois valores para serem gravados no arquivo: \n");
    scanf("%d%d%*c", &a, &b);
    
    if (arq == NULL) {
        perror("Erro ao abrir o arquivo!");
        exit(1);
    }
    
    fprintf(arq, "%d, %d", a, b);
    
    fclose(arq);
    
    return 0;
}
