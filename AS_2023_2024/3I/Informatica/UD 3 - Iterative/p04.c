/**
*	Author: Pradella F.
*	Date: 16.11.23
*	File: p04.c
* 	Desc: Realizzare un algoritmo che, come una cassiera del supermercato,
*	richiede l'importo di singoli prodotti.
*	Quando l'importo inserito è 0 allora comunica il totale della spesa,
*	il numero di prodotti ed il prezzo medio.
*/
#include <stdio.h>

int main(){
	int prezzo;		// variabile per il prezzo richiesto in input.
	int totale;		// variabile per il totale da pagare.
	int cntProdotti;// Contatore dei prodotti inseriti.
	float media;	// variabile per la media dei prezzi inseriti.
	
	totale = 0;
	cntProdotti = 0;
	media = 0.0;
	
	do{
		printf("Inserisci il prezzo ");		// richiesta di un prezzo
		scanf("%d", &prezzo);
		fflush(stdin);
		
		if(prezzo != 0){					// se il prezzo inserito � diverso da 0.
			totale = totale + prezzo;		// aggiungo il prezzo al totale.
			cntProdotti = cntProdotti + 1;	// incremento il numero di prezzi inseriti.
		}
	}while(prezzo != 0);
	
	media = (float)totale / cntProdotti;	// calcolo il prezzo medio.
	
	printf("Numero prodotti inseriti: %d\n", cntProdotti);
	printf("Spesa totale: %d\n", totale);
	printf("Prezzo medio inserito: %.2f\n", media);	
		
	return(0);
}
