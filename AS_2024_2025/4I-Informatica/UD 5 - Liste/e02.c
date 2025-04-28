/*
    Esempio di base di costruzione e visualizzazione di una lista.
    - inserimento in testa.
    - visualizzazione della lista
    !! CON FUNZIONI !!
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int valore;
    struct Nodo* next;
}Nodo;

void vediLista(Nodo* _testa);
Nodo* pushTesta(Nodo* _testa, int _val);

int main(){
    Nodo *testa;
    Nodo *tmp;
    testa = NULL;

    testa = pushTesta(testa, 45);
    testa = pushTesta(testa, 56);
    testa = pushTesta(testa, 22);
    testa = pushTesta(testa, 89);
    vediLista(testa);

    printf("\n\n");
    testa = pushTesta(testa, 100);
    testa = pushTesta(testa, 1055);
    vediLista(testa);

    return(0);
}

void vediLista(Nodo* _testa){
    Nodo* tmp;
    // visualizzo la lista esistente con un ciclo
    tmp = _testa;                // faccio puntare TMP alla TESTA attuale della lista.
    printf("Testa: %d\n", tmp);
    while(tmp){
        printf("Addr: %d - Valore: %d - Next: %d\n", tmp, tmp->valore, tmp->next);
        tmp = tmp->next;
    }
}

Nodo* pushTesta(Nodo* _testa, int _val){
    Nodo *tmp;
    tmp = malloc(sizeof(Nodo)); // alloco in memoria un nuovo nodo e l'indirizzo lo assegno a tmp.
    tmp->valore = _val;           // assegno alla parte valore del nodo il numero 33.
    tmp->next = _testa;          // al puntatore al nodo successivo assegno la testa attuale.
    return(tmp); 
}