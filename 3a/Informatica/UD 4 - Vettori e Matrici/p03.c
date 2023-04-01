#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 10


void initVettore(int [],int);
/**
* @Abstract Inizializza un vettore con valori random compresi tra
* min e max;se gli estremi sono a 0 i numeri random vanno da 1 a 100.
* @param int[] vettore da utilizzare 
* @param int dimensione del vettore
* @param int estremo inferiore del random
* @param int estremo superiore del random 
*/
void initVettoreRandom(int [],int ,int ,int );
void stampaVettore(int [],int);
/**
* @abstract Moltiplica tutte le celle del vettore per un valore fisso detto fattore
* @param int[] vettore da utilizzare
* @param int dimensione del vettore
* @param int fattore moltiplicativo
*/
void moltiplicaVettore(int[], int, int);

/**
* @abstract trova tutti i multipli di un valore passato e denominato base
* @param int[] vettore da utilizzare
* @param int dimensione del vettore
* @param int valore di riferimento "base" 
*/
void trovaMultipli(int[], int, int);

/**
* @abstract dato un vettore in input modificarne ogni singolo parametro mettendo
la somma cumulativa fino alla iesima posizione
* @param int[] vettore da utilizzare
* @param int dimensione del vettore
*/
void totaliSuccessivi(int[], int);

/**
* @Abstract verifica se i valori del vettore sono tutti in ordine crescente
* @param int[] vettore da utilizzare
* @param int dimensione del vettore
*/
void verificaVettoreCrescente(int[], int);

/**
* @Abstract inverte i valori nel vettore rispetto alla metà del vettore
* @param int[] vettore da utilizzare
* @param int dimensione vettore
*/
void ribaltaVettore(int[], int);

int main(){
	int vet[DIM];
	srand(time(NULL)); // obbligatoria per generare numeri random
	
	initVettoreRandom(vet,DIM,1,8);
	stampaVettore(vet, DIM);
	
	printf("\n\n");
	moltiplicaVettore(vet, DIM, 2);
	stampaVettore(vet, DIM);
	
	printf("\n\n");
	trovaMultipli(vet, DIM, 3);
	
	printf("\n\n");
	totaliSuccessivi(vet, DIM);
	stampaVettore(vet, DIM);
	
	printf("\n\n");
	verificaVettoreCrescente(vet, DIM);
	
	printf("\n\n");
	ribaltaVettore(vet, DIM);
	stampaVettore(vet, DIM);
	return(0);
}

/* DEFINIZIONE DELLE FUNZIONI */
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
void moltiplicaVettore(int _vet[], int _DIM, int _fattore){
	int i;
	
	for(i=0;i<_DIM;i++){
		_vet[i] = _vet[i] * _fattore;
	}
}
void trovaMultipli(int _vet[], int _DIM, int _base){
	int i;
	
	for(i=0;i<_DIM;i++){
		if(_vet[i] % _base == 0){
			printf("%3d", _vet[i]);
		}
		else{
			printf("  #");
		}
	}
}
void totaliSuccessivi(int _vet[], int _DIM){
	int i;
	
	for(i=1;i<_DIM;i++){
		_vet[i] = _vet[i] + _vet[i - 1]; 
	}
}
void verificaVettoreCrescente(int _vet[], int _DIM){
	int i;
	int crescente;
	
	crescente=1; //di default ipotizzo che il vettore sia crescente
	
	for(i=1;i< _DIM; i++){
		if(_vet[i] < _vet[i-1]){
			crescente=0; //condizione che rende il vettore non più crescente 
		}
	}
	if(crescente==1){
		printf("regola verificata");
	}
	else{
		printf("una coppia non rispetta la crescente");
	}
}
void ribaltaVettore(int _vet[], int _DIM){
	int i;
	int tmp;
	
	for(i=0;i<_DIM/2;i++){
		tmp=_vet[i];
		_vet[i]=_vet[_DIM - i - 1];
		_vet[_DIM - i - 1] = tmp;
	}
}
