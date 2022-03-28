/*Realizzare un programma C che richiede in input un valore numerico compreso tra 5 e 15,
 presenta un breve menu con le seguenti voci:
1. Genera matrice casuale e calcola il valor medio.
2. Disegna il triangolo inferiore con numeri casuali.
3. Richiedi N valori, comunicando al termine minimo, massimo e numero di valori pari
   e dispari.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ## PROTOTIPI
/**
 * @brief Funzione che richiede l'input di un numero all'utente, nel range min max passati
 * per valore.
 * @return int Numero inserito dall'utente.
 */
int getNumber(int, int);
/**
 * @brief Funzione che visualizza il menu di scelte e restituisce l'intero selezionato.
 * 
 * @return int Voce selezionata.
 */
int writeMenu();
/**
 * @brief Visualizza una matrice casuale di NxN valori e restituisce il valor medio
 * 
 * @return float Media dei valori della matrice
 */
float getMediaMatrice(int);
/**
 * @brief Visualizza il triangolo inferiore della matrice di numeri casuali.
 * @param int Dimensione della matrice quadrata.
 */
void triangoloInferioreCausale(int);
/**
 * @brief Serie numerica di N valori, determinando minimo, massimo, nr pari e nr dispari.
 * @param int Numero di valori da richiedere.
 * @param int* Riferimento alla vaiabile per il minimo.
 * @param int* Riferimento alla varaibile per il massimo.
 * @param int* Riferimento alla variabile per il numero di valori pari.
 * @param int* Riferimento alla variabile per il numero di valori dispari.
 */
void serieNumerica(int, int*, int*, int*, int*);
// ## MAIN PROGRAM
int main(){
   int N;
   int scelta;
   float media;
   int minimo, massimo, nrPari, nrDispari;
   N = getNumber(5, 15);
   do{
      scelta = writeMenu();
      switch(scelta){
         case 1:{
            media = getMediaMatrice(N);
            printf("\nMedia dei valori: %.2f\n\n", media);
            break;
         }
         case 2:{
            triangoloInferioreCausale(N);
            printf("\n\n");
            break;
         }
         case 3:{
            serieNumerica(N, &minimo, &massimo, &nrPari, &nrDispari);
            printf("Valore minimo: %d, massimo: %d\n", minimo, massimo);
            printf("Nr. valori pari: %d, dispari: %d\n\n", nrPari, nrDispari);
            break;
         }
      }
   }while(scelta != 0);
   return(0);
}
// ## DEFINIZIONE FUNZIONI
int getNumber(int _min, int _max){
   int num;
   do{
      printf("Inserisci numero: ");
      scanf("%d", &num);
      fflush(stdin);
   }while(( num < _min) || (num > _max));
   return(num);
}

int writeMenu(){
   int sc;
   printf("1. Genera matrice casuale di NxN valori e calcola il valor medio.\n");
   printf("2. Disegna il triangolo inferiore con numeri casuali.\n");
   printf("3. Richiedi N valori, comunicando al termine minimo, massimo e numero di valori pari e dispari.\n");
   printf("0. USCITA\n");
   printf("Scelta: ");
   scanf("%d", &sc);
   fflush(stdin);
   return(sc);
}

float getMediaMatrice(int _n){
   int i, j;
   int randomico;
   int sommaTotale;

   srand(time(NULL));
   sommaTotale = 0;

   for(i=1; i<=_n; i++){
      for(j=1; j<=_n; j++){
         randomico = rand()%20+1;
         printf("%3d", randomico);
         sommaTotale = sommaTotale + randomico;
      }
      printf("\n");
   }
   return((float)sommaTotale/(_n*_n));
}

void triangoloInferioreCausale(int _n){
   int i, j;
   int randomico;

   srand(time(NULL));
   for(i=1; i<=_n; i++){
      for(j=1; j<=_n; j++){
         if(i>j){
            randomico = rand()%20+1;
            printf("%3d",randomico);
         }
         else{
            printf(" **");
         }
      }
      printf("\n");
   }
}

void serieNumerica(int _n, int *_min, int *_max, int *_pari, int *_dispari){
   int i;
   int num;
   *_pari = 0;
   *_dispari = 0;

   for(i=1; i<=_n; i++){
      printf("Inserisci valore %d: ", i);
      scanf("%d", &num);
      if(i==1){
         *_min = num;
         *_max = num;
      }
      else{
         if(num < *_min)   *_min = num;
         if(num > *_max)   *_max = num;
      }

      if(num%2 == 0) *_pari = *_pari + 1;
      else  *_dispari = *_dispari + 1;
   }
}
