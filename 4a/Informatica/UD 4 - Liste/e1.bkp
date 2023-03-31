#include <stdio.h>
#include <stdlib.h>

// Definizione dells truttura Nodo
typedef struct nodo{
    int val;
    struct nodo *next;
}Nodo;

// Dichiarazione dei prototipi
/**
 * @brief Aggiunge un nodo in testa alla lista
 * @param Nodo* Puntatore alla testa della lista.
 * @param int Valore da inserire nel nodo.
 * @return Nuova testa della lista.
*/
Nodo* addTesta(Nodo *, int);
/**
 * @brief Visualizza una lista.
 * @param Nodo* Puntatore alla testa della lista.
*/
void showLista(Nodo *);
/**
 * @brief Visualizza una lista in modo ricorsivo
 * @param Nodo* Puntatore alla lista.
*/
void showListaRecursive(Nodo *);
/**
 * @brief Visualizza una lista al contrario in modo ricorsivo.
 * @param Nodo* Puntatore alla lista.
*/
void showListaReversedRecursive(Nodo *);
/**
 * @brief Estrae un nodo dalla testa della lista, con controllo esistenza.
 * @param Nodo* Puntatore alla testa della lista
 * @return Nuova testa della lista.
*/
Nodo* popTesta(Nodo *);
/**
 * @brief Aggiunge un nodo alla coda della lista.
 * @param Nodo* Puntatore alla testa della lista.
 * @param int valore da inserire nel nodo
 * @return Nodo* Puntatore alla nuova testa.
*/
Nodo* pushCoda(Nodo *, int );
/**
 * @brief Ricerca il valore massimo o minimo interno alla lista.
 * @param Nodo* Puntatore alla testa della lista.
 * @param int 0->Minimo; 1->Massimo
 * @return Valore trovato.
*/
int ricercaMaxMinLista(Nodo *, int);
/**
 * @brief Determina la lunghezza di una lista.
 * @param Nodo* Puntatore alla testa della lista.
 * @return Numero di nodi che compongono la lista.
*/
int contaNodi(Nodo*);

// ### MAIN PROOGRAM ###
int main(){
    Nodo *t;        // puntatore alla testa della lista.
    t = NULL;       // inizialmente punta a NULL (nessuna lista creata)

    // eseguo tre inserimenti di prova.
    t = addTesta(t, 5);
    t = addTesta(t, 7);
    t = addTesta(t, 9);

    // eseguo la chiamata della funzione di visualizzazione della lista.
    showLista(t);
    printf("\n\n");
    showListaRecursive(t);
    printf("\n\n");
    showListaReversedRecursive(t);

    return(0);
}

// Definizione delle funzioni
Nodo* addTesta(Nodo *_testa, int _val){
    Nodo *tmp;
    tmp = malloc(sizeof(Nodo));
    tmp->next = _testa;
    tmp->val = _val;
    return(tmp);
}
void showLista(Nodo *_testa){
    Nodo *tmp;
    tmp = _testa;
    while(tmp != NULL){
        printf("Address: %d; val: %d, next: %d\n", tmp, tmp->val, tmp->next);
        tmp = tmp->next;
    }
}
/*
Address: 11605616; val: 9, next: 11612120
Address: 11612120; val: 7, next: 11612104
Address: 11612104; val: 5, next: 0
*/

void showListaRecursive(Nodo *_tmp){
    if(_tmp != NULL){
        printf("Address: %d; val: %d, next: %d\n", _tmp, _tmp->val, _tmp->next);
        showListaRecursive(_tmp->next);
    }
}
void showListaReversedRecursive(Nodo *_tmp){
    if(_tmp != NULL){
        showListaReversedRecursive(_tmp->next);
        printf("Address: %d; val: %d, next: %d\n", _tmp, _tmp->val, _tmp->next);        
    }
}
Nodo* popTesta(Nodo *_head){
	if(_head == NULL)
		return NULL;
	Nodo* _nh = _head->next;	// New head
	free(_head);
	return _nh;
}
Nodo* pushCoda(Nodo *_head, int _val){
	Nodo *_tmp = _head;	// Nodo temporaneo di appoggio per scorrere lista
	Nodo *_nt = (Nodo*) malloc(sizeof(Nodo));	// New tail
	_nt->next = NULL;
	_nt->val = _val;
	
	if(_tmp == NULL)	// Se la lista era vuota, ritorno il nuovo nodo
		return _nt;
	
	//getTail
	while ( _tmp->next != NULL){
		_tmp = _tmp->next;
	}
	_tmp->next = _nt;
	return _head;
}
int ricercaMaxMinLista(Nodo *_head, int _scelta){
	// scelta == 0, minimo
	// scelta == 1, massimo
	if(_head != NULL){
		if(_scelta == 1){		// ricerca massimo
			int max = _head->val;
			Nodo *_tmp = _head;
			while ( _tmp != NULL){	// scorro lista
				if(_tmp->val > max )	// aggiorno massimo
					max = _tmp->val;
				_tmp = _tmp->next;
			}
			return max;
		}
		if(_scelta == 0){		// ricerca minore
			int min = _head->val;
			Nodo *_tmp = _head;
			while ( _tmp != NULL){	// scorro lista
				if(_tmp->val < min )	// aggiorno minimo
					min = _tmp->val;
				_tmp = _tmp->next;
			}
			return min;
		}
		return -1;	// se parametro errato
	}
	return -1;		// se lista vuota
}
int contaNodi(Nodo* _head){
	int cnt = 0;	// numero nodi
	Nodo* _tmp = _head;	// nodo tmp per scorrere
	while ( _tmp != NULL){			// scorro lista
		cnt++;
		_tmp = _tmp->next;
	}
	return cnt;		// ritorno numero nodi
}
