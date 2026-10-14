/*
    Contenuto del file LIB.C
    - Contiene lo sviluppo delle funzioni, il codice necessario ad ogni funzione
    per eseguire le operazioni che abbiamo progettato
    - DEVE includere tutte le librerie necessarie alle varie funzioni
    - DEVE includere il file lib.h dei prototipi.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "lib.h"

void initVettore(int _dim, int _v[], int _value){
    int i;
    for(i=0; i<_dim; i++){
        _v[i] = _value;
    }
}

void stampaVettore(int _dim, int _v[]){
    int i;
    for(i=0; i<_dim; i++){
        printf("%d ", _v[i]);
    }
}

void caricaVettore(int _dim, int _v[], int _min, int _max){
    int i;
    srand(time(NULL));

    for(i=0; i<_dim; i++){
        _v[i] = _min + (rand() % (_max - _min +1));
    }
}

float mediaVettore(int _dim, int _v[]){
    int i;
    int totale;
    float media;

    // calcolo la somma di tutti i valori presenti nel vettore
    totale = 0;
    for(i=0; i<_dim; i++){
        totale = totale + _v[i];
    }

    // calcolo la media !devo usare il casting per il calcolo!
    media = (float)totale / _dim;

    // restituisco la media
    return media;
}

void minimoMassimoVettore(int _dim, int _v[]){
    int i;
    int min, max;

    // ciclo per trovare il valore minimo presente nel vettore.
    min = _v[0];
    for(i=1; i<_dim; i++){
        if(_v[i] < min)
            min = _v[i];
    }

    // ciclo per trovare il valore maggiore presente nel vettore.
    max = _v[0];
    for(i=1; i<_dim; i++){
        if(_v[i] > max)
            max = _v[i];
    }

    printf("min: %d, max: %d\n", min, max);
}

void ordinaVettore(int _dim, int _v[], int _modo){
    int i, j;
    int tmp;

    // modo 0 -> decrescente
    if(_modo == 0){
        for(i=0; i<_dim; i++){
            for(j=i; j<_dim; j++){
                if(_v[i] < _v[j]){
                    tmp = _v[i];
                    _v[i] = _v[j];
                    _v[j] = tmp;
                }
            }
        }
    }

    // modo 1 -> crescente
    if(_modo == 1){
        for(i=0; i<_dim; i++){
            for(j=i; j<_dim; j++){
                if(_v[i] > _v[j]){
                    tmp = _v[i];
                    _v[i] = _v[j];
                    _v[j] = tmp;
                }
            }
        }
    }
}

// ==============================================================================

void initMatrice(int _rows, int _cols, int _m[_rows][_cols], int _min, int _max){
    int i, j;
    srand(time(NULL));

    for(i=0; i<_rows; i++){
        for(j=0; j<_cols; j++){
            _m[i][j] = _min + (rand() % (_max - _min + 1));
        }
    }
}

void stampaMatrice(int _rows, int _cols, int _m[_rows][_cols]){
    int i, j;

    for(i=0; i<_rows; i++){
        for(j=0; j<_cols; j++){
            printf("%4d", _m[i][j]);
        }
        printf("\n");
    }
}