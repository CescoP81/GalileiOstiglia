/*
   Realizzare un programma C che richieda una stringa da tastiera e determina se contiene delle doppie,
   es tetto, lotto, zappa.
*/
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Visualizzazione di una stringa tramite puntatore.
 * @param char* Puntatore alla stringa
 */
void viewString(char *);
/**
 * Funzione che determina la presenza di lettere doppie consecutive.
 * @param char* Puntatore alla stringa.
 * @return 1 Doppie presenti, 0  Doppie non presenti
 */
int findDoppie(char *);

int main(){
   /* creo un puntatore a stringa e successivamente alloco uno spazio per 100 caratteri 99+'\0'.
      l'area di memoria inizializzata non la riduco in caso la stringa sia più piccola dei
      100 caratteri massimi previsti.
   */
   char *s;
   s = (char *) malloc(sizeof(char) * 100);
   
   // acquisisco la stringa da tastiera.
   printf("Stringa: ");
   scanf("%s", s);
   fflush(stdin);

   // visualizzo la stringa passando il puntatore alla funzione
   viewString(s);

   // chiamo la funzione per la verifica delle doppie
   if(findDoppie(s))
      printf("\nLa parola %s contiene delle doppie.", s);
   else
      printf("\nLa parola %s non contiene delle doppie.", s);
   return(0);
}

// ---------------------------------
void viewString(char *_s){
   while(*_s != '\0'){
      printf("%c", *_s);
      _s = _s + 1;
   }
}

int findDoppie(char *_s){
   while(*_s != '\0' && *(_s+1) != '\0'){
      if(*_s == *(_s+1))
         return(1);
      _s = _s + 1;
   }
   return(0);
}