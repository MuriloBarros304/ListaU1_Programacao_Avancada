#include <stdio.h>
#include <stdlib.h>
#define max 50

int compare(const void * a, const void * b) { // função de comparação
   return (*(int*)a - *(int*)b); // retorna a diferença, utiliza o conteúdo dos ponteiros
}

int main(void){
    int n = max;
    int i, aux, j;
    float *x;
    printf("Digite o número de elementos (no máximo 50): ");
    scanf("%d", &n);
    x = (float*) malloc(n*sizeof(float));
    for(i=0;i<n;i++){
        rand() % 10; // números aleatórios até 10
        //printf("x[%d] = %.2f\n", i, x[i]);
    }
    qsort(x, n, sizeof(float), compare);//recebe como argumentos o array x, o n, o tamanho dos elementos, e uma função de comparação
    printf("\n");
    printf("após a ordenação \n");
    printf("\n");
    for(i=0;i<n;i++){
    printf("x[%d] = %.2f\n", i, x[i]);
    }
    free(x);
}