/*
*  Auth: Pradella Francesco.
*  Date: 15.11.2021
*  File: p05.c
*  Description: Realizzare un programma che richiede un ipotetico anno, determina se tale anno
*  è BISESTILE oppure no.
*/
#include <stdio.h>

int main(){
   int anno;
   int bisestile;

   // inserimento anno
   printf("Inserisci un anno: ");
   scanf("%d", &anno);
   fflush(stdin);

   //determino se è bisestile oppure no.
   if(anno%100 == 0){   // se è un secolo
      if(anno%400 == 0){ // è divisibile anche per 400?
         printf("Anno Bisestile.");
      }
      else{
         printf("Anno non bisestile.");
      }
   }
   else{    // se non è un secolo deve essere divisibile per 4
      if(anno%4 == 0){
         printf("Anno Bisestile.");
      }
      else{
         printf("Anno non bisestile.");
      }
   }

   printf("\n\n");

   // stesso procedimento ma con utilizzo di un FLAG
   if(anno%100 == 0){   // se è un secolo
      if(anno%400 == 0) bisestile = 1;
      else bisestile = 0;
   }
   else{    // se non è un secolo deve essere divisibile per 4
      if(anno%4 == 0) bisestile = 1;
      else bisestile = 0;
   }

   if(bisestile) // equivale a bisestile==1 o più generalmente bisestile != 0
      printf("L'anno e' Bisestile.");
   else
      printf("L'anno non e' Bisestile.");
   return(0);
}
