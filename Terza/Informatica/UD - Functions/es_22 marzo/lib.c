#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"

void initVettore(int _v[], int _length){
    srand(time(NULL));
    int i;

    for(i=0; i<_length; i++)
        _v[i] = rand()%50 + 1;
}

void stampaVet(int _v[], int _length){
    int i;

    for(i=0; i<_length; i++){
        printf("%3d", _v[i]);
    }
}

int ricercaValore(int _v[], int _length, int _src){
    int i;
    int cnt; // contatore per i valori trovati uguali nel vettore.

    cnt = 0;
    for(i=0; i<_length; i++){
        if(_v[i] == _src)
            cnt++;
    }
    return(cnt);
}

int swapValori(int _v[], int _length, int _index1, int _index2){
    int tmp;
    // determino se gli indici sono validi
    if(_index1 <=0 || _index1>_length)
        return(0);
    if(_index2 <=0 || _index2>_length)
        return(0);
    
    // eseguo lo swap
    tmp = _v[_index1];
    _v[_index1] = _v[_index2];
    _v[_index2] = tmp;
    return(1);
}

int equalsVettori(int _v1[], int _v2[], int _length){
    int i;
    int uguali;

    uguali = 1;
    for(i=0; i<_length; i++){
        if(_v1[i] != _v2[i])
            uguali = 0;
    }
    return(uguali);
}