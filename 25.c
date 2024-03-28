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
// função para mudar um elemento
void muda(int ***matriz, int i, int j, int k){ // recebe a matriz e os índices
    printf("Insira o elemento para mudar: \n");
    scanf("%d", &matriz[i][j][k]);
}

int main(void){
    int ***m;
    int np, nc, nl, i, j, k, plano, linha, coluna;
    printf("Insira os tamanhos da matriz: (planos, linhas, colunas)");
    scanf("%d %d %d", &np, &nl, &nc);
    // alocação dinâmica de memória
    m = malloc(np * sizeof(int **));
    m[0] = malloc(np * nl * sizeof(int *));
    m[0][0] = malloc(np * nl * nc * sizeof(int));
    // fixação dos ponteiros
    for (i=0;i<np;i++) {
        m[i] = m[0] + i * nl;
        for (j=0;j<nl;j++) {
            m[i][j] = m[0][0] + (i * nl + j) * nc;
        }
    }
    // preenchendo com números aleatórios
    for(i=0;i<np;i++){
        for(j=0;j<nl;j++){
            for(k=0;k<nc;k++){
                m[i][j][k] = rand() % 10;
            }
        }
    }
    // selecionar plano
    printf("Insira o plano para impressão: \n");
    scanf("%d", &plano);

    // imprimir
    for(j=0;j<nl;j++){
        for(k=0;k<nc;k++){
            printf("[%d][%d][%d]=%d ", plano, j, k, m[plano][j][k]);
        } printf("\n");
    } 
     
    printf("Insira o endereço do elemento para mudar: \n");
    scanf("%d %d %d", &plano, &linha, &coluna);
    muda(m, plano, linha, coluna);

    //após mudar
    printf("Após mudar um elemento: \n");
    for(i=0;i<np;i++){
        for(j=0;j<nl;j++){
            for(k=0;k<nc;k++){
                printf("[%d][%d][%d]=%d ", i, j, k, m[i][j][k]);
            } printf("\n");
        } printf("p+1 \n");
    }
    free(m[0][0]);
    free(m[0]);
    free(m);
}