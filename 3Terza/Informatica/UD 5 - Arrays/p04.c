/*
   Inizializzare un vettore di 10 eementi con valori random compresi tra 
   1 e 25 estremi compresi.
*/
#include <stdio.h>
#include <stdlib.h>  //librerie per la generazione di numeri random.
#include <time.h>    // come sopra.

#define DIM 10

int main(){
   int vet[DIM];
   int i;

   // inizializzo il generatore di numeri random
   srand(time(NULL));

   // ciclo di caricamento valori nel vettore.
   /* rand() -> genera un numero casuale grande (non ci importa quanto)
      rand()%25 -> resto dell divisione per 25, genera un numero possibile tra 0 e 24
      aggiungento +1 significa che sposto il rando 0-24 di una unità quindi 1-25
   */
   for(i=0; i<DIM; i++){
      vet[i] = rand()%25 + 1; 
   }
   
   // visualizzo il vettore ottenuto
   for(i=0; i<DIM; i++){
      printf("%d ", vet[i]);
   }

   return(0);
}