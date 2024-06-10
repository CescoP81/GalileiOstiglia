#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	// variabili di gioco
	int numeroRandom;
	int numeroUtente;
	int cntTentativi;
	
	// 1° step: genero il numero random compreso tra 1 e 99.
	srand(time(NULL));
	numeroRandom = 1 + (rand() % 99);
	
	// 2° step: l'utente deve indovinare il numero generato random
	// nel minor numero di tentativi possibile.
	cntTentativi = 0;
	do{
		cntTentativi++;
		printf("Indovina il valore segreto: ");
		scanf("%d", &numeroUtente);
		fflush(stdin);
		
		if(numeroUtente == numeroRandom){
			printf("\nYuppiii hai indovinato il numero SeGrEtO!!\n\n");
		}
		
		if(numeroUtente < numeroRandom){
			printf("Ops, hai scelto un numero troppo piccolo...\n");
		}
		
		if(numeroUtente > numeroRandom){
			printf("Ops, hai scelto un numero troppo grande...\n");
		}
	}while(numeroUtente != numeroRandom);
	
	printf("!! HAI UTILIZZATO %d TENTATIVI!!\n", cntTentativi);	
	return(0);
}
