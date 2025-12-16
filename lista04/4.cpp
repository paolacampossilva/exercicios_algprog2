/* Discuta, passo a passo, o efeito do seguinte fragmento de código:

int *v;
v = (int *) malloc(10 * sizeof(int));

    R: Um ponteiro inteiro v foi incializado e depois declarado com 
    alocação dinâmica de memória. A função malloc() possui como parâmetro 
    quantos bytes serão alocados, a função sizeof() possui como parâmetro 
    alguma variável ou tipo para que retorne o quanto esse(a) ocupa de espaço 
    na memória e (int *) faz o casting do void * retornado pela função malloc(), 
    o que não é necessário pois essa é uma das únicas conversões que são feitas 
    automaticamente pela linguagem. Portanto, a expressão está separando um espaço 
    contínuo na memória para 10 variáveis do tipo int e armazenando o endereço do 
    primeiro elemento no ponteiro v (similar ao funcionamento de um vetor).
*/
