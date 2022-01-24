/* Programma di esempio sull'utilizzo degli array, caricamento da tastiera
visualizzazione e calcolo della somma totale valori.
*/
#include <stdio.h>

#define DIM 3    // definisco una costanta con valore intero pari a 5.

int main(){
   int i;         // variabile necessaria per i cicli for di scorrimento sul vettore.
   int vet[DIM];  // dichiarazione di un vettore intero di DIM elementi.
   int somma;     // variabile per calcolare la somma totale dei valori inseriti nel vettore.
   float media;   // variabile per il calcolo della media.

   // carico i valori nel vettore chiedendoli all'utente.
   for(i=0; i<DIM; i++){
      printf("Valore in posizione %d: ", i);
      scanf("%d", &vet[i]);
      fflush(stdin);
   }

   // visualizzo i valori inseriti nel vettore
   printf("\nVettore: ");
   for(i=0; i<DIM; i++){
      printf("%d ", vet[i]);
   }
   printf("\n\n");

   // calcolo la somma di tutti i valori presenti nel vettore.
   somma = 0;
   for(i=0; i<DIM; i++){
      somma = somma + vet[i];
   }
   printf("Somma totale: %d", somma);
   printf("\n\n");

   // calcolo della media dei valori presenti nel vettore.
   somma = 0;
   for(i=0; i<DIM; i++){
      somma = somma + vet[i];
   }
   media = (float)somma / DIM;      // eseguo il casting temporaneo della variabile somma.
   printf("Media: %.2f", media);    // %.2f ".2f" -> indica il numero di cifre decimali.

   return(0);
}