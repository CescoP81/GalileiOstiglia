/*
    Definizione delle funzioni sviluppate come libreria.
    - include il file lib.h.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
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

bool stampaSubArray(int _v[], int _dim, int _index1, int _index2){
    int i;
    // test su esistenza indice1.
    if(_index1 < 0 || _index1 > _dim)
        return false;
    // test su esistenza indice21.
    if(_index2 < 0 || _index2 > _dim)
        return false;
    // test verifica se index1 maggiore di index2.
    if(_index1 > _index2)
        return false;
    // test che indice2 sia più grande di index1
    if(_index1 == _index2)
        return false;
    
    // stampa tra gli indici validi, estremi compresi.
    for(i=_index1; i<=_index2; i++)
        printf("%d ", _v[i]);
    return true;
}

//---------------------------

void caricaMatrice(int _rows, int _cols, int _m[_rows][_cols]){
    int i,j;
    srand(time(NULL));

    // doppio ciclo di caricamento matrice
    for(i=0; i<_rows; i++){
        for(j=0; j<_cols; j++){
            _m[i][j] = 1 + rand()%25;
        }
    }
}

void stampaMatrice(int _rows, int _cols, int _m[_rows][_cols]){
   int i,j;
   
   // doppio ciclo di stampa matrice
   for(i=0; i<_rows; i++){
        for(j=0; j<_cols; j++){
            printf("%3d", _m[i][j]);
        }
        printf("\n");
    }
}