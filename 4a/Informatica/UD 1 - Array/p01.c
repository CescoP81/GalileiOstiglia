/*
   Esempio di utilizzo e gestione di un array mono-dimensionale
   Elenco funzioni richieste:
   x Input da tastiera di un vettore di interi.
   x visualizzazione di un vettore.
   - visualizzazione al contrario.
   - ricerca di un valore
   - calcolo del valor medio
   - azzeramento di una cella scelta da utente.
   - scambio tra due celle scelte dall'utente.
   - ordinamento di un vettore.
   - ricerca valore massimo e/o minimo.
   
   ATTENZIONE:
   per ogni punto è richiesta una funzione specifica.
*/
#include <stdio.h>
#define DIM 5

/* Prototipi delle funzioni */
/* ======================== */

/**
 * @brief Richiede in input i valori da inserire in un vettore.
 * @param int[] Vettore da utilizzare nella funzione.
 * @param int Dimensione del vettore passato.
 */
void inputVettore(int[], int);
/**
 * @brief Stampa un vettore passato alla funzione.
 * @param int[] Vettore da utilizzare nella funzione.
 * @param int Dimensione del vettore passato.
 */
void printVettore(int[], int);

/* MAIN PROGRAM */
int main(){
   int vet[DIM];
   int vet2[DIM*2];

   inputVettore(vet, DIM);
   printVettore(vet, DIM);

   printf("\n");

   inputVettore(vet2, DIM*2);
   printVettore(vet2, DIM*2);

   return(0);
}

/* Sviluppo delle singole funzioni */
void inputVettore(int _v[], int _d){
   int i;
   for(i=0; i<_d; i++){
      printf("Inserisci il valore alla posizione [%d]: ", i);
      scanf("%d", &_v[i]);
      fflush(stdin);
   }
}
void printVettore(int _v[], int _d){
   int i;
   for(i=0; i<_d; i++){
      printf("%4d", _v[i]);
   }
}
