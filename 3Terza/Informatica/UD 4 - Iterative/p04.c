/*
   Realizzare un programma che visualizza i divisori dei primi N numeri
   naturali con N inserito da tastiera, e comunica per ogni numero se è primo oppure
   no.
*/
#include <conio.h>
#include <stdio.h>

int main(){
   int nValori;
   int numero;
   int divisore;
   int cnt;

   // chiedo all'utente quanti valori vuole analizzare.
   printf("Inserisci il numero di valori: ");
   scanf("%d", &nValori);
   fflush(stdin);

   // numero varia da 1 al numero N inserito dall'utente
   for(numero=1; numero <= nValori; numero++){
      printf("%d: ", numero);
      cnt = 0; // per ogni numero azzero il contatore
      // ricerco i divisori.
      for(divisore=1; divisore<=numero; divisore++){
         if(numero%divisore == 0){
            printf("%d, ", divisore);
            cnt++;
         }
      }
      // controllo il contatore per determinare se numero è primo oppure no.
      if(cnt<=2){
         printf("Numero primo.");
      }
      else{
         printf("Non primo.");
      }
      printf("\n");
   }
   return(0);
}