#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Nodo{
    int valore;
    struct Nodo *next;
}Nodo;
// == PROTOTIPI ==
/**
 * Visualizza la lista con iterativa
 * @param Nodo* Puntatore alla testa attuale.
*/
void showLista(Nodo *_t);

Nodo* pushCoda(Nodo *_t, int _v);
Nodo* popCoda(Nodo *_t);
// == MAIN ==
int main(){
    Nodo *head;
    head = 0;

    showLista(head); // lista vuota...

    head = pushCoda(head, 22);
    showLista(head);  // 22

    head = pushCoda(head, 33);
    showLista(head); // 22, 33

    head = pushCoda(head, 44);
    showLista(head); //22, 33, 44

    // cerco di svuotare la lista
    printf("\n");
    head = popCoda(head);   // esce il 44
    showLista(head);

    head = popCoda(head);   //esce il 33
    showLista(head);

    head = popCoda(head);   // esce il 22
    showLista(head);

    head = popCoda(head);   // lista vuota.
    return(0);
}

// == FUNZIONI ==
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