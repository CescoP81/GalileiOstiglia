#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
// prototipi delle funzioni, includono tipo di ritorno, nome della funzione
// numero e tipo dei parametri sia per valore che per riferimento.
void somma(int, int);
void somma_2(int *, int *);

int main(){
	int x, y;
	x = 10;
	y = 3;
	somma(x, y);
	printf("%d - %d\n\n", x, y);
	
	somma_2(&x, &y);
	printf("%d - %d\n", x, y);
	return(0);
}

// sviluppo funzioni
void somma(int _a, int _b){
	int risultato;
	risultato = _a + _b;
	printf("%d\n", risultato);
	_a = 90;
}

void somma_2(int *_a, int *_b){
	int risultato;
	risultato = *_a + *_b;
	printf("%d\n", risultato);
	*_a = 90;
}



