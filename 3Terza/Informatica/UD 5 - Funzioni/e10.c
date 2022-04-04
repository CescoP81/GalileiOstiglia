/*Realizzare un algoritmo, il più ottimizzato possibile, che indovini un numero inserito
 dall'utente in un intervallo definito (min, max).
 Comunica il numero di tentativi utilizzati per indovinare il numero.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN 5
#define MAX 20

int getUserNumber(int, int);
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
      cntTentativi++;
      sceltoRandom = MIN + rand()%(MAX-MIN+1);
      if(sceltoRandom == numeroUtente){
         printf("L'AI ha indovinato il numero in %d tentativi!", cntTentativi);
         indovinato = 1;
      }
      else{
         if(sceltoRandom > numeroUtente)
            printf("L'AI ha sparato troppo alto...\n");
         else
            printf("L'AI ha sparato troppo basso...\n");
      }
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