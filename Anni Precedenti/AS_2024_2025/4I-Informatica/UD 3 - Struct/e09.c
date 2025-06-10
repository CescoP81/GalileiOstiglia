/*
Date: 2025.01.07
Author: Rossi Marco
Abstract: Creare un programma per catalogare delle merci che sono
identificate da:
-matricola (char[5])
-descrizione (char[15])
-prezzo (float)
-data di scadenza(anno/mese/giorno)(struct di 3 int)
Permettere l'inserimento di un massimo di 10 merci,
visualizzare le merci presenti, ricercare per mese di scadenza.
L'ultima clausola �:
-garantire che non siano presenti due matricole uguali
(m001, m002, m001[non pu� esistere])

## DA ULTIMARE PER LUNEDi' 13 ##
*/
#include<stdio.h>
#include<string.h>

typedef struct{
	char matricola[5];
	char descrizione[15];
	float prezzo;
	struct{
		int anno;
		int mese;
		int giorno;
	}dataScadenza;
}prodotto;

void inserisciMerce(prodotto _lista[], int _contaProdotti, int _maxProdotti);

int main(){
	prodotto lista[10];
	int sceltaMenu;
	int cercaMese;
	int contaProdotti = 0;
	int i;
	
	do{
		printf("Men�:\n");
		printf("1) Inserisci prodotto\n");
		printf("2) Visualizza elenco prodotti\n");
		printf("3) Ricerca per mese scadenza\n");
		printf("4) Esci");
		printf("Scelta: ");
		scanf("%d", &sceltaMenu);
		fflush(stdin);
		
		switch(sceltaMenu){
			case 1:{
				inserisciMerce(lista[10], &contaProdotti, 10);
				break;
			}
			case 2:{
				for(i=0; i<contaProdotti; i++){
				}
				break;
			}
		}
	}while(sceltaMenu != 0);
}

void inserisciMerce(prodotto _lista[], int *_contaProdotti, int _maxProdotti){
	int i, matricolaUguale;
	
	if(_contaProdotti < _maxProdotti){
		//chiedo i dati della nuova merce perche sono su una cella valida
		do{
			printf("Matricola: ");
			scanf("%s", _lista[*_contaProdotti].matricola);
			matricolaUguale = 0;
			for(i=0; i<*_contaProdotti; i++){
				if(strcmp(_lista[*_contaProdotti].matricola, _lista[i].matricola) == 0){
					matricolaUguale = 1;
				}	
			}
		}while(matricloaUguale = 1);
		printf("Descrizione: ");
		scanf("%s", _lista[*_contaProdotti].descrizione);
		printf("Prezzo: ");
		scanf("%f", &_lista[*_contaProdotti].prezzo);
		printf("Data di scadenza(separati da uno /)");
		scanf("%d/%d/%d", &_lista[*_contaProdotti].dataScadenza.anno,&_lista[*_contaProdotti].dataScadenza.mese, &_lista[*_contaProdotti].dataScadenza.giorno);
		*_contaProdotti++;
	}
	else
		printf("Posto esaurito.\n");
}
