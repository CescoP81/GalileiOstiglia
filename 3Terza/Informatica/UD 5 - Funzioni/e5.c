/*
   Distinzione tra funzioni VOID e non VOID
   ticket: Rovilla L.

   Sottoprogrammi:
      - Procedure: funzioni che NON ritornano nulla al chiamante ( saranno delle VOID)
      - Funzioni: funzioni che RITORNANO qualcosa al chiamante (non saranno delle VOID)
*/
#include <conio.h>
#include <stdio.h>

/**
 * @brief Procedura che stampa i numeri da 1 a N inserito come parametro.
 * @param int Numero inserito di fine serie * 
 */
void stampaNumeri(int);

/**
 * @brief Funzione che restituisce un numero verificando che l'input da tastiera sia
 * compreso tra due estremi min e max
 * @param int Numero minimo accettabile.
 * @param int numero massimo accettabile.
 * @return int Numero inserito e verificato.
 */
int getNumero(int, int);

int main(){
   int N;
   
   N = getNumero(10, 30);

   stampaNumeri(N);
   return(0);
}

void stampaNumeri(int _n){
   int i;
   for(i=1; i<=_n; i++)
      printf("%d ", i);
}

int getNumero(int _min, int _max){
   int num;
   do{
      printf("Inserisci un numero: ");
      scanf("%d", &num);
      fflush(stdin);
   }while(num<_min || num>_max);

   return(num);
}