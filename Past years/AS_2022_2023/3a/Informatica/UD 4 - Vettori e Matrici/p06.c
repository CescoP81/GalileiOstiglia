#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 10
/**
* @brief Inizializza un vettore con valori random compresi tra min e max;se gli estremi sono a 0 i numeri random vanno da 1 a 100.
* @param int[] vettore da utilizzare 
* @param int dimensione del vettore
* @param int estremo inferiore del random
* @param int estremo superiore del random 
*/
void initVettoreRandom(int [],int ,int ,int );

void stampaVettore(int [],int);

/**
* @brief funzione che riceve vett1 e vett2 e nel vett3 metti la differenza tra vett1 e vett2
* @param int[] vett1 da utilizzare
* @param int[] vett2 da utilizzare
* @param int[] vett3 differenza tra vett1 e vett2
* @param int dimensione del vettore
*/
void differenzaVettori(int [], int [], int[], int);

/**
* @brief funzione che determina e visualizza i valori che nel vettore sono quadrati perfetti
* @param int[] vettore da utilizzare
* @param int dimensione del vettore
*/
void quadratiPerfetti(int [], int);

/**
* @brief funzione che ricerchi e stampi le coppie di due valori presenti nel vettore tali che:
il primo valore sia uguale al quadrato del secondo
* @param int [] vettore da utilizzare
* @param int dimensione del vettore
*/
void quadratiVettore(int [], int);

/**
* @brief funzione che ricerchi e stampi nel vettore i valori uguali vicini presenti nel vettore
* @param int [] vettore da utilizzare
* @param int dimensione del vettore
*/
void valoriUgualiVicini(int [], int);

/**
* @brief  Creare una funzione che prende in input 3 vettori la funzione deve inserire in v3 gli elementi presenti 
in v1 che sono presenti anche in v2
* @param int[] vett1 da utilizzare
* @param int[] vett2 da utilizzare
* @param int[] vett3 da utilizzare
* @param int dimensione del vettore
*/
void VettoriValoriUguali(int [],int [],int [],int);

void initVettore(int [],int);
int main(){
	int vett1[DIM];
	int vett2[DIM];
	int vett3[DIM]={0};
	srand(time(NULL));
	
	initVettoreRandom(vett1, DIM, 1, 20);
	stampaVettore(vett1, DIM);
	
	initVettoreRandom(vett2, DIM, 1, 20);
	stampaVettore(vett2, DIM);
	
	differenzaVettori(vett1, vett2, vett3, DIM);
	stampaVettore(vett3, DIM);
	printf("\n");
	
	quadratiPerfetti(vett1, DIM);
	printf("\n");
	quadratiVettore(vett1, DIM);
	printf("\n");
	valoriUgualiVicini(vett1, DIM);
	printf("\n");
	initVettore(vett3,DIM);
	VettoriValoriUguali(vett1,vett2,vett3,DIM);
	stampaVettore(vett3, DIM);
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

void differenzaVettori(int _v1[], int _v2[], int _v3[], int _DIM){
	int i;
	
	for(i=0; i<_DIM; i++){
		_v3[i] = _v1[i] - _v2[i];
	}
}

void quadratiPerfetti(int _v[], int _DIM){
	int i;
	int j;
	
	for(i=0; i<_DIM; i++){
		for(j=1; j<_v[i]; j++){
			if(_v[i] == (j*j)){
				printf("%d = %d * %d\n", _v[i], j, j);
			}
		}
	}
}

void quadratiVettore(int _v[], int _DIM){
	int i;
	int j;
	
	for(i=0; i<_DIM; i++){
		for(j=0; j<_DIM; j++){
			if(_v[i] == _v[j]*_v[j]){
				printf("%d , %d\n", _v[i], _v[j]);
			}	
		}	
    }
}

void valoriUgualiVicini(int _v[], int _DIM){
	int i;
	
	for(i=0;i<_DIM;i++){
		if(_v[i] == _v[i+1]){
			printf("%d ", _v[i]);
		}
	}
}
void initVettore(int _v[],int _DIM){	
	int i;
	
	for(i=0;i<_DIM;i++){
		_v[i]=0;
	}	
}
void VettoriValoriUguali(int _vet1[],int _vet2[],int _vet3[],int _DIM){
	int i;
	int j;
	int x=0;
	int trovato;
	
	for(i=0;i<_DIM;i++){
		trovato=0;
		for(j=0;j<_DIM;j++){
			if(_vet1[i] ==_vet2[j]){
				trovato=1;	
			}
		}
		if(trovato==1){
			_vet3[x]=_vet1[i];
			x++;
		}
	}
}
