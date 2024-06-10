/**
 * Author:  Francesco Pradella
 * Date:    28.10.2023
 * Desc:    Soluzione alla traccia_2 dei test proposti per la verifica di laboratorio.
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
*/
void initVettore(int[], int, int);

/**
 * Print an array with direction choice.
 * @param int[] Reference to an array.
 * @param int Size of the array.
*/
void printVettore(int[], int);

/**
 * Even and odd value into the array
 * @param int[] Reference to an array.
 * @param int Size of the array.
*/
void pariDispariVettore(int[], int);

/** Find and replace a specific value.
 * @param int[] Reference to an array.
 * @param int Size of the array.
 * @param int Old value to search.
 * @param int New value.
*/
void findAndReplaceVettore(int[], int, int, int);

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
    initVettore(vet, DIM, 12);                  // inizializzo il vettore con valori tra 12 e 12*2
    // -- punto 2
    printVettore(vet, DIM);                     // stampo il vettore da inizio a fine.
    printf("\n\n");
    // -- punto 3
    pariDispariVettore(vet, DIM);               // valori pari e dispari con medie.
    printf("\n\n");
    // -- punto 4
    findAndReplaceVettore(vet, DIM, 14, 99);    // cerco il 14 e sostituisco con 99.
    printVettore(vet, DIM);                     // stampo il vettore con eventuali modifiche.
    printf("\n\n");
    // -- punto 5
    orderMinMaxVettore(vet, DIM, &minimo, &massimo);
    printVettore(vet, DIM);
    printf("\n");
    printf("Valore minimo %d\n", minimo);
    printf("Valore massimo: %d", massimo);

    return(0);
}

void initVettore(int _vet[], int _dim, int _min){
    int i;
    int max;

    max = _min * 2;
    for(i=0; i<_dim; i++){
        _vet[i] = _min + 1 + rand()%(max - _min);
    }
}
void printVettore(int _vet[], int _dim){
    int i;

    for(i=0; i<_dim; i++){
        printf("%3d", _vet[i]);
    }
}
void pariDispariVettore(int _vet[], int _dim){
    int i;
    int pari, cntPari;
    int dispari, cntDispari;

    pari = 0;
    cntPari = 0;
    dispari = 0;
    cntDispari = 0;

    for(i=0; i<_dim; i++){
        if(_vet[i]%2 == 0){
            pari = pari + _vet[i];
            cntPari++;
        }
        else{
            dispari = dispari + _vet[i];
            cntDispari++;
        }
    }
    printf("Valori pari trovati %d, con media valori: %.2f\n", cntPari, (float)pari/cntPari);
    printf("Valori dispari trovati %d, con media valori: %.2f", cntDispari, (float)dispari/cntDispari);
}
void findAndReplaceVettore(int _vet[], int _dim, int _old, int _new){
    int i;
    for(i=0; i<_dim; i++){
        if(_vet[i] == _old)
            _vet[i] = _new;
    }
}
void orderMinMaxVettore(int _vet[], int _dim, int *_min, int *_max){
    int i, j;
    int tmp;
    for(i=0; i<_dim-1; i++){
        for(j=i; j<_dim; j++){
            if(_vet[i] < _vet[j]){
                tmp = _vet[i];
                _vet[i] = _vet[j];
                _vet[j] = tmp;
            }
        }
    }

    *_max = _vet[0];
    *_min = _vet[_dim-1];
}