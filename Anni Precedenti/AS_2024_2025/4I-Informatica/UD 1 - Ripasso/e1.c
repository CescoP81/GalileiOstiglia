/* Ripasso generale sui concetti di terza linguaggio C. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int DIM = 10;

int main(){
    int a;  // variabile intera singola
    int i;  // variabile intera singola

    int vet[DIM]; // Array di DIM posizioni intere.

    srand(time(NULL));

    // inizializzo un vettore con numeri random compresi tra 1 e 20
    for(i=0; i<DIM; i++){
        vet[i] = (rand()%20) + 1;
    }

    // stampo il vettore generato in precedenza.
    for(i=0; i<DIM; i++){
        printf("%3d", vet[i]);
    }

    return(0);
}