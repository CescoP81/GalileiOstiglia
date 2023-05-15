/**
 * Realizzare un programm C che inizializza con una funzione
 * un vettore di 20 elementi con valori random compresi tra 1 e 10.
 * Grazie ad due funzioni RICORSIVE, stampa il vettore a video e ne calcola
 * la somma dei valori.
 * */
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 5

void initVettore(int [], int);
void printVettoreR(int [], int, int);
void printVettoreRovesciatoR(int [], int);
int sommaTotaleR(int [], int);

int main(){
   int vet[DIM];
   srand(time(NULL));
   int s=0;

   initVettore(vet, DIM);
   printVettoreR(vet, 0, DIM);
   printf("\n\n");
   printVettoreRovesciatoR(vet, DIM);
//*/
   printf("\n\n");
   s = sommaTotaleR(vet, DIM);
   printf("Somma: %d", s);

   return(0);
}

void initVettore(int _v[], int _dim){
   int i;
   for(i=0; i<_dim; i++){
      _v[i] = rand()%10 + 1;
   }
}

void printVettoreR(int _v[], int _index, int _dim){
   if(_index < _dim){
      printf("%3d", _v[_index]);
      printVettoreR(_v, _index+1, _dim);
   }
}

void printVettoreRovesciatoR(int _v[], int _index){
   if(_index > 0){
      printf("%3d", _v[_index-1]);
      printVettoreRovesciatoR(_v, _index-1);
   }
}

int sommaTotaleR(int _v[], int _index){
   int s;
   if(_index > 0){
      //printf("--%d\n", _v[_index-1]);
      s = _v[_index-1]+sommaTotaleR(_v, _index-1);
      //printf("---%d", s);
      return(s);
   } 
   //else{
      return(0);
   //} 
   //*/
}