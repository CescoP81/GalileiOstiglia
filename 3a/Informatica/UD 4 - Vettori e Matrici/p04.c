#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 10

void initVettore(int [],int);
/**
* @brief Inizializza un vettore con valori random compresi tra
* min e max;se gli estremi sono a 0 i numeri random vanno da 1 a 100.
* @param int[] vettore da utilizzare 
* @param int dimensione del vettore
* @param int estremo inferiore del random
* @param int estremo superiore del random 
*/
void initVettoreRandom(int [],int ,int ,int );
void stampaVettore(int [],int);

/**
*@brief funzione che ritorna la media di tutti i valori del vettore
*@param int[] vettore da utilizzare
*@param int dimensione del vettore
*@return valore medio del vettore
*/
float mediaValori(int [], int);

/**
*@brief inizializza un vettore con valori random univoci compresi tra 1 e 2 * dim
*@param int[] Vettore da utilizzare.
*@param int Dimensione del vettore.
*/
void initVettoreValoriUnivoci(int [], int);

int main(){
	int vet[DIM];
	srand(time(NULL));
	
	initVettoreRandom(vet, DIM, 1, 10);
	stampaVettore(vet, DIM);
	
	float media = mediaValori(vet, DIM);
	printf("\nla media e': %f\n", media);
	
	initVettoreValoriUnivoci(vet, DIM);
	stampaVettore(vet, DIM);
	return(0);
}

void initVettore(int _v[],int _DIM){	
	int i;
	
	for(i=0;i<_DIM;i++){
		_v[i]=0;
	}	
}
void stampaVettore(int _v[],int _DIM){
	int i;
	
	for(i=0;i<_DIM;i++){
		printf("%3d",_v[i]);
	}
	printf("\n");
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
float mediaValori(int _v[], int _DIM){
	float media;
	int i;
	float somma = 0;
	
	for(i=0; i<_DIM; i++){
		somma = somma + _v[i];
	}
	media = somma / _DIM;
	return(media);	
}
void initVettoreValoriUnivoci(int _v[], int _DIM){
	int i;	    //variabile per il ciclo di riempimento
	int j;		// variabile per il ciclo di ricerca
	int trovato; //flag utilizzato per verificare se un numero è univoco o no
	
	i=0;
	while(i<_DIM){
		trovato=0;
		_v[i]=1 + rand()%(_DIM * 2);
		for(j=0; j<i; j++){
			if(_v[j] == _v[i]){
				trovato=1;
			}
		}
		if(trovato==0){
			i=i+1;
		}
	}
}
