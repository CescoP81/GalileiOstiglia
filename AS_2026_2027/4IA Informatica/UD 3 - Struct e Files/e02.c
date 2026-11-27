#include <stdio.h>
#include "lib.c"

#define DIM 3

int main(){
    Shape figura;
    Shape vectorShape[DIM];

    inputShape(&figura);
    printf("Base: %d, Altezza: %d\n\n", (&figura)->b, (&figura)->h);
    //printf("Base: %d, Altezza: %d\n\n", figura.b, figura.h);
    printShape(figura);


    // --- estensione esercizio utilizzando un vettore di 3 elementi.
    for(int i=0; i<DIM; i++){
        inputShape(&vectorShape[i]);    // passo l'indirizzo di ogni cella del vettore.
    }    

    for(int i=0; i<DIM; i++){
        printShape(vectorShape[i]); //passo una copia di ogni cella del vettore.
    }
    return 0;
}