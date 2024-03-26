/*
Crie uma função capaz de realizar multiplicação matricial da forma C = AxB. A função deve
receber 6 argumentos: os ponteiros para as matrizes A, B e C, o número de linhas e colunas de A
e o número de colunas de B (assuma que o número de coluna de A é igual ao número de linhas
de B). O resultado da multiplicação deve ficar armazenado em C. Crie um programa para testar
sua implementação, capaz de utilizar a função de multiplicação e imprimir as três matrizes. A
função criada para multiplicação não deve realizar nenhum tipo de saída de dados no terminal.
Exemplo: para multiplicar duas matrizes (A e B) de dimensões 2x3 e 3x4, respectivamente (o
resultado deve ficar armazenado em C).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void multiplica_matrizes(int **A, int **B, int **C, int NLA, int NCA, int NCB) {
    int i, j, k;
    for(i=0;i<NLA;i++) { // o número de linhas de A é igual ao número de linhas de B
        for(j=0;j<NCB;j++) { // o número de colunas de C é igual ao número de colunas de B
            C[i][j] = 0;
            for(k=0;k<NCA;k++) { // o número de produtos é igual ao número de colunas de A e linhas de B
                C[i][j] += A[i][k] * B[k][j];
            }                               // c00 = a00*b00 + a01*b10 + a02*b20 + a03*b30 
                                            // c01 = a00*b01 + a01*b11 + a02*b21 + a03*b31
                                            // c10 = a10*b00 + a11*b10 + a12*b20 + a13*b30
        }
    }
}

int main(void) {
    int i, j;
    int **a, **b, **c;
    int nla=5, nca=4, ncb=3;
  
    // alocação de memória para a matriz A
    a = (int**)malloc(nla * sizeof(int*));
    a[0] = (int*)malloc(nla * nca * sizeof(int));
    for(i=1;i<nla;i++) {
        a[i] = a[i-1] + nca;
    }
  
    // alocação de memória para a matriz B
    b = (int**)malloc(nca * sizeof(int*));
    b[0] = (int*)malloc(nca * ncb * sizeof(int));
    for(i=1;i<nca;i++) {
        b[i] = b[i-1] + ncb;
    }
  
    // alocação de memória para a matriz C
    c = (int**)malloc(nla * sizeof(int*));
    c[0] = (int*)malloc(nla * ncb * sizeof(int));
    for(i=1;i<nla;i++) {
        c[i] = c[i-1] + ncb;
    }

    // preenchendo as matrizes a e b
    for(i=0;i<nla;i++) {
        for(j=0;j<nca;j++) {
            a[i][j] = rand() % 10;
        }
    }

    for(i=0;i<nca;i++) {
        for(j=0;j<ncb;j++) {
            b[i][j] = rand() % 10;
        }
    }

    multiplica_matrizes(a, b, c, nla, nca, ncb);

    //imprimir as matrizes
    printf("a: \n");
    for(i=0;i<nla;i++) {
        for(j=0;j<nca;j++) {
            printf("%d\t", a[i][j]);
        } 
        printf("\n");
    } 

    printf("b: \n");
    for(i=0;i<nca;i++) {
        for(j=0;j<ncb;j++) {
            printf("%d\t", b[i][j]);
        } 
        printf("\n");
    } 

    printf("c: \n");
    for(i=0;i<nla;i++) {
        for(j=0;j<ncb;j++) {
            printf("%d\t", c[i][j]);
        } 
        printf("\n");
    } 

    // liberando a memória alocada
    free(a[0]);
    free(b[0]);
    free(c[0]);
  
    free(a);
    free(b);
    free(c);

    return 0;
}
