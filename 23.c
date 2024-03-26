/*
A respeito das funções implementadas, avalie as afirmações a seguir.
    I. O resultado da impressão na linha 24 é: 7 - 7.
    II. A função funcao1, no pior caso, é uma estratégia mais rápida do que a funcao2.
    III. A função funcao2 implementa uma estratégia iterativa na concepção do algoritmo.
É correto o que se afirma em:
    IV. I, apenas.
    V. III, apenas.
    VI. I e II, apenas.
    VII. II e III, apenas.
    VIII. I, II e III.
Justifique sua resposta.
*/

#include <stdio.h>
#define TAM 10

int funcao1(int vetor[], int v){ // função para buscar um elemento em um vetor
    int i;
    for (i = 0; i < TAM; i++){ // varre todos os elementos um por um
        if (vetor[i] == v)
            return i; // retorna o índice
    }
    return -1;
}

int funcao2(int vetor[], int v, int i, int f){ // v é o elemento para se buscar no vetor, i é início, f é o final
    int m = (i + f) / 2; // índice médio para buscar o vetor
    if (v == vetor[m]) // se for igual ao elemento buscado retorna o índice
        return m;
    if (i >= f) // se o início for maior q o final
        return -1; // erro
    if (v > vetor[m]) // se o valor buscado for maior que o valor no índice médio
        return funcao2(vetor, v, m+1, f); // recursividade: a função é chamada com o valor médio +1 como início
    else
        return funcao2(vetor, v, i, m-1); // a função é chamada com o valor médio -1 como final
}

int main(){
    int vetor[TAM] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19}; // importante ser crescente
    printf("%d - %d", funcao1(vetor, 15), funcao2(vetor, 15, 0, TAM-1)); // comparando os dois resultados: 7 - 7, correto.
    return 0;
}
/*
Resposta: IV. I, apenas. Já que a funcao2 é mais rápida por usar um valor médio e recursividade enquanto funcao1 varre todo o vetor até achar
o valor buscado, no pior caso a funcao2 é mais veloz. Além disso a funcao2 não usa uma estratégia iterativa, mas sim uma estratégia
resursiva, chamando ela mesma dentro dela para os próximos passos, iterativa é a funcao1, que utiliza um laço de repetição for.
*/