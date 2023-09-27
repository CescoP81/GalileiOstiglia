/*
    - Inizializzazione di un vettore di 10 elementi con valori random compresi tra 1 e 25 (estremi compresi).
    - Visualizzazione vettore.
    - Ordinamento vettore Crescente-decrescente.
    - Swap tra posizioni.
    - Ricerca valore.
    - Sostituzione valore.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int DIM=10;
void initVettore(int[], int);
void printVettore(int[], int);
void orderAscending(int[], int);
void orderDescending(int[], int);

/**
 * Ordina un vettore in modo crescente o decrescente a scelta dell'utente
 * @param int[] Vettore di riferimento.
 * @param int Dimensione del vettore.
 * @param int Scelta ordinamento 0->Crescente / 1->Decrescente
*/
void orderVettore(int[], int, int);

int main(){
    int vettore[DIM];

    initVettore(vettore, DIM);
    printVettore(vettore, DIM);

    orderAscending(vettore, DIM);
    printVettore(vettore, DIM);

    initVettore(vettore, DIM);
    orderDescending(vettore, DIM);
    printVettore(vettore, DIM);

    printf("\n");
    initVettore(vettore, DIM);
    printVettore(vettore, DIM);
    orderVettore(vettore, DIM, 1);
    printVettore(vettore, DIM);

    return(0);
}

void initVettore(int _vet[], int _dim){
    int i;
    srand(time(NULL));

    for(i=0; i<_dim; i++){
        _vet[i] = 1 + (rand()%25);
    }
}
void printVettore(int _vet[], int _dim){
    int i;

    for(i=0; i<_dim; i++){
        printf("%3d", _vet[i]);
    }
    printf("\n");
}
void orderAscending(int _vet[], int _dim){
    int i, j;
    int tmp;
    for(i=0; i<_dim; i++){
        for(j=i; j<_dim; j++){
            if(_vet[i] > _vet[j]){
                tmp = _vet[i];
                _vet[i] = _vet[j];
                _vet[j] = tmp;
            }
        }
    }
}
void orderDescending(int _vet[], int _dim){
    int i, j;
    int tmp;
    for(i=0; i<_dim; i++){
        for(j=i; j<_dim; j++){
            if(_vet[i] < _vet[j]){
                tmp = _vet[i];
                _vet[i] = _vet[j];
                _vet[j] = tmp;
            }
        }
    }
}

void orderVettore(int _vet[], int _dim, int _order){
    int i, j;
    int tmp;

    if(_order == 0){ // 0 --> Ordine crescente
        for(i=0; i<_dim; i++){
            for(j=i; j<_dim; j++){
                if(_vet[i] > _vet[j]){
                    tmp = _vet[i];
                    _vet[i] = _vet[j];
                    _vet[j] = tmp;
                }
            }
        }
    }
    if(_order == 1){ // 1 --> Decrescente
        for(i=0; i<_dim; i++){
            for(j=i; j<_dim; j++){
                if(_vet[i] < _vet[j]){
                    tmp = _vet[i];
                    _vet[i] = _vet[j];
                    _vet[j] = tmp;
                }
            }
        }
    }
}