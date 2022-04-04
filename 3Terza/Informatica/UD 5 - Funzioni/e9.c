/*
Realizzare un programma denominato AltoBasso.c, il programma richiede da tastiera gli
estremi minimo e massimo tra cui estrarre random un numero N da indovinare,
successivamente tramite un ciclo richiede all'utente di indovinare il numero
inserendolo da tastiera finche non esatto. Ad ogni tentativo il programma
comunica se il numero da indovinare è più alto o più basso di quello inserito.
Quando il numero viene indovinato, visualizza il numero di tentativi usati.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * @brief Restituisce un numero random nell'intervallo dato, estremi compresi
 * @param int Estremi inferiore.
 * @param int Estremo superiore
 * 
 * @return int Numero random.
 */
int getRandomNumber(int, int);
/**
 * @brief Restituisce il numero scelto dall'utente nell'intervallo indicato
 * @param int Estremi inferiore.
 * @param int Estremo superiore
 * 
 * @return int Numero scelto dall'utente.
 */
int getNumeroUtente(int, int);

int main(){
   int numeroDaIndovinare;
   int numeroScelto;
   int cntTentativi;
   int minimo = 1;
   int massimo = 20;
   int indovinato;

   srand(time(NULL));
   numeroDaIndovinare = getRandomNumber(minimo, massimo);
   indovinato = 0;
   cntTentativi = 0;
   do{
      cntTentativi = cntTentativi + 1;
      numeroScelto = getNumeroUtente(minimo, massimo);
      if(numeroScelto == numeroDaIndovinare){
         indovinato = 1;
         printf("\n -- Hai Indovinato!! Tentativi Usati: %d", cntTentativi);
      }
      else{
         if(numeroScelto > numeroDaIndovinare)
            printf("\n -- Sei troppo alto!!\n");
         else
            printf("\n --Sei troppo basso""\n");
      }
   }while(indovinato == 0);  // while(!indovinato);
   return(0);
}

int getRandomNumber(int _min, int _max){
   int n;
   n = _min + (rand()%(_max - _min + 1 ));
   return(n);
}
int getNumeroUtente(int _min, int _max){
   int n;
   do{
      printf("Inserisci un numero(%d <> %d): ", _min, _max);
      scanf("%d", &n);
      fflush(stdin);
   }while(n<_min || n>_max);
   return(n);
}