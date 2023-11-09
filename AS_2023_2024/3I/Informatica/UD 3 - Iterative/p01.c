/*
	Author: 	Francesco Pradella
	Date:		09.11.23
	File:		UD2 Iterative\p01.c
	Desc:		Prove di utilizzo delle strutture iterative (Cicli)
*/
#include<stdio.h>

int main(){
	int numero;
	int risposta;
	
	// esempio di utilizzo dell'iterativa do-while.
	// permette di ri-eseguire un algoritmo con scelta dell'utente.
	do{
		// input di un valore intero.
		printf("Inserisci un numero: ");
		scanf("%d", &numero);
		fflush(stdin);
		
		// calcolo e comunico il doppio del numero inserito.
		numero = numero * 2;
		printf("Il doppio vale: %d\n\n", numero);
		
		// utilizzo il do-while per avere un controllo sull'input della risposta.
		do{
			printf("Vuoi ripetere?(0->no / 1->si): ");
			scanf("%d", &risposta);
			fflush(stdin);				
		}while(risposta<0 || risposta>1);
		// il while che segue chiude il DO generale della riga 15.
	}while(risposta == 1);
	
	printf("\n\n -- Grazie per aver usato il programma --\n");
	return(0);
}
