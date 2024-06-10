/*
	Author:		Francesco Pradella
	Date:		28.11.23
	File:		p07.c
	Desc:		Utilizzo delle iterative per problemi matematici.
				Programma che richiesto un numero determina
				la somma dei divisori e dei non divisori.
*/
#include <stdio.h>

int main(){
	int num;
	int div;
	int sommaDivisori;
	int sommaNonDivisori;
	
	// input del numero.
	printf("Inserisci un numero: ");
	scanf("%d", &num);
	fflush(stdin);
	
	div = 1;
	sommaDivisori = 0;
	sommaNonDivisori = 0;
	while(div <= num){
		if(num%div == 0){
			//printf("d: %d\n", div);
			sommaDivisori = sommaDivisori + div;
		}
		else{
			//printf("nd: %d\n", div);
			sommaNonDivisori = sommaNonDivisori + div;
		}
		div = div + 1;
	}
	
	printf("Somma dei divisori: %d\n", sommaDivisori);
	printf("Somma die non divisori: %d\n", sommaNonDivisori);
		
	return(0);
}
