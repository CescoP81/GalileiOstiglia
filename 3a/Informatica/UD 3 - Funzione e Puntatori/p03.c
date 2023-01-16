#include <stdio.h>

/**
 * Funzione che riceve due valori e restituisce la somma.
 * @param int Valore uno.
 * @param int Valore due.
 * @return int Somma dei valori.
*/
int sommaValori(int, int);

/**
 * Somma i divisori di un numero.
 * @param int Valore da utilizzare.
*/
void sommaDivisori(int);

/**
 * Calcola il Massimo Comun Divisore tra due numeri.
 * @param int Valore 1
 * @param int Valore 2
*/
void mcd(int, int);

/**
 * Calcola il Minimo Comune Multiplo tra due numeri.
 * @param int Valore 1
 * @param int Valore 2
*/
void mcm(int, int);



int main(){
    int a = 5;
    int b = 4;
    int s;

    s = sommaValori(a, b);
    printf("La somma vale: %d", s);
    printf("\n\n");
    sommaDivisori(12);
    printf("\n");
    mcd(12, 28);
    printf("\n");
    mcm(3, 7);
    return(0);
}

int sommaValori(int _v1, int _v2){
    int somma;
    somma = _v1 + _v2;
    return(somma);
}
void sommaDivisori(int _x){
    int div;
    int somma;

    somma = 0;
    for(div=1; div<=_x; div++){
        if(_x%div == 0)
            somma = somma + div;
    }
    printf("Somma divisori di %d: %d", _x, somma);
}
void mcd(int _x, int _y){
    int min;
    int div;
    int mcd;

    if(_x < _y)
        min = _x;
    else
        min = _y;
    
    for(div=1; div<=min; div++){
        if((_x%div == 0) && (_y%div == 0))
            mcd = div;
    }
    printf("L'mcd tra %d e %d vale: %d", _x, _y, mcd);
}
void mcm(int _x, int _y){
    int mcm;
    
    if(_x>_y)
        mcm = _x;
    else
        mcm = _y;
    
    while((mcm%_x !=0) || (mcm%_y != 0)){
        mcm = mcm + 1;
    }

    printf("Il minimo comune multiplo tra %d e %d vale: %d.", _x, _y, mcm);
        
}

