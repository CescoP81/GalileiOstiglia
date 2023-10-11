#include<stdio.h>
#include<stdlib.h>
#include<time.h>

const int DIM=10;

/**
 * Stampa un vettore di interi in modo ricorsivo
 * @param int[] Vettore di riferimento.
 * @param int Indice attuale da stampare.
 * @param int Dimensione del vettore.
*/
void stampaRicorsivaVettore(int[], int, int);

int main(){
    int vet[DIM];
    int i;
    srand(time(NULL));

    // genero il vettore in modo random con valori compresi tra 1 e 25
    for(i=0; i<DIM; i++)
        vet[i] = 1 + rand()%25;

    // stampo il vettore con un ciclo
    for(i=0; i<DIM; i++)
        printf("%3d", vet[i]);

    printf("\n\n");
    stampaRicorsivaVettore(vet, 0, DIM);
    return(0);    
}

void stampaRicorsivaVettore(int _vet[], int _indice, int _dim){
     //stampa dalla cella zero alla cella _dim-1
    if(_indice < _dim){
        printf("%3d", _vet[_indice]);
        stampaRicorsivaVettore(_vet, _indice+1, _dim);     
    }
    // */

    /* //stampa dalla cella _dim-1 alla cella 0
    if(_indice < _dim){
        stampaRicorsivaVettore(_vet, _indice+1, _dim);
        printf("%3d", _vet[_indice]);    
    }
    // */

}
/*
 stampa con for: 14  5  2 22  4  7 24 20  4 11

 stampa funzione: 14  5  2 22  4  7 24 20  4 11
-----
stampa con for: 18 10 25 11 19  6 12 10 10 14

stampa funzione: 14 10 10 12  6 19 11 25 10 18
*/