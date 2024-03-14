#include <stdio.h>

int main(void){

int i, j;
int *p, *q;
i= 1;
j = 2;
p = &i;
q = &j;
p = &*&i;
i = (*p)++ + *q;
printf("%d\n", i);

/*
*p = &i; -> Não é possível atribuir o conteúdo que q aponta ao endereço de j
i = (*&)j; -> Operação inválida devido aos parênteses
q = *p; -> Não é possível armazenar o conteúdo de um ponteiro em um ponteiro
*/
}