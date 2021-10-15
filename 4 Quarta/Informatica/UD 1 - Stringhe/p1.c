/*
Desc: Realizzare un programma C che richieda una stringa da tastiera (max 20 char):
      - determina la sua lunghezza e la comunica.
      - la stampa al contrario char-by-char.
      - esegue il conteggio delle vocali.
Auth: Pradella F.
Date: 14.10.2021
*/

#include <stdio.h>

#define DIM 21    // 20 car + '\0'

int strLength(char []);
void printReverseString(char []);
int contaLettera(char, char []);

int main(){
   char str[DIM];
   char vocali[5]={'a','e','i','o','u'};
   int i;

   printf("Inserisci una stringa: ");
   scanf("%s", str);
   fflush(stdin);
   printf("Stringa inserita: %s\n", str);

   // determino lunghezza
   printf("Lunghezza: %d\n", strLength(str));

   // stampo la stringa al contrario
   printf("Stringa al contrario: ");
   printReverseString(str);
   printf("\n");

   // conteggio delle vocali.
   printf("Presenza vocali:\n");
   for(i=0; i<5; i++){
      printf("%c compare: %d\n", vocali[i], contaLettera(vocali[i], str));
   }
   return(0);
}

int strLength(char _s[]){
   int i;
   i = 0;
   while(_s[i] != '\0')
      i++;
   return(i);
}

void printReverseString(char _s[]){
   int i;
   for(i=strLength(_s)-1; i>=0; i--)
      printf("%c", _s[i]);
}

int contaLettera(char _l, char _s[]){
   int i;
   int cnt;

   cnt = 0;
   for(i=0; i<strLength(_s); i++){
      if(_s[i] == _l)
         cnt++;
   }
   return(cnt);
}