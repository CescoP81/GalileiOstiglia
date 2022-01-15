/*
   programma C che partendo da un N fisso, lo codifica prima 
   in una serie di cifre binarie utilizzando un ciclo while.
   Successivamente utilizzando un ciclo for il numero N viene codificato
   con un numero di bit fisso pari a 8.

   Modificare questo programma richiedendno il numero N decimale da
   trasformare in binario.
*/
#include <stdio.h>

int main(){
   int n;
   int r;      // resto della divisione
   int i;

   n = 37;     // numero decimale da codificare in Binario.
   while(n > 0){
      r = n % 2;
      printf("%d", r);
      n = n / 2;
   }

   printf("\n\n");   // scompongo il numero con un numero fisso di 8 bit.
   n = 37;
   for(i=0; i<8; i++){
      r = n % 2;
      printf("%d", r);
      n = n / 2;
   }

   printf("\n\n");
   int binary[8]; // dichiaro un vettore o Array monodimensionale di 8 celle intere.
   n = 37;
   for(i=0; i<8; i++){     // scompongo n in bit e li colloco nelle celle del vettore.
      binary[i] = n % 2;
      n = n / 2;
   }
   // il numero nel vettore scomposto è: 10100100

   for(i=7; i>=0; i--){ 
      printf("%d", binary[i]);
   }
   // il numero binario stampato al contrario è: 00100101

   return(0);
}
// 37 -> 101001      -> 100101
// 37 -> 10100100    -> 00100101