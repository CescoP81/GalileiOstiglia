/*
   Creare un programma C che richieda l'inserimento di 5 valori in un vettore.
   Determina e comunica la POSIZIONE (indice) del valore maggiore e del valore minore
*/
#include <stdio.h>

#define DIM 5

int main(){
   int vet[DIM];
   int i;
   int max, imax;    // variabili per il valore massimo e l'indice del valore massimo
   int min, imin;    // variabili per il valore minimo e l'indice del valore minimo.

   // inserimento valori
   for(i=0; i<DIM; i++){
      printf("Valore alla posizione %d: ", i);
      scanf("%d", &vet[i]);
      fflush(stdin);
   }
   printf("\n");
   // visualizzo il vettore
   for(i=0; i<DIM; i++){
      printf("[%d]: %d\n", i, vet[i]);
   }

   // ricerca massimo e relativo indice
   max = vet[0];
   imax = 0;
   for(i=0; i<DIM; i++){
      if(vet[i] > max){
         max = vet[i];
         imax = i;
      }
   }
   printf("Valore massimo %d in posizione %d\n", max, imax);

   min = vet[0];
   imin = 0;
   for(i=0; i<DIM; i++){
      if(vet[i] < min){
         min = vet[i];
         imin = i;
      }
   }
   printf("Valore minimo %d in posizione %d\n", min, imin);


   return(0);
}
