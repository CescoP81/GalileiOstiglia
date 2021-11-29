/* Esempio di scrittura ciclo 
   WHILE -> Controllo in testa
   (le istruzioni potrebbero non essere eseguite nemmeno una volta.)

   Acquisire in input un numero intero positivo, stampare tutti i numeri
   compresi tra il numero inserito e 50.
*/
#include <stdio.h>

int main(){
   int num;
   int num2;
   printf("Inserisci numero: ");
   scanf("%d", &num);
   fflush(stdin);

   num2 = num;
   printf("Ciclo While: ");
   while(num <= 50){
      printf("%3d", num);
      num = num + 1;
   }

/* scommentare per vedere la differenza tra while e do-while  
   printf("\n\nCiclo do-while: ");
   do{
      printf("%3d", num2);
      num2 = num2 + 1;
   }while(num2 <= 50);
// */
   return(0);
}