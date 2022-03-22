/*
Realizzare un programma che gestisca una lista dove ogni nodo è composto da una
struttura persona identificata da nome, cognome, età.
Il programma deve prevedere l'inserimento in coda di nuovi nodi con input da tastiera,
prima di uscire dal programma tutti i nodi devono essere salvati su di un file,
successivamente deve essere possibile caricare i nodi da un file.
*/
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct persona{
   char nome[30];
   char cognome[30];
}Persona;

typedef struct nodo{
   Persona p;
   struct Nodo* next;
}Nodo;

void addTesta(Nodo **, Persona);
void vediLista(Nodo *);

int main(){
   Persona p;
   Nodo *head = NULL;
   int i;

   for(i=0; i<3; i++){
      printf("Cognome: ");
      scanf("%s", p.cognome);
      fflush(stdin);
      printf("Nome: ");
      scanf("%s", p.nome);
      fflush(stdin);
      addTesta(&head, p);
   }
   printf("\n\n");
   vediLista(head);
   return(0);
}

void addTesta(Nodo **t, Persona x){
   Nodo *tmp = (Nodo*) malloc(sizeof(Nodo));
   tmp->next = *t;
   tmp->p = x;
   *t = tmp;
}
void vediLista(Nodo *t){
   if(t != NULL){
      printf("%s %s\n", t->p.cognome, t->p.nome);
      vediLista(t->next);
   }
}