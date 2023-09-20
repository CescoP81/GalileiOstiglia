/*
    Author: F.P.
    Date: 20.09.23
    Abstract: Programma di allenamento su vettori e funzioni.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int DIM=10;
/*-- PROTOTIPI --*/
/**
 * Inizializza un vettore di DIM elementi interi con valori tra 1 e 20 estremi compresi.
 * @param int[] Vettore di riferimento
 * @param int Dimensione del vettore.
*/
void initVettore(int [], int);
/**
 * Stampa un vettore di DIM elementi interi.
 * @param int[] Vettore di riferimento.
 * @param int Dimensione del vettore.
*/
void printVettore(int [], int);
/**
 * Calcola e restituisce la media di un vettore di DIM elementi interi.
 * @param int[] Vettore di riferimento.
 * @param int Dimensione del vettore
 * @return Media calcolata.
*/
float mediaVettore(int[], int);
/**
 * Trova e restituisce il valore maggiore presente nel vettore.
 * @param int[] Vettore di riferimento.
 * @param int Dimensione del vettore.
 * @return Valore maggiore del vettore.
*/
int massimoVettore(int[], int);

/*-- MAIN PROGRAM --*/
int main(){
    int vet[DIM];
    initVettore(vet, DIM);
    printVettore(vet, DIM);
    printf("\n\n");
    printf("Media del vettore: %.2f \n", mediaVettore(vet, DIM));
    printf("Valore massimo presente: %d \n", massimoVettore(vet, DIM));
    return(0);
}

void initVettore(int _vet[], int _dim){
    int i;
    srand(time(NULL));

    for(i=0; i<_dim; i++){
        _vet[i] = 1 + rand()%20;
    }
}
void printVettore(int _vet[], int _dim){
    int i;
    for(i=0; i<_dim; i++){
        printf("%3d", _vet[i]);
    }
}
float mediaVettore(int _vet[], int _dim){
    int i;
    float somma;

    somma = 0.0;
    for(i=0; i<_dim; i++){
        somma = somma + _vet[i];
    }
    somma = somma / _dim;
    return(somma);
}
int massimoVettore(int _vet[], int _dim){
    int i;
    int max;

    max = _vet[0]; // mettere _max = 0 non è garanzia di correttezza dell'algoritmo.
    for(i=0; i<_dim; i++){
        if(_vet[i] > max)
            max = _vet[i];
    }

    return(max);
}