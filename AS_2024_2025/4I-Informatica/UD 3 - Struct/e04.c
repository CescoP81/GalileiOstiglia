/*
	File: 	e04.c
	Date:	2024.11.26
	Author:	Manfredini Tommaso
	Abstract: Realizzare un programma C che gestisca una lista della spesa di massimo 20 elementi, per ogni elemento deve essere possibile specificare Nome, quantita e prezzo.
	Il programma deve permettere di inserire un elemento per volta, visualizzare gli elementi presenti, calcolare e comunicare il totale della spesa in quel momento.
*/
#include <stdio.h>
#include<string.h>

#define SPESA 20

typedef struct{
	char prodotto[20];
	int quantita;
	float prezzo;
}Elemento;

int main (){
	Elemento carrello[20];
	int numeroProdotti;
	int i;
	int scelta;
	
	numeroProdotti=0;
		
	do{
		printf("1. aggiungi elemento: \n");
		printf("2. visualizza spesa: \n");
		printf("3. totale spesa: \n");
		printf("0. uscita");
		printf("scelta: \n");
		scanf("%d", &scelta);
		switch(scelta){
			case 1:{
				if(numeroProdotti<SPESA){
					// devo richiedere all'utente i dati del nuovo prodotto 
					printf("inserisci il prodotto: \n");
					scanf("%s", carrello[numeroProdotti].prodotto);
					printf("inserisci la quantit�: \n");
					scanf("%d", &(carrello[numeroProdotti].quantita));
					printf("indrisci prezzo: \n");
					scanf("%f", &(carrello[numeroProdotti].prezzo));
					numeroProdotti++;
				}else{
					printf("carrello pieno. \n");
				}
				break;
			}
			case 2:{
				for(i=0; i<numeroProdotti; i++){
					printf("%s %d %.2f\n", carrello[i].prodotto, carrello[i].quantita, carrello[i].prezzo);
				}
				break;
			}
			case 3:{
				
				break;
			}
			case 0:{
				printf("spesa conclusa.");
				break;
			}
			default:{
				printf("scelta non valida\n");
				break;
			}	
		}
	}while(scelta!=0);
}
