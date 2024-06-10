/*
	Author:		Francesco Pradella
	Date:		06.12.23
	File:		p12.c
	Desc:		Realizzare un programma C che richiesti due valori N1 e N2
				calcoli e comunichi il primo valore che è divisibile per N1 e N2
				contemporaneamente.
*/
#include <stdio.h>

int main(){
	int N1, N2;
	// variabile per il ciclo di ricerca del numero divisibile per N1 e N2
	int val;
	
	// input di due valori positivi maggiori di zero
	do{
		printf("Inserisci N1: ");
		scanf("%d", &N1);
		fflush(stdin);
	}while(N1 <= 0);
	
	do{
		printf("Inserisci N2: ");
		scanf("%d", &N2);
		fflush(stdin);
	}while(N2 <= 0);
	
	// determino il valore maggiore tra i due inseriti e lo assegno a 'val'
	if(N1 > N2){
		val = N1;
	}
	else{
		val = N2;
	}
	
	// prima soluzione alla ricerca del valore divisibile.
	/*while((val%N1 !=0) || (val%N2 != 0)){
		val = val + 1;
	}
	printf("Il primo valore divisibile per n1 e n2 e': %d.", val);
	*/
	
	// seconda soluzione alla ricerca
	int trovato = 0; // 0 in informatica significa sempre FALSO
	do{
		if(val%N1 == 0){
			if(val%N2 == 0){
				trovato = 1;
			}
		}
		if(trovato == 0){
			val = val + 1;
		}
	}while(trovato != 1);
	printf("Il primo valore divisibile per n1 e n2 e': %d.", val);	
	
	return(0);
}
