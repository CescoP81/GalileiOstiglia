/*
    Esempio di base di costruzione e visualizzazione di una lista.
    - inserimento in testa.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int valore;
    struct Nodo* next;
}Nodo;

int main(){
    Nodo *testa;
    Nodo *tmp;
    testa = NULL;

    // creo il primo nodo della lista
    tmp = malloc(sizeof(Nodo)); // alloco in memoria un nuovo nodo e l'indirizzo lo assegno a tmp.
    tmp->valore = 33;           // assegno alla parte valore del nodo il numero 33.
    tmp->next = testa;          // al puntatore al nodo successivo assegno la testa attuale.
    testa = tmp;                // assegno alla testa l'indirizzo del nodo appena creato. 

    // ripeto le istruzioni di creazione di un nodo per altre tre volte.
    tmp = malloc(sizeof(Nodo)); // alloco in memoria un nuovo nodo e l'indirizzo lo assegno a tmp.
    tmp->valore = 37;           // assegno alla parte valore del nodo il numero 33.
    tmp->next = testa;          // al puntatore al nodo successivo assegno la testa attuale.
    testa = tmp;

    tmp = malloc(sizeof(Nodo)); // alloco in memoria un nuovo nodo e l'indirizzo lo assegno a tmp.
    tmp->valore = 44;           // assegno alla parte valore del nodo il numero 33.
    tmp->next = testa;          // al puntatore al nodo successivo assegno la testa attuale.
    testa = tmp;

    tmp = malloc(sizeof(Nodo)); // alloco in memoria un nuovo nodo e l'indirizzo lo assegno a tmp.
    tmp->valore = 99;           // assegno alla parte valore del nodo il numero 33.
    tmp->next = testa;          // al puntatore al nodo successivo assegno la testa attuale.
    testa = tmp;

    // visualizzo la lista esistente con un ciclo
    tmp = testa;                // faccio puntare TMP alla TESTA attuale della lista.
    printf("Testa: %d\n", tmp);
    while(tmp){
        printf("Addr: %d - Valore: %d - Next: %d\n", tmp, tmp->valore, tmp->next);
        tmp = tmp->next;
    }

    return(0);
}