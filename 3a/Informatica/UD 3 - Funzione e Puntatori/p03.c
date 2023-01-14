#include <stdio.h>

/**
 * Funzione che riceve due valori e restituisce la somma.
 * @param int Valore uno.
 * @param int Valore due.
 * @return int Somma dei valori.
*/
int sommaValori(int, int);

int main(){
    int a = 5;
    int b = 4;
    int s;

    s = sommaValori(a, b);
    printf("La somma vale: %d", s);
    return(0);
}

int sommaValori(int _v1, int _v2){
    int somma;
    somma = _v1 + _v2;
    return(somma);
}
