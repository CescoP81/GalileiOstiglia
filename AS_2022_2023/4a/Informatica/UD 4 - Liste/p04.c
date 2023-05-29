#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodo{
	char nome[20];
	char cognome[20];
	struct nodo* next;
}Nodo;

/**
 * @brief Add a new node to the head of the list.
 * @param Nodo** Pointer to pointer.
 * @param char Vector.
 * @param char Vector.
*/
void addTesta(Nodo**, char [], char []);

/**
 * @brief Show all nodes of a list.
 * @param Nodo* Pointer to the head.
*/
void showLista(Nodo*);
/**
 * @brief Add a new node the the tail of the list.
 * @param char Vector.
 * @param char Vector.
*/
void addCoda(Nodo**, char [], char []);
int main(){
	Nodo* t;
	t = NULL;
	char v1[20];
	char v2[20];
	
	
	addTesta(&t, "Alessandro", "Magnani");
	addTesta(&t, "Zakaria", "Rizqy");
	addTesta(&t, "Nicolo", "Goldoni");
	showLista(t);
	printf("\n\n");
	
	addCoda(&t, "Achraf", "Zahir");
	showLista(t);
	return 0;
}
void addTesta(Nodo** _head, char _v1[], char _v2[]){
	Nodo* nh = malloc(sizeof(Nodo));
	
	strcpy(nh->nome, _v1);
	strcpy(nh->cognome, _v2);
	nh->next = *_head;
	*_head = nh;
}
void showLista(Nodo *_head){
    Nodo *tmp;
    tmp = _head;
    while(tmp != NULL){
        printf("%s, %s\n", tmp->nome, tmp->cognome);
        tmp = tmp->next;
    }
}
void addCoda(Nodo** _head, char _v1[], char _v2[]){
	Nodo* nt = malloc(sizeof(Nodo));
	strcpy(nt->nome, _v1);
	strcpy(nt->cognome, _v2);
	nt->next = NULL;
	
	Nodo* tmp;
	tmp = *_head;
	if(tmp == NULL){	//se la lista è vuota
		*_head = tmp;
	}
	else{
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
		tmp->next = nt;
	}
}


