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
float getMediaVettore(int _vet[], int _dim){
    int i;
    int somma;
    //float media;

    somma = 0;  // azzero la variabile accumulatore altrimenti potrei avere valori errati o casuali.
    for(i=0; i<_dim; i++){
        somma = somma + _vet[i];
    }
    // media = (float)somma / _dim;
    // return(media);
    return((float)somma / _dim);
}
int getValoreMassimo(int _vet[], int _dim){
    int i;
    int max;

    max = _vet[0];
    for(i=1; i<_dim; i++){
        if(_vet[i] > max)
            max = _vet[i];
    }
    return(max);
}
int isPrimo(int _val){
    int div;
    if(_val < 2){
        return(0);
    }
    if(_val == 2)
        return(1);
    div = 2;
    while(div < _val){
        if(_val%div == 0)
            return(0);
        div = div + 1;
    }
    return(1);
}
void stampaValoriPrimi(int _vet[], int _dim){
    int i;
    for(i=0; i<_dim; i++){
        if(isPrimo(_vet[i]) == 1)
            printf("%3d", _vet[i]);
    }
}