/* Author: Cutroneo Vincenzo
desc: richiedere un valore positivo maggiore di 0 e inferiore o uguale a 10
quindi visualizzare le tabelline da 1 a 10 per tutti i numeri da 1 a n inserito 
data: 13/12/2023
*/
#include <stdio.h>

int main(){
	int v1;
	int v2;
	int r,c;
	do{
		printf("inserire un valore positivo maggiore di 0 e inferiore o uguale a 10: ");
		scanf("%d", &v1);
		fflush(stdin);
	}while(v1<=0 || v1>10);
	
	//ciclo iterativo delle righe
	r=1;
	while(r<=v1){
		// ciclo iterativo delle colonne
		c=1;
		while(c<=10){
			printf("%4d", (r*c));
			c=c+1;
		}
		r=r+1;
		printf("\n");	
	}
	
	//richiedere in input un secondo valore (v2) quindi visualizzare le tabelline da v1 per 1 fino
	// a v1 per v2
	printf("\n\n");
	
	do{
		printf("Inserire un valore positivo maggiore di 0 e inferiore o uguale a 10: ");
		scanf("%d", &v2);
		fflush(stdin);
	}while(v2<=0 || v2>10);
	
	// ciclo iterativo delle righe
	r=1;
	while(r<=v2){
		// ciclo iterativo delle colonne
		c=1;
		while(c<=v2){
			printf("%4d", (r*c));
			c=c+1;
		}
		r=r+1;
		printf("\n");	
	}
	return(0);
}

