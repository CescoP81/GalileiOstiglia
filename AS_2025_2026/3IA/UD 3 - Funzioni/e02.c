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

    // verifico funzione terna pitagorica
    if(isTernaPitagorica(3,4,5))
        printf("I valori 3,4,5 sono una terna pitagorica.\n");
    else
        printf("I valori 3,4,5 non sono una terna pitagorica.\n");
        
    return(0); 
}