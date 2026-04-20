/*
    Esempio di dichiarazione, inizializzazione e stampa di un Array (vettore)
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 10  // non definisce in realtà una costante, ma un ALIAS, cioè quando il programma viene compilato
                // dove è presente la parola DIM viene sostituita con il valore intero 10 
/*
potreste trovare anche questo, ma è relativo a C++ 
const int DIM=10;
*/
int main(){
    // dichiaro un vettore di 10 celle di intero
    int vet[DIM];
    int i;

    // inizializzo il vettore con valori random compresi tra 1 e 10
    srand(time(NULL));
    for(i=0; i<DIM; i++){
        vet[i] = 1 + rand()%10;
    }

    // stampo a video il vettore inizializzato.
    /*for(i=0; i<DIM; i++){
        printf("[%d]= %d\n", i, vet[i]);
    }*/
    for(i=0; i<DIM; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
    
    // stampo a video le celle di posizione pari.
    for(i=0; i<DIM; i++){
        if(i%2 == 0)
            printf("%d ", vet[i]);
        else
            printf("* ");
    }
    printf("\n");

    // stampo a video le celle con cntenuto pari
    for(i=0; i<DIM; i++){
        if(vet[i] % 2 == 0)
            printf("%d ", vet[i]);
        else
            printf("* ");
    }
    printf("\n");

    // stampa a video tutti i valori divisibili per 3.
    for(i=0; i<DIM; i++){
        if(vet[i] % 3 == 0)
            printf("%d ", vet[i]);
        else
            printf("* ");
    }
    return(0);
}