/* Esercitazione sulle matrici e funzioni che ricevono matrici. */
#include <stdio.h>
#include "lib.c"

#define DIM 10
#define ROWS 5  // definisco nr. righe della matrice.
#define COLS 5  // definisco nr. colonne della matrice.

int main(){
    int matrix[ROWS][COLS];

    caricaMatrice(ROWS, COLS, matrix);
    stampaMatrice(ROWS, COLS, matrix);
    printf("\n\n");
    caricaMatriceScacchiera(ROWS, COLS, matrix);
    stampaMatrice(ROWS, COLS, matrix);
    return 0;
}