// file con la definizione delle singole funzioni.
#include <stdio.h>
#include "lib.h"

int inputNumber(int _p1, int _p2){
    int inserito;
    char junk;

    if(_p1==0 && _p2==0){
        printf("Inserisci un valore intero: ");
        scanf("%d", &inserito);
        junk = getchar();
        return(inserito);
    }
    if(_p1 != 0 && _p2 != 0 && _p1<_p2){
        do{
            printf("Inserisci un valore intero compreso tra %d e %d: ", _p1, _p2);
            scanf("%d", &inserito);
            junk = getchar();
        }while(inserito<_p1 || inserito>_p2);
        return(inserito);
    }
    if(_p1 == 0 && _p2 > 0){
        do{
            printf("Inserisci un valore intero compreso inferiore di %d: ", _p2);
            scanf("%d", &inserito);
            junk = getchar();
        }while(inserito >= _p2);
        return(inserito);
    }
    return(-1);
}

int getMaxDivider(int _v1, int _v2, int _v3){
    int valoreMinimo;       // valore minore tra i tre passati.
    int div;                // variabile per ciclo divisori.
    int divisoreMaggiore;   // variabile che contiene il divisore Maggiore trovato.

    // determino il valore minore tra i tre passati come parametri.
    valoreMinimo = _v1;
    if(_v2 < valoreMinimo) valoreMinimo = _v2;
    if(_v3 < valoreMinimo) valoreMinimo = _v3;
   
    // eseguo un ciclo di divisori da 1 al valore minimo trovato
    for(div=1; div<=valoreMinimo; div++){
        if((_v1%div == 0) && (_v2%div == 0) && (_v3%div == 0)){
            divisoreMaggiore = div;
        }
    }
    // restituisco il divisore maggiore trovato.
    return(divisoreMaggiore);
}

void swapValue(int* _x, int* _y){
    int tmp;
    tmp = *_x;
    *_x = *_y;
    *_y = tmp;
}

void orderValues(int* _v1, int* _v2, int* _v3, int _ordine){
    int scambioAvvenuto;
    if(_ordine == 0){   // selezionato ordine decrescente
        do{
            scambioAvvenuto = 0;
            if(*_v1 < *_v2){
                swapValue(_v1, _v2);
                scambioAvvenuto = 1;
            }
            if(*_v2 < *_v3){
                swapValue(_v2, _v3);
                scambioAvvenuto = 1;
            }
        }while(scambioAvvenuto != 0);
    }

    if(_ordine == 1){   // selezioanato ordine crescente
        do{
            scambioAvvenuto = 0;
            if(*_v1 > *_v2){
                swapValue(_v1, _v2);
                scambioAvvenuto = 1;
            }
            if(*_v2 > *_v3){
                swapValue(_v2, _v3);
                scambioAvvenuto = 1;
            }
        }while(scambioAvvenuto != 0);
    }
}