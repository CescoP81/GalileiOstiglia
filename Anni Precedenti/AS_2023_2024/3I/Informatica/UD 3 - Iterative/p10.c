/*
	Author:		Francesco Pradella
	Date:		05.12.23
	File:		p10.c
	Desc:		Realizza un programma C che richiede in input due valori N un valore positivo maggiore di 50; D un valore positivo minore di 10.
	 			Visualizzare a video tutti i valori da 1 a N che siano multipli di D.
*/
#include <stdio.h>

int main(){
	int N, D;
	int val;
	
	// inserimento di N
	do{
		printf("Inserisci un numero N: ");
		scanf("%d", &N);
		fflush(stdin);
	}while(N<=50);
	
	// inserimento di D
	do{
		printf("Inserisci un numero D: ");
		scanf("%d", &D);
		fflush(stdin);
	}while(D>=10);
	
	// ciclo di verifica di ogni numero compreso tra 1 e N inserito da tastiera.
	val = 1;
	while(val <= N){
		if(val%D == 0){
			printf("%d - ", val);
		}
		val = val + 1;
	}
	return(0);
}
