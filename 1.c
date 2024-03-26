/*
Seja o seguinte trecho de programa:
Determine o valor das seguintes expressões, justificando o porquê de cada resultado:
*/

#include <stdio.h>

int main(){
    int i=3,j=5,r;
    int *p, *q;
    float rf;
    p = &i;
    q = &j;

    p == &i; // Retorna 3, já que recebe o endereço na memória de onde está armazenado o valor de i
    printf("p = %d\n", *p);

    r = *p - *q; // Novamente trabalhando com conteúdos de ponteiros, dessa vez foi feita a subtração: 3 - 5
    printf("*p - *q = %d\n", r);

    r = **&p; // O programa armazena o conteúdo do ponteiro em "r", criando um ponteiro que aponta para outro ponteiro, apontando assim para o valor de i
    printf("**&p = %d\n", r);

    r = 3 - *p/(*q) + 7; // 10, pois a parte inteira da divisão 3/5 é 0, portanto temos: 3 - 0 + 7 = 10
    printf("3 - *p/(*q) + 7 = %d\n", r);
    return 0;
}

