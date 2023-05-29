/*
   Realizzare i punti dell'esercizio precedente ma con funzioni.
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 5

void initVettore(int [], int);
void printVettore(int [], int);

void initMatrice(int [][DIM], int);
void printMatrice(int [][DIM], int);

int sommaVettore(int [], int);
void sommaRigheMatriceVettore(int [][DIM], int [], int);

// -- MAIN PROGRAM --
int main(){
   int mat[DIM][DIM];
   int vet[DIM];
   srand(time(NULL));

   initVettore(vet, DIM);
   printVettore(vet, DIM);

   printf("\n\n");
   
   initMatrice(mat, DIM);
   printMatrice(mat, DIM);

   printf("\n\n");
   sommaRigheMatriceVettore(mat, vet, DIM);
   return(0);
}

void initVettore(int _v[], int _dim){
   int i;
   for(i=0; i<_dim; i++){
      *(_v+i) = rand()%20 + 1;
   }
}

void printVettore(int _v[], int _dim){
   int i;
   for(i=0; i<_dim; i++){
      printf("%3d", *(_v+i));
   }
}

void initMatrice(int _m[][DIM], int _dim){
   int i;
   for(i=0; i<DIM; i++){
      initVettore(_m[i], _dim);
   }
}

void printMatrice(int _m[][DIM], int _dim){
   int i;
   for(i=0; i<DIM; i++){
      printVettore(_m[i], _dim);
      printf("\n");
   }
}

int sommaVettore(int _v[], int _dim){
   int s=0;
   int i;
   for(i=0; i<_dim; i++)
      s = s + *(_v+i);
   return(s);
}

void sommaRigheMatriceVettore(int _m[][DIM], int _v[], int _dim){
   int i;
   for(i=0; i<_dim; i++){
      if(sommaVettore(_m[i], _dim) < sommaVettore(_v, _dim))
         printf("Riga %d ha somma valori inferiore al vettore.\n", i+1);
      if(sommaVettore(_m[i], _dim) > sommaVettore(_v, _dim))
         printf("Riga %d ha somma valori superiore al vettore.\n", i+1);
      if(sommaVettore(_m[i], _dim) == sommaVettore(_v, _dim))
         printf("Riga %d ha somma valori uguale al vettore.\n", i+1);
   }
}