#include <stdio.h>
#include "lib.c"

#define DIM 10

int main(){
    int vettore[DIM];     // vettore di DIM elementi interi
    int i;

    srand(time(NULL));  // inizializzo il generatore di numeri random.

    initVettore(vettore, DIM);      // chiamo la funzione di inizializzazione del vettore.
    stampaVettore(vettore, DIM);    // chiamo la funzione di stampa a video del vettore.

    printf("\n");
    initVettore(vettore, 5);
    stampaVettore(vettore, 5);

    printf("\n");
    initVettore(vettore, 3);
    stampaVettore(vettore, 3);

    printf("\n");
    printf("%c", 218);


    return(0);
}