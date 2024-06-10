/*
Desc: Realizzare un programma C che richieda una stringa da tastiera (max 20 char):
      - esegue un conteggio per ogni singola lettera dell'alfabeto, comunicando quante volte compare.
      - Realizza una seconda stringa, come risultato leggendo la prima al contrario.
Auth: Pradella F.
Date: 14.10.2021
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
 * Conta e restituisce il numero di volte che una lettera compare in una stringa.
 * @param char Lettera da cercare.
 * @param char[] Stringa da utilizzare
 * @return int Numero di volte che la lettera compare nella stringa.
 */
int contaLettera(char, char []);
/**
 * Genera una seconda stringa come contrario della prima.
 * @param char[] Stringa iniziale originale.
 * @param char[] Stringa in cui verrà costruita la contraria alla prima.
 */
void reverseString(char [], char []);

int main(){
   char str[DIM];
   char str_rev[DIM];
   int i;

   printf("Inserisci una stringa: ");
   scanf("%s", str);
   fflush(stdin);
   printf("Stringa inserita: %s\n", str);

   // conteggio delle lettere.
   printf("Presenza lettere:\n");
   for(i='a'; i<='z'; i++){
      printf("%c compare: %d\n", i, contaLettera(i, str));
   }

   // creo la seconda stringa come contrario della prima
   reverseString(str, str_rev);
   printf("\nReverse: %s", str_rev);
   return(0);
}

int strLength(char _s[]){
   int i;
   i = 0;
   while(_s[i] != '\0')
      i++;
   return(i);
}

void reverseString(char _src[], char _dst[]){
   int i;
   for(i=0; i<strLength(_src); i++){
      _dst[strLength(_src)-i-1] = _src[i];
   }
   _dst[strLength(_src)] = '\0';
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