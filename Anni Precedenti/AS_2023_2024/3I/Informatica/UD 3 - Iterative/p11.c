/*
	Author:		Francesco Pradella
	Date:		05.12.23
	File:		p11.c
	Desc:		Realizza un programma C che richiede due valori N1 e N2 positivi
				e maggiori di 20. Il programma visualizza tutti i divisori comuni
				sia a N1 che a N2.
*/
#include <stdio.h>

int main(){
	int N1, N2;
	int min;
	int val;
	
	// inserimento dei valori N1 e N2
	do{
		printf("Inserisci N1: ");
		scanf("%d", &N1);
		fflush(stdin);
	}while(N1 <= 20);
	
	do{
		printf("Inserisci N2: ");
		scanf("%d", &N2);
		fflush(stdin);
	}while(N2 <= 20);
	
	// divisori comuni ai due numeri.
	// determino il minore tra i due
	if(N1<N2){
		min = N1;
	}
	else{
		min = N2;
	}
	
	// ciclo dei divisori da 1 fino al minore determinato.
	val = 1;
	while(val <= min){
		if(N1%val == 0){
			if(N2%val == 0){
				printf("%d - ", val);
			}
		}
		/* altrimenti usando i connettori logici
		if((N1%val == 0) && (N2%val == 0))
			printf("%d - ", val);
		*/
		val = val + 1;
	}	
	return(0);
}
