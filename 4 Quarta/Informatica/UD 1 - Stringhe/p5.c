#include <conio.h>
#include <stdio.h>
#include "funzioni.c"

#define RIGHE 5
#define DIM 30

int main(){
   char elenco[RIGHE][DIM];
   int i;

   // ciclo di inserimento stringhe
   for(i=0; i<RIGHE; i++){
      printf("Inserisci stringa [%d]: ", i+1);
      scanf("%s", elenco[i]);
      fflush(stdin);
   }
   printf("\n");
   // ciclo verifica inserimento, stampo l'elenco di stringhe.
   for(i=0; i<RIGHE; i++){
      printf("%d. %s\n", i+1, elenco[i]);
   }
   printf("\n");
   // determino e comunico la lunghezza di ogni singola stringa.
   for(i=0; i<RIGHE; i++){
      printf("%d. %s = %d caratteri\n", i+1, elenco[i], strLength(elenco[i]));
   }

   return(0);
}

