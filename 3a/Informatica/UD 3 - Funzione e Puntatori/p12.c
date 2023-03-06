/*
	Programma di visualizzazione della ASCII TABLE, finding di un carattere o del relativo codice decimale.
	Sviluppato con funzioni.
*/
#include <stdlib.h> 
#include <stdio.h>

void tabellaAscii();
void verificaCarattere(char);
void verificaDecimale(int);

int main(){
	int scelta;
	int decimale;
	char carattere;
		
	do{
		printf("1 stampa ascii \n");
		printf("2 verifica carattere.\n");
		printf("3 verifica codice decimale.\n");
		printf("0 uscita\n");
		printf("scelta: ");
		scanf("%d", &scelta);
		fflush(stdin);
		switch (scelta){
			case 1: {
				tabellaAscii();				
				break;
			}
			case 2:{
				printf("inserisci un carattere: ");
				scanf("%c", &carattere);
				fflush(stdin);
				
				verificaCarattere(carattere);								
				break;
			}
			case 3:{
				printf("inserisci un numero: ");
				scanf("%d", &decimale);
				fflush(stdin);
				
				verificaDecimale(decimale);							
				break;
			}			
		}
		system ("PAUSE");
	}while(scelta!=0);
}

void tabellaAscii(){
	int i;
	printf("ASCII table: \n");
	for(i=1;i<=255;i++){
		printf("%d: %c ", i, i);
		if(i%15==0)					
			printf("\n");					
	}
}

void verificaCarattere(char _car){
	printf("%c --> %d\n", _car, _car);	
}

void verificaDecimale(int _dec){
	if(_dec<255){
		printf("%d --> %c\n", _dec, _dec);
	}else{
		printf("out of ASCII table\n");
	}	
}
