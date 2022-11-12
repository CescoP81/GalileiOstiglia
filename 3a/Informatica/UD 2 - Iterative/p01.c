/*
Algoritmo che richiede un valore da tastiera finche
non è compreso in un range 5-15 estremi compresi.
*/
#include <stdio.h>

// dichiarazione di costanti.
#define MIN_RANGE 5
#define MAX_RANGE 15

int main(){
    int val;    // variabile per il valore inserito da tastiera.

    // ciclo di richiesta valore.
    do{
        printf("Inserisci un valore compreso tra %d e %d: ", MIN_RANGE, MAX_RANGE);
        scanf("%d", &val);
        fflush(stdin);
    }while(val<=MIN_RANGE || val>=MAX_RANGE);

    // verifico il valore inserito
    printf("Valore valido: %d", val);
    return(0);
}