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

/**
 * Visualizza la lista
 * @param Nodo* Riferimento alla testa della lista
 */
void vediLista(Nodo* _testa);
/**
 * Inserisce un nuovo nodo come testa della lista, riceve la testa e il valore da inserire come parametri. 
 * @param Nodo* Riferimento alla testa della lista. 
 * @param int Valore da inserire come informazione nel nodo. 
 * @return Riferimento alla nuova testa della lista. 
 */
Nodo* pushTesta(Nodo* _testa, int _val);

/*## MAIN PROGRAM ## */
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

/*## SVILUPPO FUNZIONI ## */
void vediLista(Nodo* _testa){
    Nodo* tmp;
    // visualizzo la lista esistente con un ciclo
    tmp = _testa;                // faccio puntare TMP alla TESTA attuale della lista.
    printf("Testa: %d\n", tmp);
    while(tmp != NULL){
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