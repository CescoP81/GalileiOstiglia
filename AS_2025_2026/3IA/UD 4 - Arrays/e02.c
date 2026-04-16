#include <stdio.h>
#include "lib.c"

#define DIM 10
#define DIM_2 2

int main(){
    int vettore[DIM];     // vettore di DIM elementi interi
    int vettore2[DIM_2];
    int i;

    srand(time(NULL));  // inizializzo il generatore di numeri random.

    initVettore(vettore, DIM);      // chiamo la funzione di inizializzazione del vettore.
    stampaVettore(vettore, DIM);    // chiamo la funzione di stampa a video del vettore.
    printf("\n\n");
/*
    printf("\n");
    initVettore(vettore, 5);
    stampaVettore(vettore, 5);

    printf("\n");
    initVettore(vettore, 3);
    stampaVettore(vettore, 3);
// */
    printf("\n");
    // stampaVettoreGraficoBasic(vettore, DIM); // da usare su CodeSpace
    stampaVettoreGrafico(vettore, DIM);
    printf("\n");
    
    initVettore(vettore2, DIM_2);
    // stampaVettoreGraficoBasic(vettore2, DIM_2); // da usare su CodeSpace
    stampaVettoreGrafico(vettore2, DIM_2);
    return(0);
}