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

/* --- funzioni con puntatori --- */
int getStringLength(char *_str){
   int i;
   int cnt;
   cnt = 0;
   i = 0;
   while(*(_str+i) != '\0'){
      cnt++;
      i++;
   }
   return(cnt);
}

int getOccurenciesOf(char *str, char src){
   int i;
   int cnt;

   cnt = 0;
   i = 0;
   while(*(str+i) != '\0'){
      if(*(str+i) == src)
         cnt++;
      i++;
   }
   return(cnt);
}

char getCharMostPresent(char *str){
   int i;
   int cmax;
   int ccnt;

   ccnt=0;
   for(i='a'; i<='z'; i++){
      if(getOccurenciesOf(str, i) > ccnt){
         ccnt = getOccurenciesOf(str, i);
         cmax = i;
      }
   }
   return(cmax);
}

int checkStrPalindroma(char *str){
   int i;
   for(i=0; i<getStringLength(str); i++){
      if(*(str+i) != *(str+getStringLength(str)-i-1))
         return(0);
   }
   return(1);
}

int getNumberOfWords(char *str){
   int i;
   int cnt;

   i = 0;
   cnt = 0;
   while(*(str+i) != '\0'){
      if(*(str+i) == ' ')
         cnt++;
      i++;
      if(*(str+i) == '\0') // questo caso verifico se sono sull'ultima parola.
         cnt++;
   }
   return(cnt);
}