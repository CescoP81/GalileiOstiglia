/*
Desc: Realizzare un programma C che richieda due stringhe da tastiera (max 20 char):
      - determina se le due stringhe sono una l'anagramma dell'altra.Date: 14.10.2021
*/
#include <stdio.h>

#define DIM 21    // 20 car + '\0'
/**
 * Determina la lunghezza di una stringa passata come parametro, basandosi sul terminatore '\0'
 * @param char[] Stringa da utilizzare
 * @return int Lunghezza della stringa.
 */
int strLength(char []);
/**
 * Determina se due stringhe passate come parametri sono due anagrammi. Due parole sono anagrammi
 * se sono formate dalle stesse lettere, nello stesso numero, ma in posizioni diverse.
 * es: casca -> sacca ### pepito -> pipeto
 * @param char[] Stringa uno da utilizzare.
 * @param char[] stringa due da utlizzare.
 * @return int 1 se sono anagrammi, 0 se non sono anagrammi.
 */
int checkAnagramma(char [], char []);

int main(){
   char str[DIM];
   char str2[DIM];
   int i;

   printf("Inserisci stringa 1: ");
   scanf("%s", str);
   fflush(stdin);
   printf("Inserisci stringa 1: ");
   scanf("%s", str2);
   fflush(stdin);
   
   printf("Stringa 1 inserita: %s\n", str);
   printf("Stringa 2 inserita: %s\n", str2);

   // verifico che sia palindroma oppure no "radar" è palindroma come "otto"
   if(checkAnagramma(str, str2))
      printf("Le due parole sono anagrammi!");
   else
      printf("Spiacente, non sono anagrammi!");
   return(0);
}

int strLength(char _s[]){
   int i;
   i = 0;
   while(_s[i] != '\0')
      i++;
   return(i);
}

int checkAnagramma(char _str[], char _str2[]){
   int alfabeto[26];
   int i;
   
   // azzero il vettore contatori associati alle lettere
   for(i=0; i<26; i++)
      alfabeto[i] = 0;

   if(strLength(_str) != strLength(_str2))
      return(0);
   else{
      // scorro la stringa 1 aumentando il contatore di ogni singola lettera che trovo
      for(i=0; i<strLength(_str); i++){
         alfabeto[_str[i]-'a']++;
      }
      // eseguo lo stesso procedimento su str_2 ma diminuendo il contatore.
      for(i=0; i<strLength(_str2); i++){
         alfabeto[_str2[i]-'a']--;
      }
      for(i=0; i<26; i++){
         if(alfabeto[i]!=0)
            return(0);
      }
   }
   return(1);
}