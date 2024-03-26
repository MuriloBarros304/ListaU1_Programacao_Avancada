/*
Assumindo que pulo[] é um vetor do tipo int, quais das seguintes expressões referenciam o
valor do terceiro elemento do vetor?
*/

#include <stdio.h>

int main(void){
    int pulo[6];
    int *p, i;
    p = pulo;
    for (i = 0; i < 6; i++){
        pulo[i] = i;
    }
    printf("*(pulo+2) = %d \n", *(pulo+2)); // conteúdo do terceiro elemento do vetor pulo
    printf(" pulo+2 = %p \n", pulo+2); // endereço do terceiro elemento do vetor pulo
    printf(" p+2 = %p \n", p+2); // endereço do terceiro elemento de pulo armazenado no ponteiro p
}