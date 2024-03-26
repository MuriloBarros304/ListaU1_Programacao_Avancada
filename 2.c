/*
Mostre o que será impresso por programa supondo que a variável i ocupa o endereço 4094 na
memória e que nessa arquitetura os inteiros possuem 2 bytes de tamanho.
*/

#include <stdio.h>

int main(void){
    int i=5; int *p;
    p = &i;
    printf("%p %p %d %d %d %d\n", p, p+1, *p+2, **&p, 3**p, **&p+4);
}
/*

p = 4094 ou 0ffe; -> endereço na memória em base hexadecimal
p + 1 = 4096 ou f000; -> endereço com 2 bytes a mais 
*p + 2 = 7; -> 5 + 2
**&p = 5; -> ponteiro dentro de um ponteiro, apenas apontando para 5
3**p = 15; -> 3 * 5 
**&p + 4 = 9; -> 5 + 4

*/