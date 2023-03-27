/*
Esercitazioni con vettori e funzioni - Extend p01.c
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define DIM 10

void initVettore(int [],int);

void stampaVettore(int [],int);

/**
* @Abstract Inizializza un vettore con valori random compresi tra
* min e max;se gli estremi sono a 0 i numeri random vanno da 1 a 100.
* @param int[] vettore da utilizzare 
* @param int dimensione del vettore
* @param int estremo inferiore del random
* @param int estremo superiore del random 
*/
void initVettoreRandom(int [],int ,int ,int );

/**
* @abstract funzione che ritorna il valore medio dei valori contenuti nel vettore
* @param int[] vettore da utilizzare
* @param int dimensione del vettore
* @return valore medio dei valori presenti
*/
int mediaVettore(int[], int);

/**
* @abstract funzione che restituisce il valore massimo contenuto nel vettore
* @param int[] vettore da utilizzare
* @param int dimensione del vettore
* @return valore massimo del vettore
*/
int massimoVettore(int[], int);

/**
* @abstract funzione che ricerca un valore nel vettore e restituisce il numero di volte che compare
* @param int[] vettore da utilizzare
* @param int dimensione del vettore
* @param int valore da cercare
* @return valori trovati
*/
int trovaValoreVettore(int[], int, int);

/**
* @abstract funzione che ricerca nel vettore il valore minimo e il valore massimo. La funzione deve quindi
scambiare il valore massimo e il valore minimo.
* @param int[] vettore da utilizzare
* @param int dimensione del vettore
*/
void scambioMinMax(int[], int);

/**
* @abstract funzione che ritorna la media dei valori pari o dispari del vettore con scelta dell'utente
* @param int[] vettore da utilizzare
* @param int dimensione del vettore
* @param int scelta pari / dispari 0-->pari 1-->dispari
* @return media calcolata
*/
int mediaPariDispari(int[], int, int);

/**
* @abstract stampa di un vettore al contrario
* @param int[] vettore da utilizzare
* @param int dimensione del vettore
*/
void stampaVettoreContrario(int[], int);

/**
* @abstract funzione che stampa tutti i valori primi e ne calcola la somma restituendola al main
* @param int[] vettore da utilizzare
* @param int dimensione del vettore
* @return sommaEStampaPrimi
*/
int sommaEStampaPrimi(int[], int);


int main(){
	int somma;
	int vet[DIM];
	srand(time(NULL));
	
	initVettore(vet,DIM);
	stampaVettore(vet,DIM);
	/*
	
	printf("\n");
	initVettoreRandom(vet,DIM,0,0);
	stampaVettore(vet,DIM);
	
	printf("\n");
	initVettoreRandom(vet,DIM,1,0);
	stampaVettore(vet,DIM);
	
	printf("\n");
	initVettoreRandom(vet,DIM,10,50);
	stampaVettore(vet,DIM);
	*/
	printf("\n");
	initVettoreRandom(vet,DIM,1,20);
	stampaVettore(vet,DIM);
	printf("\n");
	
	printf("media del vettore: %d\n", mediaVettore(vet, DIM));
	printf("il valore massimo e': %d\n", massimoVettore(vet, DIM));
	printf("il valore %d e' presente nel vettore: %d\n", 10, trovaValoreVettore(vet, DIM, 10));
	scambioMinMax(vet, DIM);
	stampaVettore(vet, DIM);
	
	printf("\n\nmedia valori pari: %d\n", mediaPariDispari(vet, DIM, 0));
	
	stampaVettoreContrario(vet, DIM);
	
	somma = sommaEStampaPrimi(vet, DIM);
	printf("la somma dei valori primi �: %d", somma);
	
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

int mediaVettore(int _vet[], int _DIM){
	int media = 0;
	int i;
	
	for(i = 0; i < _DIM; i++){
		media = media + _vet[i];
	}
	media = media / _DIM;
	return(media);
}

int massimoVettore(int _vet[], int _DIM){
	int max;
	int i;
	
	max = _vet[0];
	for(i = 1; i < _DIM; i++){
		if(_vet[i] > max){
			max = _vet[i];
		}
	}
	return(max);
}

int trovaValoreVettore(int _vet[], int _DIM, int _src){
	int i;
	int cnt = 0;
	
	for(i = 0; i < _DIM; i++){
		if(_vet[i] == _src){
			cnt++;
		}
	}
	return(cnt);
}

void scambioMinMax(int _vet[], int _DIM){
	int i;
	int max, imax;
	int min, imin;
	int tmp;
	
	max = _vet[0];
	imax = 0;
	min = _vet[0];
	imin = 0;
	
	for(i = 1; i < _DIM; i++){
		if(_vet[i] > max){
			max = _vet[i];
			imax = i;
		}
		if(_vet[i] < min){
			min = _vet[i];
			imin = i;
		}
	}
	tmp = _vet[imin];
	_vet[imin] = _vet[imax];
	_vet[imax] = tmp;
}

int mediaPariDispari(int _v[], int _DIM, int _PD){
	
	int i;
	int somma = 0;
	int cnt = 0;
	int media = 0;
	
	for(i=0;i<_DIM;i++){
		/*
		if(_PD == 0){
			if(_v[i] % 2 == 0){
				somma = somma + _v[i];	
				cnt++;			
			}
		}
		
		if(_PD == 1){
			if(_v[i] % 2 != 0){
				somma = somma + _v[i];	
				cnt++;			
			}
		}
		il codice che segue � equivalente ma "ottimizzato"
		*/
		if(_v[i] % 2 == _PD){
			somma = somma + _v[i];
			cnt++;
		}

	}
	printf("\n");
	printf("%d %d", somma, cnt);
	media = somma / cnt;
	return(media);
}

void stampaVettoreContrario(int _v[], int _DIM){
	int i;
	printf("\n\n");
	for(i=(_DIM-1);i>=0;i--){
		printf("%3d",_v[i]);
	}	
}

int sommaEStampaPrimi(int _v[], int _DIM){
	
	int i;
	int cnt;
	int conto;
	int somma = 0;
	printf("\n\n");
	for(i=0;i<_DIM;i++){
		conto = 0;
		
		for(cnt = 1; cnt < _v[i]; cnt++){
			if(_v[i] % cnt == 0){
				conto++;
			}
		}

		if(conto <= 2){
			printf("%3d", _v[i]);
			somma = somma + _v[i];
		}	
	}
	printf("\n");
	return(somma);
	
	
}





