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

int inputValoreRange(int _min, int _max){
    int valore;

    
    return(valore);
}

int nextPrimo(int _val){
    int nextP;
    /* soluzione funzionante ma ottimizzabile 
    bool primo;
    int nextP;
    int div;
    nextP = _val;
    do{
        nextP = nextP + 1;
        primo = true;
        for(div=2; div<nextP; div++){
            if(nextP%div == 0)
                primo = false;
        }
    }while(primo == false);*/

    //while(isPrimo(nextP) == false){
    nextP = _val + 1;
    while(!isPrimo(nextP)){
        nextP = nextP + 1;
    }

    return(nextP);
}
int nextPrimo3(int _val) {
    while (! isPrimo(++_val))
        ;
    return _val;
}

int prevPrimo(int _val){
    int nextP;
    nextP = _val;
    do{
        nextP = nextP - 1;
    }while(!isPrimo(nextP));
    return(nextP);
}

void raddoppiaValore(int* _n){
    int tmp;            // creo una variabile intera di supporto

    printf("Addr ricevuto: %p\n", _n);

    tmp = *_n;          // in tmp metto il contenuto della cella di memoria il cui indirizzo è un _n.
    tmp = tmp * 2;      // raddoppio il valore contenuto in tmp.
    *_n = tmp;          // nella cella di memoria all'indirizzo contenuto in _n metto il valore di tmp.

    // equivalente a: *_n = (*_n)*2;
}

void calcolaAreaPerimetro(int _base, int _altezza, int* _area, int* _perimetro){
    // creo variabili di appoggio per calcola area e perimetro.
    int tmpArea;
    int tmpPerimetro;

    // eseguo i calcoli.
    tmpArea = _base * _altezza;
    tmpPerimetro = (_base+_altezza) * 2;

    // assegno i valori calcolati nelle rispettive celle di memoria di cui conosci gli indirizzi.
    *_area = tmpArea;
    *_perimetro = tmpPerimetro;
}