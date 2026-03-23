/* CONTIENE LA DEFINIZIONE DELLE FUNZIONI, INCLUDE mialib.h */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
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

bool isPrimo(int _num){
    int div;
    int cnt;

    cnt = 0;
    for(div=1; div<=_num; div++){
        if(_num%div == 0)
            cnt = cnt + 1;
    }

    if(cnt <= 2)
        return(true);
    else
        return(false);
}

int nextPrimo(int _num){
    int nextP;
    nextP = _num + 1;
    while(isPrimo(nextP) == false){
        nextP = nextP + 1;
    }
    return(nextP);
}

int prevPrimo(int _num){
    int prevP;
    prevP = _num - 1;
    while(isPrimo(prevP) == false){
        prevP = prevP - 1;
    }
    return(prevP);
}

void generaPrimi(int _num, int _n){
    int casuale;
    int cnt;
    int cntTot;

    cnt = 1;
    cntTot = 0;
    do{
        cntTot = cntTot + 1;
        //casuale = 1 + rand()%999; sostituisco con la seconda opzione
        casuale = getRandomValueInterval(_num+1, 999);
        if(isPrimo(casuale) && casuale>_num){   //equivalente a (isPrimo(casuale)==true && casuale>_num)
            printf("%d ", casuale);
            cnt = cnt + 1;
        }
    }while(cnt <= _n);
    printf("Generazioni totali: %d\n", cntTot);
}