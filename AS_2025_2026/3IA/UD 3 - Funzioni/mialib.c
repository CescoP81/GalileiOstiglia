/*  Contiene il codice C delle diverse funzioni che compongono la mia libreria. */
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "mialib.h"

bool isPrimo(int _n){
    int div;    // variabile per i divisori del numero passato come parametro.
    int cnt;    // contatore per i divisori trovati del numero passato come parametro.

    cnt = 0;
    for(div=1; div<=_n; div++){
        if(_n%div == 0) // ho trovato un divisore! -> incremento il contatore
            cnt++;
    }

    if(cnt<=2)
        return(true);
    else
        return(false);
}
bool isPerfect(int _n){
    int div;
    int somma;
    
    somma = 0;
    div = 1;
    while(div <= _n){
        if(_n%div == 0){
            somma = somma + div;
        }
        div = div + 1;
    }
    
    if(somma == (_n*2))
        return(true);
    else
        return(false);    
}
bool isTernaPitagorica(int _n1, int _n2, int _n3){
    if((_n1*_n1) + (_n2+_n2) == (_n3*_n3))
        return(true);
    else
        return(false);
}