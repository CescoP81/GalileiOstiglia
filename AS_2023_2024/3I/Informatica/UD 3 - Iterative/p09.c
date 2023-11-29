/*
	Author:		Francesco Pradella
	Date:		28.11.23
	File:		p08.c
	Desc:		Utilizzo delle iterative per problemi matematici.
				Programma che richiede un numero e determina se il numero
				è PRIMO oppure no.
				Un numero risulta essere primo quando è divisibile solo
				per 1 e per se stesso.
				Es: 7 è primo, 13 è primo, 20 non è primo.
*/
#include <stdio.h>

int main(){
	int num;	// variabile per il numero in input
	int div;	// variabile per i divisori.
	int contatoreDivisori;	// variabile per contare il numero dei divisori
	
	// input del numero
	printf("Inserisci un numero: ");
	scanf("%d", &num);
	fflush(stdin);
	
	// ciclo iterativo per provare tutti i divisori del numero inserito.
	div = 1;
	contatoreDivisori = 0;
	while(div<=num){
		if(num%div == 0){
			contatoreDivisori = contatoreDivisori + 1;
		}
		div = div + 1;
	}
	
	// test sul numero di divisori trovati
	if(contatoreDivisori <= 2){
		printf("Il numero inserito %d e' primo.", num);
	}
	else{
		printf("Il numero inserito %d non e' primo.", num);
	}
	
	return(0);
}
