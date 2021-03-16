#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct libro{
    char titolo[20];
    int npagine;
}Libro;

typedef struct nodo{
    Libro *lib; // potrei anche fare Libro l -> Quindi alla malloc di un nodo ottengo anche una variabile di tipo Libro.
    struct nodo* next;
}Nodo;
// -- PROTOTIPI --
void addNodoTesta(Nodo **_l, char *_t, int _pag);
void addNodoCoda(Nodo *_l, char *_t, int _pag);
void printLista(Nodo *_l);

// -- MAIN --
int main(){
    Nodo *list;
    list = NULL;

    addNodoTesta(&list, "Baricco", 156);
    addNodoTesta(&list, "Pippi Bella", 200);
    addNodoTesta(&list, "Il Metalmeccanico", 80);

    addNodoCoda(list, "Lo Specialista",150);
    printLista(list);

    return(0);
}

// -- FUNZIONI --
void addNodoTesta(Nodo **_l, char *_t, int _pag){
    Nodo *tmp;
    tmp = (Nodo *) malloc(sizeof(Nodo));

    // assegnamo al nodo-> next la testa esistente.
    tmp->next = *_l;

    // allochiamo un nuovo libro nel nodo
    tmp->lib = (Libro*) malloc(sizeof(Libro));
    // impostiamo i campi del nuovo libro con quelli passati per parametro.
    strcpy(tmp->lib->titolo, _t);
    tmp->lib->npagine = _pag;

    *_l = tmp;
}

void addNodoCoda(Nodo *_l, char *_t, int _pag){
    // ciclo per fermarmi sull'ultimo nodo della lista.
    while(_l->next != NULL)
        _l = _l->next;
    
    _l->next = (Nodo *) malloc(sizeof(Nodo));
    _l = _l->next;

    _l->next = NULL;
    _l->lib = (Libro *) malloc(sizeof(Libro));
    strcpy(_l->lib->titolo, _t);
    _l->lib->npagine = _pag;
}

void printLista(Nodo *_l){
    while(_l){
        printf("%s %d\n", _l->lib->titolo, _l->lib->npagine);
        _l = _l->next;
    }
}