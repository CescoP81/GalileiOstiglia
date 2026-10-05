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