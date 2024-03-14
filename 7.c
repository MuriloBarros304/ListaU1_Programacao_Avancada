#include <stdio.h>

int main(void){
    int mat[4], *p, x;
    for(x=0;x<4;x++){
        mat[x] = x;
    }
    for (x=0;x<4;x++){
        printf("x[%d] = %d \n", x, (mat[x]));
    }
    p = mat + 1;
    printf("*p = %d\n", *p);
    p = mat;
    printf("*p = %d\n", *p);
    x = (*mat);
    printf("p = mat + 1 -> %p\n", p); // endereço do segundo elemento do vetor
    printf("p = mat -> %p\n", p); // endereço do segundo elemento atualizado
    printf("x = (*mat) -> %d\n", x); // primeiro elemento do vetor 
// todas as alternativas são válidas
}