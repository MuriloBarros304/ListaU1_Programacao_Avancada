#include <stdio.h>
#include <stdlib.h>

void send(unsigned long estado){

}

int main(void){
    int m[8][8];
    int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            m[i][j] = rand() & 1;
        }
    }
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}