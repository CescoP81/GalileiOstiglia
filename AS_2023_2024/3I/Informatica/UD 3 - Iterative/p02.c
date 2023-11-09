/*
	Author: Francesco Pradella
	Date:	09.11.23
	File:	\ud 2\p02.c
	Desc: 	Esempio di utilizzo del costrutto While().
*/
#include <stdio.h>

int main(){
	int numero;
	
	// richiedo un numero da 1 a 10
	printf("Inserisci un numero da 1 a 10: ");
	scanf("%d", &numero);
	fflush(stdin);
	
	// visualizzo tutti i numero dal valore inserito
	// fino al valore 25 compreso.
	while(numero <= 25){
		printf("%d ", numero);
		numero = numero + 1;
	}
	
	printf("\n\n -- Grazie di aver usato il programma --\n");
	return(0);
}
