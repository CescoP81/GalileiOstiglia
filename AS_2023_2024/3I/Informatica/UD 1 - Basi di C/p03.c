/*
	Author: Francesco Pradella
	Date: 17.10.2023
	Filename: p03.c
	Desc: Algoritmo che richiesta una data nel formato
	giorno mese anno, determina e comunica se � valida.
*/
#include <stdio.h>

int main(){
	// dichiarazione ed inizializzazione delle variabili.
	int giorno = 0;
	int mese = 0;
	int anno = 0;
	int bisestile = 0;
	
	// fase di input dei dati
	printf("Inserisci giorno: ");
	scanf("%d", &giorno);
	printf("Inserisci mese: ");
	scanf("%d", &mese);
	printf("Inserisci anno: ");
	scanf("%d", &anno);
	
	// fase di test delle variabili
	// test sull'anno
	if(anno%100 == 0){
		if(anno%400 == 0){
			bisestile=1;
		}
	}
	else{
		if(anno%4 == 0){
			bisestile = 1;
		}
	}
	
	if(mese>=1 && mese<=12){ // test sul valore del mese
		if(mese == 2){ //test sul mese di febbraio
			if(giorno>=1 && giorno<=28+bisestile){
				printf("Data valida!");
			}
			else{
				printf("Data non valida");
			}
		}
		else{
			if(mese==1 || mese==3 || mese==5 || mese==7 || mese==8 || mese==10 || mese==12){
				if(giorno>=1 && giorno<=31){ // test se i giorni sono validi per i mesi da 31
					printf("Data valida!");
				}
				else{
					printf("Data non valida");
				}
			}
			else{
				if(giorno>=1 && giorno<=30){ // test se i giorni sono validi per i mesi da 30
					printf("Data Valida!");
				}
				else{
					printf("Data non valida");
				}
			}
		}
	}
	return(0);
}



