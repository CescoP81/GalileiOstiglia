/**
*	Author: Pradella F.
*	Date: 08.11.2021
*	Description: Visualizzazione di variabili, indirizzi, escape code.
*/
#include <stdio.h>

int main(){
   int numero;
   int x,y,z;

   printf("Inserisci un numero: ");
   scanf("%d", &numero);
   fflush(stdin);

   // Stampo informazioni varie.
   printf("Contenuto variabili numero: %d\n", numero);
   printf("Indirizzo variabile numero: %d\n", &numero);
   
   printf("\n\n");

   printf("Numero/2: %d\n", (numero / 2));
   printf("Numero%2: %d\n", (numero % 2));

   x = 5;
   y = 25;
   z = 175;
   // esempio di spaziatura mobile
   /* 5
      25
      175*/
   printf("%d\n", x);
   printf("%d\n", y);
   printf("%d\n", z);
   printf("\n");
   printf("%3d\n", x);
   printf("%3d\n", y);
   printf("%3d\n", z);


   return(0);
}