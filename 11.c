#include <stdio.h>
int main(void){
    double *px, x[4]; // ponteiro apontando para o vetor x
    int i;
    px = &x[0];
    for(i=0;i<4;i++){
        x[i]=1.2*i;
    }
    printf("x = %p\n", x);
    //printf("*x = %d\n", *px);
    printf("x+1 = %p\n", (x+1));
    //printf("*(x+1) = %d\n", *(px+1));
    printf("x+2 = %p\n", (x+2));
    //printf("*(x+2) = %d\n", *(px+2));
    printf("x+3 = %p\n", (x+3));
    //printf("*(x+3) = %d\n", *(px+3));
}
// Espera-se que a cada incrementação do endereço de um determinado tipo seja equivalente 
// ao tamanho, exemplo sendo int: x = 4092, x+1 = 4094 (4092+2), sendo float: x+1 = 4096 (4092+4).

// Verificando:
/* Valor = 4092
char = 1 byte -> 1
int = 2 bytes -> 4
float = 4 bytes -> 4
double = 8 bytes -> 4
 */
 // Ou seja, todos com exceção do int se comportam como o esperado, saltando de acordo com seu tamanho em bytes.