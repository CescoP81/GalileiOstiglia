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

// ## MAIN PROGRAM
int main(){
   int N;
   int scelta;
   float media;
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

            break;
         }
         case 3:{

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