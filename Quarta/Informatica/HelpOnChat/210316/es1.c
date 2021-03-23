#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
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
void printListaR(Nodo *_l);
int findTitoloLibro(Nodo *_l, char *_t);
Nodo* getDatiLibro(Nodo *_l, char *_t);
Libro* getDatiLibro2(Nodo *_l, char *_t);

// -- MAIN --
int main(){
    Nodo *list;
    list = NULL;
    int pos;

    addNodoTesta(&list, "Baricco", 156);
    addNodoTesta(&list, "Pippi Bella", 200);
    addNodoTesta(&list, "Il Metalmeccanico", 80);

    addNodoCoda(list, "Lo Specialista",150);
    
    printLista(list);
    printf("\n\n");
    printListaR(list);

    printf("\n\n");

    //pos=findTitoloLibro(list, "Baricco");
    if(findTitoloLibro(list, "Baricco") != -1)
        printf("Titolo trovato in posizione %d\n", findTitoloLibro(list, "Baricco"));
    else
        printf("No titolo.");
    
    Nodo *nodoTrovato;
    nodoTrovato = getDatiLibro(list, "Baricco");
    if(nodoTrovato)
        printf("%s %d", nodoTrovato->lib->titolo, nodoTrovato->lib->npagine);
    
    printf("\n\n");

    Libro *libroTrovato;
    libroTrovato = getDatiLibro2(list, "Baricco");
    if(libroTrovato)
        printf("%s %d", libroTrovato->titolo, libroTrovato->npagine);
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
// stampa iterativa con ciclo
void printLista(Nodo *_l){
    while(_l){
        printf("%s %d\n", _l->lib->titolo, _l->lib->npagine);
        _l = _l->next;
    }
}
// stampa ricorsiva
void printListaR(Nodo *_l){
    if(_l != NULL){
        printf("%s %d\n", _l->lib->titolo, _l->lib->npagine);
        printListaR(_l->next);
    }
}

int findTitoloLibro(Nodo *_l, char *_t){
    int posizione;
    posizione = 1;
    while(_l != NULL){
        if(strcmp(_l->lib->titolo, _t) == 0)
            return(posizione);
        else{
            _l = _l->next;
            posizione++;  
        }
    }
    return(-1);
}

Nodo* getDatiLibro(Nodo *_l, char *_t){
    while(_l){
        if(strcmp(_l->lib->titolo, _t) == 0)
            return(_l);
        _l = _l->next;
    }
    return(_l);
}

Libro* getDatiLibro2(Nodo *_l, char *_t){
    while(_l){
        if(strcmp(_l->lib->titolo, _t) == 0)
            return(_l->lib);
        _l = _l->next;
    }
    return(NULL); 
}