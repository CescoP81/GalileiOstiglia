/*
Realizzare un programma C che sviluppi le seguenti funzioni:
1. initVettore -> inizializza un vettore di 15 elementi con valori casuali tra 1 e 50 estremi compresi.
2. stampaVettore -> visualizza l'intero vettore.
3. ricercaValore -> Riceve un vettore ed un valore da ricercare, restituisce il numero di volte che trova il valore nel vettore.
4. swapValori -> riceve un vettore e due indici, quindi scambia il valore delle celle identificate dagli indici. Ritorna 1 se l'operazione è stata eseguita, ritorna 0 se gli indici non sono validi.
5. equalsVettori -> riceve due vettori di uguale lunghezza e verifica che siano uguali oppure no.
    ritorna 1 se i due vettori sono uguali, 0 se non sono uguali.
*/
#include <conio.h>
#include <stdio.h>
#include "lib.c"

#define DIM 15

int main(){
    int vet1[DIM];
    int vet2[DIM];
    int val;
    int indice1, indice2;

    // punto 1
    initVettore(vet1, DIM);
    initVettore(vet2, DIM);

    // punto 2
    stampaVettore(vet1, DIM);
    stampaVettore(vet2, DIM);

    // punto 3
    printf("Valore per ricerca: ");
    scanf("%d", &val);
    fflush(stdin);
    printf("Il valore %d e' stato trovato: %d volta/e.\n", val, ricercaValore(vet1, DIM, val));
    printf("Il valore %d e' stato trovato: %d volta/e.\n", val, ricercaValore(vet2, DIM, val));

    // punto 4
    printf("Indice 1: ");
    scanf("%d", &indice1);
    fflush(stdin);
    printf("Indice 2: ");
    scanf("%d", &indice2);
    fflush(stdin);
    if(swapValori(vet1, DIM, indice1, indice2) == 1){
        printf("Valori Scambiati\n");
        stampaVettore(vet1, DIM);
        printf("\n");
    }
    else
        printf("Valori non scambiati, errore negli indici.\n");

    // punto 5
    if(equalsVettori(vet1, vet2, DIM) == 1)
        printf("I due vettori contengono gli stessi valori.");
    else
        printf("I due vettori differiscono per almeno un valore.");
}