#include<stdio.h>
#include<stdlib.h>

typedef struct Nodo{
    int valore;
    struct Nodo *next;
}Nodo;

Nodo* pushTesta(Nodo *_t, int _val);
void showLista(Nodo *_t);

int main(){
    Nodo *head;     // creo un puntatore al primo nodo della lista.
    head = 0;       // l'indirizzo puntato lo imposto a zero come inizializzazione.

    showLista(head);
    // push in testa di 3 valori
    head = pushTesta(head, 22);
    showLista(head);
    head = pushTesta(head, 35);
    showLista(head);
    head = pushTesta(head, 40);
    showLista(head);
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
        while(tmp){     // (tmp != 0)
            printf("%d ", tmp->valore);
            tmp = tmp->next;
        }
        printf("\n");
    }
}