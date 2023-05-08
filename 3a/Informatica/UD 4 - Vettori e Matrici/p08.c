#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RIGHE 5
#define COLONNE 10 

/**
* @brief Inizializza una matrice ricevendo righe e colonne da utilizzare e 
  il range minimo e massimo dei valori random
* @param int[][] Matrice da utilizzare
* @param int Dimensione righe
* @param int DImensione colonne
* @param int Valore minimo del range
* @param int Valore massimo del range
*/
void initMatrice(int [][COLONNE], int, int, int, int);

/**
* @brief Funzione che stampa i valori della matrice
* @param int[][] Matrice da utilizzare
* @param int Dimensione righe
* @param int Dimensione colonne
*/
void stampaMatrix(int [][COLONNE], int, int);

/**
* @brief Ricerca un valore nella matrice e stampa tutte le posizioni (i,j)in cui compare
* @param int[][] Matrice da utilizzare
* @param int Dimensione righe
* @param int Dimensione colonne
* @param int valore da ricercare
*/
void ricercaValore(int [][COLONNE],int,int,int);

/**
* @brief Sostituisce un valore presente nella matrice con un nuovo valore passato come parametro
* @param int[][] Matrice da utilizzare
* @param int Dimensione righe
* @param int Dimensione colonne
* @param int valore da cercare
* @param int valore da sostitire
*/
void ricercaValoreSostituire(int [][COLONNE],int,int,int,int);

/**
* @brief Ricerca e stampa le coordinate del valore massimo presente nella matrice
* @param int[][] Matrice da utilizzare
* @param int Dimensione righe
* @param int Dimensione colonne
* @param int valore da cercare
* @param int valore massimo
*/
void ricercaValoreMassimo(int [][COLONNE],int,int);
int main(){
	int mat[RIGHE][COLONNE];
	
	srand(time(NULL));
	
	initMatrice(mat, RIGHE, COLONNE, 0, 20);
	stampaMatrix(mat, RIGHE, COLONNE);
	
	printf("\n\n");
	
	ricercaValore(mat,RIGHE,COLONNE,13);
	
	printf("\n\n");
	
	ricercaValoreSostituire(mat,RIGHE,COLONNE,11,99);
	stampaMatrix(mat, RIGHE, COLONNE);
	
	printf("\n\n");
	ricercaValoreMassimo(mat,RIGHE,COLONNE);
	return(0);
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
void ricercaValore(int _mat[][COLONNE],int _r,int _c,int _v){
	int i,j;
	
	for(i=0;i<_r;i++){
		for(j=0;j<_c;j++){
			if(_mat[i][j]==_v){
				printf("%d: [%d,%d] ",_mat[i][j],i,j);
			}
		}
	}
}
void ricercaValoreSostituire(int _mat[][COLONNE],int _r,int _c,int _v,int _s){
	int i,j;
	
	for(i=0;i<_r;i++){
		for(j=0;j<_c;j++){
			if(_mat[i][j]==_v){
				_mat[i][j]=_s;
			}
		}
	}
}
void ricercaValoreMassimo(int _mat[][COLONNE],int _r,int _c){
	int i,j;
	int max; 	//variabile per contenere il valore massimo trovato
	int imax;	//indice i in cui trovo il max
	int jmax;	//indice j in cui trovo il max
	
	max=_mat[0][0];
	imax=0;
	jmax=0;
	for(i=0;i<_r;i++){
		for(j=0;j<_c;j++){
			if(_mat[i][j]>max){
				max=_mat[i][j];
				imax=i;
				jmax=j;
			}
		}
	}
	printf("%d=[%d][%d]",max,imax,jmax);
}
