/**
 * Realizzare un programma che richiede una stringa composta da più
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

int main(){
   char *s;
   s = malloc(sizeof(char)*10);

   printf("Inserisci la frase: ");
   gets(s);
   fflush(stdin);

   printf("\n\n");
   printf("%s", s);

   return(0);
}