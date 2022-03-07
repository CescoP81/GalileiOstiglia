/*
Scrivere una funzione che ritorna al chiamante il massimo e il minimo di una sequenza di cinque
numeri interi introdotti dall'utente.
La funzione:
   - legge i numeri introdotti utilizzando la funzione askNumber()
   - ritorna al chiamante i due valori utilizzando il passaggio per riferimento
*/
#include <conio.h>
#include <stdio.h>

int askNumber(int, int);
void minMaxNumbers(int*, int*);
//##############################
int main(){
   int minimo, massimo;
   minMaxNumbers(&minimo, &massimo);

   printf("Il minimo inserito: %d\n", minimo);
   printf("Il massimo inserito: %d\n", massimo);

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

void minMaxNumbers(int *_min, int *_max){
   int i;
   int x;
   for(i=1; i<=5; i++){
      x = askNumber(5, 20);
      if(i == 1){
         *_min = x;
         *_max = x;
      }
      else{
         if(x < *_min)
            *_min = x;
         if(x > *_max)
            *_max = x;
      }
   }
}
