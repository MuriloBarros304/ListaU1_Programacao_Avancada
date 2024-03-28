/*
Um programador precisa desenvolver uma aplicação em linguagem C para manipular matrizes
capazes de armazenar representações de modelos tridimensionais.
Entende-se que o tamanho da matriz é definido pelo usuário e esta deve ser alocada
dinamicamente usando malloc() em tempo de execução. O processo de criar um modelo na
matriz consiste em atribuir aos seus elementos os valores inteiros “1” ou “0” para simbolizar
que há ou não parte do modelo naquela posição. Uma analogia para o modelo seria que a
criação funciona como no jogo "Minecraft", onde "0" representaria a ausência de objeto e "1"
representaria a presença de objetos.
Nesta aplicação, as matrizes devem ser definidas como tipos de dados int. Isto posto, pede-se
que o programador prepare os algoritmos de alocação dinâmica (usando malloc()/free()) para
guardar os dados da matriz tridimensional e crie um programa de testes para verificar se a sua
implementação foi realizada corretamente de modo a garantir as seguintes condições:
a. O usuário do programa de testes deverá poder fornecer o tamanho da matriz tridimensional
que deseja manipular, inserindo as dimensões da altura, largura e profundidade desta.
b. O usuário do programa de testes poderá solicitar a impressão de um dos planos da matriz
tridimensional.
c. O usuário do programa de testes poderá modificar o estado de um dos elementos da matriz.
Insira no seu código comentários para indicar como as posições da matriz poderão ser
acessadas.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int ***m;
    int nc, nl, np, i, j, k;
    //scanf()
    nc = 2;
    nl = 4;
    np = 5;
    m = malloc(nl * sizeof(int **));
    m[0] = malloc(nc * nl * sizeof(int *));
    m[0][0] = malloc(nc * nl * np * sizeof(int));

    for (i=0;i<nl;i++) {
        m[i] = m[0] + i * nc;
        for (j=0;j<nc;j++) {
            m[i][j] = m[0][0] + (i * nc + j) * np;
        }
    }

    for(i=0;i<nl;i++){
        for(j=0;j<nc;j++){
            for(k=0;k<np;k++){
                m[i][j][k] = rand() % 10;
            }
        }
    }

    for(i=0;i<nl;i++){
        for(j=0;j<nc;j++){
            for(k=0;k<np;k++){
                printf("[%d][%d][%d]=%d ", i, j, k, m[i][j][k]);
            }
        } printf("\n");
    }

    free(m[0][0]);
    free(m[0]);
    free(m);
}