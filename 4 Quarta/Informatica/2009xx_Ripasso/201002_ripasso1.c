#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R 5
#define C 5

void ricerca_min_max(int [][C], int *, int *);
int ricerca_valore(int [][C], int);

int main(){
	srand(time(NULL));
	int mat[R][C];
	int min, max;
	int val;
	int i,j;
	
	// inizializzazione random della matrice.
	for(i=0; i<R; i++){
		for(j=0; j<C; j++){
			mat[i][j] = rand()%50+1;
		}
	}
	
	// stampa della matrice
	for(i=0; i<R; i++){
		for(j=0; j<C; j++){
			printf("%3d", mat[i][j]);
		}
		printf("\n");
	}
	
	// determinare maggiore e minore con una funzione.
	ricerca_min_max(mat, &min, &max);
	printf("\n\nMin: %d; Max: %d\n", min, max);
	
	printf("Ricerca: ");
	scanf("%d", &val);
	fflush(stdin);

	if(ricerca_valore(mat, val))
		printf("\nValore presente Nr. %d volte.", ricerca_valore(mat,val));
	else
		printf("\nValore non presente.");
	
	return(0);
}

void ricerca_min_max(int m[][C], int *_min, int *_max){
	int i,j;
	// ricerca del minimo
	*_min = m[0][0];
	for(i=0; i<R; i++){
		for(j=0; j<C; j++){
			if(m[i][j] < *_min)
				*_min = m[i][j];
		}
	}
	
	// ricerca del massimo
	*_max = m[0][0];
	for(i=0; i<R; i++){
		for(j=0; j<C; j++){
			if(m[i][j] > *_max)
				*_max = m[i][j];
		}
	}
}

int ricerca_valore(int m[][C], int _src){
	int i, j;
	int cnt = 0;
	for(i=0; i<R; i++){
		for(j=0; j<C; j++){
			if(m[i][j] == _src)
				cnt++;
		}
	}
	return(cnt);
}
