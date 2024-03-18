// um ponteiro para uma função é uma variável do tipo ponteiro que armazena o endereço de 
// memória de uma função, para assim tratá-la como uma variável
#include <stdio.h>

float multiplica(float a, float b){ // criação da função do tipo float que recebe dois floats e os multiplica
    return a * b; // retorna um float
}

int main(void){
    float (*p_multiplica)(float, float) = multiplica; // ponteiro do tipo float* recebendo o endereço de "multiplica" na memória
    float result = (*p_multiplica)(2.3, 3.4); // result recebe o valor da função chamada pelo ponteiro criado acima

    printf("resultado: %.3f\n", result); // print do resultado retornado com 3 casas decimais após a vírgula
}