#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R 5
#define C 6

int main(){
	
	int m[R][C];
	int v[C];
	int i,j;
	
	srand(time(NULL));
	
	// inizializzazione della matrice con singole cifre random 
	// in ogni cella.
	for(i=0; i<R; i++){
		for(j=0; j<C; j++){
			m[i][j] = rand()%10;	
		}
	}
	
	// visualizzo la matrice
	for(i=0; i<R; i++){
		for(j=0; j<C; j++){
			printf("%2d", m[i][j]);
		}
		printf("\n");
	}
	
	// richiesta del vettore da verificare come match.
	for(i=0; i<C; i++){
		printf("[%d]: ",i+1);
		scanf("%d", &v[i]);
		fflush(stdin);
	}
	
	
	return(0);	
}
