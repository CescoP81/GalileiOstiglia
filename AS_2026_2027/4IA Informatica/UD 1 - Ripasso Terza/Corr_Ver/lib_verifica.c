#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib_verifica.h"

void initMatrixVector(int _rows, int _cols, int _m[_rows][_cols], int _cell, int _v[], int _min, int _max){
    int i, j;
    srand(time(NULL));

    // inizializzo la matrice
    for(i=0; i<_rows; i++){
        for(j=0; j<_cols; j++){
            _m[i][j] = _min + (rand()%(_max-_min+1));
        }
    }

    // inizializzo il vettore
    for(i=0; i<_cell; i++){
        _v[i] = _min + (rand()%(_max-_min+1));
    }
}

void stampaMatrice(int _rows, int _cols, int _m[_rows][_cols]){
    int i, j;
    for(i=0; i<_rows; i++){
        for(j=0; j<_cols; j++){
            printf("%3d", _m[i][j]);
        }
        printf("\n");
    }
}

void stampaVettore(int _cell, int _v[]){
    int i;
    for(i=0; i<_cell; i++)
        printf("%3d", _v[i]);
}

int indiceRigaMediaMaggiore(int _rows, int _cols, int _m[_rows][_cols]){
    int i, j;
    int media;  // media della riga
    int mediaMax;
    int indexMax;

    for(i=0; i<_rows; i++){
        media = 0;
        for(j=0; j<_cols; j++){
            media = media + _m[i][j];
        }
        media = media / _cols;
        printf("Riga [%d]: %d\n", i, media);
        if((i==0) || (media>mediaMax)){
            mediaMax = media;
            indexMax = i;
        }
    }

    return indexMax;
}

int sommeVettoreColonne(int _rows, int _cols, int _m[_rows][_cols], int _cell, int _v[]){
    int i,j;
    int sommaVettore;
    int sommaColonna;
    int cntMaggiori;    // contatore che conta quante colonne hanno somma valori maggiore di somma vettore

    // calcolo la somma dei valori del vettore
    sommaVettore = 0;
    for(i=0; i<_cell; i++){
        sommaVettore = sommaVettore + _v[i];
    }
    //printf("Somma vettore: %d\n", sommaVettore);

    cntMaggiori=0;
    for(i=0; i<_cols; i++){
        sommaColonna = 0;
        for(j=0; j<_rows; j++){
            sommaColonna = sommaColonna + _m[j][i];
        }
        //printf("Somma Colonna[%d]: %d\n", i, sommaColonna);
        if(sommaColonna > sommaVettore)
            cntMaggiori++;
    }

    return cntMaggiori;
}

int swapCelle(int _rows, int _cols, int _m[_rows][_cols], int _r1, int _c1, int _r2, int _c2){
    int tmp;    // variabile di comodo per effettuare il successivo scambio
    if((_r1 >= 0 && _r1 < _rows) && (_r2 >= 0 && _r2 < _rows) && (_c1 >= 0 && _c1 < _cols) && (_c2 >= 0 && _c2 < _cols)){
        tmp = _m[_r1][_c1];
        _m[_r1][_c1] = _m[_r2][_c2];
        _m[_r2][_c2] = tmp;
        return 1;
    }

    return 0;
}