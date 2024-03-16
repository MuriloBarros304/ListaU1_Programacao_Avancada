#include <stdio.h>

void main(){
    int const *x = 3; // Declarando ponteiro e preenchendo na mesma declaração, erro
    printf("%d", ++(*x)); // Ponteiro declarado como const, ou seja, não pode ser incrementado
    }