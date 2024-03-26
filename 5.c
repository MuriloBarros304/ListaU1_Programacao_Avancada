/*
Determine o que será mostrado pelo seguinte programa (compile-o, execute-o e explique se
foram obtidas as respostas esperadas).
*/

#include <stdio.h>

int main(void){
    float vet[5] = {1.1,2.2,3.3,4.4,5.5};
    float *f;
    int i;
    f = vet;
    printf("contador/valor/valor/endereco/endereco\n");
    for(i = 0 ; i <= 4 ; i++){
        printf("i = %d",i);
        printf(" vet[%d] = %.1f",i, vet[i]);
        printf(" *(f + %d) = %.1f",i, *(f+i));
        printf(" &vet[%d] = %X",i, &vet[i]);
        printf(" (f + %d) = %X",i, f+i);
        printf("\n");
    }
}
/*

O contador serve para mapear as incrementações do laço for. Nele será impresso, inicialmente, 
o valor de cada componente do vetor vet, um a cada volta do for, em seguida será impresso 
o conteúdo armazenado no ponteiro f, sendo também um por incrementação do for, que soma 
a cada iteração fazendo imprimir o próximo termo. Logo após será impresso o endereço de vet
no ponteiro f de duas formas diferentes: &vet[i] e (f + i)

*/