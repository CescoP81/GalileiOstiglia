/*
	Example of a list with nodes containing a structure.
    With this example I will show you the creation of a list where each node contain another structure called Persona.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char n[30];
	char c[30];
	int a;
}Persona;

typedef struct nodo{
	Persona p;
	struct nodo *next;
}Nodo;

/**
 * @brief Add a new node to the head of the list.
 * @param Nodo* Pointer to the head.
 * @param Persona the structure pre filled with values.
 * @return Return the reference of the new head.
*/
Nodo* addTesta(Nodo*, Persona);
/**
 * @brief Show all nodes of a list.
 * @param Nodo* Pointer to the head.
*/
void showLista(Nodo*);
/**
 * @brief Open a file and write the structures of the list in it.
 * @param Nodo* Pointer to the head.
 * @param char Name of the file.
*/
void writeToFile(Nodo*, char[]);
/**
 * @brief Open a file and read each structure and create a list with them.
 * @param Nodo* Pointer to the head.
 * @param char Name of the file.
*/
Nodo* loadFromFile(Nodo*, char[]);

int main(){
	Persona x;
	Nodo* t;
	Nodo* t2;
	t2 = NULL;
	t = NULL;
	
	strcpy(x.n, "Andrea");
	strcpy(x.c, "Bianchi");
	x.a = 1997;
	t = addTesta(t, x);
	
	strcpy(x.n, "Giulia");
	strcpy(x.c, "Rossi");
	x.a = 2001;
	t = addTesta(t, x);
	
	strcpy(x.n, "Chiara");
	strcpy(x.c, "Kizqy");
	x.a = 1995;
	t = addTesta(t, x);
	
	showLista(t);
	writeToFile(t, "lista.txt");
	
	t2 = loadFromFile(t2, "lista.txt");
	printf("\n\n");
	showLista(t2);
	
	return (0);
}
Nodo* addTesta(Nodo* _head, Persona _p){
	Nodo* nh;
	nh = malloc(sizeof(Nodo));
	nh->next = _head;
	nh->p = _p;
	return (nh);
}
void showLista(Nodo *_testa){
    Nodo *tmp;
    tmp = _testa;
    while(tmp != NULL){
        printf("%s, %s, %d\n", tmp->p.n, tmp->p.c, tmp->p.a);
        tmp = tmp->next;
    }
}
void writeToFile(Nodo* _head, char _filename[]){
	FILE *f = fopen(_filename, "wb");
	
	while(_head != NULL){
		fwrite(&(_head->p), sizeof(Persona), 1, f);
		_head = _head->next;
	}
	fclose(f);
}
Nodo* loadFromFile(Nodo* _head, char _filename[]){
	FILE *f = fopen(_filename, "rb");
	int n;
	Persona tmp;
	
	while(!feof(f)){
		n = fread(&tmp, sizeof(Persona), 1, f);
		if(n > 0){
			_head = addTesta(_head, tmp);
		}
	}
	return(_head);
}
