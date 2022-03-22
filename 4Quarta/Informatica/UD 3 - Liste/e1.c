/*
Creare un programma che gestisca una lista formata da un numero non definito a priori
di Nodi, ogni nodo contiene un valore intero ed un puntatore al nodo successivo.
Realizzare le seguenti operazioni di base:
- Inserimento di un nodo in testa alla lista.
- Inserimento di un nodo in coda alla lista.
- Scorrimento (visualizzazione di tutta la lista).
- Conteggio elementi di una lista.
- Ricerca di un elemento nella lista (valore intero).
- Estrazione di un nodo dalla testa della lista.
- Estrazione di un nodo dalla coda della lista.
Realizzare per ogni punto una FUNZIONE con i dovuti parametri per gestire la lista.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
   int value;
   struct Nodo *next;
};