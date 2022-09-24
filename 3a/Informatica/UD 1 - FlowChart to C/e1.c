#include <stdio.h>

int main(){
   // dichiarazione ed inizializzazione delle variabili utili al mio algoritmo.
   int v1=0;
   int v2=0;
   int v3=0;
   int maggiore=0;
   int minore=0;

   // fase di input dei valori iniziali.
   printf("Inserisci V1: ");
   scanf("%d", &v1);
   fflush(stdin);

   printf("Inserisci V2: ");
   scanf("%d", &v2);
   fflush(stdin);
   
   printf("Inserisci V3: ");
   scanf("%d", &v3);
   fflush(stdin);

   // determinazione del valore maggiore
   maggiore = v1; // scrivere v1 = maggiore significa perdere v1!!

   if(v2 > maggiore){
      maggiore = v2;
   }

   if(v3 > maggiore){
      maggiore = v3;
   }
   
   printf("\nIl valore maggiore e': %d\n", maggiore);

   // determinazione del valore minore
   minore = v1;

   if(v2 < minore){
      minore = v2;
   }

   if(v3 < minore){
      minore = v3;
   }

   printf("Il valore minore e': %d\n", minore);


   // determino per ogni valore se è pari oppure dispari
   if(v1 % 2 == 0){
      printf("%d e' pari\n", v1);
   }
   else{
      printf("%d e' dispari\n", v1);
   }

   if(v2 % 2 == 0){
      printf("%d e' pari\n", v2);
   }
   else{
      printf("%d e' dispari\n", v2);
   }

   if(v3 % 2 == 0){
      printf("%d e' pari\n", v3);
   }
   else{
      printf("%d e' dispari\n", v3);
   }

   return(0);
}