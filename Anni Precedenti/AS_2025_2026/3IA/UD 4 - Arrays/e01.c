#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 7
//const int DIM=10;

int main(){
    int vet[DIM];       // array di 10 elementi interi indicizzati da 0 a 9.
    int i;              // variabile tipica per lo scorrimento di un vettore.
    int tmp;

    srand(time(NULL));
    // init di un vettore con valori casuali tra 1 e 10
    for(i=0; i<DIM; i++){
        printf("Indice i: %d\n", i);
        vet[i] = 1 + rand()%10;
    }

    // stampo il vettore per vedere i valori assegnati
    for(i=0; i<DIM; i++){
        printf("%3d ", vet[i]);
    }
    printf("\n");

    // raddoppio dei valori del vettore
/*    for(i=0; i<DIM; i++){
        tmp = vet[i];
        tmp = tmp * 2;
        vet[i] = tmp;
        // vet[i] = vet[i] * 2;
    }
        */
    // stampo il vettore per vedere i valori assegnati
    for(i=0; i<DIM; i++){
        printf("%3d ", vet[i]);
    }
    printf("\n");

    // visualizza SOLAMENTE i valori pari che compaiono nel vettore.
    printf("valori pari:\n");
    for(i=0; i<DIM; i++){
        if(vet[i] % 2 == 0){
            printf("%3d ", vet[i]);
        }
        else{
            printf("*** ");
        }
    }
    printf("\n");

    // visualizza i valori contenuti nelle CELLE di indice PARI.
    printf("indici pari:\n");
    for(i=0; i<DIM; i++){
        if(i % 2 == 0){
            printf("%3d ", vet[i]);
        }
        else{
            printf("*** ");
        }
    }
    printf("\n");
    return(0);
}