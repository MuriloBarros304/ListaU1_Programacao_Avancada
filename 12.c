#include <stdio.h>

int main(void){
    float aloha[10], coisas[10][5], *pf, value = 2.2;
    int i=3;

    // comandos
    aloha[2] = value; // válido
    scanf("%f", aloha); // inválido, 
    aloha = "value"; // inválido, aloha é um vetor do tipo float, não pode armazenar um literal
    printf("%f", aloha); // inválido, para funcionar o tipo dos dois argumentos do printf devem ser iguais
    coisas[4][4] = aloha[3]; // inválido, dimensões diferentes
    coisas[5] = aloha; // inválido, tipos diferentes
    pf = value; // value é um float, pf é um ponteiro de float, ou seja, tipos diferentes
    pf = aloha; // válido, tipos de variáveis float*
}