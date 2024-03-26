/*
O que fazem os seguintes programas em C?
*/

#include <stdio.h>

// int main(void){
//     int vet[] = {4, 9, 13};
//     int i;
//     for(i=0;i<3;i++){
//         printf("%d ", *(vet+i));
//     }
// }
// declara um vetor com 3 inteiros e os imprime

int main(){
    int vet[] = {4, 9, 13};
    int i;
    for(i=0;i<3;i++){
        printf("%X ",vet+i);
    }
}
// declara um vetor com 3 elementos e imprime os endereços dos elementos na memória