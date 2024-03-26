/*
Seja x um vetor de 4 elementos, declarado da forma TIPO x[4]. Suponha que depois da
declaração, x esteja armazenado no endereço de memória 4092 (ou seja, o endereço de x[0]).
Suponha também que na máquina seja usada uma variável do tipo char ocupa 1 byte, do tipo
int ocupa 2 bytes, do tipo float ocupa 4 bytes e do tipo double ocupa 8 bytes. Quais serão os
valores de x+1, x+2 e x+3 se:
◦ x for declarado como char?
◦ x for declarado como int? 
◦ x for declarado como float?
◦ x for declarado como double?
Implemente um programa de computador para testar estas suposições e compare as respostas
oferecidas pelo programa com as respostas que você idealizou.
*/

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
/* 
Valor = 4092
char = 1 byte -> 1
int = 2 bytes -> 4
float = 4 bytes -> 4
double = 8 bytes -> 4
 */
 // Ou seja, todos com exceção do int se comportam como o esperado, saltando de acordo com seu tamanho em bytes.