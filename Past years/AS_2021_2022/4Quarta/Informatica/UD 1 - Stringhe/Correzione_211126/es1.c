/*
Creare un programma C che richieda una stringa da tastiera, quindi eseguire le seguenti operazioni creando specifiche funzioni:
• countingChar → ricevendo stringa e carattere, comunica quante volte compare tale carattere e se compare anche due volte consecutivamente.
• growUpAsFirst → Verifica la prima lettera della stringa e se è in minuscolo, la pone in maiuscolo insieme a tutte quelle uguali nella stringa.
• hideVocals → riceve la stringa e sostituisce ogni vocale con un #.
*/
#include <stdio.h>
#define DIM 20

/**
 * @brief Conta quante volte compare il carattere nella stringa.
 * @param char[] Stringa da analizzare.
 * @param char Carattere da utilizzare.
 */
void countingChar(char[], char);
/**
 * @brief Da minuscolo a maiuscolo, la prima lettera e tutte quelle uguali ad essa.
 * @param char[] Stringa da analizzare.
 */
void growUpAsFirst(char[]);
/**
 * @brief Nasconde le vocali della stringa con un #
 * @param char[] La stringa da analizzare.
 */
void hideVocals(char[]);

int main()
{
   char str[DIM];
   char c;

   printf("Inserisci una stringa: ");
   scanf("%s", &str);
   fflush(stdin);

   printf("Inserisci un carattere: ");
   scanf("%c", &c);
   fflush(stdin);

   // punto 1
   countingChar(str, c);
   printf("\n");
   // punto 2
   growUpAsFirst(str);
   printf("Stringa modificata: %s\n", str);
   // punto 3
   hideVocals(str);
   printf("Stringa modificata: %s\n", str);
   return (0);
}

void countingChar(char _str[], char _c)
{
   int i;
   int cnt;
   int doppie;

   i = 0;
   doppie = 0;
   cnt = 0;
   while (_str[i] != '\0')
   {
      if (_str[i] == _c)
         cnt++;
      if (_str[i + 1] != '\0')
         if (_str[i] == _str[i + 1])
            doppie = 1;
      i++;
   }
   printf("Il carattere %c compare nella stringa %s: %d volta/e.\n", _c, _str, cnt);
   if (doppie)
      printf("Il carattere %c e' presente in almeno una doppia.\n", _c);
   else
      printf("Non sono presenti doppie.\n");
}
void growUpAsFirst(char _str[])
{
   int i;
   char c = '\0';
   i = 0;
   if ((_str[i] >= 'a') && (_str[i] <= 'z'))
   {
      c = _str[i];
      while (_str[i] != '\0')
      {
         if (_str[i] == c)
            _str[i] = 'A' + (_str[i] - 'a'); // ciccia -> [0]='c' c='c' 'A'+('c'-'a')
         i++;
      }
   }
}
void hideVocals(char _str[])
{
   int i, j;
   char vocali[5] = {'a', 'e', 'i', 'o', 'u'};

   i = 0;
   while (_str[i] != '\0')
   {
      for (j = 0; j < 5; j++)
      {
         if ((_str[i] == vocali[j]) || (_str[i] == vocali[j] + ('A' - 'a')))
            _str[i] = '#';
      }
      i++;
   }
}