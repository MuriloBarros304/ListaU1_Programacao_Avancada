/*
Determine o que será mostrado pelo seguinte programa (compile-o, execute-o e verifique se
foram obtidas as respostas esperadas, justificando o porque de cada uma).
*/

#include <stdio.h>

int main(void){
    int valor;
    int *p1;
    float temp;
    float *p2;
    char aux;
    char *nome = "Ponteiros";
    char *p3;
    int idade;
    int vetor[3];
    int *p4;
    int *p5;

    // (a)
    valor = 10;
    p1 = &valor;
    *p1 = 20; // alterando "valor" para 20
    printf("a = %d \n", valor); // deve retornar 20, foi alterado

    // (b)
    temp = 26.5;
    p2 = &temp; // armazenando o endereço de temp
    *p2 = 29.0; // novo valor
    printf("b = %.1f \n", temp);

    // (c)
    p3 = &nome[0]; // apenas o primeiro caractere da palavra "Ponteiros"
    aux = *p3; // armazena o conteúdo de p3
    printf("c = %c \n", aux);

    // (d)
    p3 = &nome[4]; // quinto caractere da palavra "Ponteiros"
    aux = *p3;
    printf("d = %c \n", aux);

    /* (e) */
    p3 = nome; // primeira letra, por padrão nome = nome[0]
    printf("e = %c \n", *p3);
    
    /* (f) */
    p3 = p3 + 4; // igual o item d, quinto caractere da string
    printf("f = %c \n", *p3);

    /* (g) */
    p3--; // quarto caractere da string
    printf("g = %c \n", *p3);

    /* (h) */
    vetor[0] = 31;
    vetor[1] = 45;
    vetor[2] = 27;
    p4 = vetor; // vetor[0]
    idade = *p4;
    printf("h = %d \n", idade);

    /* (i) */
    p5 = p4 + 1; // vetor[1]
    idade = *p5; // segundo número do array
    printf("i = %d \n", idade);

    /* (j) */
    p4 = p5 + 1; // p4 atualizada, terceiro número do array
    idade = *p4;
    printf("j = %d \n", idade);

    /* (l) */
    p4 = p4 - 2; // primeiro número do array
    idade = *p4;
    printf("l = %d \n", idade);

    /* (m) */
    p5 = &vetor[2] - 1; // decrementando o endereço 2 em uma unidade, ficando com 1, ou seja, vetor[1] = 45
    printf("m = %d \n", *p5);

    /* (n) */
    p5++; // vetor[2] (vetor[1++])
    printf("n = %d \n", *p5);

}