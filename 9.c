/*
Qual será a saída do seguinte programa
*/

#include <stdio.h>

struct teste{
    int x = 3;
    char nome[4] = "jose";
    };

int main(){
    struct teste *s;
    printf("%d", s->x);
    printf("%s", s->name); // nome != name
    }

// O programa retornará um erro: preenchimento de variáveis dentro
// da declaração do struct