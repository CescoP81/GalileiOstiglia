/*
	Author:		Francesco Pradella
	Date:		28.11.23
	File:		p08.c
	Desc:		Utilizzo delle iterative per problemi matematici.
				Programma che richiesti due numeri da tastiera, 
				verifica e comunica se sono numeri Amici/Amicali.
				Due numeri si dicono AMICALI se la somma dei divisori
				del primo numero è uguale al secondo numero e viceversa.
*/
#include <stdio.h>

int main(){
	int num1;
	int num2;
	int somma1;
	int somma2;
	int div;
	
	printf("Inserisci numero 1: ");
	scanf("%d", &num1);
	fflush(stdin);
	printf("Inserisci numero 2: ");
	scanf("%d", &num2);
	fflush(stdin);
	
	// somma divisori primo numero
	div = 1;
	somma1 = 0;
	while(div < num1){
		if(num1%div == 0){
			somma1 = somma1 + div;
		}
		div = div + 1;
	}
	
	// somma divisori secondo numero
	div = 1;
	somma2 = 0;
	while(div < num2){
		if(num2%div == 0){
			somma2 = somma2 + div;
		}
		div = div + 1;
	}
	
	printf("Numero %d somma divisori %d\n", num1, somma1);
	printf("Numero %d somma divisori %d\n", num2, somma2);
	
	if((num1==somma2) && (num2==somma1)){
		printf("I numeri sono AMICALI\n");
	}
	else{
		printf("I due numeri non sono AMICALI\n");
	}
	return(0);	
}
