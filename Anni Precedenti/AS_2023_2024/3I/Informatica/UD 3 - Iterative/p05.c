/**
*	Author: Pradella F.
*	Date: 16.11.23
*	File: p05.c
* 	Desc: Richiedere un numero in input accettando solo numeri dispari,
	una volta accettato un numero dispari calcolare e comunicare il suo doppio.
*/
#include <stdio.h>

int main(){
	int numero;
	
	do{
		printf("Inserisci un numero dispari: ");
		scanf("%d", &numero);
		fflush(stdin);
	}while(numero%2 == 0);
	
	printf("Numero originale: %d\n", numero);
	
	numero = numero * 2;
	printf("Numero raddoppiato: %d\n", numero);
	
	return(0);
}
