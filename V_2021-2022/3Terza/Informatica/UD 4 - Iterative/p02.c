/* Programma che acquisito un numero in input
stampa a video tutti i suoi divisori.
*/
#include <stdio.h>

int main(){
   int num;    // variabile per il numero acquisito in input.
   int div;    // variabile per il ciclo iterativo dei divisori.

   // 1.acquisisco il numero
   printf("Inserisci un numero: ");
   scanf("%d", &num);
   fflush(stdin);

   // 2. ciclo iterativo dei divisori, basato su variabile div.
   printf("\nDivisori: ");
   div = 1;                      // punto di partenza dei divisori.
   while(div <= num){            // controllo di essere inferiore o uguale al num
      if(num%div == 0){
         printf("%3d", div);
      }
      div = div + 1;             // incremento del divisore.
   }

   // 2.bis ciclo iterativo dei divisori, basato su variabile div. (in ordine decrescente)
   printf("\n\nDivisori: ");
   div = num;
   while(div >= 1){
      if(num%div == 0){
         printf("%3d", div);
      }
      div = div - 1;             // incremento del divisore.
   }
   

   return(0);
}