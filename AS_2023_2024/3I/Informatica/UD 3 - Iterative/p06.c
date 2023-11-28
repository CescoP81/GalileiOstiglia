/*
	Author:		Francesco Pradella
	Date:		28.11.23
	File:		p06.c
	Desc:		Utilizzo delle iterative per problemi matematici.
				Programma che richiesto un numero determina e
				visualizza tutti i divisori.
*/
#include <stdio.h>

int main(){
	int num;	// numero richiesto da tastiera.
	int div;	// variabile per il divisore da testare
	
	// input del numero da tastiera
	printf("Inserisci un numero: ");
	scanf("%d", &num);
	fflush(stdin);
	
	// iterativa per determinare i divisori, si parte sempre da 1
	// fino al numero stesso.
	div = 1;
	while(div <= num){
		if(num%div == 0){
			printf("Divisore trovato: %d\n", div);
		}
		div = div + 1;
	}
	return(0);
}
