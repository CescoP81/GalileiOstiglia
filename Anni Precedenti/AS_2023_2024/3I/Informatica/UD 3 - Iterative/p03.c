/**
*	Author:		Francesco Pradella
*	Date:		16.11.23
*	File:		p03.c
*	Desc:		Richiedere all'utente un numero intero N positivo,
*	stampare a video tutti i numeri pari compresi tra 1 ed il numero inserito.
*	es: N=15 -> 2, 4, 6, 8, 10, 12, 14
*/
#include <stdio.h>

int main(){
	int N; 		// numero inserito dall'utente.
	int cnt; 	// contatore che andrà da 1 al numero inserito, estremo compreso.
	
	printf("Inserisci un numero: ");
	scanf("%d", &N);
	fflush(stdin);
	
	cnt = 1;						// contatore parte da 1 e incrementato di 1 arriverà fino a N
	while(cnt <= N){
		if(cnt%2 == 0){				// condizione del valore pari fatta su 'cnt', ogni volta che il ciclo gira
			printf("%d ", cnt);
		}
		cnt = cnt + 1;	
	}
	
	return(0);
}
