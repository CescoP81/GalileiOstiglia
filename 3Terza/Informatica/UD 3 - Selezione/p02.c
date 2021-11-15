/*
*  Auth: Pradella Francesco.
*  Date: 15.11.2021
*  File: p02.c
*  Description: Realizzare un programma che richiede un numero da tastiera,
*  quindi comunica se è pari e multiplo di 3.
*/
#include <stdio.h>

int main(){
   int num; // variabile per il numero inserito da tastiera.

   // fase di input del numero.
   printf("Inserisci numero: ");
   scanf("%d", &num);
   fflush(stdin);

   // fase di test e selezione
   if(num%2 == 0){      // condizione per un numero pari (resto 0 della divisione per 2)
      if(num%3 == 0){   // condizione per un numero multiplo di 3 (resto 0 della divisione per 3)
         printf("Il numero e' pari e multiplo di 3.");
      }
      else{
         printf("Il numero e' pari ma NON multiplo di 3.");
      }
   }
   else{
      printf("Il numero NON e' pari, ma potrebbe essere multiplo di 3.");
   }  
   return(0);
}