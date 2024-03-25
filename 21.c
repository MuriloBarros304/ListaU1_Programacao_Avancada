// alternativa C
int f(char *data){
    void *s;
    s = malloc(50); // alocação de 50 bytes da memória
    int size = strlen(data);
    if (size > 50) // se size menor que 50
        return(-1); // sai do programa, sem liberar
        /* free(s); --> o ideal seria ter um free dentro do if também */  
    free(s); // libera caso size seja menor ou igual a 50
    return 0;
}
// há um vazamento de memória caso o tamanho da função data, que armazena s, seja maior que 50