#include <stdio.h>
int main(void){
    int *x, i, v[4]; // ponteiro apontando para o vetor x
    x = &v[0];
    for(i=0;i<4;i++){
        v[i]=i;
    }
    printf("x = %p\n", x);
    printf("*x = %d\n", *x);
    printf("x+1 = %p\n", (x+1));
    printf("*(x+1) = %d\n", *(x+1));
    printf("x+2 = %p\n", (x+2));
    printf("*(x+2) = %d\n", *(x+2));
    printf("x+3 = %p\n", (x+3));
    printf("*(x+3) = %d\n", *(x+3));
}
/* Valor = 4092
char = 1 byte
int = 2 bytes
float = 4 bytes
double = 8 bytes
 */