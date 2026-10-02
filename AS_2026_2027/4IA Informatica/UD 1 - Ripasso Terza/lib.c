/*
    Definizione delle funzioni sviluppate come libreria.
    - include il file lib.h.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "lib.h"

void caricaVettore(int _v[], int _dim, int _min, int _max){
    int i;
    srand(time(NULL));

    for(i=0; i<_dim; i++){
        _v[i] = _min + rand()%(_max - _min + 1);
    }
}

void stampaVettore(int _v[], int _dim){
    int i;
    for(i=0; i<_dim; i++){
        printf("%d ", _v[i]);
    }
}

float mediaVettore(int _v[], int _dim){
    int totale;
    int i;
    totale = 0;
    for(i=0; i<_dim; i++)
        totale = totale + _v[i];
    
    return ((float)totale)/_dim;
}

int getValoreAt(int _v[], int _dim, int _index){
    if(_index >=0 && _index<_dim)
        return _v[_index];
    else
        return -1;
}
