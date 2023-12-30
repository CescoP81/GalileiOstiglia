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
* @brief Stampa la matrice e a fianco di ogni riga visualizza la somma totale dei valori e la media 
  di ogni singola riga.
* @param int[][] Matrice da utilizzare
* @param int Dimensione righe
* @param int Dimensione colonne
*/
void sommaMediaRigheMatrix(int [][COLONNE], int, int);

/**
* @brief Stampa della matrice e per ogni riga determina il minimo e il massimo
* @param int[][] Matrice da utilizzare
* @param int Dimensione righe
* @param int Dimensione colonne
*/
void minMaxRigheMatrix(int [][COLONNE], int, int);

/**
*@brief stampa a video solo i valori primi e un'asterisco per i non primi
* @param int[][] Matrice da utilizzare
* @param int Dimensione righe
* @param int Dimensione colonne
*/
void stampaPrimi(int mat[][COLONNE], int r, int c);

/**
*@brief stampa i valori pari o dispari di ogni singola riga in base al primo valore della riga
* @param int[][] Matrice da utilizzare
* @param int Dimensione righe
* @param int Dimensione colonne
*/
void stampaPariDispari(int mat[][COLONNE], int r, int c);

/**
*@brief confronta e stampa ogni riga della matrice se la somma dei valori e maggiore della somma dei valori nel vettore
* @param int[][] Matrice da utilizzare
* @param int Dimensione righe
* @param int Dimensione colonne e vettore
*@param int[] vettore da usare
*/
void stampaSommaMaggiore(int [][COLONNE], int , int , int []);

int main(){
	int mat[RIGHE][COLONNE];
	int vet[5]={8, 17, 10, 0, 9};
	
	srand(time(NULL));
	
	initMatrice(mat, RIGHE, COLONNE, 0, 20);
	stampaMatrix(mat, RIGHE, COLONNE);
	
	sommaMediaRigheMatrix(mat, 3, 4);
	
	minMaxRigheMatrix(mat, 3, 4);
	stampaPrimi(mat, RIGHE, COLONNE);
	
	stampaPariDispari(mat, RIGHE, COLONNE);
	
	stampaSommaMaggiore(mat, RIGHE, 5, vet);
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

void sommaMediaRigheMatrix(int _mat[][COLONNE], int _r, int _c){
	int i, j;
	float sommarighe = 0, mediarighe = 0;
	
	for(i = 0; i < _r; i++){
		sommarighe = 0;
		for(j = 0; j < _c; j++){
			sommarighe = sommarighe + _mat[i][j];
			printf("%4d", _mat[i][j]);
		}
		mediarighe = sommarighe / _c;
		printf(" = %.2f -- %.2f", sommarighe, mediarighe);
		printf("\n");
	}
	printf("\n\n");
}

void minMaxRigheMatrix(int _mat[][COLONNE], int _r, int _c){
	int i, j;
	int min, max;
	
	for(i = 0; i < _r; i++){
		//Inizializzo MIN e MAX con la prima cella della riga I 
		min = _mat[i][0];
		max = _mat[i][0];
		//Eseguo il controllo per ogni cella della riga I 
		for(j = 0; j < _c; j++){
			if(_mat[i][j] < min){
				min = _mat[i][j];
			}
			if(_mat[i][j] > max){
				max = _mat[i][j];
			}
			printf("%4d", _mat[i][j]);
		}
		//Stampo i due valori trovati
		printf(" = %d -- %d", min, max);
		printf("\n");
	}
	printf("\n\n");
}

void stampaPrimi(int mat[][COLONNE], int r, int c){
	int i, j;
	int cntDiv, div;
	
	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			cntDiv=0;
			div=1;
			while(div<=mat[i][j]){
				if(mat[i][j]%div==0){
					cntDiv++;
				}
				div++;
			}
			if(cntDiv>2){
				printf("   *");
			}else{
				printf("%4d", mat[i][j]);	
			}
		}
		printf("\n");
	}
	printf("\n\n");
}

void stampaPariDispari(int mat[][COLONNE], int r, int c){
	int i, j;
	
	for(i=0; i<r; i++){
		for(j=0; j<c; j++){
			if(mat[i][0] % 2 == mat[i][j] % 2){
				printf("%4d", mat[i][j]);
			}else{
				printf("   *");
			}
		}
		printf("\n");
	}
	printf("\n\n");
}

void stampaSommaMaggiore(int mat[][COLONNE], int r, int c, int vet[]){
	int i, j;
	int sommaVet, sommaMat;
	
	for(i=0; i<r; i++){
		sommaVet=0;
		sommaMat=0;
		//calcolo le somme riga e vettore
		for(j=0; j<c; j++){
			sommaVet=sommaVet+vet[j];
			sommaMat=sommaMat+mat[i][j];
		}
		for(j=0; j<c; j++){
			if(sommaMat>sommaVet){
				printf("%4d", mat[i][j]);
			}else{
				printf("   *");
			}
		}
		printf("\n");
	}
	printf("\n\n");
}
