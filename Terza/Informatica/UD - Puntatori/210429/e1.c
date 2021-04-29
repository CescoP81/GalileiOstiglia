#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 10

int initVettore(int *_v, int _length);
int printVettore(int *_v, int _length);

int main(){
    int vet[DIM];
    int i;
    
    printf("Dimensione di un INTERO: %d\n", sizeof(int));

// PRIMA PARTE----
/*
    for(i=0; i<DIM; i++){
        printf("Cella [%d]: %d\n", i, &vet[i]);
    }
    
    printf("\n");
    initVettore(vet, DIM);
    printVettore(vet, DIM);
*/
// SECONDA PARTE----

    int tmp;        // tmp = 'ciao'; tmp = 'c'+'i'+'a'+'o';
    // 99 -> bin
    char *ptmp;
    ptmp = (char *)&tmp;
    *(ptmp) = 'c';
    *(ptmp+1) = 'i';
    *(ptmp+2) = 'a';
    *(ptmp+3) = 'o';
    for(i=0; i<4; i++)
        printf("[%d] -> %c\n",(ptmp+i), *(ptmp+i));

    printf("\ntmp: %d", tmp);
    return(0);
}

int initVettore(int *_v, int _length){
    srand(time(NULL));
    int i;
    for(i=0; i<_length; i++){
        *(_v+i) = rand()%100 + 1;
    }
}

int printVettore(int *_v, int _length){
    int i;
    for(i=0; i<_length; i++){
        printf("[%d] - %d -> %4d\n", i, (_v+i), *(_v+i));
    }
}