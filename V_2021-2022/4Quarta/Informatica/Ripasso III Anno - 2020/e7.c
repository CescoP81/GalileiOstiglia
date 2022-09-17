/* 
Realizza in C un semplice gioco dell'impiccato
dove l'utente ha 10 tentativi per indovinare un codice numerico di 8 cifre
comprese tra 0 e 9.
Strutturare le funzioni necessarie.
*/
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 8
#define MAX_TENTATIVI 10

void generaCodice(int [], int [], int);
void printCodice(int [], int);

int main(){
   int cod_originale[DIM];
   int cod_indovinato[DIM];
   int cnt_tentativi;
   int cifra;

   generaCodice(cod_originale, cod_indovinato, DIM);

   printCodice(cod_originale, DIM);
   printf("\n");
   printCodice(cod_indovinato, DIM);

   cnt_tentativi = 1;
   do{
      // vi ho fatto il difficile, ora proseguite!
      
   }while(cnt_tentativi <= MAX_TENTATIVI);
   return(0);
}

void generaCodice(int _co[], int _ci[], int _dim){
   srand(time(NULL));
   int i;
   for(i=0; i<_dim; i++){
      _co[i] = rand()%10;
      _ci[i] = -1;
   }
}

void printCodice(int _ci[], int _dim){
   int i;
   for(i=0; i<_dim; i++)
      if(_ci[i]>=0)
         printf("%d", _ci[i]);
      else
         printf("-");
}