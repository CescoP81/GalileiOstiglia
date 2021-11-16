/*
Realizzare un programma che richiede una stringa composta da più
parole, lunga massimo 100 char.
Scansionando la stringa deve comunicare:

- lettera che compare più volte.
- lettera che compare meno.
- Numero di parole che compongono la stringa.
- Parola più lunga.
- Parola più corta.
*/
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

int LetteraMag(char []);
int LetteraMag2(char *);
int NumWord(char *);
int CambiaCarattere(char *,char,char);

void DividiParole(char *);

int main(){
   char *str;
   str = malloc(sizeof(char)*100);
   int indice_mag;
   int num_word;
   char src,dst;
   // acquisizione della stringa e stampa d verifica.
   printf("Inserisci la frase: ");
   gets(str);
   fflush(stdin);
   printf("\n\n");
   printf("%s", str);
   //------------------------
   indice_mag = LetteraMag(str);
   printf("\n\nLettera che compare piu' volte: %c", indice_mag);
   indice_mag = LetteraMag2(str);
   printf("\n\nLettera che compare piu' volte: %c", indice_mag);
   //numero di parole presenti nella stringa
   num_word = NumWord(str);
   if(num_word != 0)
      printf("\n\nLa stringa contiene %d parole", num_word);
   else  
      printf("\n\nLa stringa non contiene parole");

   printf("Inserisci un carattere: ");
   scanf("%c",&src);
   fflush(stdin);

   printf("Inserisci un carattere: ");
   scanf("%c",&dst);
   fflush(stdin);

   printf("\nNumero sostituzioni: %d",CambiaCarattere(str,src,dst));
   printf("\n%s",str);
   return(0);
}

int LetteraMag(char s[]){
   int alfa[26];
   int i;
   int indice;
   int Max;

   for(i=0; i<26; i++){
      alfa[i] = 0;
   }

   for(i=0; s[i] != '\0'; i++ )
      alfa[s[i] - 'a'] ++;

   /*for(i=0; i<26; i++)
      printf("%3d ", alfa[i]);
   */
   indice = 0;
   Max = alfa[0];

   for(i=1; i<26; i ++){
      if(alfa[i] > Max){
         Max = alfa[i];
         indice =  i;
      }
   }

   return(indice + 'a');
   
}

int LetteraMag2(char *s){
   int alfa[26];
   int i;
   int indice;
   int Max;

   for(i=0; i<26; i++){
      alfa[i] = 0;
   }

   for(i=0; *(s+i) != '\0'; i++ )
      alfa[*(s+i) - 'a'] ++;

   /*for(i=0; i<26; i++)
      printf("%3d ", alfa[i]);
   */
   indice = 0;
   Max = alfa[0];

   for(i=1; i<26; i ++){
      if(alfa[i] > Max){
         Max = alfa[i];
         indice =  i;
      }
   }

   return(indice +'a');
   
}

int NumWord(char *s){
   int i;
   int cnt;

   cnt=0;
   if(*s != '\0'){
      cnt = 1;

      for(i=0; *(s+i) != '\0'; i++){
         if(*(s+i) == ' ')
            cnt++;
      }
   }
   return(cnt);
}

int CambiaCarattere(char *_s,char _src,char _dst){
   int i;
   int cnt;
   cnt=0;
   for(i=0;*(_s+i)!='\0';i++){
      if(*(_s+i)==_src){
         *(_s+i)=_dst;
         cnt++;
      }
   }
   return (cnt);
}

// DA TERMINARE //
void DividiParole(char *str){ //divide la stringa in singole parole e per ognuna visualizza la lunghezza
   int i;
   char buffer[101];

  // if(*str != '\0'){
 
   for(i=0;*(str+i)!=' ';i++){
      buffer[0] = *(str+i); // str+i *str+i *(str+i) *(str)+i
      if(*(str+i) ==' ')

   }
} 