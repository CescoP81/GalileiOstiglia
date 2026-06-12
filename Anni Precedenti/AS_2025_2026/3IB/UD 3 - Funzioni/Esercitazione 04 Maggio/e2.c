/**
Realizza un programma C che richiede in input un valore compreso tra 1 e 999, con una funzione
deve determinare un numero la cui somma delle cifre sia uguale alla somma delle cifre del numero
inserito.
Es:
input 147 → 1+4+7 = 12
return funzione: 552 → 5+5+2 = 12
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.c"

int main(){
    int valore;
    char junk;
    srand(time(NULL));

    do{
    printf("Inserisci un valore compreso tra 1 e 999: ");
    scanf("%d", &valore);
    junk = getchar();
    }while((valore < 1) || (valore > 999));

    printf("Numero inserito: %d\n", valore);
    printf("Numero con ugual somma delle cifre: %d", numeroEquivalente(valore));

    return(0);
}