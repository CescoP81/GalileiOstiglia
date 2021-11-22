/* Esempio di utilizzo del costrutto SWITCH-CASE. */

#include <stdio.h>

int main(){
   int scelta;                // conterrà la scelta numerica effettuata dall'utente.
   int base, altezza, area;   // variabili per il rettangolo case 1.
   int raggio, circonferenza; // variabili per la circonferenza case 2.
   int numero, divisore;      // variabili per il case 3.

   // 1. visualizzare all'utente la lista delle scelte.
   printf("1. Calcolo area rettangolo.\n");
   printf("2. Calcolo lunghezza circonferenza.\n");
   printf("3. Verifica divisore.\n");
   // da fare
   printf("4. verifica multiplo.\n");
   printf("5. verifica anno Bisestile.\n");
   printf("6. Verifica numero pari e multiplo di 3.\n");
   printf("Scelta: ");
   scanf("%d", &scelta);
   fflush(stdin);

   // 2. selezione del blocco da eseguire tramite switch-case.
   switch(scelta){
      case 1:{
         printf("Inserisci la base: ");
         scanf("%d", &base);
         fflush(stdin);
         printf("Inserisci l'altezza: ");
         scanf("%d", &altezza);
         fflush(stdin);

         area = base * altezza;
         printf("Area del rettangolo: %d\n", area);
         break;
      }
      case 2:{
         printf("Inserisci il raggio: ");
         scanf("%d", &raggio);
         fflush(stdin);

         circonferenza = raggio*raggio*3.14;
         printf("Lunghezza circonferenza: %d\n", circonferenza);
         break;
      }
      case 3:{
         printf("Inserisci un numero: ");
         scanf("%d", &numero);
         fflush(stdin);
         printf("Inserisci il divisore: ");
         scanf("%d", &divisore);
         fflush(stdin);
         if(numero%divisore == 0)
            printf("%d e' un divisore di %d.", divisore, numero);
         else
            printf("%d non e' un divisore di %d.", divisore, numero);
         break;
      }
      // case da aggiungere.

      default:{
         printf("Scelta effettuata non valida!");
         break;
      }
   }
   return(0);
}
/*
   if(scelta == 1){
      ramo del vero caso 1
   }
   if(scelta == 2){
      ramo del vero caso 2
   }
   if(scelta == 3){
      ramo del vero caso 3
   }
*/
/*
   if(scelta == 1){

   }
   else{
      if(scelta == 2){

      }
      else{
         if(scelta == 3){

         }
         else{
            // caso del default, cioè se scelta non è ne 1, ne 2, ne 3.
         }
      }
   }
*/