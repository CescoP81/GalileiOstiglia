#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
   char titolo[30];
   char autore[30];
   int n_pagine;
}Libro;

int main(){
   Libro l;
   FILE *fp_in, *fp_out;
   char *filename="libreria.dat";
   char titolo[30];
   int scelta;
   
   do{
      printf("1. Inserisci libro nel file.\n");
      printf("2. Visualizza libri in elenco.\n");
      printf("3. Ricerca per titolo.\n");
      printf("0. Uscita.\n");
      printf("Scelta: ");
      scanf("%d", &scelta);
      fflush(stdin);

      switch(scelta){
         case 1:{
            // acquisisco la struttura dall'utente
            printf("Titolo: ");
            gets(l.titolo);
            fflush(stdin);
            printf("Autore: ");
            gets(l.autore);
            fflush(stdin);
            printf("Pagine: ");
            scanf("%d", &l.n_pagine);
            fflush(stdin);

            // apro il file in modalità 'a+' aggiunta/creazione
            fp_out = fopen(filename, "a+b");
               // scrivo la struttura sul file.
               fwrite(&l, sizeof(Libro), 1, fp_out);
            fclose(fp_out);
            break;
         }
         case 2:{
            // apro il file in lettura.
            printf("\n-- Elenco: --\n");
            fp_in = fopen(filename, "rb");
               while(fread(&l, sizeof(Libro), 1, fp_in)>0){
                  printf("%30s | %30s | %4d\n", l.titolo, l.autore, l.n_pagine);
               }
            fclose(fp_in);
            break;
         }
         case 3:{
            // richiedo il titolo da ricercare.
            int flag=0;
            printf("Cerca titolo: ");
            gets(titolo);
            fflush(stdin);

            // scorro il file e per ogni struttura letto confronto i titoli.
            fp_in = fopen(filename, "rb");
            while(fread(&l, sizeof(Libro), 1, fp_in) > 0){
               if(strcmp(l.titolo, titolo) == 0){ // restituisce zero se le stringhe sono uguali.
                  printf("Trovato: %s di %s nr. pagine %d\n", l.titolo, l.autore, l.n_pagine);
                  flag = 1;
               }
            }
            if(!flag)
               printf("Nessun libro a catalogo con il titolo specificato!\n");
            fclose(fp_in);
            break;
         }
      }
      printf("\n\n -- Premere un tasto per continuare --");
      getchar();
   }while(scelta != 0);
   return(0);
}