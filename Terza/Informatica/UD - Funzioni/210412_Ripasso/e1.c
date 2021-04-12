/*
    Programma che inizializza un vettore di 5 elementi random compresi tra 1 e 20 ed una
    matrice 10x5 con numeri random compresi tra 1 e 20.
    1 Inizializzare vettore e matrice.
    2 Stampare a video vettore e matrice.
    3 Confrontare la matrice con il vettore e visualizzare solo quelle righe che hanno
    4 Calcolare e restituire la media della matrice.
    somma totale maggiore della somma del vettore.
    (CON FUNZIONI)
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// COSTANTI
#define C 5
#define R 10
// PROTOTIPI

/* Inizializza un vettore di interi
@param int[] Vettore da inizializzare
@param int Dimensione del vettore
@return void
*/
void initVettore(int _v[], int _length);
/* Inizializza una matrice di interi
@param int[][] Matrice da inizializzare
@param int Numero di righe della matrice.
@param int NUmero di colonne della matrice.
@return void
*/
void initMatrice(int _m[][C], int _rows, int _cols);
/* Stampa a video un vettore di interi
@param int[] Vettore da inizializzare
@param int Dimensione del vettore
@return void
*/
void printVettore(int _v[], int _length);
/* Stampa una matrice di interi
@param int[][] Matrice da inizializzare
@param int Numero di righe della matrice.
@param int NUmero di colonne della matrice.
@return void
*/
void printMatrice(int _m[][C], int _rows, int _cols);
/* Confronta ogni singola riga della matrice con il vettore di riferimento, se la somma
dei valori della riga è maggiore della somma dei valori del vettore, la riga viene stampata.
@param int[] Vettore di riferimento.
@param int[][] Matrice da confrontare.
@param int Numero di righe.
@param int Numero di colonne e numero delle celle del vettore.
@return void.
*/
void confrontoMatriceVettore(int _v[], int _m[][C], int _rows, int _cols);
/* FUnzione che calcola e restituisce la media del valori di una matrice.
@param int[][] Matrice da elaborare.
@param int Numero delle righe.
@param int Numero delle colonne.
@return float Media totale della matrice.
*/
float mediaMatrice(int _m[][C], int _rows, int _cols);

// MAIN
int main(){
    srand(time(NULL));
    int vet[C];
    int mat[R][C];

    initVettore(vet, C);
    initMatrice(mat, R, C);

    printVettore(vet, C);
    printf("\n\n");
    printMatrice(mat, R, C);

    printf("\n\n");
    confrontoMatriceVettore(vet, mat, R, C);
    
    printf("\n\n");
    printf("Media della matrice: %.2f", mediaMatrice(mat, R, C));
    return(0);
}
// FUNZIONI

void initVettore(int _v[], int _length){
    int i;
    for(i=0; i<_length; i++){
        _v[i] = rand()%20+1;
    }
}

void initMatrice(int _m[][C], int _rows, int _cols){
    int i, j;
    for(i=0; i<_rows; i++){
        for(j=0; j<_cols; j++){
            _m[i][j] = rand()%20+1;
        }
    }
}

void printVettore(int _v[], int _length){
    int i;
    for(i=0; i<_length; i++)
        printf("%3d", _v[i]);
}

void printMatrice(int _m[][C], int _rows, int _cols){
    int i,j;
    for(i=0; i<_rows; i++){
        for(j=0; j<_cols; j++){
            printf("%3d", _m[i][j]);
        }
        printf("\n");
    }
}

void confrontoMatriceVettore(int _v[], int _m[][C], int _rows, int _cols){
    int i, j;
    int s_vet;  // somma dei valori del vettore.
    int s_riga; // somma dei valori di una determinata riga della matrice.

    // calcolo la somma dei valori presenti nel vettore.
    s_vet = 0;
    for(i=0; i<_cols; i++){
        s_vet = s_vet + _v[i];
    }

    for(i=0; i<_rows; i++){
        s_riga = 0;
        for(j=0; j<_cols; j++){
            s_riga = s_riga + _m[i][j];
        }

        if(s_riga > s_vet){
            for(j=0; j<_cols; j++){
                printf("%3d", _m[i][j]);
            }
        }
        else
            printf("#--");
        printf("\n");
    }
}

float mediaMatrice(int _m[][C], int _rows, int _cols){
    int i,j;
    int somma;
    float media;

    somma = 0;
    for(i=0; i<_rows; i++){
        for(j=0; j<_cols; j++){
            somma = somma + _m[i][j];
        }
    }

    media = (float)somma / (_rows*_cols);
    return(media);
}