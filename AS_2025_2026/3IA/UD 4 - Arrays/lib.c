#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"

void initVettore(int _vet[], int _dim){
    int i;
    for(i=0; i<_dim; i++){
        _vet[i] = 1 + rand()%10;
    }
}
void stampaVettore(int _vet[], int _dim){
    int i;
    for(i=0; i<_dim; i++){
        printf("%3d ", _vet[i]);
    }
}
void stampaVettoreGrafico(int _vet[], int _dim){
    // put your code here...
}