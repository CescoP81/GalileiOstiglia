#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "mialib.c"

int main(){
    int val;
    char junk;

    // acquisisco un valore generico da tastiera.
    printf("Inserisci un valore: ");
    scanf("%d", &val);
    junk = getchar();

    // verifico la correttezza della funzione isPrimo per determinare se un numero è primo oppure no.
    if(isPrimo(val)) // oppure scrivere if(isPrimo(val) == true) è la stessa cosa.
        printf("Il numero %d e' primo.\n",val);
    else 
        printf("Il numero %d non e' primo.\n",val);

    //val = nextPrimo(val);
    printf("Successivo primo: %d\n", nextPrimo(val));

    printf("Primo precedente: %d\n", prevPrimo(val));

    printf("Valore originale: %d\n", val);
    
    return(0);
}