/**
*	Author: Pradella F.
*	Date: 08.11.2021
*	Description: Esempio di selezione unaria e binaria.
*/
#include <stdio.h>

int main(){
   int valore;

   // acquisisco il valore in input.
   printf("Inserisci un valore: ");
   scanf("%d", &valore);
   fflush(stdin);

   // determino se il valore è positivo, nullo o negativo.
   if(valore > 0){
      printf("Il valore e' positivo.\n");
   }
   if(valore == 0){
      printf("Il valore e' nullo.\n");
   }
   if(valore < 0){
      printf("Il valor e' negativo.\n");
   }

   printf("\n\n");
   // selezione per determinare se un numero è maggiore di 10, oppure minore o uguale
   if(valore > 10){
      printf("Il valore e' maggiore di 10 unita'\n");
   }
   else{
      printf("IL valore e' inferiore o uguale a 10 unita'\n");
   }
   return(0);
}