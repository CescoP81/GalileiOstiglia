#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define DIM 5

/** Inizializza la matrice quadrta con valori random
 * @param int[][] Matrice da inizializzare.
 * @param int Dimensione della matrice.
 */
void initMat(int [][DIM], int);
/** Stampa la matrice quadrata a video
 * @param int[][] Matrice da inizializzare.
 * @param int Dimensione della matrice.
 */
void printMat(int [][DIM], int);
/** Ordina in modo crescente (Ascending) ogni singola riga della matrice quadrata
 * @param int[][] Matrice da inizializzare.
 * @param int Dimensione della matrice.
 */
void orderAscRow(int [][DIM], int);
/** Calcola e restituisce la media dei valori della matrice quadrata
 * @param int[][] Matrice da inizializzare.
 * @param int Dimensione della matrice.
 * @return float Media dei valori
 */
float avgMat(int [][DIM], int);
/** Determina riga con somma minima e massima della matrice quadrata.
 * @param int[][] Matrice da inizializzare.
 * @param int Dimensione della matrice.
 * @param int* Indirizzo variabile per indice riga minima.
 * @param int* Indirizzo variabile per indice riga massima.
 */
void rowMinMaxMat(int [][DIM], int, int *, int *);

int main(){
   int mat[DIM][DIM];      // matrice quadrata.
   float media;            // variabile per media della matrice restituita da apposita funzione
   int imin, imax;         // variabili per indici riga con somma minima e somma massima.

   initMat(mat, DIM);
   
   //1
   printMat(mat, DIM);
   printf("\n");

   //2
   orderAscRow(mat, DIM);
   printMat(mat, DIM);
   printf("\n");

   //3
   media = avgMat(mat, DIM);
   printf("Media della matrice: %.2f", media);
   printf("\n");

   //4
   rowMinMaxMat(mat, DIM, &imin, &imax);
   printf("Riga con somma minore: %d\n", imin+1);
   printf("Riga con somma maggiore: %d", imax+1);
   return(0);
}

//----------------------------
void initMat(int _m[][DIM], int _l){
   int i, j;
   srand(time(NULL));

   for(i=0; i<_l; i++){
      for(j=0; j<_l; j++){
         _m[i][j] = rand()%(20-5+1) + 5;
      }
   }
}

void printMat(int _m[][DIM], int _l){
   int i, j;
   for(i=0; i<_l; i++){
      for(j=0; j<_l; j++){
         printf("%3d", _m[i][j]);
      }
      printf("\n");
   }
}

void orderAscRow(int _m[][DIM], int _l){
   int i, j, k;
   int tmp;

   for(i=0; i<_l; i++){
      for(j=0; j<_l; j++){
         for(k=j; k<_l; k++){
            if(_m[i][j] > _m[i][k]){
               tmp = _m[i][j];
               _m[i][j] = _m[i][k];
               _m[i][k] = tmp;
            }
         }
      }
   }
}

float avgMat(int _m[][DIM], int _l){
   float s;
   int i, j;
   s = 0;
   for(i=0; i<_l; i++){
      for(j=0; j<_l; j++){
         s = s + _m[i][j];
      }
   }
   return(s/(_l*_l));
}

void rowMinMaxMat(int _m[][DIM], int _l, int *imin, int *imax){
   int i, j;
   int stmp, smin, smax;
   

   for(i=0;i<_l; i++){
      smin = smin + _m[0][i];
      smax = smax + _m[0][i];
   }
   *imin = 0;
   *imax = 0;

   for(i=1; i<_l; i++){
      stmp = 0;
      for(j=0; j<_l; j++){
         stmp = stmp + _m[i][j];
      }
      
      if(stmp > smax){
         smax = stmp;
         *imax = i;
      }

      if(stmp < smin){
         smin = stmp;
         *imin = i;
      }
   }
}
