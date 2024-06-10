/*
	Esempio di Dichiarazione ed utilizzo delle funzioni in C
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//== sezione dei prototipi / dichiarazione delle funzioni
/**
* Funzione che ricevuto un valore ne visualizza i divisori.
* @param int Valore di cui visualizzare i divisori.
*/
void vediDivisori(int _x);
/**
* Funzione che verifica e comunica se un numero è primo.
* @param int Valore da verificare.
*/
void verificaNumeroPrimo(int _x);

/**
* Funzione che calcola e restituisce la somma dei divisori di un numero
* @param int Valore di cui trovare i divisori.
* @return int Somma dei divisori trovati
*/
int sommaDivisori(int _x);

int main(){
	int valore;
	int risultato;
	
	valore = 12;			// imposto un valore iniziale.
	vediDivisori(valore); 	// richiamo la funzione passando la variabile valore.
	valore = 26;			// sostituisco il valore.
	vediDivisori(valore);	// richiamo nuovamente la funzione
	printf("\n");
	
	// verifica funzionamento di verificaNumeroPrimo
	valore = 27;
	verificaNumeroPrimo(valore);
	valore = 13;
	verificaNumeroPrimo(valore);
	
	// verifica funzionamento di sommaDivisori.
	valore = 6;
	risultato = sommaDivisori(valore);
	printf("La somma vale %d\n", risultato);
	valore = 24;
	risultato = sommaDivisori(valore);
	printf("La somma vale %d\n", risultato);
	
	return(0);
}

//== sezione di sviluppo funzioni / definizione delle funzioni
void vediDivisori(int _x){
	int div;
	div = 1;
	printf("Lista dei divisori:\n");
	while(div <= _x){
		if(_x%div == 0)		
			printf("%d e' divisore.\n", div);
		div = div + 1;
	}
}

void verificaNumeroPrimo(int _x){
	int div;	// variabile per i divisori da verificare.
	int cntDiv;	// contatore dei divisori.
	
	div = 1;
	cntDiv = 0;	// scorro tutti i divisori e conto quelli trovati.
	while(div <= _x){
		if(_x%div == 0)
			cntDiv = cntDiv + 1;
		div = div + 1;
	}
	
	if(cntDiv <= 2) // numeri primi hanno 1 o al più 2 divisori.
		printf("Il numero %d e' primo.\n", _x);
	else
		printf("Il numero %d non e' primo.\n", _x);
}

int sommaDivisori(int _x){
	int div;
	int somma;
	
	// trovo i divisori e li sommo alla variabile 'somma'
	div = 1;
	somma = 0;
	while(div <= _x){
		if(_x%div == 0)
			somma = somma + div;
		div = div + 1;
	}
	
	// ritorno la somma al MAIN PROGRAM
	return(somma);
}









