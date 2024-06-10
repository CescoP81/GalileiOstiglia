/*
   Come p04.c ma i valori da testare devono essere compresi tra
   due estremi N1 e N2 con N1 minore di N2.
*/
#include <conio.h>
#include <stdio.h>

int main(){
   int N1, N2;          // estremi dei valori da analizzare.
   int numero;          // numero da analizzare.
   int divisore;        // ciclo dei divisori.
   int cnt;             // contatore dei devisori.

   // richiesto N1 e N2
   printf("Inserisci N1: ");
   scanf("%d", &N1);
   fflush(stdin);
   printf("Inserisci N2: ");
   scanf("%d", &N2);
   fflush(stdin);

   // solo se N1 è minore di N2 allora procedo
   if(N1 < N2){
      for(numero=N1; numero<=N2; numero++){
         printf("%d: ", numero);
         cnt = 0;
         for(divisore=1; divisore<=numero; divisore++){
            if(numero%divisore == 0){
               printf("%d, ", divisore);
               cnt++;
            }
         }
         if(cnt <= 2){
            printf("numero primo");
         }
         else{
            printf("non primo.");
         }
         printf("\n");
      }
   }
   else{
      printf("Ciclo non realizzabile...");
   }
   return(0);
}