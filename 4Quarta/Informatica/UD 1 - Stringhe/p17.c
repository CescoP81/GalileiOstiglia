/*
   Scrivere un programma che richiede l'inserimento consecutivo di stringhe finche
   non viene inserita la stringa 'fine' in quel caso il programma termina comunicando
   la stringa più lunga e più corta inserita.
*/
#include <conio.h>
#include <stdio.h>
#define DIM 20

int strLength(char[]);
void strCopy(char[], char[]);
int checkFine(char[], char []);

int main(){
   char parola[DIM];    // parola inserita di volta in volta dall'utente.
   int lmax;            // lunghezza della parola più lunga.
   char pmax[DIM];      // parola più lunga inserita.
   int lmin;            // lunghezza della parola più corta.
   char pmin[DIM];      // parola più corta inserita.
   char fine[5]={'f','i','n','e','\0'};

   lmin = DIM;            // azzero le due variabili che contengono lunghezza minore e maggiore.
   lmax = 0;
   do{
      // inserisco la parola
      printf("\nParola: ");
      scanf("%s", parola);
      fflush(stdin);

      if(!checkFine(parola, fine)){
         if(strLength(parola) > lmax){
            lmax = strLength(parola);
            strCopy(parola, pmax);
         }
         if(strLength(parola) < lmin){
            lmin = strLength(parola);
            strCopy(parola, pmin);
         }
      }
   }while(!checkFine(parola, fine));

   printf("\n\n");
   printf("\nParola %s -> lunga: %d",pmin,lmin);
   printf("\nParola %s -> lunga: %d",pmax,lmax);
   return(0);
   /*printf("%d", strLength(parola));
   strCopy(parola, pmax);
   printf("\n\n%s", pmax);
   printf("\n\n%d", checkFine(parola, fine));*/
}

int strLength(char st[]){
   int i;
   i=0;
   while(st[i] != '\0')
      i++;
   return(i);
}

void strCopy(char src[], char dst[]){
   int i;
   i=0;
   while(src[i]!='\0'){
      dst[i] = src[i];
      i++;
   }
   dst[i] = '\0';
}

int checkFine(char st[], char check[]){
   int i;
   if(strLength(st) != 4)
      return(0);
   else{
      i=0;
      while(st[i] != '\0'){
         if(st[i] != check[i])
            return(0);
         i++;
      }
      return(1);
   }
}