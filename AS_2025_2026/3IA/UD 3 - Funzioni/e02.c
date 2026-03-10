/* Contiene il main program dell'esercizio che voglio svolgere */
#include <stdio.h>
#include "mialib.c"

int main(){
    int valore;
    int junk;
    for(valore=1; valore <= 7; valore++){
        if(isPrimo(valore))
            printf("%d -> Primo\n", valore);
    }
    printf("\n\n");
    for(valore=7; valore <= 15; valore++){
        if(isPrimo(valore))
            printf("%d -> Primo\n", valore);
    }
    printf("\n\n");
    for(valore=15; valore <= 25; valore++){
        if(isPrimo(valore))
            printf("%d -> Primo\n", valore);
    }
    printf("\n\n");
    for(valore = 1; valore<=30; valore++){
        if(isPerfect(valore))
            printf("%d -> Perfetto\n", valore);
    }

    return(0);
}