
/*
	File: 	e04.c
	Date:	2024.11.26
	Author:	Manfredini Tommaso
	Update: 2024.12.02 - Turazza K.
	Abstract: Realizzare un programma C che gestisca una lista della spesa di massimo 20 elementi, per ogni elemento deve essere possibile specificare Nome, quantita e prezzo.
	Il programma deve permettere di inserire un elemento per volta, visualizzare gli elementi presenti, calcolare e comunicare il totale della spesa in quel momento.
*/
#include <stdio.h>
#include <string.h>

#define SPESA 20

typedef struct{
	char prodotto[20];
	int quantita;
	float prezzo;
}Elemento;

float totaleSpesa(Elemento _carrello[], int _numeroProdotti);
void ricerca(Elemento _carrello[], int _numeroProdotti, char _prodotto[]);

int main (){
	char prodotto[20];
	Elemento carrello[20];
	int numeroProdotti;
	int i;
	int scelta;
	float totale=0;
	
	numeroProdotti=0;
		
	do{
		printf("1. aggiungi elemento \n");
		printf("2. visualizza spesa \n");
		printf("3. totale spesa \n");
		printf("4. ricerca prodotto \n"); //la ricerca si basa sul nome
		printf("0. uscita");
		printf("scelta: \n");
		scanf("%d", &scelta);
		switch(scelta){
			case 1:{
				if(numeroProdotti<SPESA){
					// devo richiedere all'utente i dati del nuovo prodotto 
					printf("inserisci il prodotto: \n");
					scanf("%s", carrello[numeroProdotti].prodotto);
					printf("inserisci la quantit?: \n");
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
				totale=totaleSpesa(carrello, numeroProdotti);
				printf("Il totale attualmente e': %.2f\n\n", totale);
				break;
			}
			case 4:{
				printf("inserisci nome da ricercare: ");
				scanf("%s", &prodotto);
				ricerca(carrello,numeroProdotti,prodotto);
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

float totaleSpesa(Elemento _carrello[], int _numeroProdotti){
	
	int i=0;
	float somma=0;
	
	for(i=0;i<_numeroProdotti;i++){
		
		somma+=_carrello[i].prezzo*((float)_carrello[i].quantita);
		
	}
	
	return (somma);
}
void ricerca(Elemento _carrello[], int _numeroProdotti, char _prodotto[]){
	int i=0;
	int j=0;
	int cnt=0;
	int index=-1;
	
	char s1[20];
	char s2[20];
	
	
	
	for(j=0;j<_numeroProdotti;j++){
		cnt = 0;
		strcpy(s1, _carrello[i].prodotto);
		strcpy(s2, _prodotto);
		
		for(i=0; s1[i]!= '\0'; i++)
			s1[i] = toupper(s1[i]);
		for(i=0; s2[i]!= '\0'; i++)
			s2[i] = toupper(s2[i]);
			
		printf("%s %s\n", s1, s2);
		cnt=strcmp(s1, s2);
		
		if(cnt==0)
			index=j;
	}
	
	printf("--%d--", index);
	if(index != -1)
		printf("%s, quantit : %d, prezzo: %.2f\n\n", _carrello[index].prodotto, _carrello[index].quantita, _carrello[index].prezzo);

}
