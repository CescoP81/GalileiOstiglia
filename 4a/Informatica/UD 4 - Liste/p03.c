/*
    Author: Tomirotti
    Date: 28.04.2023
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
 * @brief Order all elements in a list.
 * @param Nodo* Pointer to the head.
*/
void orderListYear(Nodo*);
/**
 * @brief Order all elements in a list by surname. User can choose the order type Ascendig or Descending.
 * @param Nodo* Pointer to the head.
 * @param int flag per decidere se è in ordine alfabetico oppure in ordine alfabetico al contrario
*/
void orderListSurname(Nodo*, int);
/**
 * @brief Ordered add of an element to the list.
 * @param Nodo* Pointer to the head.
 * @param Persona passo una variabile di tipo persona.
*/
Nodo* addOrderList(Nodo*, Persona);
int main(){
	
	Persona x;
	Nodo* t;
	t = NULL;
	
	strcpy(x.n, "Andrea");
	strcpy(x.c, "Bianchi");
	x.a = 1997;
	//t = addTesta(t, x);
	t = addOrderList(t, x);
	
	strcpy(x.n, "Giulia");
	strcpy(x.c, "Rossi");
	x.a = 2001;
	t = addOrderList(t, x);
	
	strcpy(x.n, "Chiara");
	strcpy(x.c, "Kizqy");
	x.a = 1995;
	t = addOrderList(t, x);
	
	strcpy(x.n, "Ilaria");
	strcpy(x.c, "Bianchi");
	x.a = 2004;
	t = addOrderList(t, x);
	
	strcpy(x.n, "Francesco");
	strcpy(x.c, "Bianchi");
	x.a = 1990;
	t = addOrderList(t, x);
	
	
	showLista(t);
	printf("\n\n");
	orderListYear(t);
	showLista(t);
	printf("\n\n");
	
	
	orderListSurname(t, 0);
	showLista(t);
	printf("\n\n");
	orderListSurname(t, 1);
	showLista(t);
	printf("\n\n");
	
	printf("---------\n\n");
	strcpy(x.n, "Alessandro");
	strcpy(x.c, "Magnani");
	x.a = 2023;
	t = addOrderList(t, x);
	showLista(t);
	
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
void orderListYear(Nodo *_testa){
	Persona tmp;
	Nodo* ind1;
	ind1 = _testa;
	Nodo* ind2;
	while(ind1 != NULL){
		ind2 = ind1->next;
		while(ind2 != NULL){
			if(ind1->p.a > ind2->p.a){
				tmp = ind1->p;
				ind1->p = ind2->p;
				ind2->p = tmp;
			}
			ind2 = ind2->next;
		}
		ind1 = ind1->next;
	}
}
void orderListSurname(Nodo *_testa, int _flag){
	Persona tmp;
	Nodo* ind1;
	ind1 = _testa;
	Nodo* ind2;
	
	if(_flag == 0){		//ordine alfabetico
		while(ind1 != NULL){
			ind2 = ind1->next;
			while(ind2 != NULL){
				if(strcmp(ind1->p.c, ind2->p.c) == +1){
					tmp = ind1->p;
					ind1->p = ind2->p;
					ind2->p = tmp;
				}
				ind2 = ind2->next;
			}
			ind1 = ind1->next;
		}
	}
	else{				//ordine alfabetico al contrario
		while(ind1 != NULL){
			ind2 = ind1->next;
			while(ind2 != NULL){
				if(strcmp(ind1->p.c, ind2->p.c) == -1){
					tmp = ind1->p;
					ind1->p = ind2->p;
					ind2->p = tmp;
				}
				ind2 = ind2->next;
			}
			ind1 = ind1->next;
		}
	}
}
Nodo* addOrderList(Nodo *_testa, Persona _p){
	Nodo* nn = malloc(sizeof(Nodo));
	nn->next = _testa;
	nn->p = _p;
	orderListSurname(nn, 0);
	return (nn);
}

