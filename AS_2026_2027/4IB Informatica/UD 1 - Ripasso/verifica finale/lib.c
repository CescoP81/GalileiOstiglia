#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"

void initVettore(int _dim, int _v[], int _min, int _max){
    srand(time(NULL));
    int i;

    if(_min >= _max){
        for(i=0; i<_dim; i++)
            _v[i] = -1;
    }
    else{
        for(i=0; i<_dim; i++)
            _v[i] = _min + (rand()%(_max - _min + 1));
    }
}

void stampaVettore(int _dim, int _v[]){
    int i;
    for(i=0; i<_dim; i++)
        printf("%4d", _v[i]);
}

void ricercaSostituisci(int _dim, int _v[], int _v1, int _v2){
    int i;

    for(i=0; i<_dim; i++){
        if(_v1 == _v[i]){
            if(_v1%2 == 0){
               _v[i] = _v2; 
            }
            else{
                _v[i] = _v[i] + _v2;
            }
        }
    }
}

int massimoVettore(int _dim, int _v[]){
    int i;      // variabile per il ciclo
    int max;    // variabile per il massimo
    int cnt;    // variabile contatore dei massimi trovati

    // trovo il valore massimo
    max = _v[0];
    for(i=1; i<_dim; i++)
        if(_v[i] > max)
            max = _v[i];
    
    // ricerco il massimo, stampo la i in cui compare e conto quante volte compare.
    cnt = 0;
    for(i=0; i<_dim; i++){
        if(_v[i] == max){
            printf("Posizione: %d\n", i);
            cnt = cnt + 1;
        }
    }
    printf("\n\n");
    // ritorno al main il numero di massimi trovati nel vettore
    return cnt;
}

int trovaDoppi(int _dim, int _v[]){
    int i;
    int trovato;    // flag se trovo oppure no valori uguali adiacenti

    trovato = 0;
    for(i=0; i<_dim-1; i++)
        if(_v[i] == _v[i+1])
            trovato = 1;
    
    return trovato;
}