/*
    Programma che inserita una parola ne calcola il numero di caratteri che la compongono
    specificando per ogni singolo carattere il numero occorrenze.
*/
#include <stdio.h>
#include "lib_stringhe.c"

#define DIM 40

int main(){
    char parola[DIM];
    char junk;

    printf("Inserisci una parola: ");
    scanf("%s", &parola);
    junk = getchar();

    contaLettere(parola);

    return 0;
}
