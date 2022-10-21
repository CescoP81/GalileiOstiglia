/**
 * Realizzare un algoritmo che tramite funzioni apposite realizzi i seguenti punti su una matrice
 * di interi 5x5
   - [ ] Caricamento con valori casuali, il range deve essere passato come parametro.
   - [ ] Stampa della matrice
   - [ ] Ricerca posizione del valore maggiore (attenzione a come restituire gli indici al main)
   - [ ] Visualizzazione del triangolo superiore, inferiore, solo diagonale principale (scelta dell'utente fatta nel main)
   - [ ] Ordinamento della matrice in modo crescente
   - [ ] Scambio delle righe con le colonne (la primma riga diventa la prima colonna e così via...)
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define DIM 5

/**
 * @brief Funzione che carica una matrice con valori random compresi in un range scelto dall'utente.
 * @param int[][] Matrice da utilizzare
 * @param int Dimensione delle righe
 * @param int Dimensione delle colonne
 * @param int Valore minimo del range
 * @param int Valore massimo del range.
*/
void initRandomMatrix(int [][DIM], int, int, int, int);
/**
 * @brief Funzione per la stampa della matrice
 * @param int[][] Matrice da utilizzare
 * @param int Dimensione delle righe
 * @param int Dimensione delle colonne
*/
void printMatrice(int [][DIM], int, int);
/**
 * Funzione che restituisce l'indice di riga e di colonna del valore maggiore
 * @param int[][] Matrice da utilizzare.
 * @param int Dimensione delle righe
 * @param int Dimensione delle colonne
 * @param int* Riferimento alla variabile per il valore massimo.
 * @param int* Riferimento alla variabile per l'indice di riga
 * @param int* Riferimento alla variabile per l'indice di colonna
*/
void ricercaValoreMaggiore(int [][DIM], int, int, int *, int*, int*);

int main(){
  int mat[DIM][DIM];
  int massimo, riga, colonna;

  initRandomMatrix(mat, DIM, DIM, 3, 20);
  printMatrice(mat, DIM, DIM);
  ricercaValoreMaggiore(mat, DIM, DIM, &massimo, &riga, &colonna);
  printf("Il valore maggiore (%d) si trova in posizione [%d][%d].", massimo, riga, colonna);
  return(0);
}

void initRandomMatrix(int _m[][DIM], int _r, int _c, int _min, int _max){
  srand(time(NULL));
  int i, j;
  for(i=0; i<_r; i++){
    for(j=0; j<_c; j++){
      _m[i][j] = _min + (rand()%(_max - _min +1));
    }
  }
}
void printMatrice(int _m[][DIM], int _r, int _c){
  int i, j;
  for(i=0; i<_r; i++){
    for(j=0; j<_c; j++){
      printf("%3d", _m[i][j]);
    }
    printf("\n");
  }
}
void ricercaValoreMaggiore(int _m[][DIM], int _r, int _c, int *_max, int *_indexRiga, int *_indexColonna){
  int i, j;
  
  *_max = _m[0][0];
  *_indexRiga = 0;
  *_indexColonna = 0;

  for(i=0; i<_r; i++){
    for(j=0; j<_c; j++){
      if(_m[i][j] > *_max){
        *_max = _m[i][j];
        *_indexRiga = i;
        *_indexColonna = j;
      }
    }
  }
}