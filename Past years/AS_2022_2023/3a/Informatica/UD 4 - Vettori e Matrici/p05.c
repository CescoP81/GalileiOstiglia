#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define DIM 5

/**
* @brief Richiede l'inserimento di valori univoci nel vettore senza un range.
* @param int[] Vettore da utilizzare
* @param int Dimensione del vettore 
*/
void loadUniqueValues(int [], int);

void stampaVettore(int [], int);

/**
* @brief Ritorna il valore del vettore più vicino al valore passato come parametro.
* @param int[] Vettore da utilizzare
* @param int Dimensione del vettore
* @return int Valore più vicino al parametro inserito
*/
int valuePiuVicinoVet(int [], int, int);

/**
* @brief Funzione che stampa a video i valori di vet1 non presenti in vet2 
* @param int[] Primo vettore da utilizzare
* @param int[] Secondo vettore da utilizzare
* @param int Dimensione del vettore
*/
void valoriNotPresentVettore(int [], int [], int);

void initVettoreRandom(int [], int, int, int);

int main(){
	int vet1[DIM] = {0};
	int vet2[DIM];
	int valDif;
	srand(time(NULL));
	
	/*
	loadUniqueValues(vet, DIM);
	stampaVettore(vet, DIM);
	printf("\n\n");
	*/
	
	initVettoreRandom(vet1, DIM, 1, 10);
	stampaVettore(vet1, DIM);
	printf("\n\n");
	
	initVettoreRandom(vet2, DIM, 1, 10);
	stampaVettore(vet2, DIM);
	printf("\n\n");
	
	valDif = valuePiuVicinoVet(vet1, DIM, 8);
	printf("Il valore del vettore piu' vicino a quello passato per parametro e' %d", valDif);
	printf("\n\n");
	
	valoriNotPresentVettore(vet1, vet2, DIM);
	printf("\n\n");
}

void loadUniqueValues(int _v[], int _DIM){
	int i;
	int cnt = 0;
	int trovato;
	
	while(cnt < _DIM){
		trovato = 0;
		printf("Inserisci dei valori[%d]: ", cnt);
		scanf("%d", &_v[cnt]);
		fflush(stdin);
		for(i = 0; i < cnt; i++){
			if(_v[i] == _v[cnt]){
				trovato = 1;
			}
		}
		printf("%d --> trovato", trovato);
		printf("\n");
		if(trovato == 0){
			cnt++;
		}
	}
}

void stampaVettore(int _v[], int _DIM){
	int i;
	
	for(i = 0; i < _DIM; i++){
		printf("%3d", _v[i]);
	}
}

int valuePiuVicinoVet(int _v[], int _DIM, int _val){
	int i;
	int diffmin;	//Differenza minima trovata
	int valDif;	  //Valore da restituire
	int diff;	//Differenza assoluta attuale
	
	diffmin = abs(_v[0] - _val);
	valDif = _v[0];
	for(i = 1; i < _DIM; i++){
		diff = abs(_v[i] - _val);
		if(diff < diffmin){
			diffmin = diff;
			valDif = _v[i];
		}
	}
	
	return(valDif);
}

void initVettoreRandom(int _v[], int _DIM, int _min, int _max){
	int i;
	
	if(_min == 0 || _max == 0 || _min >= _max){	
		for(i = 0; i< _DIM; i++){
			_v[i] = rand() % 100 + 1;
		}
	}
	else{
		for(i = 0; i< _DIM; i++){
			_v[i] = _min + (rand() % (_max - _min + 1));
		}
	}
}

void valoriNotPresentVettore(int _v1[], int _v2[], int _DIM){
	int i;	//Variabile per vettore1
	int trovato;	//Flag di controllo
	int j = 0;	//Variabile per vettore2
	
	for(i = 0; i < _DIM; i++){
		trovato = 0;
		for(j = 0; j < _DIM; j++){
			if(_v1[i] == _v2[j]){
				trovato = 1;
			}
		}
		if(trovato == 0){
			printf("%d ", _v1[i]);
		}
	}
}