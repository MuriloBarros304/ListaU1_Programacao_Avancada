/*
Escreva uma função em linguagem C que escreva em um vetor a soma dos elementos
correspondentes de outros dois vetores (os tamanhos dos vetores devem ser fornecidos pelo
usuário). Por exemplo, se o primeiro vetor contiver os elementos 1, 3, 0 e -2, e o segundo vetor
contiver os elementos 3, 5, -3 e 1, o vetor de soma terá valores resultantes iguais a 4, 8, -3 e -1. A
função deve receber 4 argumentos: os nomes dos três vetores e o número de elementos
presentes em cada vetor. Exemplo:
*/

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
/*
Exemplo de entrada:
Tamanho dos vetores: 4
vetor 1: {1,3,4,2}
vetor 2: {1,5,3,3}
Resulta: {2,8,7,5} 
*/