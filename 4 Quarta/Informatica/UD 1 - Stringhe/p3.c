/*
Desc: Realizzare un programma C che richieda una stringa da tastiera (max 20 char):
      - determina se la parola è palindroma (è uguale anche se letta al contrario)Auth: Pradella F.
Date: 14.10.2021
*/
#include <stdio.h>

#define DIM 21    // 20 car + '\0'

int strLength(char []);
int checkPalindroma(char []);

int main(){
   char str[DIM];
   int i;

   printf("Inserisci una stringa: ");
   scanf("%s", str);
   fflush(stdin);
   printf("Stringa inserita: %s\n", str);

   // verifico che sia palindroma oppure no "radar" è palindroma come "otto"
   if(checkPalindroma(str))
      printf("Parola Palindroma!");
   else
      printf("Spiacente, non e' palindroma!");
   return(0);
}

int strLength(char _s[]){
   int i;
   i = 0;
   while(_s[i] != '\0')
      i++;
   return(i);
}

int checkPalindroma(char _str[]){
   int i;
   int check;

   check = 1;   // assumo come iniziale che sia palindroma.
   for(i=0; i<strLength(_str); i++){
      if(_str[i] != _str[strLength(_str)-i-1])
         check = 0;
   }
   return(check);
}