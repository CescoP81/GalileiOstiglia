/**
 * Author:  Francesco Pradella
 * Date:    28.10.2023
 * Desc:    Soluzione alla traccia_1 dei test proposti per la verifica di laboratorio.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int DIM = 10;

/**
 * Init an array with random value between min and max.
 * @param int[] Reference to an array.
 * @param int Size of the array.
 * @param int min value of the random range.
 * @param int max value of the random range.
*/
void initVettore(int[], int, int, int);

/**
 * Print an array with direction choice.
 * @param int[] Reference to an array.
 * @param int Size of the array.
 * @param int Direction.
*/
void printVettore(int[], int, int);

/**
 * Calculate and print the divisors for a number
 * @param int[] Reference to an array.
 * @param int Size of the array.
*/
void trovaDivisoriVettore(int[], int);

/**
 * Find and reset a specific value.
 * @param int[] Reference to an array.
 * @param int Size of the array.
 * @param int Value to search and reset.
*/
void ricercaAzzeravettore(int[], int, int);

/**
 * Sort in ascending order and return min and max values.
 * @param int[] Reference to an array.
 * @param int Size of the array.
 * @param int* reference for min value.
 * @param int* reference for max value.
*/
void orderMinMaxVettore(int[], int, int*, int*);

int main(){
    int vet[DIM];
    srand(time(NULL));
    int minimo, massimo;

    // -- punto 1
    initVettore(vet, DIM, 5, 25);       // inizializzo il vettore con valori tra 5 e 25
    // -- punto 2
    printVettore(vet, DIM, 0);          // stampo il vettore da inizio a fine.
    printf("\n");
    printVettore(vet, DIM, 1);          // stampo il vettore da fine a inizio.
    printf("\n");
    // -- punto 3
    trovaDivisoriVettore(vet, DIM);     // per ogni valore del vettore stampo il numero dei divisori.
    printf("\n");
    // -- punto 4
    ricercaAzzeravettore(vet, DIM, 15); // ricerco e azzero il valore 15 se presente nel vettore.
    printVettore(vet, DIM, 0);          // stampo il vettore da inizio a fine.
    printf("\n");
    // -- punto 5
    orderMinMaxVettore(vet, DIM, &minimo, &massimo);
    printVettore(vet, DIM, 0);
    printf("\n");
    printf("Valore minimo %d\n", minimo);
    printf("Valore massimo: %d", massimo);

    return(0);
}

void initVettore(int _vet[], int _dim, int _min, int _max){
    int i;
    for(i=0; i<_dim; i++){
        _vet[i] = _min + rand()%(_max - _min + 1);
    }
}
void printVettore(int _vet[], int _dim, int _choice){
    int i;

    for(i=0; i<_dim; i++){
        if(_choice == 0)
            printf("%3d", _vet[i]);
        if(_choice)
            printf("%3d", _vet[_dim-i-1]);
    }
}
void trovaDivisoriVettore(int _vet[], int _dim){
    int i, div;
    int cntDiv;

    for(i=0; i<_dim; i++){
        printf("%3d: ", _vet[i]);
        cntDiv = 0;
        for(div=1; div<=_vet[i]; div++){
            if(_vet[i]%div == 0)
                cntDiv++;
        }
        printf("%d", cntDiv);
        printf("\n");
    }
}
void ricercaAzzeravettore(int _vet[], int _dim, int _value){
    int i;
    for(i=0; i<_dim; i++){
        if(_vet[i] == _value){
            _vet[i] = 0;
        }
    }
}
void orderMinMaxVettore(int _vet[], int _dim, int *_min, int *_max){
    int i, j;
    int tmp;
    for(i=0; i<_dim-1; i++){
        for(j=i; j<_dim; j++){
            if(_vet[i] > _vet[j]){
                tmp = _vet[i];
                _vet[i] = _vet[j];
                _vet[j] = tmp;
            }
        }
    }

    *_min = _vet[0];
    *_max = _vet[_dim-1];
}