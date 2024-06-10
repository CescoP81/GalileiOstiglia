/**
 * Author:  Francesco Pradella
 * Date:    28.10.2023
 * Desc:    Soluzione alla traccia_3 dei test proposti per la verifica di laboratorio.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int COLS = 5;
const int ROWS = 5;

/**
 * init the matrix vith values between 1 and 9
 * @param int[][] Reference of the matrix.
 * @param int Rows size.
 * @param int Columns size.
*/
void initMatrice(int[][COLS], int, int);

/**
 * Print the matrix with total of each row
 * @param int[][] Reference of the matrix.
 * @param int Rows size.
 * @param int Columns size.
*/
void printMatriceSomme(int[][COLS], int, int);

/**
 * Total of even and odd values into the matrix.
 * @param int[][] Reference of the matrix.
 * @param int Rows size.
 * @param int Columns size.
 * @param int* Reference for even counter.
 * @param int* Reference for odd counter.
*/
void evenOddValueMatrice(int[][COLS], int, int, int*, int*);

/**
 * Find and reset a specific value
 * @param int[][] Reference of the matrix.
 * @param int Rows size.
 * @param int Columns size.
 * @param int Value to find and reset.
*/
void findAndResetMatrice(int[][COLS], int, int, int);

/**
 * Find and count a specific value
 * @param int[][] Reference of the matrix.
 * @param int Rows size.
 * @param int Columns size.
 * @param int Value to find and count.
*/
int findAndCountMatrice(int[][COLS], int, int, int);

int main(){
    int mat[ROWS][COLS];
    int value, risult;
    int pari, dispari;
    srand(time(NULL));


    // -- punto 1
    initMatrice(mat, ROWS, COLS);
    // -- punto 2
    printMatriceSomme(mat, ROWS, COLS);
    printf("\n\n");
    // -- punto 3
    evenOddValueMatrice(mat, ROWS, COLS, &pari, &dispari);
    printf("Somma dei valori pari: %d\n", pari);
    printf("Somma valori dispari: %d\n", dispari);
    printf("\n");
    // -- punto 4
    findAndResetMatrice(mat, ROWS, COLS, 4);
    printMatriceSomme(mat, ROWS, COLS);
    printf("\n\n");
    // -- punto 5
    value = 7;
    risult = findAndCountMatrice(mat, ROWS, COLS, value);
    printf("Valore cercato %d, trovato %d volta/e.", value, risult);
    return(0);
}

void initMatrice(int _mat[][COLS], int _r, int _c){
    int i, j;
    for(i=0; i<_r; i++){
        for(j=0; j<_c; j++){
            _mat[i][j] = 1 + rand()%9;
        }
    }
}
void printMatriceSomme(int _mat[][COLS], int _r, int _c){
    int i, j, somma;
    for(i=0; i<_r; i++){
        somma = 0;
        for(j=0; j<_c; j++){
            somma = somma + _mat[i][j];
            printf("%2d", _mat[i][j]);
        }
        printf(" --> %d", somma);
        printf("\n");
    }
}
void evenOddValueMatrice(int _mat[][COLS], int _r, int _c, int *_even, int *_odd){
    int i, j;
    *_even = 0;
    *_odd = 0;

    for(i=0; i<_r; i++){
        for(j=0; j<_c; j++){
            if(_mat[i][j]%2 == 0)
                *_even = *_even + _mat[i][j];
            else
                *_odd = *_odd + _mat[i][j];
        }
    }

}
void findAndResetMatrice(int _mat[][COLS], int _r, int _c, int _value){
    int i, j;
    for(i=0; i<_r; i++){
        for(j=0; j<_c; j++){
            if(_mat[i][j] == _value)
                _mat[i][j] = 0;
        }
    }
}
int findAndCountMatrice(int _mat[][COLS], int _r, int _c, int _value){
    int i, j;
    int cnt;

    cnt = 0;
    for(i=0; i<_r; i++){
        for(j=0; j<_c; j++){
            if(_mat[i][j] == _value)
                cnt++;
        }
    }
    return(cnt);
}