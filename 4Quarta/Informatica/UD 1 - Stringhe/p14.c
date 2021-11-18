/*
   Auth: Pradella F.
   Date: 18.11.2021 
   File: p14.c
   Descr: Accesso e copia caratteri da vettore di char a stringa
   allocata dinamicamente.
*/
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define DIM 20
void InputStringa(char []);            // funzione per input stringa come vettore di caratteri.
char* NuovaStringa(char [], char*);    // funzione che alloca una stringa e restituisce il puntatore al main.
void NuovaStringa_2(char [], char**);  // funzione che alloca e modifica una stringa nel main. (use del puntatore a puntatore)

int main(){
   char stringa[DIM];
   char* pstringa;
   char* pstringa2;

   InputStringa(stringa);
   printf("stringa inserita: %s", stringa);

   pstringa = NuovaStringa(stringa, pstringa);
   printf("\n\nStringa allocata/copiata: %s", pstringa); 

   NuovaStringa_2(stringa, &pstringa2);
   printf("\n\nStringa 2: %s", pstringa2);

return(0);   
}

void InputStringa(char str[]){

   printf("Inserisci una stringa (max 19 caratteri): ");
   scanf("%s", str);
   fflush(stdin);

}

char* NuovaStringa(char str[], char* pstr){ //str sempre 20, pstr dimensione stringa e contenuto
   int i;
   int cnt;

   //1. calcolare lunghezza reale della stringa in str
   i = 0;
   cnt = 0;
   while(str[i]!= '\0'){
      cnt++;
      i++;
   }
   //2. allocazione della reale lunghezza della stringa in pstr + '\0'
   printf("%d", cnt);
   pstr =(char *) malloc(sizeof(char) * (cnt+1));

   //3. copia dei caratteri da str a pstr
   for(i=0; i<cnt; i++){
      *(pstr+i) = str[i];
   }
   *(pstr+i) = '\0';
   return(pstr);
}

void NuovaStringa_2(char str[], char** ppstr){
   int i;
   int cnt;

   //1. calcolare lunghezza reale della stringa in str
   i = 0;
   cnt = 0;
   while(str[i]!= '\0'){
      cnt++;
      i++;
   }

   // 2.
   *ppstr = malloc(sizeof(char) * (cnt+1));

   // 3.
   for(i=0; i<cnt; i++){
      *(*ppstr+i) = str[i];
   }
   *(*ppstr+i) = '\0';
   //printf("%s", *ppstr);
}