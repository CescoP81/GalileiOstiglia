#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define DIM 5


int main(){
   int m[DIM][DIM];        // matrice quadrata
   int v[DIM];             // vettore
   int i, j;               // indici per scorrimento su matrice e vettore
   int flag;               // variabile booleana usata al punto 4
   int svet, srow;         // variabili di somma per vettore e per righe matrice.
   srand(time(NULL));

   // 1 - Inizializzo la matrice con valori da 1 a 10
   for(i=0; i<DIM; i++){
      for(j=0; j<DIM; j++){
         m[i][j] = rand()%10 + 1;
      }
   }

   // 2 - Stampo la matrice a video
   for(i=0; i<DIM; i++){
      for(j=0; j<DIM; j++){
         printf("%3d", m[i][j]);
      }
      printf("\n");
   }
   printf("\n\n");

   // 3 - Richiesto il vettore all'untente 
   for(i=0; i<DIM; i++){
      printf("Inserisci [%d] valore: ",i+1);
      scanf("%d",&v[i]);
      fflush(stdin);
   }
   printf("\n\n");

   // 4 - Verifico se ogni riga della matrice è uguale al vettore, in caso affermativo comunico l'indice di riga.
   for(i=0; i<DIM; i++){
      flag = 1;
      for(j=0; j<DIM; j++){
         if(v[j] != m[i][j])
            flag = 0;
      }
      if(flag){
         printf("La riga %d e' uguale al vettore.\n", i+1);
      }
   }
   printf("\n\n");

   // 5 - Verifico e comunico quali righe hanno somma valori maggiore della somma valori del vettore.
   svet = 0;
   for(i=0; i<DIM; i++)
      svet = svet + v[i];
   for(i=0; i<DIM; i++){
      srow = 0;
      for(j=0; j<DIM; j++){
         srow = srow + m[i][j];
      }
      if(srow > svet)
         printf("La riga %d ha somma totale maggiore del vettore.\n", i+1);
   }
   return(0);
}