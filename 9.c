/* #include <stdio.h>


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
    free(s);
} */

// Com Correções:
#include <stdio.h>
#include <stdlib.h>

struct teste {
    int x;
    char nome[4]; // 4 caracteres
};

int main(void) {
    struct teste *s = malloc(5*sizeof(struct teste)); // alocação de memória para s
    if (s == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return 1;
    }

    s->x = 3;
    s->nome, "jose"; 

    printf("%d\n", s->x);
    int i;
    for(i;i<4;i++){
        printf("%s\n", s->nome);
    }
    free(s); // liberar a memória alocada
    return 0;
}
