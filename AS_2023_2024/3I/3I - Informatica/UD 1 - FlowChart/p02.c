/*	Author: Francesco Pradella
	Date: 10.10.23
	File: p02.c
	Abstract: Realizzare un algoritmo che richiede due valori in input (n1 e n2),
	se n1 è maggiore di n2 effettua lo scambio dei valori.
*/
#include <stdio.h>

int main(){
	// dichiarazione variabili
	int n1, n2, temp;
	
	// richiesta valori in input
	printf("Inserisci n1: ");
	scanf("%d",&n1);
	printf("Inserisci n2: ")
	scanf("%d", &n2);
	
	// test se n1 > n2
	if(n1 > n2){
		temp = n1;
		n1 = n2;
		n2 = temp;
	}
	
	// comunico i valori dopo l'eventuale scambio
	printf("Numero 1: %d \n", n1);
	printf("Numero 2: %d \n", n2);
}
