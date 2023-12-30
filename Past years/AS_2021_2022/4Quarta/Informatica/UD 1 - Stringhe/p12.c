/*
programma che contiene due funzioni che fanno:
- incolla_v1: funzione void che va a mettere nella prima stringa la seconda stringa
- incolla_v2: funzione char* che ritorna un puntatore alla terza stringa
*/
#include<stdio.h>
#include<stdlib.h>

#define DIM 100

void copy_to(char*, char*);

/**Funzione che ritorna la dimensione della stringa senza contare lo \0
* @param char* della prima cella della nostra stringa
* return int della dimensione della stringa
*/
int str_len(char*);

/**Funzione attacca alla prima stringa tramite uno spazio
* @param char* della prima cella della nostra stringa 1
* @param char* della prima cella della nostra stringa 2
* return void
*/
void incolla_v1(char*, char*);

/**Funzione che ritorna la cella iniziale di una stringa dato dall'unione delle due stringhe
* @param char* della prima cella della nostra stringa 1
* @param char* della prima cella della nostra stringa 2
* return char* della prima cella della terza stringa
*/
char* incolla_v2(char*, char*);

int main(){
   char* str1_access_pointer = (char*)malloc(sizeof(char)*DIM);
   char* str2_access_pointer = (char*)malloc(sizeof(char)*DIM);
   char* str3_access_pointer = NULL;

   //input delle due stringhe
   printf("\ninserisci stringa: ");
   gets(str1_access_pointer);
   fflush(stdin);

   printf("\ninserisci stringa: ");
   gets(str2_access_pointer);
   fflush(stdin);

   //la prima funzione
   incolla_v1(str1_access_pointer, str2_access_pointer);
   puts(str1_access_pointer);

   //la seconda funzione
   str3_access_pointer = incolla_v2(str1_access_pointer, str2_access_pointer);
   puts(str3_access_pointer);

   //libero le memorie
   free(str1_access_pointer);
   free(str2_access_pointer);
   free(str3_access_pointer);

   return (0);
}

void copy_to(char* source, char* destination){
   for(;*source!='\0';source++, destination++)
      *destination=*source;
   *destination='\0';
}

int str_len(char* p){
   int cnt = 0;
   for(;*p!='\0';p++)
      cnt++;
   return cnt;
}

void incolla_v1(char* p_str1, char* p_str2){
   /*0.devo re-allocare lo spazio della prima stringa in modo tale che ci stiano tutte e due le 
   stringhe + 2 (uno per lo spazio e uno per lo '\0'*/
   p_str1=(char*)realloc(p_str1, (str_len(p_str1)+str_len(p_str2)+2) * sizeof(char));

   //1.aggiungo uno spazio dopo la prima stringa sostituendo la \0 con lo spazio
   *(p_str1+str_len(p_str1))=' ';

   //2.aggiungo la seconda stringa alla prima stringa
   copy_to(p_str2, (p_str1+str_len(p_str1)));
}

char* incolla_v2(char* p_str1, char* p_str2){
   /*0.devo re-allocare lo spazio della TERZA STRINGA in modo tale che ci stiano tutte e due le 
   stringhe + 2 (uno per lo spazio e uno per lo '\0'*/
   char* p_str3=(char*)malloc((str_len(p_str1)+str_len(p_str2)+2) * sizeof(char));

   //1.per  prima cosa metto la prima stringa nel terzo buffer
   copy_to(p_str1, p_str3);

   //2.aggiungo uno spazio dopo la prima stringa sostituendo la \0 con lo spazio
   *(p_str3+str_len(p_str1))=' ';

   //3.aggiungo la seconda stringa alla terza stringa
   copy_to(p_str2, (p_str3+str_len(p_str1)+1));

   //4.ritorno della terza stringa creata
   return p_str3;
}
