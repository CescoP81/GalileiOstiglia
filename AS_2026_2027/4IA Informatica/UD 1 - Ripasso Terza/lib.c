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

void ordinaVettore(int _v[], int _dim, int _mode){
    int i, j; // indici delle iterative.
    int box;

    if(_mode == 0){ // ordinamento decrescente
        for(i=0; i<_dim; i++){
            for(j=i; j<_dim; j++){
                if(_v[j] > _v[i]){
                    box = _v[i];
                    _v[i] = _v[j];
                    _v[j] = box;
                }
            }
        }
    }
    if(_mode == 1){ // ordinamento crescente
        for(i=0; i<_dim; i++){
            for(j=i; j<_dim; j++){
                if(_v[j] < _v[i]){
                    box = _v[i];
                    _v[i] = _v[j];
                    _v[j] = box;
                }
            }
        }
    }
    
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

void caricaMatriceScacchiera(int _rows, int _cols, int _m[_rows][_cols]){
    int i, j;
    int cella;
    srand(time(NULL));
    
    cella = 0;
    for(i=0; i<_rows; i++){
        for(j=0; j<_cols; j++){
            do{
                _m[i][j] = 1 + rand()%99;
            }
            while(cella%2 != _m[i][j]%2);
            cella++;
        }
    }
}

float calcolaMediaMatrice(int _rows, int _cols, int _m[_rows][_cols]){
    int i, j;
    int sommaTotale;
    float media;

    // doppio ciclo per calcolo della somma totale
    sommaTotale = 0;
    for(i=0; i<_rows; i++){
        for(j=0; j<_cols; j++){
            sommaTotale = sommaTotale + _m[i][j];
        }
    }

    // calcolo e restituisco la media
    media = (float)sommaTotale / (_rows*_cols);
    return media;
}

void stampaSommeRigheMatrice(int _rows, int _cols, int _m[_rows][_cols]){
    int i,j;
    int sommaRiga;

    // stampo e contemporaneamente calcolo la somma delle celle per la riga i
    for(i=0; i<_rows; i++){
        sommaRiga = 0;
        for(j=0; j<_cols; j++){
            printf("%3d", _m[i][j]);
            sommaRiga = sommaRiga + _m[i][j];
        }
        printf(" -> %3d", sommaRiga);
        printf("\n");
    }
}

void triangoloInfSupMatrice(int _rows, int _cols, int _m[_rows][_cols]){
    int i, j;
    int sommaInfe;
    int sommaSupe;
    int sommaDiag;

    sommaInfe = 0;
    sommaSupe = 0;
    sommaDiag = 0;
    for(i=0; i<_rows; i++){
        for(j=0; j<_cols; j++){
            if(j>i)
                sommaSupe = sommaSupe + _m[i][j];
            if(i>j)
                sommaInfe = sommaInfe + _m[i][j];
            if(i == j)
                sommaDiag = sommaDiag + _m[i][j];
        }
    }

    printf("Superiore: %d, Inferiore: %d, Diagonale: %d", sommaSupe, sommaInfe, sommaDiag);
}