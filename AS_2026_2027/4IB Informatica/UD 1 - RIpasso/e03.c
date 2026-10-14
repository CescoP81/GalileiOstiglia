// Programma per testare l'uso delle funzioni.
#include <stdio.h>
#include "lib.c"

#define R 5
#define C 5

int main(){
    int matrix[R][C];

    initMatrice(R, C, matrix, 1, 15);
    stampaMatrice(R, C, matrix);
    return 0;
}