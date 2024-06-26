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
    int ***m; // a indexação da matriz será (plano, linha, coluna) -> [i][j][k]
    int np, nc, nl, i, j, k, plano, linha, coluna, pAtual;
    printf("Insira os tamanhos da matriz: (planos, linhas, colunas)\n");
    scanf("%d %d %d", &np, &nl, &nc);
    // alocação dinâmica de memória
    m = malloc(np * sizeof(int **));
    m[0] = malloc(np * nl * sizeof(int *));
    m[0][0] = malloc(np * nl * nc * sizeof(int));
    // fixação dos ponteiros
    for (i=0;i<np;i++) {
        m[i] = m[0] + i * nl; // fixar as linhas nos planos
        for (j=0;j<nl;j++) {
            m[i][j] = m[0][0] + (i * nl + j) * nc; // fixar as colunas 
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
    if(plano>=np){ // para evitar que o usuário insira um plano que não tem na matriz
        printf("a matriz não tem esse plano, insira o plano para impressão novamente: \n");
        scanf("%d", &plano); // inserir novamente     
    }
    // imprimir
    for(j=0;j<nl;j++){
        for(k=0;k<nc;k++){
            printf("[%d][%d][%d]=%d ", plano, j, k, m[plano][j][k]);
        } printf("\n");
    } 
    pAtual = plano; // armazenando o plano impresso
    printf("Insira o endereço do elemento para mudar: (plano, linha, coluna) \n");
    scanf("%d %d %d", &plano, &linha, &coluna); 
    if(pAtual == plano) // para mudar apenas um elemento do plano impresso anteriormente
        muda(m, plano, linha, coluna); // muda o elemento selecionado
    else{
        printf("Plano inválido, selecione um elemento do plano impresso anteriormente\n");
        scanf("%d %d %d", &plano, &linha, &coluna);
        muda(m, plano, linha, coluna); // muda o elemento corrigido
    } // se essa condição não existisse, seria possível mudar qualquer elemento da matriz

    //após mudar (imprime todos os planos)
    printf("Após mudar um elemento: \n");
    for(i=0;i<np;i++){ // planos
        for(j=0;j<nl;j++){ // linhas
            for(k=0;k<nc;k++){ // colunas
                printf("[%d][%d][%d]=%d ", i, j, k, m[i][j][k]);
            } printf("\n");
        } printf("\n");
    }
    free(m[0][0]);
    free(m[0]);
    free(m);
}
/*

Exemplo de entrada: 2 3 4
planos: 2
linhas: 3
colunas: 4

matriz completa:
3 6 7 5
3 5 6 2
9 1 2 7

0 9 3 6
0 6 2 6
1 8 7 9
O usuário escolhe um dos planos acima para imprimir, caso seja inválido deve inserir novamente.
*Insira o endereço do elemento para mudar*
1 0 1
*Insira o elemento para mudar*
5
Após mudar um elemento, no caso o [1][0][1]:
3 6 7 5
3 5 6 2
9 1 2 7

0 5 3 6 // 5 adicionado
0 6 2 6
1 8 7 9

*/