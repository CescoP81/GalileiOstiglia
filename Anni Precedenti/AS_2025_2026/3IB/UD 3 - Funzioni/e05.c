#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mialib.c"

int main(){
    int a, b;
    int x, y;

    a = 6;
    b = 14;
    printf("a: %d, b: %d\n", a, b);

    // usando & prima della variabile significa
    // passare l'indirizzo in memoria della variabile.
    scambiaValori(&a, &b);
    // stampo per vedere se è avvenuto lo scambio effettivo dei valori.          
    printf("a: %d, b: %d\n\n", a, b);

    calcolaAreaPerimetro(a, b, &x, &y);
    printf("Rettangolo %dx%d: Area=%d Perimetro=%d\n\n", a, b, x, y);
    return(0);
}