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
    caricaVettore(DIM, vett, 0, 50);
    stampaVettore(DIM, vett);
    printf("\n");
    printf("Media del vettore: %.2f", mediaVettore(DIM, vett));
    printf("\n");
    return 0;
}