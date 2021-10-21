#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <conio.h>

#include "funzioni.h"

int strLength(char _s[]){
   int i;
   i = 0;
   while(_s[i] != '\0')
      i++;
   return(i);
}

int getIndexMaxLength(char _e[][DIM], int _r){
   int max;
   int indice;
   int i;

   max = strLength(_e[0]);
   indice = 0;
   for(i=1; i<_r; i++){
      if(strLength(_e[i]) > max){
         max = strLength(_e[i]);
         indice = i;
      }
   }
   return(indice);
}