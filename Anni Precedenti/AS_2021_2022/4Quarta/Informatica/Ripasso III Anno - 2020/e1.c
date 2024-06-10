// sezione delle librerie.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
// sezione delle costanti.
#define DIM 10
// sezione dei prototipi delle funzioni.
void initVettore(int [], int);
void printVettore(int [], int);

// sezione del MAIN PROGRAM
int main(){
   srand(time(NULL));
   int a;         // variabile per valore utente.
   int i;         // variabile per cicli
   int v[DIM];    // vettore di valori interi random.

   // input di un valore da tastiera
   printf("Inserisci valore: ");
   scanf("%d", &a);
   fflush(stdin); // libero il buffer di tastiera dal carattere "invio";

   // inizializzazione del vettore con valori random.
   /*for(i=0; i<DIM; i++){
      v[i] = rand()%100+1;
   }*/
   initVettore(v, DIM);

   // stampa del vettore di numeri random
   /*for(i=0; i<DIM; i++)
      printf("%4d", v[i]);*/
   printVettore(v, DIM);
   printf("\n");

   // utilizzo del costrutto if-else per visualizzare solamente i valori pari.
   // e multipli di a.
   printf("A: %d\n", a);
   for(i=0; i<DIM; i++){
      /*if(v[i]%2 == 0){
         if(v[i]%a == 0)
            printf("%4d", v[i]);
      }*/

      if((v[i]%2 == 0) && (v[i]%a == 0))
         printf("%4d", v[i]);
   }

   return(0);
}

// sezione di definizione delle funzioni.
void initVettore(int _v[], int _l){
   int i;
   for(i=0; i<_l; i++){
      _v[i] = rand()%100;
   }
}
void printVettore(int _v[], int _l){
   int i;
   for(i=0; i<_l; i++)
      printf("%4d", _v[i]);
}