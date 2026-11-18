#include <stdio.h>
#include "lib_verifica.c"

#define DIM 5

int main(){
    int matrix[DIM][DIM];
    int vector[DIM];
    char junk;
    int indexMaxMedia;
    int cntColonneMaggiori;

    // risposta al punto A della verifica.
    initMatrixVector(DIM, DIM, matrix, DIM, vector, 10, 25);

    // risposta al punto B stampa matrice e vettore
    stampaMatrice(DIM, DIM, matrix);
    printf("\n\n");
    stampaVettore(DIM, vector);
    printf("\n\n");

    indexMaxMedia = indiceRigaMediaMaggiore(DIM, DIM, matrix);
    printf("Riga con media maggiore: %d", indexMaxMedia);
    printf("\n\n");

    cntColonneMaggiori = sommeVettoreColonne(DIM, DIM, matrix, DIM, vector);
    printf("Colonne maggiori del vettore: %d", cntColonneMaggiori);
    printf("\n\n");

    stampaMatrice(DIM, DIM, matrix);
    printf("\n\n");
    if(swapCelle(DIM, DIM, matrix, 0,0, 4, 4)){
        printf("Scambio avvenuto...\n");
        stampaMatrice(DIM, DIM, matrix);
    }
    else{
        printf("Scambio non avvenuto.");
    }
    printf("\n\n");
    if(swapCelle(DIM, DIM, matrix, 0,0, 6, 5)){
        printf("Scambio avvenuto...\n");
        stampaMatrice(DIM, DIM, matrix);
    }
    else{
        printf("Scambio non avvenuto.");
    }

    return 0;
}