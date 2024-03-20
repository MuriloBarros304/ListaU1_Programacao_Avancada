#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 50 

int compare(int a, int b) { // função de comparação
    return (a-b);
}

int compq(const void *a, const void *b) { // função de comparação para o qsort
    return (*(int *)a-*(int *)b);
}

void ordena(int *array, int num, int (*comp)(int, int)) { // função que ordena com bubble sort
    int i, j;
    for (i=0;i<num-1;i++) {
        for (j=0;j<num-i-1;j++) {
            if ((*comp)(array[j], array[j + 1]) > 0) {
                int aux = array[j];
                array[j] = array[j + 1];
                array[j + 1] = aux;
            }
        }
    }
}

int main() {
    clock_t inicio, fim;
    double tempo;
    int n = max;
    int i;
    int *x; // um array de inteiros
    int *y; // outro array de inteiros
    printf("Digite o número de elementos (no máximo 50): ");
    scanf("%d", &n);
    x = (int *)malloc(n * sizeof(int));
    y = (int *)malloc(n * sizeof(int));
    if (x == NULL) {
        printf("Erro ao alocar memória\n");
        return 1;
    }
    if (y == NULL) {
        printf("Erro ao alocar memória\n");
        return 1;
    }
    for (i = 0; i < n; i++) {
        x[i] = rand() % 10; // números aleatórios até 10
        y[i] = x[i]; // y é uma cópia de x
    }
    printf("\n");
    printf("x antes da ordenação \n"); // imprimir x
    for (i = 0; i < n; i++) {
        printf("x[%d] = %d\n", i, x[i]);
    }
    printf("\n"); 
    printf("y antes da ordenação \n"); // imprimir y
    for (i = 0; i < n; i++) {
        printf("y[%d] = %d\n", i, y[i]);
    }
    inicio - clock();
    ordena(x, n, compare); // ponteiro para função compare
    fim = clock();
    tempo = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    printf("com o bubble sort levou %.5f segundos \n", tempo);
    printf("\n");
    printf("array após a ordenação por bubble sort\n");
    for (i = 0; i < n; i++) {
        printf("x[%d] = %d\n", i, x[i]);
    }
    inicio = clock();
    qsort(y, n, sizeof(int), compq);
    fim = clock();
    tempo = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    printf("com o qsort levou %.5f segundos \n", tempo);
    printf("\n");
    printf("array após a ordenação por qsort\n");
    for (i = 0; i < n; i++) {
        printf("y[%d] = %d\n", i, y[i]);
    }
    free(x);
    free(y);
    return 0; // concluindo, o qsort levou cerca de 0.00002 segundos para fazer a mesma tarefa que o bubble sort levou 0.00146 segundos
    // ou seja, o qsort é muito mais eficiente levando em consideração o tempo que ele leva para ordenar um array
}
