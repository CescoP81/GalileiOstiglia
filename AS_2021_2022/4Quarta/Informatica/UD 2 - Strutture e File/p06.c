/*
Scrivere un programma C che richiede una lettera da tastiera,
legga un file di testo contenente delle parole e visualizza a video
quelle parole che hanno la lettera inserita come iniziale (maiuscola o minuscola).
*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 20

int main(){
   char str[DIM];
   char c;
   FILE *fpin;

   // richiedo il carattere da usare come iniziale della parola.
   printf("Carattere iniziale: ");
   scanf("%c", &c);
   fflush(stdin);

   // apro il file di testo per leggere le singole parole.
   fpin = fopen("parole.txt", "rt");

   fscanf(fpin, "%s", &str);                    // lettura iniziale da file 
   while(!feof(fpin)){     // se NON sono alla fine del file -> IF !(NOT)
      if((str[0]==c) || (str[0]=='A'+(c-'a'))){
         printf("%s ", str);     
      }
      fscanf(fpin, "%s", &str);
   }

   fclose(fpin);
   return(0);
}