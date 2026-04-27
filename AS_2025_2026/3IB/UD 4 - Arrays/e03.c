// contiene il main program di test delle funzioni, o chiamate delle funzioni.
#include <stdio.h>
#include "lib.c"

#define DIM 10  // la userò come dimensione del vettore.

int main(){
    int vettore[DIM]; // crea/alloca un vettore di 10 celle di tipo intero con indici da 0 a 9.

    inizializzaVettoreRandom(vettore, DIM);
    printf("Vettore inizializzato: ");
    stampaVettore(vettore, DIM);

    return(0);
}