/**
*	Author: Pradella F.
*	Date: 08.11.2021
*	Description: Programma che acquisisce in input due numeri interi, calcola e visualizza in
   output la somma.
*/
#include <stdio.h>

int main(){
   // 1. dichiaro due variabili intere per contenere i valori in input.
   int v1, v2, somma;

   // 2. fase di input per il primo valore
   printf("Inserisci valore 1: ");     // messaggio per l'utente.
   scanf("%d", &v1);                   // acquisizione del valore e salvataggio nella variabile v1
   fflush(stdin);                      // pulizia del buffer di input da eventuali residui.

   // 2.1 fase di input per il secondo valore
   printf("Inserisci valore 2: ");
   scanf("%d", &v2);
   fflush(stdin);

   // 3. fase calcolo della somma tra i due valori.
   somma = v1 + v2;

   // 4. Comunico all'utente il risultato in output.
   printf("Somma: %d", somma);

   return(0);
}