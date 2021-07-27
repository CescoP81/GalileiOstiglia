#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define DIM 4
#define DIM_2 5

int main(){
	int a;
	int b;
	int c;
	int vet[DIM];
	int mat[DIM][DIM_2];
	int i;
	int j;
	int dim;
	int somma;
	
	a = 5;
	b = 7;
	
	c = a + b;
	printf("Somma: %d\n", c);
	
	c = a * b;
	printf("Moltiplicazione: %d\n", c);
	
	if(a < b){
		printf("A e' minore di B\n");
	}
	else{
		if(a > b)
			printf("A e' maggiore di B\n");
		else
			printf("A e' uguale a B\n");
	}
	
	// CICLI
	c = 1;
	while( c<=a ){
		printf("%d ", c);
		c = c + 1;
	}
	printf("\n\n");
	
	c = 1;
	do{
		printf("%d", c);
		c = c + 1;
	}while(c <= a);
	printf("\n\n");
	
	for(c=1; c<=a; c++){
		printf("%d", c);
	}
	printf("\n\n");
	
	
	// VETTORI
	/* DIM 10
		vet[DIM] -> vet[10] -> vet[0]...vet[9]*/
	srand(time(NULL));
	for(i=0; i<DIM; i++){
		vet[i] = rand()%10 + 1;
	}
	for(i=0; i<DIM; i++){
		printf("%d ", vet[i]);
	}
	printf("\n\n");
	
	for(i=0; i<DIM; i++){
		vet[i] = vet[i] * 2;
	}
	for(i=0; i<DIM; i++){
		printf("%d ", vet[i]);
	}
	printf("\n\n");
	for(i=DIM-1; i>=0; i--){
		printf("%d ", vet[i]);
	}
	printf("\n\n");
	
	// MATRICI
	for(i=0; i<DIM; i++){
		for(j=0; j<DIM_2; j++){
			mat[i][j] = rand()%10 + 1;
		}
	}
	
	for(i=0; i<DIM; i++){
		for(j=0; j<DIM_2; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
	
	for(i=0; i<DIM; i++){
		somma = 0;
		for(j=0; j<DIM_2; j++){
			printf("%d ", mat[i][j]);
			somma = somma + mat[i][j];
		}
		printf(" = %d", somma);
		printf("\n");
	}
	printf("\n\n");
	// NUMERO PRIMO
	int num;
	int cnt;
	int div;
	
	num = 18;
	cnt = 0;
	/*
		'%' -> resto della divisione
		'/' -> risultato della divisione (quoziente)
	*/
	for(div = 2; div<num; div++){
		if(num%div == 0)
			cnt++;
	}
	
	if(cnt == 0){
		printf("Primo.");
	}
	else{
		printf("Non Primo.");
	}
	
	
	
	return(0);
}
