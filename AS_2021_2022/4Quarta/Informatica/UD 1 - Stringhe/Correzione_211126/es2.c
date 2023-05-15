/*
Creare un programma C che richieda una sequenza di stringhe (lunghezza max 20 char), la sequenza finisce se viene inserita una sola lettera, per ogni stringa inserita devono essere applicate le seguenti funzioni:
• showReversed → visualizza la stringa al contrario e comunica se palindroma.
• ShakeString → analizzando la stringa, le lettere minuscole diventano maiuscole e viceversa.
• BuildAnagram → ricevuta una parola ne costruisce un anagramma e lo ritorna al main.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 20
/**
 * @brief Calcola e restituisce la lunghezza di una stringa.
 * @param char[] La stringa da analizzare.
 * @return int Numero di caratteri della stringa.
 */
int strLength(char[]);
/**
 * @brief Visualizza la stringa al contrario e determina se palindroma.
 * @param char[] La stringa da analizzare.
 * @return int 1 se palindroma / 0 se non palindroma
 */
int showReversed(char[]);
/**
 * @brief Modifica la stringa: le minuscole in maiuscole e viceversa.
 * @param char[] La stringa da analizzare.
 */
void shakeString(char[]);
/**
 * @brief Costruisce un anagramma partendo da una parola data.
 * @param char[] Stringa sorgente.
 * @param char[] Stringa destinazione contenente anagramma. 
 */
void buildAnagram(char[], char[]);

int main(){
   char str[DIM];
   char anagramma[DIM];
   do{
      printf("Parola: ");
      scanf("%s", str);
      fflush(stdin);

      if(strLength(str) > 1){ // ho una stringa valida da utilizzare.
         //punto 1
         if(showReversed(str))
            printf("\nStringa palindroma.\n");
         else
            printf("\nStringa non palindroma.\n");
         //punto 2
         shakeString(str);
         printf("Stringa after shake: %s\n", str);
         //punto 3
         buildAnagram(str, anagramma);
         printf("Anagramma: %s", anagramma);
      }
      printf("\n------------\n");
   }while(strLength(str)>1);
   return(0);
}

int strLength(char _str[]){
   int i;
   i=0;
   while(_str[i] != '\0')
      i++;
   return(i);
}

int showReversed(char _str[]){
   int i;
   int check;

   check = 1;
   i = 0;
   while(_str[i] != '\0'){
      printf("%c", _str[strLength(_str)-i-1]);
      if(_str[i] != _str[strLength(_str)-i-1])
         check = 0;
      i++;
   }
   return(check);
}

void shakeString(char _str[]){
   int i;
   i=0;
   while(_str[i] != '\0'){
      if((_str[i]>='a') && (_str[i]<='z'))
         _str[i] = 'A' + (_str[i]-'a');
      else
         _str[i] = 'a' + (_str[i]-'A');
      i++;
   }
}

void buildAnagram(char _str[], char _dst[]){
   int i;
   int lettere[26];
   int random;
   for(i=0; i<26; i++)
      lettere[i] = 0;

   // determino quali e quante lettere compongono la parola originale.
   // conto sia maiuscole che minuscole, ma l'anagramma sarà formato solo da minuscole.
   i=0;
   while(_str[i] != '\0'){
      if((_str[i]>='a') && (_str[i]<='z'))
         lettere[_str[i]-'a']++;
      if((_str[i]>='A') && (_str[i]<='Z'))
         lettere[_str[i]-'A']++;
      i++;
   }

   /* pesco a random una possibile lettera e controllo se il suo contatore è maggiore di zero,
      in quel caso la lettera la aggiungo al vettore destinazione e decremento il contatore.
      passo quindi alla posizione successiva da riempire.
   */
   i=0;
   while(i<strLength(_str)){
      random = rand()%26;           
      if(lettere[random]>0){
         _dst[i] = 'a'+random;
         lettere[random]--;
         i++;
      }
   }
   _dst[i]='\0';
}