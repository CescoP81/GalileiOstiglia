#include <stdlib.h>
#include <time.h>
#include "lib.h"

void initMatrice(int _m[][_C], int _r, int _c){
    int i, j;
    srand(time(NULL));
    // inizializzazione della matrice
    for(i=0; i<_r; i++){
        for(j=0; j<_c; j++){
            _m[i][j] = rand()%20+1;
        }
    }
}

void stampaMatrice(int _m[][_C], int _r, int _c){
    int i, j;
    for(i=0; i<_r; i++){
        for(j=0; j<_c; j++){
            printf("%3d", _m[i][j]);
        }
        printf("\n");
    }
}

float mediaMatrice(int _m[][_C], int _r, int _c){
    int i, j;
    int somma;
    
    somma = 0;
    for(i=0; i<_r; i++){
        for(j=0; j<_c; j++){
            somma = somma + _m[i][j];
        }
    }

    return((float)somma/(_r*_c));
}

void ricercaMinimoMatrice(int _m[][_C], int _r, int _c, int *x, int *y){
    int i, j; // indici per i cicli sulla matrice.
    int min; // valore minimo presente nella matrice.
    int min_i, min_j; // coordinate riga e colonna del minimo trovato.

    min = _m[0][0];
    min_i = 0;
    min_j = 0;

    for(i=0; i<_r; i++){
        for(j=0; j<_c; j++){
            if(_m[i][j] < min){
                min = _m[i][j];
                min_i = i;
                min_j = j;
            }
        }
    }

    *x = min_i;
    *y = min_j;
}