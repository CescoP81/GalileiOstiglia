#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R 5
#define C 6

int trova_riga(int [][C], int []);

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
	
	printf("\n\n");
	if(trova_riga(m, v) >=0 )
		printf("La riga e' presente nella matrice, in posizione %d", trova_riga(m, v)+1);
	else
		printf("La riga non e' presente nella matrice.");
	
	return(0);	
}

int trova_riga(int _m[][C], int _v[]){
	int i, j;
	int cnt;
	int trovato;
	
	trovato = -1;
	for(i=0; i<R && trovato!=-1; i++){
		cnt = 0;
		for(j=0; j<C; j++){
			if(_m[i][j] == _v[j])
				cnt++;
		}
		
		if(cnt == C){
			trovato = i;
		}
	}
	return(trovato);
}
