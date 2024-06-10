/*
   Realizzare il seguente scema grafico con numero di righe inserito
   da tastiera.
   n=5;
   *
   **
   ***
   ****
   *****
*/
#include <stdio.h>

int main(){
   int n;
   int riga;
   int asterisco;

   printf("Inserisci n: ");
   scanf("%d", &n);
   fflush(stdin);
   // ciclo più esterno è dedicato alle righe
   for(riga=1; riga<=n; riga++){
      // ad ogni riga, stampo un numero uguale di *
      for(asterisco=1; asterisco<=riga; asterisco++){
         printf("* ");
      }
      printf("\n");
   }
   return(0);
}