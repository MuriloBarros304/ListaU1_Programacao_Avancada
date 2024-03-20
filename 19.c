#include <stdio.h>
#include <stdlib.h>
#define max 50

void soma_vetores(int *vet1, int *vet2, int *resultado, int n){ 
    int i;
    for(i=0;i<n;i++){
        resultado[i] = vet1[i] + vet2[i]; // soma os respectivos elementos dos vetores e armazena no vetor resultado
    }
}

int main(){
    int *x, *y, i, num = max;
    int *result;
    x = malloc(num * sizeof(int)); // alocação de memória
    y = malloc(num * sizeof(int));
    result = malloc(num * sizeof(int));
    printf("digite o tamanho dos vetores: \n");
    scanf("%d", &num); // tamanho dos vetores
    printf("digite o primeiro vetor (máx 50): \n");
    for(i=0;i<num;i++){ // receber valores do primeiro array
        scanf("%d", &x[i]);
    } 
    printf("agora digite o segundo vetor (máx 50): \n");
    for(i=0;i<num;i++){ // receber valores do segundo array
        scanf("%d", &y[i]);
    } 
    soma_vetores(x, y, result, num);
    printf("somando... \n");
    printf("Resultado: \n");
    for(i=0;i<num;i++){ // mostrar resultado
        printf("%d, ", result[i]);
    }
    free(x);
    free(y);
    return 0;
}