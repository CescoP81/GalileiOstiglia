#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RIGHE 5
#define COLONNE 5

void initVettoreRandom(int [],int ,int ,int );

void stampaVettore(int [],int);

void initMatrice(int [][COLONNE], int, int, int, int);

void stampaMatrix(int [][COLONNE], int, int);

/**
* @brief: Funzione che scambia righe e colonne in una matrice
* @param int matrice da usare
* @param int dimensione righe della matrice
* @param int dimensione colonne della matrice
*/
void scambioRigheColonne(int [][COLONNE], int, int);

/**
* @brief: Confronta un vettore con ogni riga della matrice e visualizza i valori del vettore che non compaiono nella riga della matrice
* @param int matrice da usare
* @param int dimensione righe della matrice
* @param int dimensione colonne della matrice
* @param int vettore da usare
*/
void confrontaMatriceVettore(int [][COLONNE], int, int, int []);
int main(){
	int mat[RIGHE][COLONNE];
	int vet[RIGHE];
	srand(time(NULL));
	
	initMatrice(mat, RIGHE, COLONNE, 1, 9);
	stampaMatrix(mat, RIGHE, COLONNE);
	printf("\n\n");
	scambioRigheColonne(mat, RIGHE, COLONNE);
	stampaMatrix(mat, RIGHE, COLONNE);
	initVettoreRandom(vet, RIGHE, 1, 9);
	stampaVettore(vet, RIGHE);
	printf("\n");
	confrontaMatriceVettore(mat,RIGHE,COLONNE,vet);
}
void initVettoreRandom(int _vet[],int _DIM,int _min,int _max){
	int i;
	
	if(_min==0 || _max==0 || _min>=_max){	
		for(i=0;i<_DIM;i++){
			_vet[i]=rand()%100 + 1;
		}
	}
	else{
		for(i=0;i<_DIM;i++){
			_vet[i]=_min+(rand()%(_max-_min+1));
		}
	}
}
void stampaVettore(int _v[],int _DIM){
	int i;
	
	for(i=0;i<_DIM;i++){
		printf("%4d",_v[i]);
	}
}
void initMatrice(int _mat[][COLONNE], int _r, int _c, int _min, int _max){
	int i, j;
	
	for(i = 0; i < _r; i++){
		for(j = 0; j < _c; j++){
			_mat[i][j] = _min + rand() % (_max - _min + 1);
		}
	}
}

void stampaMatrix(int _mat[][COLONNE], int _r, int _c){
	int i, j;
	
	for(i = 0; i < _r; i++){
		for(j = 0; j < _c; j++){
			printf("%4d", _mat[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}
void scambioRigheColonne(int _mat[][COLONNE], int _r, int _c){
	int i,j;
	int tmp[RIGHE][COLONNE];
	
	// Riempio la tmp per colonne prendendo i dati dalle righe di mat 
	for(j = 0; j < _c; j++){
		for(i = 0; i < _r; i++){
			tmp[j][i] = _mat[i][j]; 
		}
	}
	// ricopio tmp in mat per modificare la matrice passata dal main 
	for(i = 0; i < _r; i++){
		for(j = 0; j < _c; j++){
			_mat[i][j] = tmp[i][j];
		}
	}
	
}
void confrontaMatriceVettore(int _mat[][COLONNE], int _r, int _c, int _vet[]){
	int i, j, k, trovato;
	
	for(i = 0; i < _r; i++){
		for(j = 0; j < _c; j++){
			printf("%4d", _mat[i][j]);
		}
		printf("--> ");
		for(k = 0; k < _c; k++){
			trovato=0;
			for(j = 0; j < _c; j++){
				if(_mat[i][j] == _vet[k]){
					trovato=1;
				}
			}
			if(trovato == 0){
				printf("%d ", _vet[k]);
			}
		}
		printf("\n");
	}
}
