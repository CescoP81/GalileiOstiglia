// contiene la definizione, il codice vero e proprio, delle funzioni
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"

void inizializzaVettoreRandom(int _vet[], int _dim){
    int i;
    srand(time(NULL));

    for(i=0; i<_dim; i++){
        _vet[i] = 1 + (rand()%99);
    }
}

void stampaVettore(int _vet[], int _dim){
    int i;
    for(i=0; i<_dim; i++){
        printf("%3d", _vet[i]);
    }
}