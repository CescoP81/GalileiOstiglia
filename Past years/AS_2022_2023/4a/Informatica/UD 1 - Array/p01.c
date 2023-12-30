/*
   Esempio di utilizzo e gestione di un array mono-dimensionale
   Elenco funzioni richieste:
   x Input da tastiera di un vettore di interi.
   x visualizzazione di un vettore.
   x visualizzazione al contrario.
   x ricerca di un valore (ritorno 0/1 in caso negativo o positivo)
   x calcolo del valor medio
   x azzeramento di una cella scelta da utente.
   x scambio tra due celle scelte dall'utente.
   x ordinamento di un vettore.
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

/**
 * @brief Stampa un vettore passato al contrario
 * @param int[] Vettore da utilizzare nella funzione.
 * @param int Dimensione del vettore passato.
 */
void printReversedVettore(int[], int);

/**
 * @brief Ricerca un valore internamente al vettore, restituisce 1 in caso sia presente altrimenti 0
 * @param int[] Vettore da utilizzare nella funzione.
 * @param int Dimensione del vettore.
 * @param int Valore da ricercare.
 * @return int 0/1 in caso positivo/negativo
 */
int searchValue(int[], int, int);

/**
 * @brief Determina la media aritmetica dei valori del vettore.
 * @param int[] Vettore da utilizzare nella funzione.
 * @param int Dimensione del vettore.
 * @return float Media aritmetica dei valori.
 */
float avgVettore(int[], int);

/**
 * @brief Azzeramento di una cella passata come indice assoluto.
 * @param int[] Vettore da utilizzare nella funzione.
 * @param int Dimensione del vettore.
 * @param int Indice di cella.
 * @return int 0/1 se l'azzeramento è avvenuto oppure no.
 */
int azzeraCellaVettore(int[], int, int);

/**
 * @brief Scambia i valori di due celle selezionate per indice.
 * @param int[] Vettore da utilizzare nella funzione.
 * @param int Dimensione del vettore.
 * @param int Indice assoluto prima cella
 * @param int Indice assoluto seconda cella
 * 
 * @return int 0/1 se lo scambio è avvenuto oppure no.
 */
int swapCelleVettore(int[], int, int, int);

/**
 * @brief Ordinamento in ordine crescente di un vettore
 * @param int[] Vettore da utilizzare nella funzione.
 * @param int Dimensione del vettore.
 * 
 */
void ordinaVettore(int[], int);

/* MAIN PROGRAM */
int main(){
   int vet[DIM];
   int vet2[DIM*2];
   int val;

   inputVettore(vet, DIM);
   printVettore(vet, DIM);
   printf("\n");
   printReversedVettore(vet, DIM);
   printf("\n");
   
   printf("\nInserisci valore da ricercare: ");
   scanf("%d", &val);
   fflush(stdin);
   if(searchValue(vet, DIM, val))
      printf("Valore presente nel vettore.");
   else
      printf("Valore non presente nel vettore.");
   printf("\n");

   printf("Media del vettore inserito: %.2f", avgVettore(vet, DIM));
   printf("\n");
   
   if(!azzeraCellaVettore(vet, DIM, 6))
      printf("Errore nel recupero della cella\n");
   printVettore(vet, DIM);
   printf("\n");
   if(!azzeraCellaVettore(vet, DIM, 3))
      printf("Errore nel recupero della cella\n");
   printVettore(vet, DIM);
   printf("\n");

   printf("\n");
   if(!swapCelleVettore(vet, DIM, 2, 4))
      printf("Errore negli indici\n");
   printVettore(vet, DIM);
   printf("\n");
   if(!swapCelleVettore(vet, DIM, 8, 4))
      printf("Errore negli indici\n");
   printVettore(vet, DIM);
   printf("\n\n");

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
void printReversedVettore(int _v[], int _d){
   int i;
   for(i=_d-1; i>=0; i--){
      printf("%4d", _v[i]);
   }
}
int searchValue(int _v[], int _d, int _src){
   int i, trovato;
   trovato = 0;
   for(i=0; i<_d; i++){
      if(_v[i] == _src)
         trovato = 1;
   }
   return(trovato);
}
float avgVettore(int _v[], int _d){
   int somma, i;
   somma = 0;
   for(i=0; i<_d; i++)
      somma = somma + _v[i];
   
   return((float)somma/_d);
}
int azzeraCellaVettore(int _v[], int _d, int _index){

   if(_index<1 || _index>_d){
      return(0);
   }   
   _v[_index-1] = 0;
   return(1);
}
int swapCelleVettore(int _v[], int _d, int _index1, int _index2){
   int box;
   if(_index1<0 || _index1>_d-1)
      return(0);
   if(_index2<0 || _index2>_d-1)
      return(0);
   
   box = _v[_index1];
   _v[_index1] = _v[_index2];
   _v[_index2] = box;
   return(1);
}
void ordinaVettore(int _v[], int _d){
   int box;
   int i, j;

   // Doppio ciclo di base per l'ordinamento di un vettore in modo crescente.
   /*for(i=0; i<_d-1; i++){
      for(j=i+1; j<_d; j++){
         if(_v[i] > _v[j]){
            box = _v[i];
            _v[i] = _v[j];
            _v[j] = box;
         }
      }
   }*/

   /* Utilizzando una funzione costruita precedentemente e funzionante.
   Attenzione che la funzione richiede indici assoluti e non relativi.*/
   for(i=0; i<_d-1; i++){
      for(j=i+1; j<_d; j++){
         if(_v[i] > _v[j]){
            swapCelleVettore(_v, _d, i, j);
         }
      }
   } //*/
}