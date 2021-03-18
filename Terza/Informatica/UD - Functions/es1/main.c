/*
    Author: Pradella Francesco
    Date: 15.03.2021
    Desc: Esempio di programma con le funzioni.
*/
#include <conio.h>
#include <stdio.h>
#include "lib.c"

#define DIM 6

int main(){
    int a;
    int ax2;
    int vet[DIM];
    
    a = 19;
    printIntero(a);

    doubleIntero(&a);
    printf("\n%d", a);

    ax2 = doubleIntero2(a);
    printf("\na: %d - (a*2): %d", a, ax2);

    printf("\n");
    initVettore(vet, DIM);
    printVettore(vet, DIM);

    if(ricercaVettore(vet, DIM, 25) == 1)
        printf("\nValore trovato!");
    else
        printf("\nValore non trovato.\n");

    printf("\n");
    reverseVettore(vet, DIM);
    printVettore(vet, DIM);
    return(0);
}