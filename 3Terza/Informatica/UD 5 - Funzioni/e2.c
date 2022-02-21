/*
   Realizzare un programma C che richiede due numeri da tastiera, quindi prevede le seguenti funzoni:
   - printDivisori -> Riceve un numero e visualizza tutti i suoi divisori.
   - getNumeroDivisori -> Riceve un valore e restituisce il numero di divisori trovati.
   - getSommaDivisori -> Riceve un numero e restituisce la somma dei suoi divisori.
   - verifayAmicali -> riceve due numeri e verifica se sono 'amicali'; si dicono amicali se la somma dei
      divisori del primo numero(escluso se stesso) è uguale al secondo E se la somma dei divisori del secondo numero(escluso se stesso)
      è uguale al primo.

   Creare la sezione dei prototipi con relativi commenti, seguita dal main, ed infine la sezione di sviluppo delle funzioni.
*/
#include <stdio.h>

/**
 * @brief Funzione che stampa i divisori di un numero, compreso se stesso, ricevuto come parametro.
 * @param int Numero da utilizzare per i divisori.
 */
void printDivisori(int);

/**
 * @brief Funzione che restituisce il numero di divisori di un numero passato come parametro
 * @param int Numero di cui contare i divisori.
 * @return int Numero divisori trovati.
 */
int getNumeroDivisori(int);

/**
 * @brief Funzione che restituisce la somma dei divisori di un numero, ESCLUSO se stesso.
 * @param int Numero di cui sommare i divisori.
 * @return int Somma dei divisori calcolata.
 */
int getSommaDivisori(int);

/**
 * @brief Funzione che riceve due numeri e verifica se sono amicali.
 * @param int Primo numero da usare.
 * @param int Secondo numero da usare.
 * @return int 1 se sono amicali, 0 se non sono amicali.
 */
int verifyAmicali(int, int);


int main(){
   int n1, n2;

   // input dei due numeri richiesti
   printf("Inserisci n1: ");
   scanf("%d", &n1);
   fflush(stdin);
   printf("Inserisci n2: ");
   scanf("%d", &n2);
   fflush(stdin);

   // richiamo della print divisori.
   printDivisori(n1);
   printf("\n");
   printDivisori(n2);
   printf("\n\n");
   printf("il numero %d ha %d divisori\n", n1, getNumeroDivisori(n1));
   printf("il numero %d ha %d divisori\n", n2, getNumeroDivisori(n2));
   printf("\n\n");
   printf("Somma dei divisori di %d: %d\n", n1, getSommaDivisori(n1));
   printf("Somma dei divisori di %d: %d\n", n2, getSommaDivisori(n2));
   printf("\n\n");
   if(verifyAmicali(n1,n2))
      printf("I due numeri sono amicali.");
   else
      printf("I due numeri NON sono amicali.");

   return(0);
}

// sezione di sviluppo funzioni.
void printDivisori(int _n){
   int div; // variabile per il ciclo dei divisori

   for(div=1; div<=_n; div++){
      if(_n % div == 0)
         printf("%5d", div);
   }
}

int getNumeroDivisori(int _n){
   int div; // variabile per il ciclo dei divisori.
   int cnt; // contatore dei divisori trovati.

   cnt = 0;
   for(div=1; div<=_n; div++){
      if(_n % div == 0)
         cnt++;
   }

   return(cnt);
}

int getSommaDivisori(int _n){
   int div;
   int somma;
   somma = 0;
   for(div=1; div<_n; div++){
      if(_n % div == 0)
         somma = somma + div;
   }
   return(somma);
}

int verifyAmicali(int _n1, int _n2){
   if((_n1 == getSommaDivisori(_n2)) && (_n2 == getSommaDivisori(_n1)))
      return(1);
   else
      return(0);
}