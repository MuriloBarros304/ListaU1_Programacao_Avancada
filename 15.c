#include <stdio.h>
#include <stdlib.h>
#define max 50

int main(void){
    int n = max;
    int i, aux, j;
    float *x;
    scanf("%d", &n);
    x = (float*) malloc(n*sizeof(float));
    for(i=0;i<n;i++){
        x[i]=rand() % 10; // números aleatórios até 10
        printf("x[%d] = %.2f\n", i, x[i]);
    }
    for(i=0;i<n-1;i++){ // bubble sort
        for(j=0;j<n-1;j++){
            if (x[j] > x[j+1]){
                aux = x[j];
                x[j] = x[j+1];
                x[j+1] = aux;
            }
        }
    }
    
    //printf("%f", x[3]);
    printf("após a ordenação \n");
    for(i=0;i<n;i++){
    printf("x[%d] = %.2f\n", i, x[i]);
    }
    free(x);
}