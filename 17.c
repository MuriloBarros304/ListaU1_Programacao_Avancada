#include <stdio.h>
#include <stdlib.h>
#define max 50

int compare(int a, int b) { // função de comparação
    return (a-b);
}

void ordena(int *array, int num, int (*comp)(int, int)) {
    int i, j;
    for (i=0;i<num-1;i++) {
        for (j=0;j<num-i-1;j++) {
            if ((*comp)(array[j], array[j + 1]) < 0) {
                int aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
}

int main() {
    int n = max;
    int i;
    int *x; // dessa vez, um array de inteiros
    printf("Digite o número de elementos (no máximo 50): ");
    scanf("%d", &n);
    x = (int *)malloc(n * sizeof(int));
    if (x == NULL) {
        printf("Erro ao alocar memória\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        x[i] = rand() % 10; // números aleatórios até 10
    }
    //ponteiro para função compare
    ordena(x, n, compare);
    printf("\n");
    printf("array após a ordenação \n");
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %d\n", i, x[i]);
    }
    free(x);
    return 0;
}
