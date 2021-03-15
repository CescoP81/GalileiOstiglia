#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"

void printIntero(int _a){
    printf("%d", _a);
}

void doubleIntero(int* _a){
    *_a = *_a * 2;
}

int doubleIntero2(int _a){
    int ris;
    ris = _a * 2;
    return(ris);
    // oppure le tre righe sopra si possono abbreviare con la riga seguente:
    // return(_a*2);
}

void initVettore(int _v[], int _length){
    int i;
    srand(time(NULL));
    for(i=0; i<_length; i++)
        _v[i] = rand()%100 + 1;
}

void printVettore(int _v[], int _length){
    int i;
    for(i=0; i<_length; i++)
        printf("%4d", _v[i]);
}

int ricercaVettore(int _v[], int _length, int _src){
    int i;
    int trovato;

    trovato = 0;
    for(i=0; i<_length; i++){
        if(_v[i] == _src)
            trovato = 1;
    }
    return(trovato);
}

void reverseVettore(int _v[], int _length){
    int tmp;
    int i;
    for(i=0; i<_length/2; i++){
        tmp = _v[i];
        _v[i] = _v[_length - i - 1];
        _v[_length - i - 1] = tmp;
    }
}