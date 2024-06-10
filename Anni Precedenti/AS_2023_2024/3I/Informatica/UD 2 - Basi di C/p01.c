/*
	Author: Pradella Francesco
	Date: 05.10.23
	File: p01.c
	Abstract: Algoritmo per il calcolo di area e perimetro
	di un rettangolo; base e altezza inseriti in input.
*/
#include <stdio.h>

int main(){
	int base;		// variabile per la base del rettangolo.
	int altezza;	// variabile per l'altezza del rettangolo.
	int area;		// contiene l'area calcolata.
	int perimetro;	// contiene il perimetro calcolato.
	
	int areaRettangolo; // meglio utilizzare la Camel Notation, prima iniziale
						// minuscola, tutte le altre maiuscole.
						/* areaRettangoloPiccolo; cerchioRosso, triangoloScaleno
	
	// fase di input dei dati (base e altezza)
	printf("Base: ");
	scanf("%d",&base);
	
	printf("Altezza: ");
	scanf("%d", &altezza);
	
	// calcolo l'area e il perimetro.
	area = base / altezza;
	perimetro = (base + altezza) * 2;
	
	// comunico (stampo) i risultati a video
	printf("Area: %d\n", area);
	printf("Perimetro: %d", perimetro);
	
	return(0);
}






