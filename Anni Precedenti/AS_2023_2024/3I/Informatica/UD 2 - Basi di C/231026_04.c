/*
    Author: Francesco P.
    Date:   2023.10.26
    file:   231026_04.c
    Desc:   Richiedi in input un valore intero,
            comunica il valore precedente e il valore successivo.
*/
#include <stdio.h>

int main(){
    int valore = 0;
    int prec = 0;
    int succ = 0;

    printf("Inserisci un valore: ");
    scanf("%d", &valore);

    succ = valore + 1;
    printf("Valore successivo: %d\n", succ);

    prec = valore - 1;
    printf("Valore precedente: %d\n", prec);

    return(0);
}