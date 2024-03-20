#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  int i, j;
  int **a, **b, **c;
  int nla=5, nca=4, nlb=4, ncb=3;
  // aloca array auxiliar
  a = (int**) malloc (nla*sizeof(int*));
  // aloca o bloco de elementos da matriz
  a[0] = (int*) malloc (nla * nca * sizeof(int));
  // fixar os ponteiros para as linhas
  for(i=1; i<nla; i++){ //5x4
    a[i] = a[i-1] + nca;
  }
  // aloca array auxiliar
  b = (int**) malloc (nca*sizeof(int*));
  // aloca o bloco de elementos da matriz
  b[0] = (int*) malloc (nca * ncb * sizeof(int));
  // fixar os ponteiros para as linhas
  for(i=1; i<nca; i++){ //nl
    b[i] = b[i-1] + ncb; //nc
  }
  c = (int**) malloc (nla*sizeof(int*));
  c[0] = (int*) malloc (nla * ncb * sizeof(int*));
  
  free(a[0]);
  free(b[0])
  
  free(a);
  free(b);
}