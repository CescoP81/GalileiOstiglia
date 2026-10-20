// Programma per testare l'uso delle funzioni.
#include <stdio.h>
#include "lib.c"

#define R 5
#define C 5

int main(){
    int matrix[R][C];

    initMatrice(R, C, matrix, 1, 15);
    stampaMatrice(R, C, matrix);
    printf("\n");
    printf("Media della matrice: %.2f\n", mediaMatrice(R, C, matrix));
    printf("\n\n");
    matriceScacchiera(R, C, matrix);
    stampaMatrice(R, C, matrix);
    return 0;
}