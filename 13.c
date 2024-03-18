#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// memory leak significa vazamento de memória, que acontece quando há uma alocação de memória e não é liberada posteriormente,
// o conteúdo da memória alocada já está inutilizado porém ainda fica armazenado, sendo assim um armazenamento inútil.

// Exemplo 1
/* char *to_italic(char *s) {
    size_t len = strlen(s);
    char *result = malloc(len + 5); // assume que malloc não falhará
    sprintf(result, "**%s**", s);
    return result;
}

int main() {
    puts(to_italic("Hello, there!")); // o correto seria armazenar esse argumento em um ponteiro para depois dar free e liberar a memória
    puts(to_italic("Memory leak"));
} */

// Exemplo 2
/* int *add(int a) {
    int *result = malloc(sizeof(int));
    *result = a + 2;
    return result;
}

int main() {
    int *result = add(5); // não há liberação da memória alocada
    printf("%d+2=%d|", 5, *result); // deveria haver um free
    printf("%d+2=%d\n", 8, *add(8)); // deveria haver um free
} */

// Exemplo 3
void funcao() {
    int *ptr = (int *)malloc(sizeof(int)); // aloca memória dinamicamente
    if (ptr == NULL) {
        printf("Falha ao alocar memória\n");
        return;
    }

    // não libera a memória alocada
}

int main() {
    funcao(); // vazamento de memória

    return 0;
}
