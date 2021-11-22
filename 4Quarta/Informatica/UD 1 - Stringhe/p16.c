#include <stdio.h>
#include <conio.h>

#define DIM 20

int analStringa(char*, char*);

int lungStringa(char*);

int cambStringa(char[], char, char);

void specchiaStringa(char[]);

int main(){
   char stringa[DIM];
   char stringa1[DIM];
   char car1;
   char car2;
   int cont=0;

   printf("Inserisci stringa: ");
   scanf("%s", stringa);
   fflush(stdin);

   printf("Inserisci stringa1: ");
   scanf("%s", stringa1);
   fflush(stdin);

   if(analStringa(stringa, stringa1)==1){
      printf("\nLe stringhe sono anagrammi.");
   }

   else{
      printf("\nLe stringhe non sono anagrammi.");
   }

   printf("\n\n");

   printf("Carattere da cambiare: ");
   scanf("%c", &car1);
   fflush(stdin);

   printf("Carattere da sostituire: ");
   scanf("%c", &car2);
   fflush(stdin);

   cont = cambStringa(stringa, car1, car2);

   printf("\nNuova stringa: %s ==> Numero cambi: %d\n\n", stringa, cont);

   specchiaStringa(stringa);

   getchar();
   return(0);
}

int lungStringa(char *s){
   int i=0;

   while(*(s+i)!='\0'){
      i++;
   }

   return(i);
}

int analStringa(char *s, char *s1){
   int check[26];
   int i;

   for(i=0; i<26; i++){
      check[i] = 0;
   }

   if(lungStringa(s) == lungStringa(s1)){
      i=0;

      while(*(s+i)!='\0'){
         check[*(s+i)-'a']++;
         i++;
      }

      /*for(i=0; i<26; i++){
         printf("%d ", check[i]);
      }*/

      i = 0;

      while(*(s1+i)!='\0'){
         check[*(s1+i)-'a']--;
         i++;
      }   

      /*for(i=0; i<26; i++){
         printf("%d ", check[i]);
      }*/

      for(i=0; i<26; i++){
         if(check[i]!=0){
            return(0);
         }
      }

      return(1);
   }

   else{
      return(0);
   }
}

int cambStringa(char s[], char c1, char c2){
   int i=0;
   int cnt=0;

   for(i=0; s[i]!='\0'; i++){
      if(s[i]==c1){
         s[i] = c2;
         cnt++;
      }
   }

   return(cnt);
}

void specchiaStringa(char s[]){
   int i; 
   for(i=lungStringa(s) - 1; i >= 0; i --){
      printf("%c", s[i]);
   }
}