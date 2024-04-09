#include <stdio.h>
#include <stdlib.h>
// dichiaro la struttura per la creazione dei nodi.
typedef struct Nodo{
    int valore;
    struct Nodo *next;
}Nodo;

int main(){
    // dichiaro un puntatore testa 't' che punterà al primo nodo della lista.
    Nodo *t;
    Nodo *tmp;
    t = 0;  // inizializziamo a zero il puntatore.

    // creo il primo nodo della lista
    t = malloc(sizeof(Nodo));
    // imposto la parte valore del nodo creato con un valore a mia scelta
    t->valore = 77;
    // imposto la parte next del nodo a zero così da indicarlo come nodo finale.
    t->next = 0;

    // inserimento di un nuovo nodo in testa alla lista.
    tmp = malloc(sizeof(Nodo));
    tmp->valore = 66;
    tmp->next = t;
    t = tmp;

    // inserimento di un nuovo nodo in testa alla lista.
    tmp = malloc(sizeof(Nodo));
    tmp->valore = 55;
    tmp->next = t;
    t = tmp;
    // inserimento di un nuovo nodo in testa alla lista.
    tmp = malloc(sizeof(Nodo));
    tmp->valore = 106;
    tmp->next = t;
    t = tmp;

    // per visualizzare la lista utilizzo un puntatore temporaneo ed un ciclo while.
    tmp = t;
    printf("Testa: %d -> \n", t);
    while(tmp != 0){
        //printf("%d -> ", tmp->valore);
        printf("Add: %d - Val: %d - next: %d\n", tmp, tmp->valore, tmp->next);
        tmp = tmp->next;
    }


    return(0);
}