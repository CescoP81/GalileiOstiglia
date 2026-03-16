/* CONTIENE LA DEFINIZIONE DELLE FUNZIONI, INCLUDE mialib.h */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mialib.h"

void vediDivisori(int _n){
    int div;
    div = 1;
    while(div <= _n){
        if(_n%div == 0){
            printf("%d ", div);
        }
        div = div + 1;
    }
}

int getIntegerValue(){
    int box;
    char junk;

    printf("Insersci un valore intero: ");
    scanf("%d", &box);
    junk = getchar();

    return(box);
}

int getIntegerValueInterval(int _min, int _max){
    int box;
    char junk;
    // ciclo di inserimento valore, finche non è compreso nel range min<->max
    do{
        printf("Inserisci un valore(tra %d e %d): ", _min, _max);
        scanf("%d", &box);
        junk = getchar();
    }while(box<_min || box>_max);

    return(box);
}

int getRandomValue(){
    int box;
    box = 1 + rand()%999;
    return(box);
}

int getRandomValueInterval(int _min, int _max){
    int box;
    box = _min + (rand()%(_max - _min + 1));
    return(box);
}