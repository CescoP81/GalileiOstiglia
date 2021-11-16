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

/**
 * Determina la lunghezza di una stringa passata come parametro, basandosi sul terminatore '\0'
 * @param char[] Stringa da utilizzare
 * @return int Lunghezza della stringa.
 */
int strLength(char[]);
/**
 * Stampa al contrario una stringa ricevuta come parametro.
 * @param char[] Stringa da utilizzare
 */ 
void printReverseString(char[]);
/**
 * Conta e restituisce il numero di volte che una lettera compare in una stringa.
 * @param char Lettera da cercare.
 * @param char[] Stringa da utilizzare
 * @return int Numero di volte che la lettera compare nella stringa.
 */
int contaLettera(char, char[]);

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

   /* conteggio delle vocali.
      le vocali le ho poste in un vettore di 5 elementi, così usando un ciclo for ad
      ogni giro del ciclo richiamo la cella del vettore vocali[] e passo la 
      vocale corrispondente alla funzione.
   */
   printf("Presenza vocali:\n");
   for(i=0; i<5; i++){
      printf("%c compare: %d\n", vocali[i], contaLettera(vocali[i], str));
   }
   //printf("La lettera 'a' compare %d volte", contaLettera('a', str));
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