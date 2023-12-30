/*
   Esempio esplicativo del concetto di puntatore a puntatore.
   Per semplicità è realizzato con puntatori di tipo intero.
*/
#include <stdio.h>

int main(){
   int a;
   int *pa;
   int **ppa;


   a = 5;
   pa = &a;
   ppa = &pa;

   printf("&a: %d e a: %d\n\n", &a, a);
   printf("&pa: %d - pa: %d -> *pa: %d\n\n", &pa, pa, *pa);
   printf("ppa: %d -> **ppa: %d",ppa, *(*ppa));
   return(0);
}