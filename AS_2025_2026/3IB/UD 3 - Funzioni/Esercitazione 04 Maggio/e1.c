#include <stdio.h>
#include "lib.c"

int main(){
    int valore;
    char junk;

    printf("Inserisci un valore: ");
    scanf("%d", &valore);
    junk = getchar();

    // punto 1:
    printf("Il numero %d e' composto da %d cifre.\n", valore, numberOfDigits(valore));
    printf("\n");
    
    // punto 2:
    printf("La media delle cifre del numero %d equivale a: %d\n", valore, avarageValueOfDigits(valore));
    printf("\n");

    // punto 3:
    printf("La cifra maggiore che compare nel numero %d equivale a: %d\n", valore, majorDigit(valore));
    printf("\n");

    // punto 3:
    printf("Il valore %d al contrario equivale a: %d", valore, reversedNumber(valore));
    printf("\n");
    return(0);
}