#include <stdio.h>
struct teste{
    int x;
    char nome[4];
};
int main(void){
    struct teste *s;
    s->x = 3;
    s->nome[] = "jose";
    printf("%d", s->x);
    printf("%s", s->nome);
}