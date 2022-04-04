/*Realizzare un algoritmo, il più ottimizzato possibile, che indovini un numero inserito
 dall'utente in un intervallo definito (min, max).
 Comunica il numero di tentativi utilizzati per indovinare il numero.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN 5
#define MAX 20

/**
 * @brief Restituisce il numero inserito dall'utente in un intervallo spcificato.
 * @param int Estremo inferiore.
 * @param int Estremo superiore.
 * 
 * @return int Numero inserito dall'utente.
 */
int getUserNumber(int, int);
/**
 * @brief Verifica se il numero random della AI è uguale a quello scelto dall'utente.
 * @param int Numero estratto random dalla AI.
 * @param int Numero scelto dall'utente.
 * @param int* Riferimento al contatore dei tentativi.
 * 
 * @return int Esito del confronto.
 */
int checkNumber(int, int, int*);

int main(){
   int numeroUtente;
   int cntTentativi;
   int indovinato;
   int sceltoRandom;

   numeroUtente = getUserNumber(MIN, MAX);
   indovinato = 0;
   cntTentativi = 0;
   do{
      sceltoRandom = MIN + rand()%(MAX-MIN+1);
      indovinato = checkNumber(sceltoRandom, numeroUtente, &cntTentativi);
   }while(indovinato == 0);
   return(0);
}

int getUserNumber(int _min, int _max){
   int n;
   do{
      printf("Inserisci un valore(%d <> %d): ", _min, _max);
      scanf("%d", &n);
      fflush(stdin);
   }while(n<_min || n>_max);
   return(n);   
}

int checkNumber(int _random, int _utente, int *_cnt){
   *_cnt = *_cnt + 1;
   if(_utente == _random){
         printf("L'AI ha indovinato il numero in %d tentativi!", *_cnt);
         return(1);
      }
   else{
      if(_random > _utente)
         printf("L'AI ha sparato troppo alto(%d)...\n", _random);
      else
         printf("L'AI ha sparato troppo basso(%d)...\n", _random);
   }
   return(0);
}