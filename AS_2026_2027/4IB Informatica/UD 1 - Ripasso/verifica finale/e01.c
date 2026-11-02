#include <stdio.h>
#include "lib.c"

#define DIM 15

int main(){
    int vett[DIM];
    int a = 5;
    int b = 25;
    int val1 = 7;
    int val2 = 4;
    int cnt_massimi;

    // test funzione 1 di inizializzazione
    initVettore(DIM, vett, a, b);
    stampaVettore(DIM, vett);
    printf("\n\n");

    // test funzione 2 di ricerca e sostituzione
    //ricercaSostituisci(DIM, vett, val1, val2);
    stampaVettore(DIM, vett);
    printf("\n\n");

    // test funzione 3 di ricerca massimo
    cnt_massimi = massimoVettore(DIM, vett);
    printf("Il massimo compare nel vettore: %d volta/te", cnt_massimi);
    printf("\n\n");

    // test funzione 4 di ricerca doppi consecutivi
    if(trovaDoppi(DIM, vett) == 1)
        printf("Esistono coppie di valori uguali adiacenti!\n");
    else
        printf("Non sono presenti valori uguali consecutivi!\n");

    return 0;
}