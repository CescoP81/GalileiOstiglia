#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Nodo{
    int valore;
    struct Nodo *next;
}Nodo;
// == PROTOTIPI
/**
 * Inserisce un nuovo nodo in testa alla lista
 * @param Nodo* Puntatore alla testa attuale.
 * @param int Valore da inserire nel nuovo nodo.
 * @return Indirizzo della nuova testa della lista
*/
Nodo* pushTesta(Nodo *_t, int _val);
/**
 * Estrae un nodo dalla testa della lista, esegue la FREE della memoria allocata.
 * @param Nodo* Puntatore alla testa attuale.
 * @return Nuovo indirizzo della testa.
*/
Nodo* popTesta(Nodo *_t);
/**
 * Aggiunge un nodo in coda alla lista.
 * @param Nodo* Riferimento alla testa.
 * @param int Valore numeri da inserire nella parte *->valore.
 * @return Riferimento alla nuova testa della lista.
*/
Nodo* pushCoda(Nodo *_t, int _v);
/**
 * Estrae un nodo dalla cosa della lista, verifica se la lista esiste, se è composta da un solo nodo
 * o se composta da più nodi.
 * @param Nodo* Riferimento alla testa della lista.
 * @return Riferimento alla nuova testa della lista.
*/
Nodo* popCoda(Nodo *_t);
/**
 * Visualizza la lista con iterativa
 * @param Nodo* Puntatore alla testa attuale.
*/
void showLista(Nodo *_t);
/**
 * Conta e restituisce il numero di nodi che compongono una lista.
 * @param Nodo* Puntatore alla testa attuale.
 * @return Numero nodi della lista.
*/
int contaElementiLista(Nodo *_t);
/**
 * Aggiunge un nuovo nodo nella posizione scelta, le posizioni devono essere specificate come 
 * numero intero positivo >=1. Se la posizione scelta è la 1 viene usata una pushTesta, se la posizione
 * è subito superiore al numero di elementi viene usata la pushCoda, in tutti gli altri casi si raggiunge
 * la posizione precedente a quella scelta e si innesta il nuovo nodo.
 * Richiede l'utilizzo della funzione contaElementiLista().
 * @param Nodo* Puntatore alla testa attuale.
 * @param int Posizione scelta per l'inserimento.
 * @param int Valore numeri da aggiungere alla lista.
 * @return Riferimento alla nuova testa della lista.
*/
Nodo* pushInPosizione(Nodo *_t, int _pos, int _val);
/**
 * Estrae un nodo nella posizione scelta, le posizioni devono essere specificate come 
 * numero intero positivo >=1. Se la posizione scelta è la 1 viene usata una popTesta, se la posizione
 * è l'ultima disponibile viene usata la popCoda, in tutti gli altri casi si raggiunge
 * la posizione precedente a quella scelta e si modifica il puntatore al nodo successivo.
 * Richiede l'utilizzo della funzione contaElementiLista().
 * @param Nodo* Puntatore alla testa attuale.
 * @param int Posizione scelta per l'inserimento.
 * @return Riferimento alla nuova testa della lista.
*/
Nodo* popInPosizione(Nodo *_t, int _pos);
// == MAIN PROGRAM
int main(){
    Nodo *testa;
    testa = NULL;
    
    testa = pushTesta(testa, 5);
    testa = pushTesta(testa, 10);
    testa = pushTesta(testa, 15);
    testa = pushTesta(testa, 20);
    showLista(testa);
    printf("\n\n");
    testa = pushInPosizione(testa, 3, 9);
    showLista(testa);
    testa = pushInPosizione(testa, 1, 18);
    showLista(testa);
    testa = pushInPosizione(testa, 7, 27);
    showLista(testa);
    // -- test della popInPosizione.
    testa = popInPosizione(testa, 1);
    showLista(testa);
    testa = popInPosizione(testa, contaElementiLista(testa));
    showLista(testa);
    testa = popInPosizione(testa, 10);
    showLista(testa);
    testa = popInPosizione(testa, 3);
    
    return(0);
}

