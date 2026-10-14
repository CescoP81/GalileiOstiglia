// Programma per testare l'uso delle funzioni.
#include <stdio.h>
#include "lib.c"

#define DIM 10

int main(){
    int vett[DIM];  // dichiaro un vettore con un numero di celle pari a DIM

    initVettore(DIM, vett, 0);
    stampaVettore(DIM, vett);
    printf("\n");
    caricaVettore(DIM, vett, 5, 15);
    stampaVettore(DIM, vett);
    printf("\n");
    caricaVettore(DIM, vett, 15, 75);
    stampaVettore(DIM, vett);
    printf("\n");
    printf("Media del vettore: %.2f", mediaVettore(DIM, vett));
    printf("\n");
    minimoMassimoVettore(DIM, vett);
    printf("\n");
    ordinaVettore(DIM, vett, 1);
    stampaVettore(DIM, vett);
    return 0;
}