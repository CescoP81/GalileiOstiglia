// contiene il main program di test delle funzioni, o chiamate delle funzioni.
#include <stdio.h>
#include "lib.c"

#define DIM 13  // la userò come dimensione del vettore.

int main(){
    int vettore[DIM]; // crea/alloca un vettore di 10 celle di tipo intero con indici da 0 a 9.
    float med;
    int max;

    inizializzaVettoreRandom(vettore, DIM);
    printf("Vettore inizializzato: ");
    stampaVettore(vettore, DIM);
    printf("\n\n");

    med = getMediaVettore(vettore, DIM);
    printf("Il valor medio vale: %.3f", med);
    printf("\n\n");

    max = getValoreMassimo(vettore, DIM);
    printf("Valore massimo presente: %d", max);
    printf("\n\n");

    printf("Valori primi presenti nel vettore: ");
    stampaValoriPrimi(vettore, DIM);
    printf("\n\n");
    
    return(0);
}