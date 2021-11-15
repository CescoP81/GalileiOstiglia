/*
*  Auth: Pradella Francesco.
*  Date: 15.11.2021
*  File: p02.c
*  Description: Realizzare un programma che richiede l'inserimento di 3 numeri interi
*  determina e comunica il valore maggiore inserito.
*/
#include <stdio.h>

int main(){
   int n1, n2, n3;
   int max;

   // acquisisco i tre valori
   printf("Inserisci n1: ");
   scanf("%d", &n1);
   fflush(stdin);

   printf("Inserisci n2: ");
   scanf("%d", &n2);
   fflush(stdin);

   printf("Inserisci n3: ");
   scanf("%d", &n3);
   fflush(stdin);

   // determinazione valore maggiore per if successivi.
   if(n1 > n2){
      if(n1 > n3){
         printf("Il maggiore e': %d", n1);
      }
   }
   if(n2 > n1){
      if(n2 > n3){
         printf("Il maggiore e': %d", n2);
      }
   }
   if(n3 > n1){
      if(n3 > n2){
         printf("Il maggiore e': %d", n3);
      }
   }
   printf("\n\n");

   // determinazione valore maggiore con variabile di supporto.
   max = n1;
   if(n2 > max)
      max = n2;
   if(n3 > max)
      max = n3;
   printf("Il valore maggiore e': %d", max);

   // determinazione valore maggiore con IF e operatore logico AND
   if((n1 > n2) && (n1 > n3)){
      printf("Il valore maggiore e': %d", n1);
   }
   if((n2 > n1) && (n2 > n3)){
      printf("Il valore maggiore e': %d", n2);
   }
   if((n3 > n1) && (n3 > n2)){
      printf("Il valore maggiore e': %d", n3);
   }

   return(0);
}