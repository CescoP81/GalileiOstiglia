#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define R 5
#define C 5

void init_mat(int [R][C], int, int);
void stampa_mat(int [R][C], int, int);

int main(){
	int m[R][C];
	srand(time(NULL));
	
	init_mat(m, R, C);
	stampa_mat(m, R, C);
	return(0);
}

void init_mat(int m[R][C], int _r, int _c){
	int i, j;
	for(i=0; i<_r; i++){
		for(j=0; j<_c; j++){
			m[i][j] = rand()%10+1;
		}
	}	
}

void stampa_mat(int m[R][C], int _r, int _c){
	int i, j;
	for(i=0; i<_r; i++){
		for(j=0; j<_c; j++){
			printf("%3d", m[i][j]);
		}
		printf("\n");
	}
}
