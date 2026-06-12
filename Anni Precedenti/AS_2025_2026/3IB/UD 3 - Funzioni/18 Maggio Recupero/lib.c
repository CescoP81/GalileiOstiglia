#include <stdio.h>
#include "lib.h"

int inputNumberRange(int _min, int _max){
    int val;
    char junk;

    if(_min < _max){
        do{
            printf("Inserisci un valore(tra %d e %d): ", _min, _max);
            scanf("%d", &val);
            junk = getchar();
        }while(val<_min || val>_max);
        return(val);
    }

    if(_min > _max){
        do{
            printf("Inserisci un valore(tra 0 e %d): ", _min);
            scanf("%d", &val);
            junk = getchar();
        }while(val<0 || val>_min);
        return(val);
    }

    if(_min == _max)
        return(-1);
}

int moltiplicaConSomme(int _n1, int _n2){
    int prodotto;
    int i;
    // prodotto è una variabile in cui sommo _n1 tante volte quando è _n2.
    prodotto = 0;
    for(i=1; i<=_n2; i++)
        prodotto = prodotto + _n1;
    
        return(prodotto);
}

int numeroDivisori(int _n){
    int divP;
    int divD;
    int div;

    divP = 0;
    divD = 0;
    for(div=1; div<=_n; div++){
        if(_n%div == 0){
            if(div%2 == 0)
                divP = divP + 1;
            else
                divD = divD + 1;
        }
    }
    printf("Trovati %d divisori PARI\n", divP);
    printf("Trovati %d divisori DISPARI\n", divD);
    return(divD+divP);
}

int totaleNumero(int _n){
    int totale;
    
    totale = 0;
    while(_n > 0){
        totale = totale + (_n%10);
        _n = _n / 10;
    }
    return(totale);
}