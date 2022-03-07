/*
Scrivere una funzione che ritorna al chiamante la media di N numeri interi compresi tra 1 e 30, N deve essere
richiesto nel main program.
La funzione:
   - legge N numeri introdotti utilizzando la funzione askNumber()
   - ritorna al chiamante il valor medio.
*/
#include <stdio.h>
#include <conio.h>

int askNumber(int, int);
float mediaValori(int);

int main(){
   int n_valori;
   float media;

   printf("Inserisci il numero di valori: ");
   scanf("%d", &n_valori);
   fflush(stdin);

   media = mediaValori(n_valori);
   printf("Media valori: %.2f", media);
   return(0);
}

// #############################
int askNumber(int _l, int _r){
   int x;
   do{
      printf("Inserisci numero: ");
      scanf("%d", &x);
      fflush(stdin);
   }while(x<_l || x>_r);
   return(x);
}

float mediaValori(int n){
   int i;
   int somma = 0;
   
   for(i=1; i<=n; i++){
      somma = somma + askNumber(1, 30);
   }
   return((float)somma/n);
}