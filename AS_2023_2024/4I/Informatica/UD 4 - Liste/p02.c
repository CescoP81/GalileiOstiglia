#include<stdio.h>
#include<stdlib.h>

typedef struct Nodo{
    int valore;
    struct Nodo *next;
}Nodo;

/**
 * Inserisce un nuovo nodo in testa alla lista
 * @param Nodo* Puntatore alla testa attuale.
 * @param int Valore da inserire nel nuovo nodo.
 * @return Indirizzo della nuova testa della lista
*/
Nodo* pushTesta(Nodo *_t, int _val);
/**
 * Visualizza la lista con iterativa
 * @param Nodo* Puntatore alla testa attuale.
*/
void showLista(Nodo *_t);
/**
 * Visualizza la lista con funzione ricorsiva -> richiami successivi finche puntate != 0
 * @param Nodo* Puntatore alla testa attuale.
*/
void showListaRicorsiva(Nodo *_t);
/**
 * Estrae un nodo dalla testa della lista, esegue la FREE della memoria allocata.
 * @param Nodo* Puntatore alla testa attuale.
 * @return Nuovo indirizzo della testa.
*/
Nodo* popTesta(Nodo *_t);
/**
 * Conta e restituisce il numero di nodi che compongono una lista.
 * @param Nodo* Puntatore alla testa attuale.
 * @return Numero nodi della lista.
*/
int contaElementiLista(Nodo *_t);
/**
 * Trova a restituisce la posizione del valore _src all'interno della lista
 * @param Nodo* Puntatore alla testa attuale.
 * @param int Valore da ricercare.
 * @return Posizione del nodo che contiene _src, altrimenti -1.
*/
int ricercaElemento(Nodo *_t, int _src);

int main(){
    Nodo *head;     // creo un puntatore al primo nodo della lista.
    head = 0;       // l'indirizzo puntato lo imposto a zero come inizializzazione.

    showLista(head);
    // push in testa di 3 valori
    head = pushTesta(head, 22);
    showLista(head);
    head = pushTesta(head, 10);
    showLista(head);
    head = pushTesta(head, 40);
    showLista(head);
    printf("\nLista ricorsiva: ");
    showListaRicorsiva(head);
    printf("\n\n");
    printf("Nodi presenti: %d\n", contaElementiLista(head));
    
    /*
    head = popTesta(head);  // toglie il 40
    showLista(head);
    head = popTesta(head);  // toglie il 35
    head = popTesta(head);  // toglie il 22 -> head avrà valore 0
    head = popTesta(head);  // dovrei vedere Lista vuota.
    printf("Nodi presenti: %d\n", contaElementiLista(head));
    */

    printf("\n\n");
    if(ricercaElemento(head, 15) != -1)
        printf("Elemento 15 trovato in posizione %d\n", ricercaElemento(head, 15));
    else
        printf("Valore non trovato\n");

    if(ricercaElemento(head, 10) != -1)
        printf("Elemento 10 trovato in posizione %d\n", ricercaElemento(head, 10));
    else
        printf("Valore non trovato\n");

    return(0);
}

Nodo* pushTesta(Nodo *_t, int _val){
    Nodo *tmp;      // puntatore temporaneo al nodo che andrò ad allocare.

    tmp = malloc(sizeof(Nodo)); // alloco un nodo in memoria e l'indirizzo lo assegno a tmp.
    tmp->valore = _val;
    tmp->next = _t;

    return(tmp);
}

void showLista(Nodo *_t){
    Nodo *tmp;
    if(_t == 0){
        printf("Lista vuota.\n");
    }
    else{
        printf("Elementi della lista: ");
        tmp = _t;
        while(tmp != 0){     // (tmp != 0)
            printf("%d ", tmp->valore);
            tmp = tmp->next;
        }
        printf("\n");
    }
}

void showListaRicorsiva(Nodo *_t){
    if(_t != 0){
        printf("%d ", _t->valore);
        showListaRicorsiva(_t->next);
    }
}

Nodo* popTesta(Nodo *_t){
    Nodo *tmp;

    if(_t != 0){    // Verifico di avere almeno un nodo da deallocare.
        tmp = _t->next;
        printf("Esce il valore: %d\n", _t->valore);
        free(_t);
        return(tmp);
    }
    else{
        printf("Lista vuota.\n");
        return(0);
    }
}

int contaElementiLista(Nodo *_t){
    Nodo *tmp;
    int cnt;

    tmp = _t;
    cnt = 0;
    while(tmp != 0){
        cnt++;
        tmp = tmp->next;
    }
    return(cnt);
}

int ricercaElemento(Nodo *_t, int _src){
    Nodo *tmp;
    int pos;

    tmp = _t;
    pos = 0;
    while(tmp != 0){
        pos = pos + 1;
        if(tmp->valore == _src){
            return(pos);
        }
        tmp = tmp->next;
    }
    return(-1);
}