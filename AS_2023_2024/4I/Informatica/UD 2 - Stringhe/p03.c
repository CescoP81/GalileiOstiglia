/**
 * Creare un programma C che soddisfi le seguenti richieste:
 * - [x] input di una stringa.
 * - [x] stampa di una stringa a video con funzione ricorsiva.
 * - [x] Conteggio delle lettere maiuscole e minuscole in una stringa.
 * - [x] Verifica se esistono doppie in una stringa 'otto', 'sette'.
 * - [x] Prima lettera sempre maiuscola (se la stringa inizia con una minuscola, la trasforma in maiuscola).
 * - [x] Per ogni lettera calcola e stampa il numero di occorrenze (quante volte ogni lettera compare).
 * - [x] Crea stringa inversa. (st1 è l'originale, st2 è l'inversa).
 * - [x] Verifica se due stringhe sono anagrammi (st2 è anagramma di st1, anagramma: parole diverse ma formate dalle stesse lettere)
 * 
 * Utilizzare le funzioni già esistenti nel file lib.c/lib.h, le nuove funzioni prima farne un test nel main e poi spostarle nel file libreria.
*/
#include <stdio.h>
#include "lib.c"
const int DIM = 21;

int main(){
    char str[DIM];
    char str2[DIM];

    // punto 1
    initStringa(str, DIM);
    inputStringa(str);

    // punto 2
    stampaStringaRicorsiva(str, 0);
	printf("\n");
    // punto 3
    contaMaiuscoleMinuscole(str);
	printf("\n");
    // punto 4
    if(verificaDoppie(str))
        printf("\nNella stringa '%s' esistono una o piu' lettere doppie\n", str);
    else
        printf("\nNella stringa '%s' non sono presenti doppie.\n", str);
    
    // punto 5
    primaLetteraMaiuscola(str);
    printf("Stringa modificata: %s\n", str);

	// punto 6
	contaSingoleLettere(str);
	printf("\n");
	
	// punto 7
	stringaInversa(str, str2);
	printf("La stringa inversa e'': %s\n", str2);
	
	return(0);
}