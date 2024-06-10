#include <stdio.h>
#include <stdlib.h>

// Definition of the structure Nodo.
typedef struct nodo{
    int val;
    struct nodo *next;
}Nodo;

/* Declaration of prototypes */ 
/**
 * @brief Add a new node to the head of the list.
 * @param Nodo* Pointer to the head.
 * @param int Value to save.
 * @return Return the new head of the list.
*/
Nodo* addTesta(Nodo *, int);
/**
 * @brief Show all nodes of a list.
 * @param Nodo* Pointer to the head.
*/
void showLista(Nodo *);
/**
 * @brief Show all nodes of a list with recursive function.
 * @param Nodo* Pointer to the head.
*/
void showListaRecursive(Nodo *);
/**
 * @brief Show a list from the tail to the head with a recursive function.
 * @param Nodo* Pointer to the head.
*/
void showListaReversedRecursive(Nodo *);
/**
 * @brief Extract a node from the head of the list, check if the list exist.
 * @param Nodo* Pointer to the head.
 * @return New reference to the head.
*/
Nodo* popTesta(Nodo *);
/**
 * @brief Add a new node the the tail of the list.
 * @param Nodo* Pointer to the head.
 * @param int Value to save into the new node.
 * @return Nodo* New reference to the head.
*/
Nodo* pushCoda(Nodo *, int );
/**
 * @brief Search and return the min or max value, min or max selected by user with a flag as parameter.
 * @param Nodo* Pointer to the head.
 * @param int Flag 0->min; 1->max
 * @return The searched value
*/
int ricercaMaxMinLista(Nodo *, int);
/**
 * @brief Count and return the number of nodes of a list.
 * @param Nodo* Pointer to the head.
 * @return The number of nodes of a list.
*/
int contaNodi(Nodo*);
/**
 * @brief Add a new node into a specific position of the list.
 * @param Nodo* Pointer to the head.
 * @param int the selected position, check if the position exist.
 * @param int The value to save into the list.
 * @return Return the new head of the list.
*/
Nodo* pushAtPos(Nodo*, int, int);
/**
 * @brief Open a file and write the number of the list in it.
 * @param Nodo* Pointer to the head.
 * @param char Name of the file.
*/
void writeToFile(Nodo*, char[]);
/**
 * @brief Create a list with values from a specific file.
 * @param Nodo* Pointer to the head.
 * @param char Name of the file.
 * @return reference to a created list.
*/
Nodo* loadFromFile(Nodo*, char[]);
/**
 * @brief Merge the second list into the first list.
 * @param Nodo* Pointer to the first list.
 * @param Nodo* Pointer to the second list.
 * @return reference to a created list.
*/
Nodo* mergeList(Nodo*, Nodo*);

// ### MAIN PROOGRAM ###
int main(){
    Nodo *t;        // puntatore alla testa della lista.
    Nodo *t2;
    Nodo *t3;
    t3 = NULL;
    t2 = NULL;
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
    /*
    showListaReversedRecursive(t); 
	*/
	t = pushAtPos(t, 1, 99); 
	showLista(t);
	printf("\n\n");
	
	t = pushAtPos(t, contaNodi(t)+1, 66);
	showLista(t);
	printf("\n\n");
	
	t = pushAtPos(t, contaNodi(t)-2, 100);
	showLista(t);
	
	writeToFile(t, "lista.txt");
	printf("\n");
	showLista(t);
	
	t2 = loadFromFile(t2, "lista.txt");
	showLista(t2);
	printf("\n---\n");
	
	t3 = mergeList(t3, t);
	t3 = mergeList(t3, t2);
	t2 = NULL;
	showLista(t3);
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
Nodo* pushAtPos(Nodo* _head, int pos, int val){
	/*
	Nodo* nPos = malloc(sizeof(Nodo));
	nPos->val = val;
	nPos->next = */
	int cnt = contaNodi(_head);
	
	Nodo* t;
	t = NULL;
	
	if(pos == 1){
		t = addTesta(_head, val) ;
		return t;
	}
	
	if(pos == cnt+1){
		t = pushCoda(_head, val);
		return t;
	}
	//printf("%d-", pos);
	
	if(pos > 1 && pos < contaNodi(_head)){	
		//printf("entro");
		int tmp = 1;
		Nodo *x; 
		x = _head;
		Nodo *box;
		while(tmp < pos-1){
			x = x->next;
			tmp++;
		}
		//printf("%d-", x);
		box = malloc(sizeof(Nodo));
		box->val = val;
		box->next = x->next;
		x->next = box;
		return (_head);
	}	
}
void writeToFile(Nodo* _head, char _filename[]){
	FILE *f = fopen(_filename, "w");		//open a file in mode writing
	
	while(_head != NULL){					//run 'til head is NULL 
		fprintf(f, "%d\n", _head->val);
		_head = _head->next;
	}
	fclose(f);								//close the file
}
Nodo* loadFromFile(Nodo* _head, char _filename[]){
	FILE *f = fopen(_filename, "r");
	int valore;
	
	while(!feof(f)){
		if(fscanf(f, "%d", &valore) > 0){
			printf("%d\n", valore);
			_head = pushCoda(_head, valore);
		}
	}
	fclose(f);
	return (_head);
}
Nodo* mergeList(Nodo* _head1, Nodo* _head2){
	while(_head2 != NULL){
		_head1 = pushCoda(_head1, _head2->val);
		_head2 = _head2->next;
	}
	return(_head1);
}
