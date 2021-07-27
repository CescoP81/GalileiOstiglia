#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct n{
    int value;
    struct n* next;
}Nodo; 

void pushTesta(Nodo **t, int _v){
    Nodo* newHead;
    newHead = (Nodo *) malloc(sizeof(Nodo));
    newHead->value = _v;
    newHead->next = *t;
    *t = newHead;
};

void pushCoda(Nodo **t, int _v){
    printf("%d", *t);
    if(*t){
        //printf("\nentro presente\n");
        Nodo* tmp;
        tmp = *t;
        while(tmp->next){
            tmp = tmp->next;
        }
        tmp->next = (Nodo*) malloc(sizeof(Nodo));
        tmp = tmp->next;
        tmp->value = _v;
        tmp->next = NULL;
    }
    else{
        //printf("\nentro lista vuota\n");
        //printf("%d", t);
        pushTesta(t, _v);
    }
}

void showList(Nodo* _head){
    Nodo* tmp;
    tmp = _head;
    while(tmp){
        printf("[%d] - %d\n", tmp, tmp->value);
        tmp = tmp->next;
    }   
}

int main(){
    Nodo *head;
    head = 0;
    printf("Head: %d\n\n", &head);

    pushCoda(&head, 12);
    showList(head);

    printf("\n\n");

    pushTesta(&head, 5);
    pushTesta(&head, 7);
    pushTesta(&head, 9);

    showList(head);
    return(0);
}