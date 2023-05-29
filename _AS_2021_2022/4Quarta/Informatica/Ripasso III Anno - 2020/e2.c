// sezione delle librerie.
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
// sezione delle costanti.
#define DIM 10
// sezione dei prototipi delle funzioni.
/**
   Inizializzazione di un vettore
   @param int[] Vettore da inizializzare.
   @param int Dimensione del vettore.
   @return void
*/
void initVettore(int [], int);
void printVettore(int [], int);

void doubleVal(int);
void doubleVal2(int *);
// sezione del MAIN PROGRAM
int main(){
   srand(time(NULL));
   int x;         // variabile per valore utente.
   int i;         // variabile per cicli
   int v1[DIM], v2[DIM], v3[DIM];
   initVettore(v1, DIM);
   initVettore(v2, DIM);
   initVettore(v3, 6);

   printVettore(v1, DIM);
   printf("\n");
   printVettore(v2, DIM);
   printf("\n");
   printVettore(v3, 6);
   printf("\n\n");

   x = 7;
   doubleVal(x);
   printf("X: %d", x);
   printf("\n\n");
   doubleVal2(&x);
   printf("X: %d", x);
   printf("\n\n");
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

void doubleVal(int _a){
   _a = _a * 2;
}
void doubleVal2(int *_a){
   *_a = (*_a)*2;
}