// == FUNZIONI
Nodo* pushTesta(Nodo *_t, int _val){
    Nodo *tmp;      // puntatore temporaneo al nodo che andrò ad allocare.

    tmp = malloc(sizeof(Nodo)); // alloco un nodo in memoria e l'indirizzo lo assegno a tmp.
    tmp->valore = _val;
    tmp->next = _t;

    return(tmp);
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
Nodo* pushCoda(Nodo *_t, int _v){
    Nodo *tmp;

    if(_t == 0){    // sono in lista vuota.
        _t = malloc(sizeof(Nodo));
        _t->valore = _v;
        _t->next = 0;
        return(_t);
    }
    else{   // ho una lista con almeno un nodo
        tmp = _t;
        while(tmp->next != 0)
            tmp = tmp->next;
        
        tmp->next = malloc(sizeof(Nodo));
        tmp = tmp->next;
        tmp->valore = _v;
        tmp->next = 0;
        return(_t);
    }
}
Nodo* popCoda(Nodo *_t){
    Nodo *tmp;

    if(_t == 0){    // ricevo una testa vuota -> nessun nodo.
        printf("Lista vuota.\n");
    }

    if(_t->next!= 0){ // ho almeno due nodi
        tmp = _t;
        while(tmp->next->next != 0)
            tmp = tmp->next;
        printf("Esce il valore: %d-\n", tmp->next->valore);
        free(tmp->next);
        tmp->next = 0;
    }
    else{   // ho un nodo solamente da liberare.
        printf("Esce il valore: %d\n", _t->valore);
        free(_t);
        _t = 0;
    }
    return(_t);
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
Nodo* pushInPosizione(Nodo *_t, int _pos, int _val){
    Nodo *tmp;  // utilizzato per il nodo da aggiungere
    Nodo *head; // utilizzato per scorrere la lista e non perdere la testa ricevuta che dovrò ritornare.
    int i;
    if(_pos<=0 || _pos>(contaElementiLista(_t)+1)){
        // se verificato l'indice è sbagliato perchè o minore di zero, o superiore all'ultima posizione della lista
        printf("Impossibile inserire, posizione errata o inesistente.\n");
        return(_t);
    }
    // se mi viene chiesto di inserire in posizione 1, quindi in testa, utilizzo la funzione già creata.
    if(_pos == 1){
        _t = pushTesta(_t, _val);
        return(_t);
    }
    // se mi viene chiesta la posizione dopo l'ultima, utilizzo la push coda.
    if(_pos == contaElementiLista(_t)+1){
        _t = pushCoda(_t, _val);
        return(_t);
    }
    // in tutti gli altri casi mi viene chiesta una posizione dalla 2 all'ultima,
    // quindi procedo con un ciclo per posizionarmi sulla posizione prima di quella scelta ed inserisco il nodo.
    head = _t;
    for(i=1; i<_pos-1; i++){
        head = head->next;
    }
    tmp = malloc(sizeof(Nodo));
    tmp->next = head->next;
    tmp->valore = _val;
    head->next = tmp;
    return(_t);
}
Nodo* popInPosizione(Nodo *_t, int _pos){
    Nodo *tmp;
    Nodo *head;
    int i;

    if(_pos<=0 || _pos>contaElementiLista(_t)){
        // se verificato l'indice è sbagliato perchè o minore di zero, o superiore all'ultima posizione della lista
        printf("Impossibile estrarre, posizione errata o inesistente.\n");
        return(_t);
    }
    if(_pos == 1){
        // se voglio togliere la prima posizione utilizzo la poptesta già realizzata.
        _t = popTesta(_t);
        return(_t);
    }
    if(_pos == contaElementiLista(_t)){
        // se voglio togliere l'ultimo elemento utilizzo la popCoda già realizzata.
        _t = popCoda(_t);
        return(_t);
    }

    // se arrivo qui la posizione è interna alla lista, raggiungo il nodo precedente a quello da
    // eliminare e modifico i puntatori.
    head = _t;
    for(i=1; i<_pos-1; i++){
        head = head->next;
    }
    tmp = head->next;
    head->next = tmp->next;
    printf("Esce il valore: %d\n", tmp->valore);
    free(tmp);

    return(_t);
}