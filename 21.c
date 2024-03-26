/*
(ENADE, 2023) Memory leak, ou vazamento de memória, é um problema que ocorre em
sistemas computacionais quando uma parte da memória, alocada para uma determinada
operação, não é liberada quando se torna desnecessária. Na linguagem C, esse tipo de problema
é quase sempre relacionado ao uso incorreto das funções malloc( ) e free( ). Esse erro de
programação pode levar a falhas no sistema se a memória for completamente consumida. Um
dos trechos abaixo apresenta um vazamento de memória. Identifique-o e justifique sua
resposta.
*/

// alternativa C
#include <stdio.h>

int f(char *data){
    void *s;
    s = malloc(50); // alocação de 50 bytes da memória
    int size = strlen(data);
    if (size > 50) // se size menor que 50
        return(-1); // sai do programa, sem liberar
        /* free(s); --> o ideal seria ter um free dentro do if também */  
    free(s); // libera caso size seja menor ou igual a 50
    return 0;
}
// há um vazamento de memória caso o tamanho da função data, que armazena s, seja maior que 50