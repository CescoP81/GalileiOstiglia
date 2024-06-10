#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#define DIM 100

#include "funzioni.c"      // ATTENZIONE CHE UTILIZZO LE FUNZIONI PRESENTI NEL FILE funzioni.c; scaricate anche funzioni.h

int main(){
   char *str;
   str = malloc(sizeof(char) * 100);
   int i;

   printf("Inserisci una stringa: ");
   scanf("%s", str);
   fflush(stdin);

   printf("1- Stringa: %s\n", str);
   printf("2- Lunghezza: %d\n", getStringLength(str));
   printf("3- Lettere presenti:\n");
   for(i='a'; i<='z'; i++){
      if(getOccurenciesOf(str, i))
         printf("%c = %d\n", i, getOccurenciesOf(str,i));
   }
   printf("4- Lettera piu' presente: %c\n", getCharMostPresent(str));

   if(checkStrPalindroma(str))
      printf("5- Parola palindroma.\n");
   else
      printf("5- Parola non palindroma.\n");

   printf("\n\n");
   printf("Inserisci una frase: ");
   gets(str);
   fflush(stdin);
   printf("6- Numero di parole: %d\n", getNumberOfWords(str));
   return(0);
}