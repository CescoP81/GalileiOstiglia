/* Esempio di utilizzo del costrutto SWITCH-CASE. */

#include <stdio.h>

int main(){
   int scelta;                // conterrà la scelta numerica effettuata dall'utente.
   int base, altezza, area;   // variabili per il rettangolo case 1.
   int raggio, circonferenza; // variabili per la circonferenza case 2.
   int numero, divisore;      // variabili per il case 3.
   int multiplo;              // variabile aggiuntiva per case 4.
   int anno;                  // variabile per il case 5.

   // 1. visualizzare all'utente la lista delle scelte.
   do{
      printf("1. Calcolo area rettangolo.\n");
      printf("2. Calcolo lunghezza circonferenza.\n");
      printf("3. Verifica divisore.\n");
      printf("4. verifica multiplo.\n");
      printf("5. verifica anno Bisestile.\n");
      printf("6. Verifica numero pari e multiplo di 3.\n");
      printf("0 -> USCITA\n");
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
         case 4:{
            printf("Inserisci numero multiplo: ");
            scanf("%d", &multiplo);
            fflush(stdin);
            printf("Inserisci numero base: ");
            scanf("%d", &numero);
            fflush(stdin);

            if(multiplo%numero == 0)
               printf("%d e' multiplo di %d.\n", multiplo, numero);
            else
               printf("%d non e' multiplo di %d.\n", multiplo, numero);
            break;
         }
         case 5:{
            printf("Inserisci un anno:");
            scanf("%d", &anno);
            fflush(stdin);
            if(anno%100 == 0){
               if(anno%400 == 0)
                  printf("Anno %d e' bisestile.\n", anno);
               else
                  printf("Anno %d non e' bisestile.\n", anno);
            }
            else{
               if(anno%4 == 0)
                  printf("Anno %d e' bisestile.\n", anno);
               else
                  printf("Anno %d non e' bisestile.\n", anno);            
            }
            break;
         }
         case 6:{
            printf("Inserisci un numero: ");
            scanf("%d", &numero);
            fflush(stdin);
            // moetodo uno, if nidificate
            if(numero%2 == 0){
               if(numero%3 == 0)
                  printf("%d e' pari e multiplo di 3.\n", numero);
               else
                  printf("%d e' pari ma non e' multiplo di 3.\n", numero);
            }
            else
               printf("%d non e' pari ma potrebbe essere multiplo di 3.\n", numero);

            // metodo 2, operatore logico AND
            if((numero%2 == 0) && (numero%3 == 0))
               printf("\n%d e' pari e multiplo di 3.\n", numero);
            else
               printf("\nUna o entrambe delle proprietà non è verificata!");
            break;
         }
         default:{
            printf("Scelta effettuata non valida!");
            break;
         }
      }
      printf("\n\n!! Premere un tasto per continuare !!");
      getchar();
   }while(scelta != 0);
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