/* Realizzare un programma che basandosi sulla struttura Persona
   formata dai campi {cognome[20], nome[20], int eta} permetta di:
   1- Acquisire due strutture come singole variabili (non un array).
   2- Visualizzare le due diverse strutture.
   3- Determinare quale delle due persone è più giovane.
   Realizzando un funzione per ogni richiesta.
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct{
   char cognome[20];
   char nome[20];
   int eta;
}Persona;

void initPersona(Persona *);
void printPersona(Persona);
int comparePersona(Persona, Persona);

int main()
{
   Persona p1;
   Persona p2;

   initPersona(&p1);
   printPersona(p1);
   
   initPersona(&p2);
   printPersona(p2);

   if(comparePersona(p1,p2) < 0)
      printf("Persona 1 e' piu' giovane tra i due.");
   else
      if(comparePersona(p1,p2) > 0)
         printf("Persona 2 e' piu' giovane tra i due.");
      else
         printf("Hanno la stessa eta'.");

   Persona *x;
   x = (Persona*) malloc(sizeof(Persona));
   (*x).eta = 19;
   printf("\n\n%d", (*x).eta);
   x->eta = 29;
   printf("\n\n%d", x->eta);

   return(0);
}

void initPersona(Persona *_p){
   printf("Cognome: ");
   scanf("%s", (*_p).cognome);
   fflush(stdin);
   printf("Nome: ");
   scanf("%s", (*_p).nome);
   fflush(stdin);
   printf("Eta': ");
   scanf("%d", &(*_p).eta);
   fflush(stdin);
}

void printPersona(Persona _p){
   printf("%s %s %d\n",_p.cognome, _p.nome, _p.eta);
}

int comparePersona(Persona _p1, Persona _p2){
   if(_p1.eta == _p2.eta)
      return(0);
   if(_p1.eta < _p2.eta)
      return(-1);
   if(_p2.eta < _p1.eta)
      return(1);  
}