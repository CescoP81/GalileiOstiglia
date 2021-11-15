/*
*  Auth: Pradella Francesco.
*  Date: 15.11.2021
*  File: p02.c
*  Description: Realizzare un programma che richiede 5 ipotetici prezzi,
*  calcola il totale e se è superiore a 50, calcola-visualizza e applica uno sconto
*  del 25%, comunicando il nuovo totale.
*/
#include <stdio.h>

int main(){
   int p1,p2,p3,p4,p5;        // variabili per i 5 prezzi richiesti
   int totale;                // totale da pagare
   int sconto_applicato;      // eventuale sconto da applicare (25% del totale se > 50)

   // fase di input dei prezzi.
   printf("Inserisci Prezzo 1: ");
   scanf("%d", &p1);
   fflush(stdin);

   printf("Inserisci Prezzo 2: ");
   scanf("%d", &p2);
   fflush(stdin);

   printf("Inserisci Prezzo 3: ");
   scanf("%d", &p3);
   fflush(stdin);

   printf("Inserisci Prezzo 4: ");
   scanf("%d", &p4);
   fflush(stdin);

   printf("Inserisci Prezzo 5: ");
   scanf("%d", &p5);
   fflush(stdin);

   // calcolo il totale da pagare.
   totale = p1 + p2 + p3 + p4 + p5;

   // determino se è previsto uno sconto oppure no.
   if(totale > 50){
      sconto_applicato = (totale * 25 / 100);
      printf("\nTotale: %d\n", totale);
      printf("Sconto applicato (25%): %d\n", sconto_applicato);
      totale = totale - sconto_applicato;
      printf("Nuovo totale: %d\n", totale);
   }
   else{
      printf("\nsTotale: %d", totale);
   }
   return(0);
}