/* acquisire una stringa di max 100 char con più parole.
richiamare una funzione toUpper che mette in maiuscola
ogni inizale*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void toUpper(char *s);

int main()
{
char *s=(char*)malloc(sizeof(char)*101);
printf("inserisci una str con più parole --> ");
gets(s);
fflush(stdin);

toUpper(s);
printf("str con modifiche --> ");
puts(s);
}

void toUpper(char *s){
   int i;
   for(i=0;*(s+i)!='\0';i++)
      if(*(s+i)==' ')
         *(s+i+1)='A'+(*(s+i+1)-'a');
}