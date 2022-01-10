/*
   Realizzare un programma C che determina se un numero inserito
   da tastiera è PERFETTO oppure no.
   Un numero si intende perfetto quando la somma dei suoi divisori è
   uguale al suo doppio.
   6: 1-2-3-6 -> 1+2+3+6 = 12 (12 è 6*2) Perfetto.
   28: ?
*/
#include <conio.h>
#include <stdio.h>

int main(){
   int numero;
   int divisore;
   int sommaDivisori;

   // chiedo il numero all'utente.
   printf("Inserisci numero: ");
   scanf("%d", &numero);
   fflush(stdin);

   // ciclo dei divisori, se trovo un divisore lo sommo al totale
   sommaDivisori = 0;
   for(divisore=1; divisore<=numero; divisore++){
      if(numero%divisore == 0){
         sommaDivisori = sommaDivisori + divisore;
      }
   }

   // test tra la somma dei divisori ed il numero analizzato.
   printf("\nSomma: %d\n", sommaDivisori);
   if(sommaDivisori == (numero*2)){
      printf("Il numero e' perfetto.");
   }
   else{
      printf("Il numero non e' perfetto.");
   }
}