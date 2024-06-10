/*
   Realizzare il seguente scema grafico con numero di righe inserito
   da tastiera.
   n=5;
   *****
    ****
     ***
      **
       *
*/
#include <stdio.h>

int main(){
   int n;
   int riga;
   int spazi;
   int asterischi;

   printf("Inserisci n: ");
   scanf("%d", &n);
   fflush(stdin);
   
   // ciclo delle righe
   for(riga=1; riga<=n; riga++){
      // ciclo per gli spazi
      for(spazi=1; spazi<=(riga-1); spazi++){
         printf("  ");
      }

      // ciclo asterischi su riga
      for(asterischi=1; asterischi<=(n-riga+1); asterischi++){
         printf("* ");
      }      
      printf("\n");
   }
   return(0);
}