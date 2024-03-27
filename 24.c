/*
Um usuário precisa implementar o controle de uma matriz de leds com 8 x 8 elementos. Para
isso, ele criou um programa em C dotado de uma matriz da forma unsigner char m[8][8] para armazenar
os estados dos leds. Como existem apenas dois estados possíveis para os leds
(aceso ou apagado), ele assumiu que leds acessos seriam denotados pelo inteiro "1" nessa matriz
e leds apagados seriam denotados pelo inteiro "0".
Ocorre que a função que controla os leds exige que a informação que controla a matriz seja
enviada via porta serial usando uma função que recebe um único inteiro não sinalizado de
64 bits, da forma send(unsigned long estado). Nesse inteiro, os bytes mais significativos deverão
guardar os estados das linhas iniciais da matriz de leds, enquanto os bytes menos significativos
devem guardar os estados das linhas finais da matriz. Assim, é necessário que cada estado
previsto na matriz m seja codificado em um bit correspondente na variável enviada pela função.
Crie um programa em linguagem C para realizar essa codificação e explique na forma de
comentários como sua codificação da matriz m na variável de 64 bits foi realizada.
*/

#include <stdio.h>
#include <stdlib.h>

// função fictícia para enviar o estado através da porta serial
void send(unsigned long estado) {
    printf("Estado enviado: %lu\n", estado); // %lu é o formato para imprimir unsigned long
}
// função para converter decimal em binário
void convert(unsigned long dec, char b[64]){
    int i;
    for(i=0;i<64;i++){
        b[63 - i] = (dec >> i) & 1; // desloca em i bits para a direita e analisa o bit menos significativo, fazendo de todos os bits de dec
    }
}

int main(void) {
    char bin[64];
    unsigned char *x;
    char m[8][8];
    unsigned long estado = 0;
    int i, j;

    // preenchendo a matriz com valores aleatórios 0 ou 1
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            m[i][j] = rand() & 1; 
        }
    }

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            printf("%d ", m[i][j]); 
        } printf("\n");
    }

    for (i = 0; i < 8; i++) { // linhas
        for (j = 0; j < 8; j++) { // colunas
            estado = estado | ((unsigned long)m[7-i][7-j] << ((i * 8) + j)); // deslocar bits, i são as linhas e j são as colunas
        }
    }

    // enviando o estado através da porta serial
    send(estado);
    // convertendo estado em binário e armazenando em bin
    convert(estado, bin);
    for(i=0;i<64;i++){
        printf("%d ", bin[i]);
        if((i+1)%8==0) // separar as linhas para melhorar visualização
            printf("|");
    }        
    return 0;
}
/*
estado inicialmente recebe 64 "0"s, um em cada bit, para preenchê-los com os bits da matriz desloca-se ela de acordo com i e j,
para que os bits menos significativos fiquem no final, o preenchimento de estado é do final ao início
*/

