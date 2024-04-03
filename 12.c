/*
Suponha que as seguintes declarações tenham sido realizadas:
Identifique quais dos seguintes comandos é válido ou inválido:
*/

#include <stdio.h>

int main(void){
    float aloha[10], coisas[10][5], *pf, value = 2.2; // declarações
    int i=3;

    // comandos
    aloha[2] = value; // válido pois está definindo que a posição 2 do vetor aloha seja igual a 2.2.
    scanf("%f", &aloha); // válido pois está pedindo pro usuário definir qual valor deve ir pra aloha[0]. 
    aloha = "value"; // inválido, aloha é um vetor do tipo float, não pode armazenar um literal, para dar certo teria que ser aloha[i] = value, com i sendo int
    printf("%f", aloha); // inválido, para funcionar o tipo dos dois argumentos do printf devem ser iguais
    coisas[4][4] = aloha[3]; // válido pois estou fazendo com que posição [4][4] da matriz "coisas" seja igual a o que tem em aloha[3].
    coisas[5] = aloha; // inválido, tipos diferentes e não pode se atribuir um array diretamente a uma matriz.
    pf = value; // value é um float, pf é um ponteiro de float, ou seja, tipos diferentes, ou seja o pf so guarda endereço de memorias.
    pf = aloha; // válido, tipos de variáveis float, guardando um endereço de memoria no primeiro vetor de aloha
}
