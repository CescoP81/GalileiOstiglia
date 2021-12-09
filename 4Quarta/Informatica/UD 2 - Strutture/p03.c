/*
   Programma di gestione di una semplice rubrica telefonica.
*/
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DIM_CONTATTI 2

typedef struct{
   char nome[20];
   char cognome[20];
   char telefono[10];
   char mail[128];
}Persona;

void addPersona(Persona[], int, char[], char[], char[], char[]);
void showRubrica(Persona[], int);

int main(){
   Persona rubrica[DIM_CONTATTI];
   int cnt_contatti;
   int scelta;

   cnt_contatti = 0;
   do{
      printf("Slot occupati %d di %d\n", cnt_contatti, DIM_CONTATTI);
      printf("1. Aggiungi contatto.\n");
      printf("2. Vedi contatti.\n");
      printf("3. Cancella contatto.\n");
      printf("4. Rircerca contatto.\n");
      printf("5. Modifica contatto.\n");
      printf("0. USCITA\n");
      printf("Scelta: ");
      scanf("%d", &scelta);
      fflush(stdin);

      switch(scelta){
         case 1:{
            char n[20], c[20], t[20], m[128];
            if(cnt_contatti < DIM_CONTATTI){
               printf("Cognome: ");
               scanf("%s", c);
               fflush(stdin);
               printf("Nome: ");
               scanf("%s", n);
               fflush(stdin);
               printf("Telefono: ");
               scanf("%s", t);
               fflush(stdin);
               printf("E-mail: ");
               scanf("%s", m);
               fflush(stdin);
               addPersona(rubrica, cnt_contatti, n, c, t, m);
               cnt_contatti++;
            }
            else{
               printf("!! Errore! Slot esauriti.!!\n\n");
            }
            break;
         }
         case 2:{
            showRubrica(rubrica, cnt_contatti);
            break;
         }
         case 3:{
            break;
         }
         case 4:{
            break;
         }
         case 5:{
            break;
         }
      }
      printf("\n\n -- PREMERE UN TASTO -- \n\n");
      system("PAUSE");
   }while(scelta != 0);
}

void addPersona(Persona _r[], int _cnt, char _n[], char _c[], char _t[], char _m[]){
   strcpy(_r[_cnt].nome, _n);
   strcpy(_r[_cnt].cognome, _c);
   strcpy(_r[_cnt].telefono, _t);
   strcpy(_r[_cnt].mail, _m);
}

void showRubrica(Persona _r[], int _cnt){
   int i;
   printf("Persone presenti:\n\n");
   for(i=0; i<_cnt; i++){
      printf("%s %s %s %s\n", _r[i].cognome, _r[i].nome, _r[i].telefono, _r[i].mail);
   }
}