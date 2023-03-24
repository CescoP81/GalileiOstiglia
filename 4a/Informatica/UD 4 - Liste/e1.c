#include <stdio.h>
#include <stdlib.h>

// Definizione dells truttura Nodo
typedef struct nodo{
    int val;
    struct nodo *next;
}Nodo;

// Dichiarazione dei prototipi
Nodo* addTesta(Nodo *, int);
void showLista(Nodo *);
void showListaRecursive(Nodo *);
void showListaReversedRecursive(Nodo *);

// ### MAIN PROOGRAM ###
int main(){
    Nodo *t;        // puntatore alla testa della lista.
    t = NULL;       // inizialmente punta a NULL (nessuna lista creata)

    // eseguo tre inserimenti di prova.
    t = addTesta(t, 5);
    t = addTesta(t, 7);
    t = addTesta(t, 9);

    // eseguo la chiamata della funzione di visualizzazione della lista.
    showLista(t);
    printf("\n\n");
    showListaRecursive(t);
    printf("\n\n");
    showListaReversedRecursive(t);

    return(0);
}

// Definizione delle funzioni
Nodo* addTesta(Nodo *_testa, int _val){
    Nodo *tmp;
    tmp = malloc(sizeof(Nodo));
    tmp->next = _testa;
    tmp->val = _val;
    return(tmp);
}

void showLista(Nodo *_testa){
    Nodo *tmp;
    tmp = _testa;
    while(tmp != NULL){
        printf("Address: %d; val: %d, next: %d\n", tmp, tmp->val, tmp->next);
        tmp = tmp->next;
    }
}
/*
Address: 11605616; val: 9, next: 11612120
Address: 11612120; val: 7, next: 11612104
Address: 11612104; val: 5, next: 0
*/

void showListaRecursive(Nodo *_tmp){
    if(_tmp != NULL){
        printf("Address: %d; val: %d, next: %d\n", _tmp, _tmp->val, _tmp->next);
        showListaRecursive(_tmp->next);
    }
}
void showListaReversedRecursive(Nodo *_tmp){
    if(_tmp != NULL){
        showListaReversedRecursive(_tmp->next);
        printf("Address: %d; val: %d, next: %d\n", _tmp, _tmp->val, _tmp->next);        
    }
}