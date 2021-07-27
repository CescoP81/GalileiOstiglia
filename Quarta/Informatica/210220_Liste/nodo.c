#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct nodo{
    int value;
    struct nodo* next;
}Nodo;
/*aggiunge un elemento in testa 
@param Nodo* riceve un puntatore a struttura di tipo Nodo
@param int valore della nuova testa
@return Nodo* ritorna l'indirizzo della nuova testa 
*/ 
Nodo* pushTesta(Nodo* t, int n){
    Nodo* newhead = (Nodo*) malloc(sizeof(Nodo));
    newhead->value = n;
    newhead->next = t;
    return newhead;
}

/*toglie un elemento in testa 
@param Nodo* riceve un puntatore a struttura di tipo Nodo
@return Nodo* ritorna l'indirizzo della nuova testa 
*/ 
Nodo* popTesta(Nodo* t){
    Nodo* tmp;
    if(t != NULL){
        tmp = t;
        t = t->next;
        free(tmp);
    }
    return(t);
}

/*aggiunge un elemento in coda 
@param Nodo* riceve un puntatore a struttura di tipo Nodo
@param int valore della nuova testa
@return Nodo* ritorna l'indirizzo della nuova testa 
*/ 
Nodo* pushCoda(Nodo* t, int n){
    if(t == NULL){
        Nodo* tmp = (Nodo*) malloc(sizeof(Nodo));
        tmp->value = n;
        tmp->next = NULL;
        return(tmp);
    }
    else{
        Nodo* tmp;
        tmp = t;
        // mi sposto fino all'ultimo nodo.
        while(tmp->next != NULL){
            tmp = tmp->next;
        }

        // alloco un nuovo nodo e assegno il suo indirizzo alla parte next dell'ultimo nodo
        tmp->next = (Nodo*) malloc(sizeof(Nodo));
        
        // mi sposto il tmp sull'ultimo nodo creato.
        tmp = tmp->next;
        
        // imposto il valore nell'ultimo nodo.
        tmp->value = n;
        // !!! metto a null il next dell'ultimo nodo per chiudere la lista.
        tmp->next = NULL;
        return(t);
    }
}

/*toglie un elemento in testa 
@param Nodo* riceve un puntatore a struttura di tipo Nodo
@return Nodo* ritorna l'indirizzo della nuova testa 
*/ 
Nodo* popCoda(Nodo* t){
    Nodo* tmp;
    if(t != NULL){
        if(t->next == NULL){
            tmp = t;
            t = NULL;
            free(tmp);
        }
        else{
            tmp = t;
            while(tmp->next->next != NULL)
                tmp = tmp->next;
            
            free(tmp->next);
            tmp->next = NULL;
        }
    }
    return(t);
}

/*stampa la lista 
@param Nodo* riceve un puntatore a struttura di tipo Nodo 
*/ 
void stampaLista(Nodo* t){
    if(t != NULL){
        printf("nodo[%d]: %d --> %d\n", t, t->value, t->next);
        stampaLista(t->next);
    }
}

/*stampa la lista 
@param Nodo* riceve un puntatore a struttura di tipo Nodo
@return int numero di nodi che compongono la lista.
*/
int contaNodi(Nodo* t){
    int cnt;

    cnt = 0;
    while(t != NULL){
        cnt++;
        t = t->next;
    }
    return(cnt);
}

/* Restituisce la somma totale delle parti value dei singoli nodi. 
@param Nodo* riceve un puntatore a struttura di tipo Nodo
@return int Somma totale delle parti value
*/
int sommaLista(Nodo* t){
    int somma;

    somma = 0;
    while(t != NULL){
        somma = somma + t->value;
        t = t->next;
    }
    return(somma);
}

/*Funzione di push in posizione scelta dall'utente.
@param Nodo* Puntatore alla testa attuale.
@param int Posizione scelta da 1 a n.
@param int valore da inserire nel nuovo nodo.
*/
Nodo* pushPosizione(Nodo* t, int p, int v){
    if(p == 1){
        /*Nodo* tmp;
        tmp = pushTesta(t, v);
        */
        // ## UTILIZZARE UNA PUSH IN TESTA
        Nodo* tmp;
        tmp = (Nodo*) malloc(sizeof(Nodo));
        tmp->value = v;
        tmp->next = t;
        return(tmp);
    }
    if(p == contaNodi(t)+1){
        // ## UTILIZZARE UNA PUSH IN CODA
        Nodo* tmp;
        tmp = t;
        while(tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = (Nodo*) malloc(sizeof(Nodo));
        tmp = tmp->next;
        tmp->value = v;
        tmp->next = NULL;
        return(t);
    }
    if(p <= contaNodi(t)){
        int i;
        Nodo* tmp;
        Nodo* tmp2;
        
        tmp = t;
        for(i=1; i<p-1; i++)
            tmp = tmp->next;
        
        tmp2 = (Nodo*) malloc(sizeof(Nodo));
        tmp2->next = tmp->next;
        tmp2->value = v;
        tmp->next = tmp2;
        return(t);
    }
    if(p > contaNodi(t)){
        printf("\nErrore, nodo non presente\n");
        return(t);
    }
}