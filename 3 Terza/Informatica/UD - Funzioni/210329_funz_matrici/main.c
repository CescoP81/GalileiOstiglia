#include <conio.h>
#include <stdio.h>
#include "lib.c"

#define R 10    // righe della matrice.
#define C 10    // colonne della matrice.

int main(){
    int matrix[R][C];

    // Punto 1: inizializzo la matrice richiamando la funzione.
    initMatrice(matrix, R, C);

    // Punto 2: stampo la matrice inizializzata
    stampaMatrice(matrix, R, C);

    // Punto 3: valor medio della matrice
    float med;
    med = mediaMatrice(matrix, R, C);
    printf("\n\nValor medio: %.2f\n", med);
    printf("Valor medio: %.2f\n\n", mediaMatrice(matrix, R, C));

    // Punto 4: ricerca indici valore minimo.
    int mi, mj;
    ricercaMinimoMatrice(matrix, R, C, &mi, &mj);
    printf("Il valore minimo si trova alle coordinate %d,%d e vale: %d.\n", mi, mj, matrix[mi][mj]);

    return(0);
}