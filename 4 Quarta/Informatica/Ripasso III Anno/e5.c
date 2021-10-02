/**
 * 1.
Realizzare un programma C che esegua le seguenti operazioni:
	a. Inizializza una matrice 5x5 con valori random compresi tra 1 e 20.
	b. Stampa la matrice.
	c. Inizializza un vettore di 5 elementi random compresi tra 1 e 20.
	d. Stampa il vettore.
	e. Per ogni RIGA della matrice determina se la somma dei suoi valori è maggiore o minore rispetto la somma dei valor del vettore.
   */
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 5

int main(){
   int mat[DIM][DIM];
   int vet[DIM];
   int i,j;
   int s_mat, s_vet;

   srand(time(NULL));
   // a. Iniz della matrice
   for(i=0; i<DIM; i++){
      for(j=0; j<DIM; j++){
         mat[i][j] = rand()%20 + 1;
      }
   }

  // b. Stampa la matrice.
   for(i=0; i<DIM; i++){
      for(j=0; j<DIM; j++){
         printf("%3d", mat[i][j]);
      }
      printf("\n");
   }
   printf("\n\n");

   // c. Inizializza un vettore di 5 elementi random compresi tra 1 e 20.
   for(i=0; i<DIM; i++){
      vet[i] = rand()%20 + 1;
   }

   // d. Stampa il vettore.
   for(i=0; i<DIM; i++){
      printf("%3d", vet[i]);
   }
   printf("\n\n");
   
   // e. Per ogni RIGA della matrice determina se la somma dei suoi valori è
   //    maggiore o minore rispetto la somma dei valor del vettore.
   s_vet = 0;
   for(i=0; i<DIM; i++){
      s_vet = s_vet + vet[i];
   }

   for(i=0; i<DIM; i++){
      s_mat = 0;
      for(j=0; j<DIM; j++){
         s_mat = s_mat + mat[i][j];
      }
      if(s_mat < s_vet)
         printf("Riga %d ha somma valori inferiore al vettore.\n", i+1);
      if(s_mat > s_vet)
         printf("Riga %d ha somma valori superiore al vettore.\n", i+1);
      if(s_mat == s_vet)
         printf("Riga %d ha somma valori uguale al vettore.\n", i+1);
   }
   return(0);
}