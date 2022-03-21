/*
   Uso del passaggio di parametri per RIFERIMENTO &-*
   ticket: Baroni M.
*/
#include <stdio.h>
#include <conio.h>
void f1(int);  // passaggio per riferimento il parametro contiene il valore

void f2(int *);// passaggio per riferimento, il parametro contiene l'indirizzo della varibile che contiene il valore.

int main(){
   int n;
   n = 6;
   f1(n);
   printf("%d\n\n", n);

   printf("n address: %d\n\n", &n);
   f2(&n);
   printf("%d\n\n", n);
   return(0);
}

// sezione funzioni 
void f1(int _n){
   _n = _n * 2;
}

void f2(int *_n){
   printf("_n value: %d\n\n", _n);
   *_n = (*_n) * 2;
}