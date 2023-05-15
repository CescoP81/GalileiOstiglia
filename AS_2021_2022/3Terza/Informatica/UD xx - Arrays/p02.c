/*
   Programma che richiede l'inserimento di un vettore di 5 elementi.
   - Visualizza il vettore
   - Determina e visualizza il valore maggiore presente nel vettore.
*/
#include <stdio.h>

#define DIM 5

int main(){
   int vet[DIM];     // vettore per i valori.
   int i;            // variabile per i cicli.
   int max;          // variabile per il massimo presente nel vettore.

   // inserimento dei valori nel vettore.
   for(i=0; i<DIM; i++){
      printf("Valore posizione %d: ", i);
      scanf("%d", &vet[i]);
      fflush(stdin);
   }

   // ciclo di ricerca del massimo.
   max = vet[0];
   for(i=0; i<DIM; i++){
      if(vet[i] > max)
         max = vet[i];     // errore che viene svolto facilemente: vet[i] = max; !!ERRORE!
   }
   printf("Valore massimo: %d", max);

   return(0);
}