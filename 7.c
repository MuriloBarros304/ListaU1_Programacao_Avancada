/*
Considerando a declaração, quais das seguintes expressões são válidas? Justifique.
*/

#include <stdio.h>

int main(void){
    int mat[4], *p, x; // declaração
    for(x=0;x<4;x++){
        mat[x] = x;
    }
    for (x=0;x<4;x++){
        printf("x[%d] = %d \n", x, (mat[x])); // x[3] = 3
    }
    p = mat + 1;
    printf("*p = %d\n", *p); // *p = 1
    printf("p = mat + 1 -> %p\n", p); // endereço do segundo elemento do vetor 

    p = mat;
    printf("*p = %d\n", *p); // *p = 0
    printf("p = mat -> %p\n", p); // endereço do segundo elemento atualizado

    x = (*mat);
    printf("x = (*mat) -> %d\n", x); // primeiro elemento do vetor //0
// todas as alternativas são válidas
}